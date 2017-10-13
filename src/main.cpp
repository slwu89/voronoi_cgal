#include "ofMain.h"
#include "ofApp.h"

/*
 * steps:
 * 1. https://jnphgs.blogspot.com/2016/06/install-cgal-and-use-it-on-xcode-project.html
 * 2. https://jnphgs.blogspot.com/2016/06/drawing-voroni-diagram-with-cgal-on.html
 * other help:
 * - https://forum.openframeworks.cc/t/compiling-with-cgal-and-boost-xcode-6-4-osx-10-10/22640
 *
 *
 */

//========================================================================
int main( ){
	ofSetupOpenGL(1024,768,OF_WINDOW);			// <-------- setup the GL context

	// this kicks off the running of my app
	// can be OF_WINDOW or OF_FULLSCREEN
	// pass in width and height too:
	ofRunApp(new ofApp());

}
