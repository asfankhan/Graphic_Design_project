#include <math.h>
#include "gMatrix.h"
#include "gVector.h"
#include <iostream>

// A class for storing camera transforms
class Camera{
	private:
	public:
		gMatrix rot;			// Current rotation matrix 
		gVector up;				// Current up vector
		gVector eye;			// Current eye/camera position

		Camera(float r, float phi, float theta); 
		void increasePhi(float inc);		// increase the phi angle. Note a negative value will decrease it. 
		void increaseTheta(float inc);		// increase the theta angle
		void increaseRad(float inc);		// increase the radius
		const gVector getEye();		// get the current eye position
		const gVector getUp();		// get the current up vector
		gMatrix rotateObjY(gMatrix curr, float degree);
		gMatrix rotateObjX(gMatrix curr, float degree);

};