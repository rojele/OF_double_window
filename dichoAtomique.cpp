#include "dichoAtomique.h"

void dichoAtomique::setWindows(shared_ptr<ofAppBaseWindow> _secondWindow,
	shared_ptr<ofAppBaseWindow> _mainWindow)
{
	// The GUI window, used for testing.
	mainWindow = _mainWindow;
	secondWindow = _secondWindow;
	mainWindow->setWindowTitle("mainWindow");
	secondWindow->setWindowTitle("seconWindow");
}

//--------------------------------------------------------------
void dichoAtomique::setup() {
	font.load("fonts/futura/Futura_Bold_font.ttf", 60);
	first_window_fbo.allocate(ofGetWidth(), ofGetHeight());
	second_window_fbo.allocate(ofGetWidth(), ofGetHeight());
}

//--------------------------------------------------------------
void dichoAtomique::update() {

}

//--------------------------------------------------------------
void dichoAtomique::draw() {
	int x = ofGetWidth() / 2;
	int y = ofGetHeight() / 2;
	string _s = to_string(ofGetSystemTimeMillis());

	ofPushMatrix();
	ofPushStyle();

	first_window_fbo.begin();
	ofClear(0);
	ofNoFill();
	ofTranslate(x, y);
	font.drawString(_s, 0, 0);
	first_window_fbo.end();
	ofPopStyle();
	ofPopMatrix();

	first_window_fbo.draw(0, 0, ofGetWidth(), ofGetHeight());
}

//--------------------------------------------------------------
void dichoAtomique::keyPressed(int key) {

}

//--------------------------------------------------------------
void dichoAtomique::keyReleased(int key) {

}

//--------------------------------------------------------------
void dichoAtomique::mouseMoved(int x, int y) {

}

//--------------------------------------------------------------
void dichoAtomique::mouseDragged(int x, int y, int button) {

}

//--------------------------------------------------------------
void dichoAtomique::mousePressed(int x, int y, int button) {

}

//--------------------------------------------------------------
void dichoAtomique::mouseReleased(int x, int y, int button) {

}

//--------------------------------------------------------------
void dichoAtomique::mouseEntered(int x, int y) {

}

//--------------------------------------------------------------
void dichoAtomique::mouseExited(int x, int y) {

}

//--------------------------------------------------------------
void dichoAtomique::windowResized(int w, int h) {

}

//--------------------------------------------------------------
void dichoAtomique::gotMessage(ofMessage msg) {

}

//--------------------------------------------------------------
void dichoAtomique::dragEvent(ofDragInfo dragInfo) {

}

void dichoAtomique::drawSecondWindow(ofEventArgs &args) {
	int x = secondWindow->getWidth() / 2;
	int y = secondWindow->getHeight() / 2;
	string _s = to_string(ofGetSystemTimeMillis());

	ofFboSettings s;
	s.width = ofGetWidth();
	s.height = ofGetHeight();
	s.internalformat = GL_RGBA;
	s.numSamples = 4;

	ofFbo second_window_fbo;
	second_window_fbo.allocate(s);

	second_window_fbo.begin();
	ofClear(0, 0);
	second_window_fbo.end();

	ofPushMatrix();
	ofPushStyle();
	second_window_fbo.begin();
	ofClear(0);
	ofNoFill();
	ofTranslate(x, y);
	ofEnableAlphaBlending();
	font.drawString(_s, 0, 0);
	second_window_fbo.end();
	ofPopStyle();
	ofPopMatrix();

	second_window_fbo.draw(0, 0, secondWindow->getWidth(), secondWindow->getHeight());
}
