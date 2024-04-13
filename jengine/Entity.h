#pragma once
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <vector>

#include "Vector2.h"
#include "Utility.h"


class VAO {
public:
	float quadVao[8] = {	
							Utility::coord(10), Utility::coord(10, false), // top-left corner
							Utility::coord(10), Utility::coord(70, false), // bottom-left corner
							Utility::coord(70), Utility::coord(70, false), // bottom-right corner
							Utility::coord(70), Utility::coord(10, false)	 // top-right corner
						}; 

	float triangleVao[6] = {
		-.5f, -.5f,
		.0f, .5f,
		.5f, -.5f
	};

	bool useQuadVao = true;

	float* getVao();
};

class Entity {
public:
	unsigned int _vbo; // buffer
	VAO _vao; // vertices

	Vector2 position;
	float rotation; // 2 dimensional shapes can only rotate on one axis, we'll represent that axis by a single float
	Vector2 scale;

	void initialize(VAO vao);
	void render();
};