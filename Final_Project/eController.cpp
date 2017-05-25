#include "eController.h"
#include <iostream>


Controller::Controller(Window* window){	
	// Create a cube
	//faces.push_back(new Face(gVector(-1, 1, -1), gVector(-1, -1, -1), gVector(1, -1, -1), gVector(1, 1, -1))); // order is important
	//faces.push_back(new Face(gVector(-1, 1, 1), gVector(-1, 1, -1), gVector(1, 1, -1), gVector(1, 1, 1)));
	//faces.push_back(new Face(gVector(1, 1, 1), gVector(1, 1, -1), gVector(1, -1, -1), gVector(1, -1, 1)));
	//faces.push_back(new Face(gVector(-1, -1, 1), gVector(-1, 1, 1), gVector(1, 1, 1), gVector(1, -1, 1)));
	//faces.push_back(new Face(gVector(-1, -1, -1), gVector(-1, -1, 1), gVector(1, -1, 1), gVector(1, -1, -1)));
	//faces.push_back(new Face(gVector(-1, 1, -1), gVector(-1, 1, 1), gVector(-1, -1, 1), gVector(-1, -1, -1)));
	//parser("sampleInput.txt", &faces);		// Will load a model from a file

	createPlane(5, 5, 5, 5);

	selected = 0;								// Start with the zero-ith face selected
	win = window; 

	win->setController(this);  // Now the window class has access to the controller and vice versa 
	
	win->updateBrowser();
	win->updateDrawing();
}

Controller::~Controller(){};

void Controller::createPlane(float row, float col, float depth, float width)
{
	faces.clear();

	for (int m = 0; m < row; m++)
	{
		for (int n = 0; n < col; n++)
		{
			faces.push_back(new Face(gVector(width*(float)(m/ row) - (width/2.0),0 , depth*(float)((n + 1) / col) - (depth / 2.0)),
				gVector(width*(float)(m/ row) - (width / 2.0), 0, depth*(float)(n / col) - (depth / 2.0)),
				gVector(width*(float)((m+1)/ row) - (width / 2.0), 0, depth*(float)(n / col) - (depth / 2.0)),
				gVector(width*(float)((m + 1) / row) - (width / 2.0), 0, depth*(float)((n + 1) / col) - (depth / 2.0))));
		}

	}
}
void Controller::resizePlane(float row, float col, float depth, float width)
{
	temp = faces;


	faces.clear();

	for (int m = 0; m < row; m++)
	{
		for (int n = 0; n < col; n++)
		{
			faces.push_back(new Face(gVector(width*(float)(m / row) - (width / 2.0), 0, depth*(float)((n + 1) / col) - (depth / 2.0)),
				gVector(width*(float)(m / row) - (width / 2.0), 0, depth*(float)(n / col) - (depth / 2.0)),
				gVector(width*(float)((m + 1) / row) - (width / 2.0), 0, depth*(float)(n / col) - (depth / 2.0)),
				gVector(width*(float)((m + 1) / row) - (width / 2.0), 0, depth*(float)((n + 1) / col) - (depth / 2.0))));
		}

	}
	int counter = 0;
	int counter2 = 0;

	for (int m = 0; m < row/2; m++)
	{
		for (int n = 0; n < col/2; n++)
		{
			faces[counter]->points[1][0] = temp[counter2]->points[1][0];
			faces[counter]->points[1][1] = temp[counter2]->points[1][1];
			faces[counter]->points[1][2] = temp[counter2]->points[1][2];
			faces[counter]->points[1][3] = temp[counter2]->points[1][3];
			counter2 += 1;
			counter += 1;

		}
		counter += col / 2;
	}

}

const int Controller::numPolys(){							// Get the number of faces
	return faces.size();
}
const gMatrix Controller::getPoly(int i){					// Get a certain face
	return faces[i]->getPoints();
}
const int Controller::getSelected(){						// Get which face has been selected
	return selected;
}
void Controller::select(int i){								// Set the selected face
	selected = i; 
	win->updateDrawing();
}

void Controller::extrudeSelected(float depth){				// Do an extrusion
	int sel = getSelected();
	gMatrix points = faces[sel]->getPoints();
	Face *f = faces[sel];
	faces.erase(faces.begin() + sel);
	gVector v1New = depth * f->getNormal() + points.getCol(0);
	gVector v2New = depth * f->getNormal() + points.getCol(1);
	gVector v3New = depth * f->getNormal() + points.getCol(2);
	gVector v4New = depth * f->getNormal() + points.getCol(3);
	faces.push_back(new Face(points.getCol(0), points.getCol(1), v2New, v1New));
	faces.push_back(new Face(points.getCol(1), points.getCol(2), v3New, v2New ));
	faces.push_back(new Face(points.getCol(2), points.getCol(3), v4New, v3New ));
	faces.push_back(new Face(points.getCol(3), points.getCol(0), v1New, v4New));
	faces.push_back(new Face(v1New, v2New, v3New, v4New));
	win->updateBrowser();
	win->updateDrawing();
	delete f;
}