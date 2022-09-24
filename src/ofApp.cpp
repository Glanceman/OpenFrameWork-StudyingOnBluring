#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
	img1.loadImage("lena.jpg");
	//img1.loadImage("circuit.tif");

	imgMat1=toCv(img1);
	cout << imgMat1.type() << endl;
}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){
	drawMat(imgMat1, 0, 0);
	//box filter
	//for (int i = 0; i < 3; i++) {
	//	Mat blurMat = boxFilter(imgMat1, i * 2 + 3);
	//	drawMat(blurMat, imgMat1.cols * (i + 1),0);
	//}
	
	//gaussian filter
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 2; j++) {
			Mat blurMat = gaussianFilter(imgMat1, i * 2 + 3, j+1+2);
			drawMat(blurMat, imgMat1.cols * (i+1), imgMat1.rows*j);
		}
	}
	
	//median filter
	//for (int i = 0; i < 3; i++) {
	//	Mat blurMat = medianFilter(imgMat1, i * 2 + 3);
	//	drawMat(blurMat, imgMat1.cols * (i + 1), 0);
	//}

}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y){

}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y){

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}

Mat ofApp::gaussianFilter(Mat img, int size, double sigma) {
	Mat temp;
	GaussianBlur(img, temp, cv::Size(size, size), sigma);
	return temp;
}

Mat ofApp::boxFilter(Mat img, int size) {
	Mat temp;
	cv::boxFilter(img, temp, -1, cv::Size(size, size));
	return temp;
}

Mat ofApp::medianFilter(Mat img, int size) {
	Mat temp;
	cv::medianBlur(img, temp, size);
	return temp;
}
