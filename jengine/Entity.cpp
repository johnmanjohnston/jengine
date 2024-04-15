#include "Entity.h"

float* VAO::getVao()
{
	if (useQuadVao)
		return quadVao;

	return triangleVao;
}

void VAO::updateVertices(Vector2 topLeft,	  Vector2 bottomLeft, 
						 Vector2 bottomRight, Vector2 topRight,
						 bool convertVectorsToScreenSpaceCoordinates = true)
{
	if (convertVectorsToScreenSpaceCoordinates) 
	{
		topLeft.x = Utility::coord(topLeft.x);
		topLeft.y = Utility::coord(topLeft.y, true);

		bottomLeft.x = Utility::coord(bottomLeft.x);
		bottomLeft.y = Utility::coord(bottomLeft.y, true);

		bottomRight.x = Utility::coord(bottomRight.x);
		bottomRight.y = Utility::coord(bottomRight.y, true);

		topRight.x = Utility::coord(topRight.x);
		topRight.y = Utility::coord(topRight.y, true);
	}

	quadVao[0] = topLeft.x;
	quadVao[1] = topLeft.y;
	quadVao[2] = bottomLeft.x;
	quadVao[3] = bottomLeft.y;
	quadVao[4] = bottomRight.x;
	quadVao[5] = bottomRight.y;
	quadVao[6] = topRight.x;
	quadVao[7] = topRight.y;
}

void Entity::initialize(VAO vao)
{
	vao.updateVertices(
		Vector2(10 + position.x, 0 + position.y),
		Vector2(10 + position.x, 20 + position.y),
		Vector2(20 + position.x, 20 + position.y),
		Vector2(20 + position.x, 0 + position.y)
	);

	this->_vao = vao;

	glGenBuffers(1, &_vbo);
	glBindBuffer(GL_ARRAY_BUFFER, _vbo);
	glBufferData(GL_ARRAY_BUFFER, 8 * sizeof(float), _vao.getVao(), GL_STATIC_DRAW);
}

void Entity::render()
{
	// redraw
		_vao.updateVertices(
			Vector2(10 + position.x, 0 + position.y),
			Vector2(10 + position.x, 20 + position.y),
			Vector2(20 + position.x, 20 + position.y),
			Vector2(20 + position.x, 0 + position.y)
		);

		glGenBuffers(1, &_vbo);
		glBindBuffer(GL_ARRAY_BUFFER, _vbo);
		glBufferData(GL_ARRAY_BUFFER, 8 * sizeof(float), _vao.getVao(), GL_STATIC_DRAW);

	glBindBuffer(GL_ARRAY_BUFFER, _vbo);
	glEnableVertexAttribArray(0);
	glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, 2 * sizeof(float), 0);


	if (_vao.useQuadVao)
		glDrawArrays(GL_QUADS, 0, 4);
	else
		glDrawArrays(GL_TRIANGLES, 0, 3);
}