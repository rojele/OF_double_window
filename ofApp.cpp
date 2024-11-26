#include "ofApp.h"


void ofApp::setWindow(shared_ptr<ofAppBaseWindow> _mainWindow)
{
	// The GUI window, used for testing.
	mainWindow = _mainWindow;
	mainWindow->setWindowTitle("main Window");

}
//--------------------------------------------------------------
void ofApp::setup() {
	main_window_fbo.allocate(ofGetWidth(), ofGetHeight());
	font.load("fonts/futura/Futura_Bold_font.ttf", 60);
}

//--------------------------------------------------------------
void ofApp::update() {

}

//--------------------------------------------------------------
void ofApp::draw() {
	cout << "ofApp.draw" << endl;
	int x = ofGetWidth() / 2;
	int y = ofGetHeight() / 2;

	ofPushMatrix();
	ofTranslate(x, y);
	main_window_fbo.begin();
	ofClear(0);
	ofNoFill();
	ofDrawCircle(0, 0, 100, 100);
	string _s = to_string(ofGetSystemTimeMillis());
	font.drawString(_s, 0, 0);
	main_window_fbo.end();
	ofPopMatrix();

	main_window_fbo.draw(0, 0, ofGetWidth(), ofGetHeight());
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key) {

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key) {

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y) {

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button) {

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button) {

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button) {

}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y) {

}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y) {

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h) {

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg) {

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo) {

}
