#include "Entity.h"

float* VAO::getVao()
{
	if (useQuadVao)
		return quadVao;

	return triangleVao;
}

void Entity::initialize(VAO vao)
{
	this->_vao = vao;

	glGenBuffers(1, &_vbo);
	glBindBuffer(GL_ARRAY_BUFFER, _vbo);
	glBufferData(GL_ARRAY_BUFFER, 8 * sizeof(float), _vao.getVao(), GL_STATIC_DRAW);
}

void Entity::render()
{
	glBindBuffer(GL_ARRAY_BUFFER, _vbo);
	glEnableVertexAttribArray(0);
	glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, 2 * sizeof(float), 0);

	if (_vao.useQuadVao)
		glDrawArrays(GL_QUADS, 0, 4);
	else
		glDrawArrays(GL_TRIANGLES, 0, 3);
}