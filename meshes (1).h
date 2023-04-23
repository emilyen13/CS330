#pragma once

// general includes
#include <iostream>
#include <vector>
#include <cstdlib>

// glew includes
#include <GL/glew.h>
#include <GLFW/glfw3.h>

// GLM Math Header inclusions
#include <glm/glm.hpp>
#include <glm/gtx/transform.hpp>
#include <glm/gtc/type_ptr.hpp>

// camera
#include "camera.h"

struct GLMesh
{
	GLuint vao;					//vertex array
	GLuint vbo;					//vertex buffer
	GLuint vbos[2];				//vertex buffer
	GLuint nIndices;			//indices of the mesh
	GLuint nVertices;

	std::vector<float> v;		//indices to draw
	std::vector<float> p;		//translation properties of the shape

	//physical properties of the shape
	float height;
	float length;
	float radius;
	float number_of_sides;

	char shapeCase;

	// each shape gets a matrix object
	glm::mat4 scale;
	glm::mat4 xrotation;
	glm::mat4 yrotation;
	glm::mat4 zrotation;
	glm::mat4 rotation;
	glm::mat4 translation;
	glm::mat4 model;
	glm::vec2 gUVScale;

	// texture information
	const char* texFilename;
	GLuint textureId;

	//texture wrapping modes
	GLint gTextWrapMode = GL_REPEAT;
	
	class Mesh
	{
	};
};