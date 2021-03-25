# NCNN YOLOv5

### 移动端NCNN部署，项目支持YOLOv5s、YOLOv4-tiny、MobileNetV2-YOLOv3-nano、Simple-Pose、Yolact、ChineseOCR-lite、ENet、Landmark106、DBFace、MBNv2-FCN与MBNv3-Seg-small模型，摄像头实时捕获视频流进行检测，也可以上传图片或者视频进行检测！

## Android:
- Android Studio 4.1.3
- Gradle model version=6.1.1, NDK version=21.0.6113669
- MACOS(10.15.7)本地编译
- 测试机型: 小米6(处理器-高通骁龙835, RAM-4GB, Android版本-8.0.0)


### 模型
| model | android | iOS | from |
|-------------------|:--------:|:--------:|:--------:|
| YOLOv5s           | yes | yes |  [Github](https://github.com/ultralytics/yolov5)   |
| YOLOv4-tiny       | yes | yes |  [Github](https://github.com/ultralytics/yolov3)   |
| YOLOv3-nano       | yes | yes |  [Github](https://github.com/dog-qiuqiu/MobileNet-Yolo)   |
| YOLOv5s_custom_op | yes | yes |  [zhihu](https://zhuanlan.zhihu.com/p/275989233)   |
| NanoDet           | yes | yes |  [Github](https://github.com/RangiLyu/nanodet)   |
| YOLO-Fastest-xl   | yes | yes |  [Github](https://github.com/dog-qiuqiu/Yolo-Fastest)   |
| Simple-Pose       | yes | yes |  [Github](https://github.com/dog-qiuqiu/MobileNet-Yolo)   |
| Yolact            | yes | yes |  [Github](https://github.com/dbolya/yolact) [zhihu](https://zhuanlan.zhihu.com/p/128974102)  |
| ChineseOCR_lite   | yes | yes |  [Github](https://github.com/ouyanghuiyu/chineseocr_lite) [zhihu](https://zhuanlan.zhihu.com/p/113338890)   |
| ENet              | bug | cancel |  [Github](https://github.com/davidtvs/PyTorch-ENet)   |
| Landmark106       | yes | yes |  [Github](https://github.com/dog-qiuqiu/MobileNet-Yolo)   |
| DBFace            | yes | yes |  [Github](https://github.com/yuanluw/DBface_ncnn_demo)   |
| MBNv2-FCN         | yes | yes |  [Github](https://github.com/open-mmlab/mmsegmentation)   |
| MBNv3-Seg-small   | yes | yes |  [Github](https://github.com/Tramac/Lightweight-Segmentation)   |
| Light_OpenPose    | yes | yes |  [Github](https://github.com/Daniil-Osokin/lightweight-human-pose-estimation.pytorch)   |


### Android：
* 由于手机性能、图像尺寸等因素导致FPS在不同手机上相差比较大。该项目主要测试NCNN框架的使用，具体模型的转换可以去NCNN官方查看转换教程。<br/>
* 由于opencv库太大只保留 arm64-v8a/armeabi-v7a 有需要其它版本的自己去官方下载。
* ncnn暂时使用vulkan版本，在加载前需要打开加速，本项目中没有打开。如果要用ncnn版本需要修改CMakeLists.txt配置。
* AS版本不一样可能编译会有各种问题，如果编译错误无法解决、建议使用AS4.0以上版本尝试一下。

该项目更多的是练习各种模型的使用与部署，在速度上没有过多处理。如果对速度有要求可以直接获取YUV等数据直接输入或使用texture与opengl等方式实现数据输入，减少中间的数据传输与转换。

懒人本地转换(不会上传模型): [xxxx -> ncnn](https://convertmodel.com/)

轻量级OpenCV:[opencv-mobile](https://github.com/nihui/opencv-mobile)

:art: 截图<br/>

| Android | iOS |
|:-----:|:-----:|
|<img width="324" height="145" src="./Screenshots/Android_CPU_or_GPU.jpg"/>| <img width="320" height="166" src="./Screenshots/iOS_CPU_or_GPU.jpg"/> |

> Android

| mbnv2-yolov3-nano | yolov4-tiny | yolov5s |
|-------------------|-------------|---------|
|<img width="270" height="500" src="./Screenshots/Android_Meizu16x_mobilenetv2_yolov3_nano.jpg"/>|<img width="270" height="500" src="./Screenshots/Android_Meizu16x_yolov4_tiny.jpg"/>|<img width="270" height="500" src="./Screenshots/Android_Meizu16x_yolov5s.jpg"/>|

| simple_pose | yolact | chineseocr_lite_01 |
|-------------------|-------------|---------|
|<img width="270" height="500" src="./Screenshots/Android_Meizu16x_simple_pose.jpg"/>|<img width="270" height="500" src="./Screenshots/Android_Meizu16x_yolact.jpg"/>|<img width="270" height="500" src="./Screenshots/Android_meizu16x_chineseocr_lite_01.jpg"/>|

| chineseocr_lite_02 | ENet | yoloface500k-landmark106 |
|-------------------|-------------|---------|
|<img width="270" height="500" src="./Screenshots/Android_meizu16x_chineseocr_lite_02.jpg"/>|<img width="270" height="500" src="./Screenshots/Android_Meizu16x_ENet.jpg"/>|<img width="270" height="500" src="./Screenshots/Android_Meizu16x_yoloface500k-landmark106.jpg"/>|

|  dbface | mbnv2_fcn | mbnv3_seg_small |
|-------------------|-------------|---------|
| <img width="270" height="500" src="./Screenshots/Android_Meizu16x_dbface.jpg"/>|<img width="270" height="500" src="./Screenshots/Android_Meizu16x_MBNFCN.jpg"/>|<img width="270" height="500" src="./Screenshots/Android_Meizu16x_MBNV3_Seg_small.jpg"/>|

|  yolov5s_custom_op | nanodet | yolo-fastest-xl |
|-------------------|-------------|---------|
| <img width="270" height="500" src="./Screenshots/Android_meizu16x_yolov5s_custom_layer.jpg"/>|<img width="270" height="500" src="./Screenshots/Android_meizu16x_nanodet.jpg"/>|<img width="270" height="500" src="./Screenshots/Android_meizu16x_yolo_fastest_xl.jpg"/>|

|  light_openpose  |
|-------------------|
| <img width="270" height="500" src="./Screenshots/Android_Meizu16x_lightopenpose.jpg"/>|



感谢:<br/>
- sunnyden, dog-qiuqiu, ..., nihui
- https://github.com/Tencent/ncnn

