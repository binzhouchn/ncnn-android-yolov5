//
// Created by 邓昊晴 on 14/6/2020.
//

#include "YoloV5.h"

bool YoloV5::hasGPU = false;
YoloV5* YoloV5::detector = nullptr;

YoloV5::YoloV5(AAssetManager* mgr, const char *param, const char *bin) {
    Net = new ncnn::Net();
    Net->load_param(mgr,param);
    Net->load_model(mgr,bin);
}

YoloV5::~YoloV5() {
    delete Net;
}

std::vector<BoxInfo> YoloV5::detect(JNIEnv* env, jobject image) {
    AndroidBitmapInfo img_size;
    AndroidBitmap_getInfo(env, image, &img_size);

    ncnn::Mat in_net = ncnn::Mat::from_android_bitmap_resize(env,image,ncnn::Mat::PIXEL_RGBA2RGB,input_size,input_size);
    float norm[3] = {1/255.f,1/255.f,1/255.f};
    float mean[3] = {0,0,0};
    in_net.substract_mean_normalize(mean,norm);
    auto ex = Net->create_extractor();
    ex.set_light_mode(true);
    ex.set_num_threads(4);
    ex.input(0, in_net);
    std::vector<BoxInfo> result;
    ncnn::Mat blob;
    ex.extract("output",blob);
    auto boxes = decode_infer(blob,{(int)img_size.width,(int)img_size.height});
    result.insert(result.begin(),boxes.begin(),boxes.end());
    return result;
}

std::vector<BoxInfo>
YoloV5::decode_infer(ncnn::Mat &data,  const cv::Size &frame_size) {
    std::vector<BoxInfo> result;
    for (int i = 0; i < data.h; i++){
        BoxInfo box;
        const float* values = data.row(i);
        box.x1 = values[2] * (float)frame_size.width;
        box.y1 = values[3] * (float)frame_size.height;
        box.x2 = values[4] * (float)frame_size.width;
        box.y2 = values[5] * (float)frame_size.height;
        box.score = values[1];
        box.label = values[0]-1;
        result.push_back(box);
    }
    return result;
}
