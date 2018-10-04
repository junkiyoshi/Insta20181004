#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup() {

	ofSetFrameRate(60);
	ofSetWindowTitle("openframeworks");

	ofEnableDepthTest();
	ofBackground(239);
}

//--------------------------------------------------------------
void ofApp::update() {

	ofSeedRandom(39);
}

//--------------------------------------------------------------
void ofApp::draw() {

	int radius = 300;
	int deg_start = 0;
	int deg_span = 10;

	this->cam.begin();

	for (int z = -300; z <= 300; z += 30) {

		deg_start = ofGetFrameNum() + z;

		for (int deg = deg_start; deg <= deg_start + 180; deg += deg_span) {

			ofColor color;
			color.setHsb(ofRandom(255), 200, 255);
			ofSetColor(color);

			ofBeginShape();
			ofVertex(radius * cos(deg * DEG_TO_RAD), radius * sin(deg * DEG_TO_RAD), z);
			ofVertex(radius * cos(deg * DEG_TO_RAD), radius * sin(deg * DEG_TO_RAD), z + 30);
			ofVertex(radius * cos((deg + deg_span) * DEG_TO_RAD), radius * sin((deg + deg_span) * DEG_TO_RAD), z + 30);
			ofVertex(radius * cos((deg + deg_span) * DEG_TO_RAD), radius * sin((deg + deg_span) * DEG_TO_RAD), z);
			ofEndShape(true);
		}
	}

	this->cam.end();	
}

//--------------------------------------------------------------
int main() {

	ofSetupOpenGL(720, 720, OF_WINDOW);
	ofRunApp(new ofApp());
}