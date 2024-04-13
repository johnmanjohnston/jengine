#pragma once
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <vector>

#include "Entity.h"

class VAO {
public:
	float quadVao[8] = { -0.9f, 0.9f,   // top-left corner
						-0.9f, 0.6f,   // bottom-left corner
						-0.6f, 0.6f,   // bottom-right corner
						-0.6f, 0.9f }; // top-right corner

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

	void initialize(VAO vao);
	void render();
};