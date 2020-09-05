#include <iostream>
#include "opencv2/viz.hpp"
#include "opencv2/opencv.hpp"

using namespace std;
using namespace cv;

int main(int argc, char **argv) {
	viz::Viz3d myWindow("Viz Demo");
	myWindow.showWidget("World_Coordinate",viz::WCoordinateSystem());
    /// Start event loop
    Mat cameraMatrix = (Mat_<double>(3,3)<<3.3512766975396431e+02, 0., 1.7470916794631543e+02, 0.,
            3.3545176025968442e+02, 1.2638178637159211e+02, 0., 0., 1.);
    Mat src = imread("./left1.png",1);
    if(src.empty()){
        cout<<"Could not load Image"<<endl;
    }
    viz::WCameraPosition cam1((Matx33d)cameraMatrix,src,1.0,viz::Color::blue());
    Vec3d R(0,1,0),T(1,1,1);
    Affine3d Cam1_pose(R,T);
    myWindow.showWidget("Cam1_Coordinate",viz::WCoordinateSystem(),Cam1_pose);
    myWindow.showWidget("Cam1",cam1,Cam1_pose);

    myWindow.spin();
    cout << "Hello VIZ" << endl;
    return 0;
}
