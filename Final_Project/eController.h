#pragma once

#include <vector>
#include <iostream>
#include "face.h"
#include "myglwidget.h"
#include "gMatrix.h"
#include "window.h"

void parser(const char* file, std::vector<Face*> *faces); // A function for loading faces from a file

class Controller{
	private:
		int selected;				// Which face is currently selected
	public:
		std::vector<Face*> faces;	// Store all of the faces/polygons in the scene
		std::vector<Face*> temp;
		Controller(Window* win); 
		~Controller();
		Window* win;					// A pointer to the display mechanisms

		const int numPolys();				// Get the number of faces
		const gMatrix getPoly(int i);		// Get a certain face
		const int getSelected();			// Get which face has been selected
		void select(int i);					// Set the selected face
		void createPlane(float row, float col, float depth, float width);
		void resizePlane(float row, float col, float depth, float width);

		void extrudeSelected(float depth);	// Perform an extrusion
};