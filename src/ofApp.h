#pragma once

#include "ofMain.h"
#include "ofMain.h"
#include "ofxCv.h"
#include "ofxOpenCv.h"
#include "ofxGui.h"
#include <vector>

using namespace ofxCv;
using namespace cv;


class ofApp : public ofBaseApp{

	public:
		void setup();
		void update();
		void draw();

		void keyPressed(int key);
		void keyReleased(int key);
		void mouseMoved(int x, int y );
		void mouseDragged(int x, int y, int button);
		void mousePressed(int x, int y, int button);
		void mouseReleased(int x, int y, int button);
		void mouseEntered(int x, int y);
		void mouseExited(int x, int y);
		void windowResized(int w, int h);
		void dragEvent(ofDragInfo dragInfo);
		Mat gaussianFilter(Mat img, int size, double sigma);

		Mat boxFilter(Mat img, int size);

		Mat medianFilter(Mat img, int size);

		void gotMessage(ofMessage msg);

		ofImage img1;
		ofImage img2;

		Mat imgMat1;
		Mat imgMat2;
		
};
