#pragma once

#include "ofMain.h"

class dichoAtomique : public ofBaseApp {

public:
	void setup();
	void update();
	void draw();

	void keyPressed(int key);
	void keyReleased(int key);
	void mouseMoved(int x, int y);
	void mouseDragged(int x, int y, int button);
	void mousePressed(int x, int y, int button);
	void mouseReleased(int x, int y, int button);
	void mouseEntered(int x, int y);
	void mouseExited(int x, int y);
	void windowResized(int w, int h);
	void dragEvent(ofDragInfo dragInfo);
	void gotMessage(ofMessage msg);


	void setWindows(shared_ptr<ofAppBaseWindow> _secondWindow,
		shared_ptr<ofAppBaseWindow> _mainWindow);

	// A handle to each window.
	shared_ptr<ofAppBaseWindow> mainWindow;
	shared_ptr<ofAppBaseWindow> secondWindow;
	void drawSecondWindow(ofEventArgs& args);
	ofFbo first_window_fbo, second_window_fbo;
	ofTrueTypeFont font;
};
