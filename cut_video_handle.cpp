#include <opencv2/opencv.hpp>
#include <fstream>
#include <stdio.h>
#include <termios.h>

#include <termio.h>
#include <stdio.h> 

using namespace std;
using namespace cv;

int scanKeyboard()
{
	int in;
	struct termios new_settings;
	struct termios stored_settings;
	tcgetattr(0,&stored_settings);
	new_settings = stored_settings;
	new_settings.c_lflag &= (~ICANON);
	new_settings.c_cc[VTIME] = 0;
	tcgetattr(0,&stored_settings);
	new_settings.c_cc[VMIN] = 1;
	tcsetattr(0,TCSANOW,&new_settings);
	 
	in = getchar();
	 
	tcsetattr(0,TCSANOW,&stored_settings);
	return in;
}

int main()
{

    int i = 1;
	VideoCapture capture(0);

	//设置相机的分辨率，无分辨率更改需求可注释掉这两行
	capture.set(CV_CAP_PROP_FRAME_WIDTH, 1920);//宽度
	capture.set(CV_CAP_PROP_FRAME_HEIGHT, 1080);//高度


	while(1)
	{
		Mat  frame;
		capture>>frame;
		imshow("fisheye",frame);

		stringstream sk;
		sk << scanKeyboard();
		string scanKeyboard = sk.str();

		if(scanKeyboard == "32"){
			stringstream ss;
			ss << i;
			string s1 = ss.str();
    		cv::imwrite("/home/llx/geekplus/cut_video_handle/cut_img_src/" + s1 + ".jpg", frame);
            ++i;
			cout<< "save img" << s1 <<endl;
             
		}
		waitKey(30);
    }
    return 0;
}

