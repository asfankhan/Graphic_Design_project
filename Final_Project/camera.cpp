#include "camera.h"

Camera::Camera(float r, float phi, float theta){
			rot = gMatrix::identityMatrix(4);
			up = gVector(0, 1, 0, 0);
			eye = gVector(0, 0, r, 1);
}

void Camera::increasePhi(float inc){
	rot = rotateObjY(rot, inc);

}

void Camera::increaseTheta(float inc){
	rot = rotateObjX(rot, inc);

}

void Camera::increaseRad(float inc){

	eye[2] += inc;
}

const gVector Camera::getEye(){
	return rot*eye;
}

const gVector Camera::getUp(){
	return rot*up;
}

gMatrix Camera::rotateObjX(gMatrix curr, float degree)
{
	float radians = (3.14 * degree) / 180;

	gMatrix m =  gMatrix(4,4);
	m[0] = gVector(cos(radians), 0, sin(radians), 0);
	m[1] = gVector(0, 1, 0, 0);
	m[2] = gVector(-sin(radians), 0, cos(radians), 0);
	m[3] = gVector(0, 0, 0, 1);;

	return (curr * m);
}
gMatrix Camera::rotateObjY(gMatrix curr, float degree)
{
	float radians = (3.14 * degree) / 180;
	gMatrix m = gMatrix(4, 4);

	m[0] = gVector(1, 0, 0, 0);
	m[1] = gVector(0, cos(radians), -sin(radians), 0);
	m[2] = gVector(0, sin(radians), cos(radians), 0);
	m[3] = gVector(0, 0, 0, 1);

	return (curr * m);
}
