#pragma once
#include "ofMain.h"

enum particleMode{
	PARTICLE_MODE_ATTRACT = 0,
	PARTICLE_MODE_REPEL,
	PARTICLE_MODE_NEAREST_POINTS,
	PARTICLE_MODE_NOISE,
	PARTICLE_MODE_DANCE
};

class Particle{
	private:
	double velocity;
	double previous;

	public:
	
		Particle();
		void BaseSpeed(){ velocity=1; }
		double getVel(){ return velocity; }
		void setVel(double v){ velocity=v; }
		void setPrevious(double r) { previous=r; }
		double getPrevious(){ return previous; }
		void setMode(particleMode newMode);	
		void setAttractPoints( vector <glm::vec3> * attract );
		void attractToPoint(int, int);
		void repelFromPoint(int, int);
		void pauseP(); //añadido
		void quadE(); //añadido
		void quartE(); //añadido
		void IncSizeE(); //añadido
		void DecSizeE(); //añadido
		void reset();
		void update();
		void draw();	
	
		glm::vec3 pos;
		glm::vec3 vel;
		glm::vec3 frc;
		
		float drag; 
		float uniqueVal;
		float scale;
		
		particleMode mode;
		
		vector <glm::vec3> * attractPoints; 
};
