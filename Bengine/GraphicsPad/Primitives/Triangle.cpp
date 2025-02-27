#include "Triangle.h"
#include <GLM\glm.hpp>
#include "Vertex3D.h"

#define NUM_ARRAY_ELEMENTS(a) sizeof(a) / sizeof (*a)


Triangle::Triangle(GLuint vertexID)
{
	vboID = vertexID;
	glGenBuffers(1, &vboID);

	ShapeData3D shapeData3d;
	Vertex3D triangle[3];

	triangle[0].position = glm::vec3(-1.0f, -0.0f, 0.0f);
	triangle[1].position = glm::vec3(-2.0f, -0.0f, 0.0f);
	triangle[2].position = glm::vec3(-1.0f, 1.0f, 0.0f);
	


	shapeData3d.numVertices = NUM_ARRAY_ELEMENTS(triangle);
	shapeData3d.vertices = new Vertex3D[shapeData3d.numVertices];
	memcpy(shapeData3d.vertices, triangle, sizeof(triangle));


	GLushort indices[] = { 0, 1, 2, 3 };
	shapeData3d.numIndices = NUM_ARRAY_ELEMENTS(indices);
	shapeData3d.indices = new GLushort[shapeData3d.numIndices];
	memcpy(shapeData3d.indices, indices, sizeof(indices));

	glBindBuffer(GL_ARRAY_BUFFER, vboID);
	glBufferData(GL_ARRAY_BUFFER, shapeData3d.vertexBufferSize() , shapeData3d.vertices, GL_STATIC_DRAW); //TODO: May need buffer sub data to allow dynamic draw

	glBindBuffer(GL_ARRAY_BUFFER, 0);

	shapeData3d.Cleanup();
}


Triangle::~Triangle()
{
	if (vboID != 0)
	{
		glDeleteBuffers(1, &vboID);
	}
}