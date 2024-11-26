#include "ofMain.h"
#include "dichoAtomique.h"
#include "ofApp.h"

shared_ptr<ofAppBaseWindow> mainWindow, secondWindow;


int main() {
	bool singleMonitor = true;
	bool fullScreen = false;
	ofGLFWWindowSettings mainSettings, secondSettings;

	// Configure settings for the main window
	mainSettings.setSize(1280, 720);
	//mainSettings.setSize(1920, 1200);

	if (singleMonitor) {
		mainSettings.monitor = 0;
		mainSettings.windowMode = fullScreen ? OF_FULLSCREEN : OF_WINDOW;
	}
	else {
		mainSettings.setPosition(ofVec2f(1920, 0));
		mainSettings.decorated = false;
		mainSettings.windowMode = OF_WINDOW;
	}


	//.. settings for the second window
	secondSettings.setSize(1280, 720);
	secondSettings.monitor = singleMonitor ? 0 : 1;


	//create the windows
	mainWindow = ofCreateWindow(mainSettings);
	secondWindow = ofCreateWindow(secondSettings);
	secondWindow->setWindowTitle("second Window");

	//instances of your app classes
	shared_ptr<ofApp> mainApp(new ofApp);
	shared_ptr<dichoAtomique> secondApp(new dichoAtomique);

	//link the second window
	secondApp->setWindows(secondWindow, mainWindow);

	ofRunApp(mainWindow, mainApp);
	ofRunApp(secondWindow, secondApp);
	ofRunMainLoop();

}
