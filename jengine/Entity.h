#pragma once
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <vector>

#include "Vector2.h"
#include "Utility.h"


class VAO {
public:
	// vertices for VAO instance is set in the Entity class
	float quadVao[8] = {
							0.f, 0.f,
							0.f, 0.f,
							0.f, 0.f,
							0.f, 0.f
						}; 

	float triangleVao[6] = {
		-.5f, -.5f,
		.0f, .5f,
		.5f, -.5f
	};

	bool useQuadVao = true;

	float* getVao();

	void updateVertices(Vector2 topLeft,	 Vector2 bottomLeft,
						Vector2 bottomRight, Vector2 topRight,
						bool convertVectorsToScreenSpaceCoordinates);
};

class Entity {
public:
	unsigned int _vbo; // buffer
	VAO _vao; // vertices

	Vector2 position;

	void initialize(VAO vao);
	void render();
};