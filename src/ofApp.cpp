#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
	ofSetVerticalSync(true);
	
	int num = 1500;
	p.assign(num, Particle());
	currentMode = PARTICLE_MODE_ATTRACT;

	currentModeStr = "1 - PARTICLE_MODE_ATTRACT: attracts to mouse"; 

	resetParticles();
}

//--------------------------------------------------------------
void ofApp::resetParticles(){

	//these are the attraction points used in the fourth demo 
	attractPoints.clear();
	for(int i = 0; i < 4; i++){
		attractPoints.push_back( glm::vec3( ofMap(i, 0, 4, 100, ofGetWidth()-100) , ofRandom(100, ofGetHeight()-100) , 0) );
	}
	
	attractPointsWithMovement = attractPoints;
	
	for(unsigned int i = 0; i < p.size(); i++){
		p[i].setMode(currentMode);		
		p[i].setAttractPoints(&attractPointsWithMovement);;
		p[i].reset();
	}	
}

//--------------------------------------------------------------
void ofApp::update(){
	for(unsigned int i = 0; i < p.size(); i++){
		p[i].setMode(currentMode);
		p[i].update();
	}
	
	//lets add a bit of movement to the attract points
	for(unsigned int i = 0; i < attractPointsWithMovement.size(); i++){
		attractPointsWithMovement[i].x = attractPoints[i].x + ofSignedNoise(i * 10, ofGetElapsedTimef() * 0.7) * 12.0;
		attractPointsWithMovement[i].y = attractPoints[i].y + ofSignedNoise(i * -10, ofGetElapsedTimef() * 0.7) * 12.0;
	}	
	if(replay==true){
		if(contador==0){
			reverse(keyPress.begin(),keyPress.end());
			iter=keyPress.end();
			keyPressed(*iter);
			keyPress.pop_back();
			contador=75;
			reverse(keyPress.begin(),keyPress.end());
		}
		else{
			contador--;
		}
	}
}

//--------------------------------------------------------------
void ofApp::draw(){
    ofBackgroundGradient(ofColor(0,100,100), ofColor(0,0,100));

	for(unsigned int i = 0; i < p.size(); i++){
		p[i].draw();
	}
	
	ofSetColor(190);
	if( currentMode == PARTICLE_MODE_NEAREST_POINTS ){
		for(unsigned int i = 0; i < attractPoints.size(); i++){
			ofNoFill();
			ofDrawCircle(attractPointsWithMovement[i], 10);
			ofFill();
			ofDrawCircle(attractPointsWithMovement[i], 4);
		}
	}

	ofSetColor(230);	
	ofDrawBitmapString(currentModeStr + "\n\nPress 'i' to increase particle size.\nPress 'd' to decrease particle size. \nPress 'f' to quadruple particle velocity.\nPress 's' to quart particle velocity. \nPress 'a' to pause.\nPress 'r' to record.\nPress 'p' to replay.\nSpacebar to reset. \nKeys 1-5 to change mode.", 10, 20);
}
void ofApp::pause(){  //añadido
	for (unsigned int i = 0; i < p.size(); i++){
		p[i].setMode(currentMode);
		p[i].pauseP();
	}
}
//añadido
void ofApp::quad(){
	for(unsigned int i=0; i<p.size(); i++){
		p[i].setMode(currentMode);
		p[i].quadE();
	}
}
//añadido
void ofApp::quart(){
	for(unsigned int i=0; i<p.size(); i++){
		p[i].setMode(currentMode);
		p[i].quartE();
	}
}
//añadido
void ofApp::IncreaseSize(){
	for(unsigned int i=0; i<p.size(); i++){
		p[i].setMode(currentMode);
		p[i].IncSizeE();
	}
}
//añadido
void ofApp::DecreaseSize(){
	for(unsigned int i=0; i<p.size(); i++){
		p[i].setMode(currentMode);
		p[i].DecSizeE();
	}
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
	if(replay==true){
		if(keyPress.size()==0 || key=='c' || key=='C'){
			resetParticles();
			replay=false;
		}
		else if(key !=* iter){
		return;
		}
		key =* iter;
	}
	if( key == '1'){
		currentMode = PARTICLE_MODE_ATTRACT;
		currentModeStr = "1 - Particle Mode: Particles attract to mouse."; 		
	}
	if( key == '2'){
		currentMode = PARTICLE_MODE_REPEL;
		currentModeStr = "2 - Particle Mode: Particles repel from mouse."; 				
	}
	if( key == '3'){
		currentMode = PARTICLE_MODE_NEAREST_POINTS;
		currentModeStr = "3 - Particle Mode: Particles attract to nearest point."; 						
	}
	if( key == '4'){
		currentMode = PARTICLE_MODE_NOISE;
		currentModeStr = "4 - Particle Mode: Particles make a snow simulation."; 						
		resetParticles();
	}
	if( key == ' ' ){
		resetParticles();
	}	
	//añadido
		if( key == '5'){
		currentMode = PARTICLE_MODE_DANCE;
		currentModeStr = "5 - Particle Mode: Particles move randomly."; 						
	}
	if (key == 'a' || key=='A'){  //añadido
		pause();
	}	
	if(key=='f' || key=='F'){
		quad();
	}
	if(key=='S' || key=='s'){
		quart();
	}
	if(key=='i' || key=='I'){
		IncreaseSize();
	}
	if(key=='d' || key=='D'){
		DecreaseSize();
	}
	if(key=='r' || key=='R'){
		currentModeStr = "R - RECORD: Currently Recording";
		record=!record;
	}
	if(record==true){
		keyPress.push_back(key);
	}
	if(key=='p' || key=='P'){
		replay=true;
		currentModeStr="P- REPLAY: Playing Recording";
	}
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
