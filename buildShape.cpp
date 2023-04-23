#include <cstdlib>
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <glm/glm.hpp>
#include <glm/gtx/transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include <vector>
#include <cmath>

#include "buildShape.h"

using namespace std;
namespace
{
	const double M_PI = 3.14159265358979323846f;
	const double M_PI_2 = 1.571428571428571;
}

void BuildShape::UBoxMesh(GLMesh& mesh)
{
	vector<float> c = { mesh.p[0], mesh.p[1], mesh.p[2], mesh.p[3] };

	mesh.v = {

		0.5f, 0.0f, 0.5f,		c[0],   c[1],   c[2],   c[3],		0.28f, 0.77f,	// front left, bottom right 
		-0.5f, 0.0f, 0.5f,		c[0],   c[1],   c[2],   c[3],		0.28f, 0.22f,	// front left, bottom left
		-0.5f, 1.0f, 0.5f,		c[0],   c[1],   c[2],   c[3],		0.1f,  0.22f,	// front left, top left
									    		   		  
		0.5f, 0.0f, 0.5f,		c[0],   c[1],   c[2],   c[3],		0.28f, 0.77f,	// front right, bottom right
		0.5f, 1.0f, 0.5f,		c[0],   c[1],   c[2],   c[3],		0.1f,  0.77f,	// front right, top right
		-0.5f, 1.0f, 0.5f,		c[0],   c[1],   c[2],   c[3],		0.1f,  0.22f,	// front right, top left
									    		   		  
									    		   		  
		0.5f, 0.0f, 0.5f,		c[0],   c[1],   c[2],   c[3],		0.49f, 0.8f,	// right right, bottom right
		0.5f, 1.0f, 0.5f,		c[0],   c[1],   c[2],   c[3],		0.49f, 0.99f,	// right right, top right
		0.5f, 1.0f, -0.5f,		c[0],   c[1],   c[2],   c[3],		0.3f,  0.99f,	// right right, top left
									    		   		  
		0.5f, 0.0f, 0.5f,		c[0],   c[1],   c[2],   c[3],		0.49f, 0.8f,	// right left, bottom right
		0.5f, 0.0f, -0.5f,		c[0],   c[1],   c[2],   c[3],		0.3f,  0.8f,	// right left, bottom left
		0.5f, 1.0f, -0.5f,		c[0],   c[1],   c[2],   c[3],		0.3f,  0.99f,	// right left, top left


		0.5f, 0.0f, -0.5f,		c[0],   c[1],   c[2],   c[3],		0.5f,  0.76f,	// back left, bottom right
		-0.5f, 0.0f, -0.5f,		c[0],   c[1],   c[2],   c[3],		0.5f,  0.22f,	// back left, bottom left
		-0.5f, 1.0f, -0.5f,		c[0],   c[1],   c[2],   c[3],		0.69f, 0.22f,	// back left, top left
									    	    	    
		0.5f, 0.0f, -0.5f,		c[0],   c[1],   c[2],   c[3],		0.5f,  0.76f,	// back right, bottom right
		0.5f, 1.0f, -0.5f,		c[0],   c[1],   c[2],   c[3],		0.69f, 0.76f,	// back right, top right
		-0.5f, 1.0f, -0.5f,		c[0],   c[1],   c[2],   c[3],		0.69f, 0.22f,	// back right, top left
		
		
		-0.5f, 0.0f, 0.5f,		c[0],   c[1],   c[2],   c[3],		0.48f, 0.02f,	// left left, bottom right
		-0.5f, 1.0f, 0.5f,		c[0],   c[1],   c[2],   c[3],		0.48f, 0.19f,	// left left, top right
		-0.5f, 1.0f, -0.5f,		c[0],   c[1],   c[2],   c[3],		0.3f,  0.19f,	// left left, top left
									    	    	    
		-0.5f, 0.0f, 0.5f,		c[0],   c[1],   c[2],   c[3],		0.48f, 0.02f,	// left left, bottom right
		-0.5f, 0.0f, -0.5f,		c[0],   c[1],   c[2],   c[3],		0.3f,  0.02f,	// left left, bottom left
		-0.5f, 1.0f, -0.5f,		c[0],   c[1],   c[2],   c[3],		0.3f,  0.19f,	// left left, top left
									    	    	    
									    	    	    
									    	    	    
									    	    	    
		-0.5f, 1.0f, 0.5f,		c[0],   c[1],   c[2],   c[3],		0.9f, 0.22f,	// top, front left
		-0.5f, 1.0f, -0.5f,		c[0],   c[1],   c[2],   c[3],		0.7f, 0.22f,	// top, back left
		0.5f, 1.0f, 0.5f,		c[0],   c[1],   c[2],   c[3],		0.9f, 0.77f,	// top, front right

		-0.5f, 1.0f, -0.5f,		c[0],   c[1],   c[2],   c[3],		0.7f, 0.22f,	// top, back left
		0.5f, 1.0f, 0.5f,		c[0],   c[1],   c[2],   c[3],		0.9f, 0.77f,	// top, front right
		0.5f, 1.0f, -0.5f,		c[0],   c[1],   c[2],   c[3],		0.7f, 0.77f,	// top, back right
									    	    	    
		-0.5f, 0.0f, 0.5f,		c[0],   c[1],   c[2],   c[3],		0.29f, 0.22f,	// bottom, front left
		-0.5f, 0.0f, -0.5f,		c[0],   c[1],   c[2],   c[3],		0.49f, 0.22f,	// bottom, back left
		0.5f, 0.0f, 0.5f,		c[0],   c[1],   c[2],   c[3],		0.29f, 0.77f,	// bottom, front right
									    	    	    
		-0.5f, 0.0f, -0.5f,		c[0],   c[1],   c[2],   c[3],		0.49f, 0.22f,	// bottom, back left
		0.5f, 0.0f, 0.5f,		c[0],   c[1],   c[2],   c[3],		0.29f, 0.77f,	// bottom, front right
		0.5f, 0.0f, -0.5f,		c[0],   c[1],   c[2],   c[3],		0.49f, 0.77f,	// bottom, back right

	};

	UTranslator(mesh);
}

void BuildShape::UBottleMesh(GLMesh& mesh) {
	vector<float> c = { mesh.p[0], mesh.p[1], mesh.p[2], mesh.p[3] };

	mesh.v = {
		0.5f,	0.0f,	0.5f,	c[0],	c[1],	c[2],	c[3],	0.8f,	0.0f,	// front left, bottom right 
		-0.5f,	0.0f,	0.5f,	c[0],	c[1],	c[2],	c[3],	0.15f,	0.0f,	// front left, bottom left
		-0.5f,	1.0f,	0.5f,	c[0],	c[1],	c[2],	c[3],	0.15f,	1.0f,	// front left, top left

		0.5f,	0.0f,	0.5f,	c[0],	c[1],	c[2],	c[3],	0.8f,	0.0f,	// front right, bottom right
		0.5f,	1.0f,	0.5f,	c[0],	c[1],	c[2],	c[3],	0.8f,	1.0f,	// front right, top right
		-0.5f,	1.0f,	0.5f,	c[0],	c[1],	c[2],	c[3],	0.15f,	1.0f,	// front right, top left


		0.5f,	0.0f,	0.5f,	c[0],	c[1],	c[2],	c[3],	0.8f,	0.0f,	// right right, bottom right
		0.5f,	1.0f,	0.5f,	c[0],	c[1],	c[2],	c[3],	0.8f,	1.0f,	// right right, top right
		0.5f,	1.0f,	-0.5f,	c[0],	c[1],	c[2],	c[3],	0.15f,	1.0f,	// right right, top left

		0.5f,	0.0f,	0.5f,	c[0],	c[1],	c[2],	c[3],	0.8f,	0.0f,	// right left, bottom right
		0.5f,	0.0f,	-0.5f,	c[0],	c[1],	c[2],	c[3],	0.15f,	0.0f,	// right left, bottom left
		0.5f,	1.0f,	-0.5f,	c[0],	c[1],	c[2],	c[3],	0.15f,	1.0f,	// right left, top left


		0.5f,	0.0f,	-0.5f,	c[0],	c[1],	c[2],	c[3],	0.8f,	0.0f,	// back left, bottom right
		-0.5f,	0.0f,	-0.5f,	c[0],	c[1],	c[2],	c[3],	0.15f,	0.0f,	// back left, bottom left
		-0.5f,	1.0f,	-0.5f,	c[0],	c[1],	c[2],	c[3],	0.15f,	1.0f,	// back left, top left

		0.5f,	0.0f,	-0.5f,	c[0],	c[1],	c[2],	c[3],	0.8f,	0.0f,	// back right, bottom right
		0.5f,	1.0f,	-0.5f,	c[0],	c[1],	c[2],	c[3],	0.8f,	1.0f,	// back right, top right
		-0.5f,	1.0f,	-0.5f,	c[0],	c[1],	c[2],	c[3],	0.15f,	1.0f,	// back right, top left


		-0.5f,	0.0f,	0.5f,	c[0],	c[1],	c[2],	c[3],	0.8f,	0.0f,	// left left, bottom right
		-0.5f,	1.0f,	0.5f,	c[0],	c[1],	c[2],	c[3],	0.8f,	1.0f,	// left left, top right
		-0.5f,	1.0f,	-0.5f,	c[0],	c[1],	c[2],	c[3],	0.15f,	1.0f,	// left left, top left

		-0.5f,	0.0f,	0.5f,	c[0],	c[1],	c[2],	c[3],	0.8f,	0.0f,	// left left, bottom right
		-0.5f,	0.0f,	-0.5f,	c[0],	c[1],	c[2],	c[3],	0.15f,	0.0f,	// left left, bottom left
		-0.5f,	1.0f,	-0.5f,	c[0],	c[1],	c[2],	c[3],	0.15f,	1.0f,	// left left, top left




		-0.5f,	1.0f,	0.5f,	c[0],	c[1],	c[2],	c[3],	0.3f,	0.5f,	// top left
		-0.5f,	1.0f,	-0.5f,	c[0],	c[1],	c[2],	c[3],	0.3f,	0.65f,	
		0.5f,	1.0f,	0.5f,	c[0],	c[1],	c[2],	c[3],	0.5f,	0.65f,	

		-0.5f,	1.0f,	-0.5f,	c[0],	c[1],	c[2],	c[3],	0.3f,	0.5f,	// top right
		0.5f,	1.0f,	0.5f,	c[0],	c[1],	c[2],	c[3],	0.5f,	0.65f,	
		0.5f,	1.0f,	-0.5f,	c[0],	c[1],	c[2],	c[3],	0.5f,	0.5f,

		-0.5f,	0.0f,	0.5f,	c[0],	c[1],	c[2],	c[3],	0.25f,	0.1f,	// bottom left
		-0.5f,	0.0f,	-0.5f,	c[0],	c[1],	c[2],	c[3],	0.25f,	0.0f,
		0.5f,	0.0f,	0.5f,	c[0],	c[1],	c[2],	c[3],	0.35f,	0.1f,

		-0.5f,	0.0f,	-0.5f,	c[0],	c[1],	c[2],	c[3],	0.25f,	0.0f,	// bottom right
		0.5f,	0.0f,	0.5f,	c[0],	c[1],	c[2],	c[3],	0.35f,	0.1f,
		0.5f,	0.0f,	-0.5f,	c[0],	c[1],	c[2],	c[3],	0.35f,	0.0f,


	};

	UTranslator(mesh);
}

void BuildShape::UCylinderMesh(GLMesh& mesh) {
	vector<float> c = { mesh.p[0], mesh.p[1], mesh.p[2], mesh.p[3] };

	mesh.v = {
		// cylinder bottom				// normals				// texture coords
		1.0f, 0.0f, 0.0f,		c[0],	c[1],	c[2],	c[3],		0.5f, 1.0f,
		.98f, 0.0f, -0.17f,		c[0],	c[1],	c[2],	c[3],		0.41f, 0.983f,
		.94f, 0.0f, -0.34f,		c[0],	c[1],	c[2],	c[3],		0.33f, 0.96f,
		.87f, 0.0f, -0.5f,		c[0],	c[1],	c[2],	c[3],		0.25f, 0.92f,
		.77f, 0.0f, -0.64f,		c[0],	c[1],	c[2],	c[3],		0.17f, 0.87f,
		.64f, 0.0f, -0.77f,		c[0],	c[1],	c[2],	c[3],		0.13f, 0.83f,
		.5f, 0.0f, -0.87f,		c[0],	c[1],	c[2],	c[3],		0.08f, 0.77f,
		.34f, 0.0f, -0.94f,		c[0],	c[1],	c[2],	c[3],		0.04f, 0.68f,
		.17f, 0.0f, -0.98f,		c[0],	c[1],	c[2],	c[3],		0.017f, 0.6f,
		0.0f, 0.0f, -1.0f,		c[0],	c[1],	c[2],	c[3],		0.0f, 0.5f,
		-.17f, 0.0f, -0.98f,	c[0],	c[1],	c[2],	c[3],		0.017f, 0.41f,
		-.34f, 0.0f, -0.94f,	c[0],	c[1],	c[2],	c[3],		0.04f, 0.33f,
		-.5f, 0.0f, -0.87f,		c[0],	c[1],	c[2],	c[3],		0.08f, 0.25f,
		-.64f, 0.0f, -0.77f,	c[0],	c[1],	c[2],	c[3],		0.13f, 0.17f,
		-.77f, 0.0f, -0.64f,	c[0],	c[1],	c[2],	c[3],		0.17f, 0.13f,
		-.87f, 0.0f, -0.5f,		c[0],	c[1],	c[2],	c[3],		0.25f, 0.08f,
		-.94f, 0.0f, -0.34f,	c[0],	c[1],	c[2],	c[3],		0.33f, 0.04f,
		-.98f, 0.0f, -0.17f,	c[0],	c[1],	c[2],	c[3],		0.41f, 0.017f,
		-1.0f, 0.0f, 0.0f,		c[0],	c[1],	c[2],	c[3],		0.5f, 0.0f,
		-.98f, 0.0f, 0.17f,		c[0],	c[1],	c[2],	c[3],		0.6f, 0.017f,
		-.94f, 0.0f, 0.34f,		c[0],	c[1],	c[2],	c[3],		0.68f, 0.04f,
		-.87f, 0.0f, 0.5f,		c[0],	c[1],	c[2],	c[3],		0.77f, 0.08f,
		-.77f, 0.0f, 0.64f,		c[0],	c[1],	c[2],	c[3],		0.83f, 0.13f,
		-.64f, 0.0f, 0.77f,		c[0],	c[1],	c[2],	c[3],		0.87f, 0.17f,
		-.5f, 0.0f, 0.87f,		c[0],	c[1],	c[2],	c[3],		0.92f, 0.25f,
		-.34f, 0.0f, 0.94f,		c[0],	c[1],	c[2],	c[3],		0.96f, 0.33f,
		-.17f, 0.0f, 0.98f,		c[0],	c[1],	c[2],	c[3],		0.983f, 0.41f,
		0.0f, 0.0f, 1.0f,		c[0],	c[1],	c[2],	c[3],		1.0f, 0.5f,
		.17f, 0.0f, 0.98f,		c[0],	c[1],	c[2],	c[3],		0.983f, 0.6f,
		.34f, 0.0f, 0.94f,		c[0],	c[1],	c[2],	c[3],		0.96f, 0.68f,
		.5f, 0.0f, 0.87f,		c[0],	c[1],	c[2],	c[3],		0.92f, 0.77f,
		.64f, 0.0f, 0.77f,		c[0],	c[1],	c[2],	c[3],		0.87f, 0.83f,
		.77f, 0.0f, 0.64f,		c[0],	c[1],	c[2],	c[3],		0.83f, 0.87f,
		.87f, 0.0f, 0.5f,		c[0],	c[1],	c[2],	c[3],		0.77f, 0.92f,
		.94f, 0.0f, 0.34f,		c[0],	c[1],	c[2],	c[3],		0.68f, 0.96f,
		.98f, 0.0f, 0.17f,		c[0],	c[1],	c[2],	c[3],		0.6f, 0.983f,

		// cylinder top					// normals				// texture coords
		1.0f, 1.0f, 0.0f,		c[0],	c[1],	c[2],	c[3],		0.5f, 1.0f,
		.98f, 1.0f, -0.17f,		c[0],	c[1],	c[2],	c[3],		0.41f, 0.983f,
		.94f, 1.0f, -0.34f,		c[0],	c[1],	c[2],	c[3],		0.33f, 0.96f,
		.87f, 1.0f, -0.5f,		c[0],	c[1],	c[2],	c[3],		0.25f, 0.92f,
		.77f, 1.0f, -0.64f,		c[0],	c[1],	c[2],	c[3],		0.17f, 0.87f,
		.64f, 1.0f, -0.77f,		c[0],	c[1],	c[2],	c[3],		0.13f, 0.83f,
		.5f, 1.0f, -0.87f,		c[0],	c[1],	c[2],	c[3],		0.08f, 0.77f,
		.34f, 1.0f, -0.94f,		c[0],	c[1],	c[2],	c[3],		0.04f, 0.68f,
		.17f, 1.0f, -0.98f,		c[0],	c[1],	c[2],	c[3],		0.017f, 0.6f,
		0.0f, 1.0f, -1.0f,		c[0],	c[1],	c[2],	c[3],		0.0f, 0.5f,
		-.17f, 1.0f, -0.98f,	c[0],	c[1],	c[2],	c[3],		0.017f, 0.41f,
		-.34f, 1.0f, -0.94f,	c[0],	c[1],	c[2],	c[3],		0.04f, 0.33f,
		-.5f, 1.0f, -0.87f,		c[0],	c[1],	c[2],	c[3],		0.08f, 0.25f,
		-.64f, 1.0f, -0.77f,	c[0],	c[1],	c[2],	c[3],		0.13f, 0.17f,
		-.77f, 1.0f, -0.64f,	c[0],	c[1],	c[2],	c[3],		0.17f, 0.13f,
		-.87f, 1.0f, -0.5f,		c[0],	c[1],	c[2],	c[3],		0.25f, 0.08f,
		-.94f, 1.0f, -0.34f,	c[0],	c[1],	c[2],	c[3],		0.33f, 0.04f,
		-.98f, 1.0f, -0.17f,	c[0],	c[1],	c[2],	c[3],		0.41f, 0.017f,
		-1.0f, 1.0f, 0.0f,		c[0],	c[1],	c[2],	c[3],		0.5f, 0.0f,
		-.98f, 1.0f, 0.17f,		c[0],	c[1],	c[2],	c[3],		0.6f, 0.017f,
		-.94f, 1.0f, 0.34f,		c[0],	c[1],	c[2],	c[3],		0.68f, 0.04f,
		-.87f, 1.0f, 0.5f,		c[0],	c[1],	c[2],	c[3],		0.77f, 0.08f,
		-.77f, 1.0f, 0.64f,		c[0],	c[1],	c[2],	c[3],		0.83f, 0.13f,
		-.64f, 1.0f, 0.77f,		c[0],	c[1],	c[2],	c[3],		0.87f, 0.17f,
		-.5f, 1.0f, 0.87f,		c[0],	c[1],	c[2],	c[3],		0.92f, 0.25f,
		-.34f, 1.0f, 0.94f,		c[0],	c[1],	c[2],	c[3],		0.96f, 0.33f,
		-.17f, 1.0f, 0.98f,		c[0],	c[1],	c[2],	c[3],		0.983f, 0.41f,
		0.0f, 1.0f, 1.0f,		c[0],	c[1],	c[2],	c[3],		1.0f, 0.5f,
		.17f, 1.0f, 0.98f,		c[0],	c[1],	c[2],	c[3],		0.983f, 0.6f,
		.34f, 1.0f, 0.94f,		c[0],	c[1],	c[2],	c[3],		0.96f, 0.68f,
		.5f, 1.0f, 0.87f,		c[0],	c[1],	c[2],	c[3],		0.92f, 0.77f,
		.64f, 1.0f, 0.77f,		c[0],	c[1],	c[2],	c[3],		0.87f, 0.83f,
		.77f, 1.0f, 0.64f,		c[0],	c[1],	c[2],	c[3],		0.83f, 0.87f,
		.87f, 1.0f, 0.5f,		c[0],	c[1],	c[2],	c[3],		0.77f, 0.92f,
		.94f, 1.0f, 0.34f,		c[0],	c[1],	c[2],	c[3],		0.68f, 0.96f,
		.98f, 1.0f, 0.17f,		c[0],	c[1],	c[2],	c[3],		0.6f, 0.983f,

		// cylinder body				// normals				// texture coords
		1.0f, 1.0f, 0.0f,		c[0],	c[1],	c[2],	c[3],		0.0, 1.0,
		1.0f, 0.0f, 0.0f,		c[0],	c[1],	c[2],	c[3],		0.0, 0.0,
		.98f, 0.0f, -0.17f,		c[0],	c[1],	c[2],	c[3],		0.0277, 0.0,
		1.0f, 1.0f, 0.0f,		c[0],	c[1],	c[2],	c[3],		0.0, 1.0,
		.98f, 1.0f, -0.17f,		c[0],	c[1],	c[2],	c[3],		0.0277, 1.0,
		.98f, 0.0f, -0.17f,		c[0],	c[1],	c[2],	c[3],		0.0277, 0.0,
		.94f, 0.0f, -0.34f,		c[0],	c[1],	c[2],	c[3],		0.0554, 0.0,
		.98f, 1.0f, -0.17f,		c[0],	c[1],	c[2],	c[3],		0.0277, 1.0,
		.94f, 1.0f, -0.34f,		c[0],	c[1],	c[2],	c[3],		0.0554, 1.0,
		.94f, 0.0f, -0.34f,		c[0],	c[1],	c[2],	c[3],		0.0554, 0.0,
		.87f, 0.0f, -0.5f,		c[0],	c[1],	c[2],	c[3],		0.0831, 0.0,
		.94f, 1.0f, -0.34f,		c[0],	c[1],	c[2],	c[3],		0.0554, 1.0,
		.87f, 1.0f, -0.5f,		c[0],	c[1],	c[2],	c[3],		0.0831, 1.0,
		.87f, 0.0f, -0.5f,		c[0],	c[1],	c[2],	c[3],		0.0831, 0.0,
		.77f, 0.0f, -0.64f,		c[0],	c[1],	c[2],	c[3],		0.1108, 0.0,
		.87f, 1.0f, -0.5f,		c[0],	c[1],	c[2],	c[3],		0.0831, 1.0,
		.77f, 1.0f, -0.64f,		c[0],	c[1],	c[2],	c[3],		0.1108, 1.0,
		.77f, 0.0f, -0.64f,		c[0],	c[1],	c[2],	c[3],		0.1108, 0.0,
		.64f, 0.0f, -0.77f,		c[0],	c[1],	c[2],	c[3],		0.1385, 0.0,
		.77f, 1.0f, -0.64f,		c[0],	c[1],	c[2],	c[3],		0.1108, 1.0,
		.64f, 1.0f, -0.77f,		c[0],	c[1],	c[2],	c[3],		0.1385, 1.0,
		.64f, 0.0f, -0.77f,		c[0],	c[1],	c[2],	c[3],		0.1385, 0.0,
		.5f, 0.0f, -0.87f,		c[0],	c[1],	c[2],	c[3],		0.1662, 0.0,
		.64f, 1.0f, -0.77f,		c[0],	c[1],	c[2],	c[3],		0.1385, 1.0,
		.5f, 1.0f, -0.87f,		c[0],	c[1],	c[2],	c[3],		0.1662, 1.0,
		.5f, 0.0f, -0.87f,		c[0],	c[1],	c[2],	c[3],		0.1662, 0.0,
		.34f, 0.0f, -0.94f,		c[0],	c[1],	c[2],	c[3],		0.1939, 0.0,
		.5f, 1.0f, -0.87f,		c[0],	c[1],	c[2],	c[3],		0.1662, 1.0,
		.34f, 1.0f, -0.94f,		c[0],	c[1],	c[2],	c[3],		0.1939, 1.0,
		.34f, 0.0f, -0.94f,		c[0],	c[1],	c[2],	c[3],		0.1939, 0.0,
		.17f, 0.0f, -0.98f,		c[0],	c[1],	c[2],	c[3],		0.2216, 0.0,
		.34f, 1.0f, -0.94f,		c[0],	c[1],	c[2],	c[3],		0.1939, 1.0,
		.17f, 1.0f, -0.98f,		c[0],	c[1],	c[2],	c[3],		0.2216, 1.0,
		.17f, 0.0f, -0.98f,		c[0],	c[1],	c[2],	c[3],		0.2216, 0.0,
		0.0f, 0.0f, -1.0f,		c[0],	c[1],	c[2],	c[3],		0.2493, 0.0,
		.17f, 1.0f, -0.98f,		c[0],	c[1],	c[2],	c[3],		0.2216, 1.0,
		0.0f, 1.0f, -1.0f,		c[0],	c[1],	c[2],	c[3],		0.2493, 1.0,
		0.0f, 0.0f, -1.0f,		c[0],	c[1],	c[2],	c[3],		0.2493, 0.0,
		-.17f, 0.0f, -0.98f,	c[0],	c[1],	c[2],	c[3],		0.277, 0.0,
		0.0f, 1.0f, -1.0f,		c[0],	c[1],	c[2],	c[3],		0.2493, 1.0,
		-.17f, 1.0f, -0.98f,	c[0],	c[1],	c[2],	c[3],		0.277, 1.0,
		-.17f, 0.0f, -0.98f,	c[0],	c[1],	c[2],	c[3],		0.277, 0.0,
		-.34f, 0.0f, -0.94f,	c[0],	c[1],	c[2],	c[3],		0.3047, 0.0,
		-.17f, 1.0f, -0.98f,	c[0],	c[1],	c[2],	c[3],		0.277, 1.0,
		-.34f, 1.0f, -0.94f,	c[0],	c[1],	c[2],	c[3],		0.3047, 1.0,
		-.34f, 0.0f, -0.94f,	c[0],	c[1],	c[2],	c[3],		0.3047, 0.0,
		-.5f, 0.0f, -0.87f,		c[0],	c[1],	c[2],	c[3], 		0.3324, 0.0,
		-.34f, 1.0f, -0.94f,	c[0],	c[1],	c[2],	c[3],		0.3047, 1.0,
		-.5f, 1.0f, -0.87f,		c[0],	c[1],	c[2],	c[3],		0.3324, 1.0,
		-.5f, 0.0f, -0.87f,		c[0],	c[1],	c[2],	c[3],		0.3324, 0.0,
		-.64f, 0.0f, -0.77f,	c[0],	c[1],	c[2],	c[3],		0.3601, 0.0,
		-.5f, 1.0f, -0.87f,		c[0],	c[1],	c[2],	c[3],		0.3324, 1.0,
		-.64f, 1.0f, -0.77f,	c[0],	c[1],	c[2],	c[3],		0.3601, 1.0,
		-.64f, 0.0f, -0.77f,	c[0],	c[1],	c[2],	c[3],		0.3601, 0.0,
		-.77f, 0.0f, -0.64f,	c[0],	c[1],	c[2],	c[3],		0.3878, 0.0,
		-.64f, 1.0f, -0.77f,	c[0],	c[1],	c[2],	c[3],		0.3601, 1.0,
		-.77f, 1.0f, -0.64f,	c[0],	c[1],	c[2],	c[3],		0.3878, 1.0,
		-.77f, 0.0f, -0.64f,	c[0],	c[1],	c[2],	c[3],		0.3878, 0.0,
		-.87f, 0.0f, -0.5f,		c[0],	c[1],	c[2],	c[3],		0.4155, 0.0,
		-.77f, 1.0f, -0.64f,	c[0],	c[1],	c[2],	c[3],		0.3878, 1.0,
		-.87f, 1.0f, -0.5f,		c[0],	c[1],	c[2],	c[3],		0.4155, 1.0,
		-.87f, 0.0f, -0.5f,		c[0],	c[1],	c[2],	c[3],		0.4155, 0.0,
		-.94f, 0.0f, -0.34f,	c[0],	c[1],	c[2],	c[3],		0.4432, 0.0,
		-.87f, 1.0f, -0.5f,		c[0],	c[1],	c[2],	c[3],		0.4155, 1.0,
		-.94f, 1.0f, -0.34f,	c[0],	c[1],	c[2],	c[3],		0.4432, 1.0,
		-.94f, 0.0f, -0.34f,	c[0],	c[1],	c[2],	c[3],		0.4432, 0.0,
		-.98f, 0.0f, -0.17f,	c[0],	c[1],	c[2],	c[3],		0.4709, 0.0,
		-.94f, 1.0f, -0.34f,	c[0],	c[1],	c[2],	c[3],		0.4432, 1.0,
		-.98f, 1.0f, -0.17f,	c[0],	c[1],	c[2],	c[3],		0.4709, 1.0,
		-.98f, 0.0f, -0.17f,	c[0],	c[1],	c[2],	c[3],		0.4709, 0.0,
		-1.0f, 0.0f, 0.0f,		c[0],	c[1],	c[2],	c[3],		0.4986, 0.0,
		-.98f, 1.0f, -0.17f,	c[0],	c[1],	c[2],	c[3],		0.4709, 1.0,
		-1.0f, 1.0f, 0.0f,		c[0],	c[1],	c[2],	c[3],		0.4986, 1.0,
		-1.0f, 0.0f, 0.0f,		c[0],	c[1],	c[2],	c[3],		0.4986, 0.0,
		-.98f, 0.0f, 0.17f,		c[0],	c[1],	c[2],	c[3],		0.5263, 0.0,
		-1.0f, 1.0f, 0.0f,		c[0],	c[1],	c[2],	c[3],		0.4986, 1.0,
		-.98f, 1.0f, 0.17f,		c[0],	c[1],	c[2],	c[3],		0.5263, 1.0,
		-.98f, 0.0f, 0.17f,		c[0],	c[1],	c[2],	c[3],		0.5263, 0.0,
		-.94f, 0.0f, 0.34f,		c[0],	c[1],	c[2],	c[3],		0.554, 0.0,
		-.98f, 1.0f, 0.17f,		c[0],	c[1],	c[2],	c[3],		0.5263, 1.0,
		-.94f, 1.0f, 0.34f,		c[0],	c[1],	c[2],	c[3],		0.554, 1.0,
		-.94f, 0.0f, 0.34f,		c[0],	c[1],	c[2],	c[3],		0.554, 0.0,
		-.87f, 0.0f, 0.5f,		c[0],	c[1],	c[2],	c[3],		0.5817, 0.0,
		-.94f, 1.0f, 0.34f,		c[0],	c[1],	c[2],	c[3],		0.554, 1.0,
		-.87f, 1.0f, 0.5f,		c[0],	c[1],	c[2],	c[3],		0.5817, 1.0,
		-.87f, 0.0f, 0.5f,		c[0],	c[1],	c[2],	c[3],		0.5817, 0.0,
		-.77f, 0.0f, 0.64f,		c[0],	c[1],	c[2],	c[3],		0.6094, 0.0,
		-.87f, 1.0f, 0.5f,		c[0],	c[1],	c[2],	c[3],		0.5817, 1.0,
		-.77f, 1.0f, 0.64f,		c[0],	c[1],	c[2],	c[3],		0.6094, 1.0,
		-.77f, 0.0f, 0.64f,		c[0],	c[1],	c[2],	c[3],		0.6094, 0.0,
		-.64f, 0.0f, 0.77f,		c[0],	c[1],	c[2],	c[3],		0.6371, 0.0,
		-.77f, 1.0f, 0.64f,		c[0],	c[1],	c[2],	c[3],		0.6094, 1.0,
		-.64f, 1.0f, 0.77f,		c[0],	c[1],	c[2],	c[3],		0.6371, 1.0,
		-.64f, 0.0f, 0.77f,		c[0],	c[1],	c[2],	c[3],		0.6371, 0.0,
		-.5f, 0.0f, 0.87f,		c[0],	c[1],	c[2],	c[3],		0.6648, 0.0,
		-.64f, 1.0f, 0.77f,		c[0],	c[1],	c[2],	c[3],		0.6371, 1.0,
		-.5f, 1.0f, 0.87f,		c[0],	c[1],	c[2],	c[3],		0.6648, 1.0,
		-.5f, 0.0f, 0.87f,		c[0],	c[1],	c[2],	c[3],		0.6648, 0.0,
		-.34f, 0.0f, 0.94f,		c[0],	c[1],	c[2],	c[3],		0.6925, 0.0,
		-.5f, 1.0f, 0.87f,		c[0],	c[1],	c[2],	c[3],		0.6648, 1.0,
		-.34f, 1.0f, 0.94f,		c[0],	c[1],	c[2],	c[3],		0.6925, 1.0,
		-.34f, 0.0f, 0.94f,		c[0],	c[1],	c[2],	c[3],		0.6925, 0.0,
		-.17f, 0.0f, 0.98f,		c[0],	c[1],	c[2],	c[3],		0.7202, 0.0,
		-.34f, 1.0f, 0.94f,		c[0],	c[1],	c[2],	c[3],		0.6925, 1.0,
		-.17f, 1.0f, 0.98f,		c[0],	c[1],	c[2],	c[3],		0.7202, 1.0,
		-.17f, 0.0f, 0.98f,		c[0],	c[1],	c[2],	c[3],		0.7202, 0.0,
		0.0f, 0.0f, 1.0f,		c[0],	c[1],	c[2],	c[3],		0.7479, 0.0,
		-.17f, 1.0f, 0.98f,		c[0],	c[1],	c[2],	c[3],		0.7202, 1.0,
		0.0f, 1.0f, 1.0f,		c[0],	c[1],	c[2],	c[3],		0.7479, 1.0,
		0.0f, 0.0f, 1.0f,		c[0],	c[1],	c[2],	c[3],		0.7479, 0.0,
		.17f, 0.0f, 0.98f,		c[0],	c[1],	c[2],	c[3],		0.7756, 0.0,
		0.0f, 1.0f, 1.0f,		c[0],	c[1],	c[2],	c[3],		0.7479, 1.0,
		.17f, 1.0f, 0.98f,		c[0],	c[1],	c[2],	c[3],		0.7756, 1.0,
		.17f, 0.0f, 0.98f,		c[0],	c[1],	c[2],	c[3],		0.7756, 0.0,
		.34f, 0.0f, 0.94f,		c[0],	c[1],	c[2],	c[3],		0.8033, 0.0,
		.17f, 1.0f, 0.98f,		c[0],	c[1],	c[2],	c[3],		0.7756, 1.0,
		.34f, 1.0f, 0.94f,		c[0],	c[1],	c[2],	c[3],		0.8033, 1.0,
		.34f, 0.0f, 0.94f,		c[0],	c[1],	c[2],	c[3],		0.8033, 0.0,
		.5f, 0.0f, 0.87f,		c[0],	c[1],	c[2],	c[3],		0.831, 0.0,
		.34f, 1.0f, 0.94f,		c[0],	c[1],	c[2],	c[3],		0.8033, 1.0,
		.5f, 1.0f, 0.87f,		c[0],	c[1],	c[2],	c[3],		0.831, 1.0,
		.5f, 0.0f, 0.87f,		c[0],	c[1],	c[2],	c[3],		0.831, 0.0,
		.64f, 0.0f, 0.77f,		c[0],	c[1],	c[2],	c[3],		0.8587, 0.0,
		.5f, 1.0f, 0.87f,		c[0],	c[1],	c[2],	c[3],		0.831, 1.0,
		.64f, 1.0f, 0.77f,		c[0],	c[1],	c[2],	c[3],		0.8587, 1.0,
		.64f, 0.0f, 0.77f,		c[0],	c[1],	c[2],	c[3],		0.8587, 0.0,
		.77f, 0.0f, 0.64f,		c[0],	c[1],	c[2],	c[3],		0.8864, 0.0,
		.64f, 1.0f, 0.77f,		c[0],	c[1],	c[2],	c[3],		0.8587, 1.0,
		.77f, 1.0f, 0.64f,		c[0],	c[1],	c[2],	c[3],		0.8864, 1.0,
		.77f, 0.0f, 0.64f,		c[0],	c[1],	c[2],	c[3],		0.8864, 0.0,
		.87f, 0.0f, 0.5f,		c[0],	c[1],	c[2],	c[3],		0.9141, 0.0,
		.77f, 1.0f, 0.64f,		c[0],	c[1],	c[2],	c[3],		0.8864, 1.0,
		.87f, 1.0f, 0.5f,		c[0],	c[1],	c[2],	c[3],		0.9141, 1.0,
		.87f, 0.0f, 0.5f,		c[0],	c[1],	c[2],	c[3],		0.9141, 0.0,
		.94f, 0.0f, 0.34f,		c[0],	c[1],	c[2],	c[3],		0.9418, 0.0,
		.87f, 1.0f, 0.5f,		c[0],	c[1],	c[2],	c[3],		0.9141, 1.0,
		.94f, 1.0f, 0.34f,		c[0],	c[1],	c[2],	c[3],		0.9418, 1.0,
		.94f, 0.0f, 0.34f,		c[0],	c[1],	c[2],	c[3],		0.9418, 0.0,
		.98f, 0.0f, 0.17f,		c[0],	c[1],	c[2],	c[3],		0.9695, 0.0,
		.94f, 1.0f, 0.34f,		c[0],	c[1],	c[2],	c[3],		0.9418, 0.0,
		.98f, 1.0f, 0.17f,		c[0],	c[1],	c[2],	c[3],		0.9695, 1.0,
		.98f, 0.0f, 0.17f,		c[0],	c[1],	c[2],	c[3],		0.9695, 0.0,
		1.0f, 0.0f, 0.0f,		c[0],	c[1],	c[2],	c[3],		1.0, 0.0,
		.98f, 1.0f, 0.17f,		c[0],	c[1],	c[2],	c[3],		0.9695, 1.0,
		1.0f, 1.0f, 0.0f,		c[0],	c[1],	c[2],	c[3],		1.0, 1.0,
		1.0f, 0.0f, 0.0f,		c[0],	c[1],	c[2],	c[3],		1.0, 0.0


	};
	

	UTranslator(mesh);
	
	
}

void BuildShape::UPlaneMesh(GLMesh& mesh) {
	vector<float> c = { mesh.p[0], mesh.p[1], mesh.p[2], mesh.p[3] };

	mesh.v = {
		//vertex positions			//color coords			//texture coords
		-1.0f, 0.0f, -1.0f,		c[0], c[1], c[2], c[3],		0.0f, 1.0f,	// 0
		 0.0f, 0.0f, 1.0f,		c[0], c[1], c[2], c[3],		0.5f, 0.0f,	// 1
		-1.0f, 0.0f, 1.0f,		c[0], c[1], c[2], c[3],		0.0f, 0.0f,	// 2

		-1.0f, 0.0f, -1.0f,		c[0], c[1], c[2], c[3],		0.0f, 1.0f,	// 0
		 0.0f, 0.0f, 1.0f,		c[0], c[1], c[2], c[3],		0.5f, 0.0f,	// 2
		 0.0f, 0.0f, -1.0f,		c[0], c[1], c[2], c[3],		0.5f, 1.0f,	// 3

		 0.0f, 0.0f, -1.0f,		c[0], c[1], c[2], c[3],		0.5f, 1.0f,	// 3
		 0.0f, 0.0f, 1.0f,		c[0], c[1], c[2], c[3],		0.5f, 0.0f,	// 2
		 1.0f, 0.0f, 1.0f,		c[0], c[1], c[2], c[3],		1.0f, 0.0f,	// 5

		 0.0f, 0.0f, -1.0f,		c[0], c[1], c[2], c[3],		0.5f, 1.0f,	// 3
		 1.0f, 0.0f, 1.0f,		c[0], c[1], c[2], c[3],		1.0f, 0.0f,	// 5
		 1.0f, 0.0f, -1.0f,		c[0], c[1], c[2], c[3],		1.0f, 1.0f,	// 4

	};

	UTranslator(mesh);

}


void BuildShape::UTorusMesh(GLMesh& mesh)
{
	vector<float> c = { mesh.p[0], mesh.p[1], mesh.p[2], mesh.p[3] };
	int _mainSegments = 30;
	int _tubeSegments = 30;
	float _mainRadius = 1.0f;
	float _tubeRadius = .1f;

	auto mainSegmentAngleStep = glm::radians(360.0f / float(_mainSegments));
	auto tubeSegmentAngleStep = glm::radians(360.0f / float(_tubeSegments));

	std::vector<glm::vec3> vertex_list;
	std::vector<std::vector<glm::vec3>> segments_list;
	std::vector<glm::vec3> normals_list;
	std::vector<glm::vec2> texture_coords;
	glm::vec3 center(0.0f, 0.0f, 0.0f);
	glm::vec3 normal;
	glm::vec3 vertex;
	glm::vec2 text_coord;

	// generate the torus vertices
	auto currentMainSegmentAngle = 0.0f;
	for (auto i = 0; i < _mainSegments; i++)
	{
		// Calculate sine and cosine of main segment angle
		auto sinMainSegment = sin(currentMainSegmentAngle);
		auto cosMainSegment = cos(currentMainSegmentAngle);
		auto currentTubeSegmentAngle = 0.0f;
		std::vector<glm::vec3> segment_points;
		for (auto j = 0; j < _tubeSegments; j++)
		{
			// Calculate sine and cosine of tube segment angle
			auto sinTubeSegment = sin(currentTubeSegmentAngle);
			auto cosTubeSegment = cos(currentTubeSegmentAngle);

			// Calculate vertex position on the surface of torus
			auto surfacePosition = glm::vec3(
				(_mainRadius + _tubeRadius * cosTubeSegment) * cosMainSegment,
				(_mainRadius + _tubeRadius * cosTubeSegment) * sinMainSegment,
				_tubeRadius * sinTubeSegment);

			//vertex_list.push_back(surfacePosition);
			segment_points.push_back(surfacePosition);

			// Update current tube angle
			currentTubeSegmentAngle += tubeSegmentAngleStep;
		}
		segments_list.push_back(segment_points);
		segment_points.clear();

		// Update main segment angle
		currentMainSegmentAngle += mainSegmentAngleStep;
	}

	float horizontalStep = 1.0 / _mainSegments;
	float verticalStep = 1.0 / _tubeSegments;
	float u = 0.0;
	float v = 0.0;

	// connect the various segments together, forming triangles
	for (int i = 0; i < _mainSegments; i++)
	{
		for (int j = 0; j < _tubeSegments; j++)
		{
			if (((i + 1) < _mainSegments) && ((j + 1) < _tubeSegments))
			{
				vertex_list.push_back(segments_list[i][j]);
				normal = normalize(segments_list[i][j] - center);
				normals_list.push_back(normal);
				texture_coords.push_back(glm::vec2(u, v));
				vertex_list.push_back(segments_list[i][j + 1]);
				normal = normalize(segments_list[i][j + 1] - center);
				normals_list.push_back(normal);
				texture_coords.push_back(glm::vec2(u, v + verticalStep));
				vertex_list.push_back(segments_list[i + 1][j + 1]);
				normal = normalize(segments_list[i + 1][j + 1] - center);
				normals_list.push_back(normal);
				texture_coords.push_back(glm::vec2(u + horizontalStep, v + verticalStep));
				vertex_list.push_back(segments_list[i][j]);
				normal = normalize(segments_list[i][j] - center);
				normals_list.push_back(normal);
				texture_coords.push_back(glm::vec2(u, v));
				vertex_list.push_back(segments_list[i + 1][j]);
				normal = normalize(segments_list[i + 1][j] - center);
				normals_list.push_back(normal);
				texture_coords.push_back(glm::vec2(u + horizontalStep, v));
				vertex_list.push_back(segments_list[i + 1][j + 1]);
				normal = normalize(segments_list[i + 1][j + 1] - center);
				normals_list.push_back(normal);
				texture_coords.push_back(glm::vec2(u + horizontalStep, v - verticalStep));
				vertex_list.push_back(segments_list[i][j]);
				normal = normalize(segments_list[i][j] - center);
				normals_list.push_back(normal);
				texture_coords.push_back(glm::vec2(u, v));
			}
			else
			{
				if (((i + 1) == _mainSegments) && ((j + 1) == _tubeSegments))
				{
					vertex_list.push_back(segments_list[i][j]);
					normal = normalize(segments_list[i][j] - center);
					normals_list.push_back(normal);
					texture_coords.push_back(glm::vec2(u, v));
					vertex_list.push_back(segments_list[i][0]);
					normal = normalize(segments_list[i][0] - center);
					normals_list.push_back(normal);
					texture_coords.push_back(glm::vec2(u, 0));
					vertex_list.push_back(segments_list[0][0]);
					normal = normalize(segments_list[0][0] - center);
					normals_list.push_back(normal);
					texture_coords.push_back(glm::vec2(0, 0));
					vertex_list.push_back(segments_list[i][j]);
					normal = normalize(segments_list[i][j] - center);
					normals_list.push_back(normal);
					texture_coords.push_back(glm::vec2(u, v));
					vertex_list.push_back(segments_list[0][j]);
					normal = normalize(segments_list[0][j] - center);
					normals_list.push_back(normal);
					texture_coords.push_back(glm::vec2(0, v));
					vertex_list.push_back(segments_list[0][0]);
					normal = normalize(segments_list[0][0] - center);
					normals_list.push_back(normal);
					texture_coords.push_back(glm::vec2(0, 0));
					vertex_list.push_back(segments_list[i][j]);
					normal = normalize(segments_list[i][j] - center);
					normals_list.push_back(normal);
					texture_coords.push_back(glm::vec2(u, v));
				}
				else if ((i + 1) == _mainSegments)
				{
					vertex_list.push_back(segments_list[i][j]);
					normal = normalize(segments_list[i][j] - center);
					normals_list.push_back(normal);
					texture_coords.push_back(glm::vec2(u, v));
					vertex_list.push_back(segments_list[i][j + 1]);
					normal = normalize(segments_list[i][j + 1] - center);
					normals_list.push_back(normal);
					texture_coords.push_back(glm::vec2(u, v + verticalStep));
					vertex_list.push_back(segments_list[0][j + 1]);
					normal = normalize(segments_list[0][j + 1] - center);
					normals_list.push_back(normal);
					texture_coords.push_back(glm::vec2(0, v + verticalStep));
					vertex_list.push_back(segments_list[i][j]);
					normal = normalize(segments_list[i][j] - center);
					normals_list.push_back(normal);
					texture_coords.push_back(glm::vec2(u, v));
					vertex_list.push_back(segments_list[0][j]);
					normal = normalize(segments_list[0][j] - center);
					normals_list.push_back(normal);
					texture_coords.push_back(glm::vec2(0, v));
					vertex_list.push_back(segments_list[0][j + 1]);
					normal = normalize(segments_list[0][j + 1] - center);
					normals_list.push_back(normal);
					texture_coords.push_back(glm::vec2(0, v + verticalStep));
					vertex_list.push_back(segments_list[i][j]);
					normal = normalize(segments_list[i][j] - center);
					normals_list.push_back(normal);
					texture_coords.push_back(glm::vec2(u, v));
				}
				else if ((j + 1) == _tubeSegments)
				{
					vertex_list.push_back(segments_list[i][j]);
					normal = normalize(segments_list[i][j] - center);
					normals_list.push_back(normal);
					texture_coords.push_back(glm::vec2(u, v));
					vertex_list.push_back(segments_list[i][0]);
					normal = normalize(segments_list[i][0] - center);
					normals_list.push_back(normal);
					texture_coords.push_back(glm::vec2(u, 0));
					vertex_list.push_back(segments_list[i + 1][0]);
					normal = normalize(segments_list[i + 1][0] - center);
					normals_list.push_back(normal);
					texture_coords.push_back(glm::vec2(u + horizontalStep, 0));
					vertex_list.push_back(segments_list[i][j]);
					normal = normalize(segments_list[i][j] - center);
					normals_list.push_back(normal);
					texture_coords.push_back(glm::vec2(u, v));
					vertex_list.push_back(segments_list[i + 1][j]);
					normal = normalize(segments_list[i + 1][j] - center);
					normals_list.push_back(normal);
					texture_coords.push_back(glm::vec2(u + horizontalStep, v));
					vertex_list.push_back(segments_list[i + 1][0]);
					normal = normalize(segments_list[i + 1][0] - center);
					normals_list.push_back(normal);
					texture_coords.push_back(glm::vec2(u + horizontalStep, 0));
					vertex_list.push_back(segments_list[i][j]);
					normal = normalize(segments_list[i][j] - center);
					normals_list.push_back(normal);
					texture_coords.push_back(glm::vec2(u, v));
				}

			}
			v += verticalStep;
		}
		v = 0.0;
		u += horizontalStep;
	}

	std::vector<GLfloat> combined_values;

	// combine interleaved vertices, normals, and texture coords
	for (int i = 0; i < vertex_list.size(); i++)
	{
		vertex = vertex_list[i];
		normal = normals_list[i];
		text_coord = texture_coords[i];
		combined_values.push_back(vertex.x);
		combined_values.push_back(vertex.y);
		combined_values.push_back(vertex.z);
		combined_values.push_back(normal.x);
		combined_values.push_back(normal.y);
		combined_values.push_back(normal.z);
		combined_values.push_back(text_coord.x);
		combined_values.push_back(text_coord.y);
	}

	// total float values per each type
	const GLuint floatsPerVertex = 3;
	const GLuint floatsPerNormal = 3;
	const GLuint floatsPerUV = 2;

	// store vertex and index count
	mesh.nVertices = vertex_list.size();
	mesh.nIndices = 0;
	mesh.shapeCase = 'E';

	// Create VAO
	glGenVertexArrays(1, &mesh.vao); // we can also generate multiple VAOs or buffers at the same time
	glBindVertexArray(mesh.vao);

	// Create VBOs
	glGenBuffers(1, mesh.vbos);
	glBindBuffer(GL_ARRAY_BUFFER, mesh.vbos[0]); // Activates the buffer
	glBufferData(GL_ARRAY_BUFFER, sizeof(GLfloat) * combined_values.size(), combined_values.data(), GL_STATIC_DRAW); // Sends vertex or coordinate data to the GPU

	// Strides between vertex coordinates
	GLint stride = sizeof(float) * (floatsPerVertex + floatsPerNormal + floatsPerUV);

	// Create Vertex Attribute Pointers
	glVertexAttribPointer(0, floatsPerVertex, GL_FLOAT, GL_FALSE, stride, 0);
	glEnableVertexAttribArray(0);

	glVertexAttribPointer(1, floatsPerNormal, GL_FLOAT, GL_FALSE, stride, (void*)(sizeof(float) * floatsPerVertex));
	glEnableVertexAttribArray(1);

	glVertexAttribPointer(2, floatsPerUV, GL_FLOAT, GL_FALSE, stride, (void*)(sizeof(float) * (floatsPerVertex + floatsPerNormal)));
	glEnableVertexAttribArray(2);

	//scale the object
	mesh.scale = glm::scale(glm::vec3(mesh.p[4], mesh.p[5], mesh.p[6]));

	const glm::mat4 rot = glm::mat4(1.0f);

	// rotate the object (x, y, z) (0 - 6.4, to the right)
	mesh.xrotation = glm::rotate(rot, glm::radians(mesh.p[7]), glm::vec3(mesh.p[8], mesh.p[9], mesh.p[10]));
	mesh.yrotation = glm::rotate(rot, glm::radians(mesh.p[11]), glm::vec3(mesh.p[12], mesh.p[13], mesh.p[14]));
	mesh.zrotation = glm::rotate(rot, glm::radians(mesh.p[15]), glm::vec3(mesh.p[16], mesh.p[17], mesh.p[18]));


	// move the object (x, y, z)
	mesh.translation = glm::translate(glm::vec3(mesh.p[19], mesh.p[20], mesh.p[21]));

	mesh.model = mesh.translation * mesh.xrotation * mesh.zrotation * mesh.yrotation * mesh.scale;

	mesh.gUVScale = glm::vec2(mesh.p[22], mesh.p[23]);

};


void BuildShape::USphereMesh(GLMesh& mesh) {
	vector<float> c = { mesh.p[0], mesh.p[1], mesh.p[2], mesh.p[3] };
	GLfloat verts[] = {
		// vertex data					// index
		// top center point
		0.0f, 1.0f, 0.0f,				//0
		// ring 1
		0.0f, 0.9808f, 0.1951f,			//1
		0.0747f, 0.9808f, 0.1802f,		//2
		0.1379f, 0.9808f, 0.1379f,		//3
		0.1802f, 0.9808f, 0.0747f,		//4
		0.1951f, 0.9808, 0.0f,			//5
		0.1802f, 0.9808f, -0.0747f,		//6
		0.1379f, 0.9808f, -0.1379f,		//7
		0.0747f, 0.9808f, -0.1802f,		//8
		0.0f, 0.9808f, -0.1951f,		//9
		-0.0747f, 0.9808f, -0.1802f,	//10
		-0.1379f, 0.9808f, -0.1379f,	//11
		-0.1802f, 0.9808f, -0.0747f,	//12
		-0.1951f, 0.9808, 0.0f,			//13
		-0.1802f, 0.9808f, 0.0747f,		//14
		-0.1379f, 0.9808f, 0.1379f,		//15
		-0.0747f, 0.9808f, 0.1802f,		//16
		// ring 2
		0.0f, 0.9239f, 0.3827f,			//17
		0.1464f, 0.9239f, 0.3536f,		//18
		0.2706f, 0.9239f, 0.2706f,		//19
		0.3536f, 0.9239f, 0.1464f,		//20
		0.3827f, 0.9239f, 0.0f,			//21
		0.3536f, 0.9239f, -0.1464f,		//22
		0.2706f, 0.9239f, -0.2706f,		//23
		0.1464f, 0.9239f, -0.3536f,		//24
		0.0f, 0.9239f, -0.3827f,		//25
		-0.1464f, 0.9239f, -0.3536f,	//26
		-0.2706f, 0.9239f, -0.2706f,	//27
		-0.3536f, 0.9239f, -0.1464f,	//28
		-0.3827f, 0.9239f, 0.0f,		//29
		-0.3536f, 0.9239f, 0.1464f,		//30
		-0.2706f, 0.9239f, 0.2706f,		//31
		-0.1464f, 0.9239f, 0.3536f,		//32
		// ring 3
		0.0f, 0.8315f, 0.5556f,			//33
		0.2126f, 0.8315f, 0.5133f,		//34
		0.3928f, 0.8315f, 0.3928f,		//35
		0.5133f, 0.8315f, 0.2126f,		//36
		0.5556f, 0.8315f, 0.0f,			//37
		0.5133f, 0.8315f, -0.2126f,		//38
		0.3928f, 0.8315f, -0.3928f,		//39
		0.2126f, 0.8315f, -0.5133f,		//40
		0.0f, 0.8315f, -0.5556f,		//41
		-0.2126f, 0.8315f, -0.5133f,	//42
		-0.3928f, 0.8315f, -0.3928f,	//43
		-0.5133f, 0.8315f, -0.2126f,	//44
		-0.5556f, 0.8315f, 0.0f,		//45
		-0.5133f, 0.8315f, 0.2126f,		//46
		-0.3928f, 0.8315f, 0.3928f,		//47
		-0.2126f, 0.8315f, 0.5133f,		//48
		// ring 4
		0.0f, 0.7071f, 0.7071f,			//49
		0.2706f, 0.7071f, 0.6533f,		//50
		0.5f, 0.7071f, 0.5f,			//51
		0.6533f, 0.7071f, 0.2706f,		//52
		0.7071f, 0.7071f, 0.0f,			//53
		0.6533f, 0.7071f, -0.2706f,		//54
		0.5f, 0.7071f, -0.5f,			//55
		0.2706f, 0.7071f, -0.6533f,		//56
		0.0f, 0.7071f, -0.7071f,		//57
		-0.2706f, 0.7071f, -0.6533f,	//58
		-0.5f, 0.7071f, -0.5f,			//59
		-0.6533f, 0.7071f, -0.2706f,	//60
		-0.7071f, 0.7071f, 0.0f,		//61
		-0.6533f, 0.7071f, 0.2706f,		//62
		-0.5f, 0.7071f, 0.5f,			//63
		-0.2706f, 0.7071f, 0.6533f,		//64
		// ring 5
		0.0f, 0.5556f, 0.8315f,			//65
		0.3182f, 0.5556f, 0.7682f,		//66
		0.5879f, 0.5556f, 0.5879f,		//67
		0.7682f, 0.5556f, 0.3182f,		//68
		0.8315f, 0.5556f, 0.0f,			//69
		0.7682f, 0.5556f, -0.3182f,		//70
		0.5879f, 0.5556f, -0.5879f,		//71
		0.3182f, 0.5556f, -0.7682f,		//72
		0.0f, 0.5556f, -0.8315f,		//73
		-0.3182f, 0.5556f, -0.7682f,	//74
		-0.5879f, 0.5556f, -0.5879f,	//75
		-0.7682f, 0.5556f, -0.3182f,	//76
		-0.8315f, 0.5556f, 0.0f,		//77
		-0.7682f, 0.5556f, 0.3182f,		//78
		-0.5879f, 0.5556f, 0.5879f,		//79
		-0.3182f, 0.5556f, 0.7682f,		//80
		//ring 6
		0.0f, 0.3827f, 0.9239f,			//81
		0.3536f, 0.3827f, 0.8536f,		//82
		0.6533f, 0.3827f, 0.6533f,		//83
		0.8536f, 0.3827f, 0.3536f,		//84
		0.9239f, 0.3827f, 0.0f,			//85
		0.8536f, 0.3827f, -0.3536f,		//86
		0.6533f, 0.3827f, -0.6533f,		//87
		0.3536f, 0.3827f, -0.8536f,		//88
		0.0f, 0.3827f, -0.9239f,		//89
		-0.3536f, 0.3827f, -0.8536f,	//90
		-0.6533f, 0.3827f, -0.6533f,	//91
		-0.8536f, 0.3827f, -0.3536f,	//92
		-0.9239f, 0.3827f, 0.0f,		//93
		-0.8536f, 0.3827f, 0.3536f,		//94
		-0.6533f, 0.3827f, 0.6533f,		//95
		-0.3536f, 0.3827f, 0.8536f,		//96
		// ring 7
		0.0f, 0.1951f, 0.9808f,			//97
		0.3753f, 0.1915f, 0.9061f,		//98
		0.6935f, 0.1915f, 0.6935f,		//99
		0.9061f, 0.1915f, 0.3753f,		//100
		0.9808f, 0.1915f, 0.0f,			//101
		0.9061f, 0.1915f, -0.3753f,		//102
		0.6935f, 0.1915f, -0.6935f,		//103
		0.3753f, 0.1915f, -0.9061f,		//104
		0.0f, 0.1915f, -0.9808f,		//105
		-0.3753f, 0.1915f, -0.9061f,	//106
		-0.6935f, 0.1915f, -0.6935f,	//107
		-0.9061f, 0.1915f, -0.3753f,	//108
		-0.9808f, 0.1915f, 0.0f,		//109
		-0.9061f, 0.1915f, 0.3753f,		//110
		-0.6935f, 0.1915f, 0.6935f,		//111
		-0.3753f, 0.1915f, 0.9061f,		//112
		// ring 8
		0.0f, 0.0f, 1.0f,				//113
		0.3827f, 0.0f, 0.9239f,			//114
		0.7071f, 0.0f, 0.7071f,			//115
		0.9239f, 0.0f, 0.3827f,			//116
		1.0f, 0.0f, 0.0f,				//117
		0.9239f, 0.0f, -0.3827f,		//118
		0.7071f, 0.0f, -0.7071f,		//119
		0.3827f, 0.0f, -0.9239f,		//120
		0.0f, 0.0f, -1.0f,				//121
		-0.3827f, 0.0f, -0.9239f,		//122
		-0.7071f, 0.0f, -0.7071f,		//123
		-0.9239f, 0.0f, -0.3827f,		//124
		-1.0f, 0.0f, 0.0f,				//125
		-0.9239f, 0.0f, 0.3827f,		//126
		-0.7071, 0.0, 0.7071f,			//127
		-0.3827f, 0.0f, 0.9239f,		//128
		// ring 9
		0.0f, -0.1915f, 0.9808f,		//129
		0.3753f, -0.1915f, 0.9061f,		//130
		0.6935f, -0.1915f, 0.6935f,		//131
		0.9061f, -0.1915f, 0.3753f,		//132
		0.9808f, -0.1915f, 0.0f,		//133
		0.9061f, -0.1915f, -0.3753f,	//134
		0.6935f, -0.1915f, -0.6935f,	//135
		0.3753f, -0.1915f, -0.9061f,	//136
		0.0f, -0.1915f, -0.9808f,		//137
		-0.3753f, -0.1915f, -0.9061f,	//138
		-0.6935f, -0.1915f, -0.6935f,	//139
		-0.9061f, -0.1915f, -0.3753f,	//140
		-0.9808f, -0.1915f, 0.0f,		//141
		-0.9061f, -0.1915f, 0.3753f,	//142
		-0.6935f, -0.1915f, 0.6935f,	//143
		-0.3753f, -0.1915f, 0.9061f,	//144
		// ring 10
		0.0f, -0.3827f, 0.9239f,		//145
		0.3536f, -0.3827f, 0.8536f,		//146
		0.6533f, -0.3827f, 0.6533f,		//147
		0.8536f, -0.3827f, 0.3536f,		//148
		0.9239f, -0.3827f, 0.0f,		//149
		0.8536f, -0.3827f, -0.3536f,	//150
		0.6533f, -0.3827f, -0.6533f,	//151
		0.3536f, -0.3827f, -0.8536f,	//152
		0.0f, -0.3827f, -0.9239f,		//153
		-0.3536f, -0.3827f, -0.8536f,	//154
		-0.6533f, -0.3827f, -0.6533f,	//155
		-0.8536f, -0.3827f, -0.3536f,	//156
		-0.9239f, -0.3827f, 0.0f,		//157
		-0.8536f, -0.3827f, 0.3536f,	//158
		-0.6533f, -0.3827f, 0.6533f,	//159
		-0.3536f, -0.3827f, 0.8536f,	//160
		// ring 11
		0.0f, -0.5556f, 0.8315f,		//161
		0.3182f, -0.5556f, 0.7682f,		//162
		0.5879f, -0.5556f, 0.5879f,		//163
		0.7682f, -0.5556f, 0.3182f,		//164
		0.8315f, -0.5556f, 0.0f,		//165
		0.7682f, -0.5556f, -0.3182f,	//166
		0.5879f, -0.5556f, -0.5879f,	//167
		0.3182f, -0.5556f, -0.7682f,	//168
		0.0f, -0.5556f, -0.8315f,		//169
		-0.3182f, -0.5556f, -0.7682f,	//170
		-0.5879f, 0.5556f, -0.5879f,	//171
		-0.7682f, -0.5556f, -0.3182f,	//172
		-0.8315f, -0.5556f, 0.0f,		//173
		-0.7682f, -0.5556f, 0.3182f,	//174
		-0.5879f, -0.5556f, 0.5879f,	//175
		-0.3182f, -0.5556f, 0.7682f,	//176
		// ring 12
		0.0f, -0.7071f, 0.7071f,		//177
		0.2706f, -0.7071f, 0.6533f,		//178
		0.5f, -0.7071f, 0.5f,			//179
		0.6533f, -0.7071f, 0.2706f,		//180
		0.7071f, -0.7071f, 0.0f,		//181
		0.6533f, -0.7071f, -0.2706f,	//182
		0.5f, -0.7071f, -0.5f,			//183
		0.2706f, -0.7071f, -0.6533f,	//184
		0.0f, -0.7071f, -0.7071f,		//185
		-0.2706f, -0.7071f, -0.6533f,	//186
		-0.5f, -0.7071f, -0.5f,			//187
		-0.6533f, -0.7071f, -0.2706f,	//188
		-0.7071f, -0.7071f, 0.0f,		//189
		-0.6533f, -0.7071f, 0.2706f,	//190
		-0.5f, -0.7071f, 0.5f,			//191
		-0.2706f, -0.7071f, 0.6533f,	//192
		// ring 13
		0.0f, -0.8315f, 0.5556f,		//193
		0.2126f, -0.8315f, 0.5133f,		//194
		0.3928f, -0.8315f, 0.3928f,		//195
		0.5133f, -0.8315f, 0.2126f,		//196
		0.5556f, -0.8315f, 0.0f,		//197
		0.5133f, -0.8315f, -0.2126f,	//198
		0.3928f, -0.8315f, -0.3928f,	//199
		0.2126f, -0.8315f, -0.5133f,	//200
		0.0f, -0.8315f, -0.5556f,		//201
		-0.2126f, -0.8315f, -0.5133f,	//202
		-0.3928f, -0.8315f, -0.3928f,	//203
		-0.5133f, -0.8315f, -0.2126f,	//204
		-0.5556f, -0.8315f, 0.0f,		//205
		-0.5133f, -0.8315f, 0.2126f,	//206
		-0.3928f, -0.8315f, 0.3928f,	//207
		-0.2126f, -0.8315f, 0.5133f,	//208
		// ring 14
		0.0f, -0.9239f, 0.3827f,		//209
		0.1464f, -0.9239f, 0.3536f,		//210
		0.2706f, -0.9239f, 0.2706f,		//211
		0.3536f, -0.9239f, 0.1464f,		//212
		0.3827f, -0.9239f, 0.0f,		//213
		0.3536f, -0.9239f, -0.1464f,	//214
		0.2706f, -0.9239f, -0.2706f,	//215
		0.1464f, -0.9239f, -0.3536f,	//216
		0.0f, -0.9239f, -0.3827f,		//217
		-0.1464f, -0.9239f, -0.3536f,	//218
		-0.2706f, -0.9239f, -0.2706f,	//219
		-0.3536f, -0.9239f, -0.1464f,	//220
		-0.3827f, -0.9239f, 0.0f,		//221
		-0.3536f, -0.9239f, 0.1464f,	//222
		-0.2706f, -0.9239f, 0.2706f,	//223
		-0.1464f, -0.9239f, 0.3536f,	//224
		// ring 15
		0.0f, -0.9808f, 0.1951f,		//225
		0.0747f, -0.9808f, 0.1802f,		//226
		0.1379f, -0.9808f, 0.1379f,		//227
		0.1802f, -0.9808f, 0.0747f,		//228
		0.1951f, -0.9808, 0.0f,			//229
		0.1802f, -0.9808f, -0.0747f,	//230
		0.1379f, -0.9808f, -0.1379f,	//231
		0.0747f, -0.9808f, -0.1802f,	//232
		0.0f, -0.9808f, -0.1951f,		//233
		-0.0747f, -0.9808f, -0.1802f,	//234
		-0.1379f, -0.9808f, -0.1379f,	//235
		-0.1802f, -0.9808f, -0.0747f,	//236
		-0.1951f, -0.9808, 0.0f,		//237
		-0.1802f, -0.9808f, 0.0747f,	//238
		-0.1379f, -0.9808f, 0.1379f,	//239
		-0.0747f, -0.9808f, 0.1802f,	//240
		// bottom center point
		0.0f, -1.0f, 0.0f,				//241
	};

	// index data
	GLuint indices[] = {
		//ring 1 - top
		0,1,2,
		0,2,3,
		0,3,4,
		0,4,5,
		0,5,6,
		0,6,7,
		0,7,8,
		0,8,9,
		0,9,10,
		0,10,11,
		0,11,12,
		0,12,13,
		0,13,14,
		0,14,15,
		0,15,16,
		0,16,1,

		// ring 1 to ring 2
		1,17,18,
		1,2,18,
		2,18,19,
		2,3,19,
		3,19,20,
		3,4,20,
		4,20,21,
		4,5,21,
		5,21,22,
		5,6,22,
		6,22,23,
		6,7,23,
		7,23,24,
		7,8,24,
		8,24,25,
		8,9,25,
		9,25,26,
		9,10,26,
		10,26,27,
		10,11,27,
		11,27,28,
		11,12,28,
		12,28,29,
		12,13,29,
		13,29,30,
		13,14,30,
		14,30,31,
		14,15,31,
		15,31,32,
		15,16,32,
		16,32,17,
		16,1,17,

		// ring 2 to ring 3
		17,33,34,
		17,18,34,
		18,34,35,
		18,19,35,
		19,35,36,
		19,20,36,
		20,36,37,
		20,21,37,
		21,37,38,
		21,22,38,
		22,38,39,
		22,23,39,
		23,39,40,
		23,24,40,
		24,40,41,
		24,25,41,
		25,41,42,
		25,26,42,
		26,42,43,
		26,27,43,
		27,43,44,
		27,28,44,
		28,44,45,
		28,29,45,
		29,45,46,
		29,30,46,
		30,46,47,
		30,31,47,
		31,47,48,
		31,32,48,
		32,48,33,
		32,17,33,

		// ring 3 to ring 4
		33,49,50,
		33,34,50,
		34,50,51,
		34,35,51,
		35,51,52,
		35,36,52,
		36,52,53,
		36,37,53,
		37,53,54,
		37,38,54,
		38,54,55,
		38,39,55,
		39,55,56,
		39,40,56,
		40,56,57,
		40,41,57,
		41,57,58,
		41,42,58,
		42,58,59,
		42,43,59,
		43,59,60,
		43,44,60,
		44,60,61,
		44,45,61,
		45,61,62,
		45,46,62,
		46,62,63,
		46,47,63,
		47,63,64,
		47,48,64,
		48,64,49,
		48,33,49,

		// ring 4 to ring 5
		49,65,66,
		49,50,66,
		50,66,67,
		50,51,67,
		51,67,68,
		51,52,68,
		52,68,69,
		52,53,69,
		53,69,70,
		53,54,70,
		54,70,71,
		54,55,71,
		55,71,72,
		55,56,72,
		56,72,73,
		56,57,73,
		57,73,74,
		57,58,74,
		58,74,75,
		58,59,75,
		59,75,76,
		59,60,76,
		60,76,77,
		60,61,77,
		61,77,78,
		61,62,78,
		62,78,79,
		62,63,79,
		63,79,80,
		63,64,80,
		64,80,65,
		64,49,65,

		// ring 5 to ring 6
		65,81,82,
		65,66,82,
		66,82,83,
		66,67,83,
		67,83,84,
		67,68,84,
		68,84,85,
		68,69,85,
		69,85,86,
		69,70,86,
		70,86,87,
		70,71,87,
		71,87,88,
		71,72,88,
		72,88,89,
		72,73,89,
		73,89,90,
		73,74,90,
		74,90,91,
		74,75,91,
		75,91,92,
		75,76,92,
		76,92,93,
		76,77,93,
		77,93,94,
		77,78,94,
		78,94,95,
		78,79,95,
		79,95,96,
		79,80,96,
		80,96,81,
		80,65,81,

		// ring 6 to ring 7
		81,97,98,
		81,82,98,
		82,98,99,
		82,83,99,
		83,99,100,
		83,84,100,
		84,100,101,
		84,85,101,
		85,101,102,
		85,86,102,
		86,102,103,
		86,87,103,
		87,103,104,
		87,88,104,
		88,104,105,
		88,89,105,
		89,105,106,
		89,90,106,
		90,106,107,
		90,91,107,
		91,107,108,
		91,92,108,
		92,108,109,
		92,93,109,
		93,109,110,
		93,94,110,
		94,110,111,
		94,95,111,
		95,111,112,
		95,96,112,
		96,112,97,
		96,81,97,

		// ring 7 to ring 8
		97,113,114,
		97,98,114,
		98,114,115,
		98,99,115,
		99,115,116,
		99,100,116,
		100,116,117,
		100,101,117,
		101,117,118,
		101,102,118,
		102,118,119,
		102,103,119,
		103,119,120,
		103,104,120,
		104,120,121,
		104,105,121,
		105,121,122,
		105,106,122,
		106,122,123,
		106,107,123,
		107,123,124,
		107,108,124,
		108,124,125,
		108,109,125,
		109,125,126,
		109,110,126,
		110,126,127,
		110,111,127,
		111,127,128,
		111,112,128,
		112,128,113,
		112,97,113,

		// ring 8 to ring 9
		113,129,130,
		113,114,130,
		114,130,131,
		114,115,131,
		115,131,132,
		115,116,132,
		116,132,133,
		116,117,133,
		117,133,134,
		117,118,134,
		118,134,135,
		118,119,135,
		119,135,136,
		119,120,136,
		120,136,137,
		120,121,137,
		121,137,138,
		121,122,138,
		122,138,139,
		122,123,139,
		123,139,140,
		123,124,140,
		124,140,141,
		124,125,141,
		125,141,142,
		125,126,142,
		126,142,143,
		126,127,143,
		127,143,144,
		127,128,144,
		128,144,129,
		128,113,129,

		// ring 9 to ring 10
		129,145,146,
		129,130,146,
		130,146,147,
		130,131,147,
		131,147,148,
		131,132,148,
		132,148,149,
		132,133,149,
		133,149,150,
		133,134,150,
		134,150,151,
		134,135,151,
		135,151,152,
		135,136,152,
		136,152,153,
		136,137,153,
		137,153,154,
		137,138,154,
		138,154,155,
		138,139,155,
		139,155,156,
		139,140,156,
		140,156,157,
		140,141,157,
		141,157,158,
		141,142,158,
		142,158,159,
		142,143,159,
		143,159,160,
		143,144,160,
		144,160,145,
		144,129,145,

		// ring 10 to ring 11
		145,161,162,
		145,146,162,
		146,162,163,
		146,147,163,
		147,163,164,
		147,148,164,
		148,164,165,
		148,149,165,
		149,165,166,
		149,150,166,
		150,166,167,
		150,151,167,
		151,167,168,
		151,152,168,
		152,168,169,
		152,153,169,
		153,169,170,
		153,154,170,
		154,170,171,
		154,155,171,
		155,171,172,
		155,156,172,
		156,172,173,
		156,157,173,
		157,173,174,
		157,158,174,
		158,174,175,
		158,159,175,
		159,175,176,
		159,160,176,
		160,176,161,
		160,145,161,

		// ring 11 to ring 12
		161,177,178,
		161,162,178,
		162,178,179,
		162,163,179,
		163,179,180,
		163,164,180,
		164,180,181,
		164,165,181,
		165,181,182,
		165,166,182,
		166,182,183,
		166,167,183,
		167,183,184,
		167,168,184,
		168,184,185,
		168,169,185,
		169,185,186,
		169,170,186,
		170,186,187,
		170,171,187,
		171,187,188,
		171,172,188,
		172,188,189,
		172,173,189,
		173,189,190,
		173,174,190,
		174,190,191,
		174,175,191,
		175,191,192,
		175,176,192,
		176,192,177,
		176, 161,177,

		// ring 12 to ring 13
		177,193,194,
		177,178,194,
		178,194,195,
		178,179,195,
		179,195,196,
		179,180,196,
		180,196,197,
		180,181,197,
		181,197,198,
		181,182,198,
		182,198,199,
		182,183,199,
		183,199,200,
		183,184,200,
		184,200,201,
		184,185,201,
		185,201,202,
		185,186,202,
		186,202,203,
		186,187,203,
		187,203,204,
		187,188,204,
		188,204,205,
		188,189,205,
		189,205,206,
		189,190,206,
		190,206,207,
		190,191,207,
		191,207,208,
		191,192,208,
		192,208,193,
		192,177,193,

		// ring 13 to ring 14
		193,209,210,
		193,194,210,
		194,210,211,
		194,195,211,
		195,211,212,
		195,196,212,
		196,212,213,
		196,197,213,
		197,213,214,
		197,198,214,
		198,214,215,
		198,199,215,
		199,215,216,
		199,200,216,
		200,216,217,
		200,201,217,
		201,217,218,
		201,202,218,
		202,218,219,
		202,203,219,
		203,219,220,
		203,204,220,
		204,220,221,
		204,205,221,
		205,221,222,
		205,206,222,
		206,222,223,
		206,207,223,
		207,223,224,
		207,208,224,
		208,224,209,
		208,193,209,

		// ring 14 to ring 15
		209,225,226,
		209,210,226,
		210,226,227,
		210,211,227,
		211,227,228,
		211,212,228,
		212,228,229,
		212,213,229,
		213,229,230,
		213,214,230,
		214,230,231,
		214,215,231,
		215,231,232,
		215,216,232,
		216,232,233,
		216,217,233,
		217,233,234,
		217,218,234,
		218,234,235,
		218,219,235,
		219,235,236,
		219,220,236,
		220,236,237,
		220,221,237,
		221,237,238,
		221,222,238,
		222,238,239,
		222,223,239,
		223,239,240,
		223,224,240,
		224,240,225,
		224,209,225,

		// ring 15 - bottom
		225,226,241,
		226,227,241,
		227,228,241,
		228,229,241,
		229,239,241,
		230,231,241,
		231,232,241,
		232,233,241,
		233,234,241,
		234,235,241,
		235,236,241,
		236,237,241,
		237,238,241,
		238,239,241,
		239,240,241,
		240,225,241
	};

	// total float values per each type
	const GLuint floatsPerVertex = 3;
	const GLuint floatsPerNormal = 3;
	const GLuint floatsPerUV = 2;

	// store vertex and index count
	mesh.nVertices = sizeof(verts) / (sizeof(verts[0]) * (floatsPerVertex));
	mesh.nIndices = sizeof(indices) / (sizeof(indices[0]));
	mesh.shapeCase = 'F';

	glm::vec3 normal;
	glm::vec3 vert;
	glm::vec3 center(0.0f, 0.0f, 0.0f);
	float u, v;
	std::vector<GLfloat> combined_values;

	// combine interleaved vertices, normals, and texture coords
	for (int i = 0; i < sizeof(verts) / (sizeof(verts[0])); i += 3)
	{
		vert = glm::vec3(verts[i], verts[i + 1], verts[i + 2]);
		normal = normalize(vert - center);
		u = atan2(normal.x, normal.z) / (2 * M_PI) + 0.5;
		v = normal.y * 0.5 + 0.5;
		combined_values.push_back(vert.x);
		combined_values.push_back(vert.y);
		combined_values.push_back(vert.z);
		combined_values.push_back(normal.x);
		combined_values.push_back(normal.y);
		combined_values.push_back(normal.z);
		combined_values.push_back(u);
		combined_values.push_back(v);
	}

	// Create VAO
	glGenVertexArrays(1, &mesh.vao); // we can also generate multiple VAOs or buffers at the same time
	glBindVertexArray(mesh.vao);

	// Create VBOs
	glGenBuffers(2, mesh.vbos);
	glBindBuffer(GL_ARRAY_BUFFER, mesh.vbos[0]); // Activates the vertex buffer
	glBufferData(GL_ARRAY_BUFFER, sizeof(GLfloat) * combined_values.size(), combined_values.data(), GL_STATIC_DRAW); // Sends vertex or coordinate data to the GPU

	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, mesh.vbos[1]); // Activates the index buffer
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);

	// Strides between vertex coordinates
	GLint stride = sizeof(float) * (floatsPerVertex + floatsPerNormal + floatsPerUV);

	// Create Vertex Attribute Pointers
	glVertexAttribPointer(0, floatsPerVertex, GL_FLOAT, GL_FALSE, stride, 0);
	glEnableVertexAttribArray(0);

	glVertexAttribPointer(1, floatsPerNormal, GL_FLOAT, GL_FALSE, stride, (void*)(sizeof(float) * floatsPerVertex));
	glEnableVertexAttribArray(1);

	glVertexAttribPointer(2, floatsPerUV, GL_FLOAT, GL_FALSE, stride, (void*)(sizeof(float) * (floatsPerVertex + floatsPerNormal)));
	glEnableVertexAttribArray(2);

	//scale the object
	mesh.scale = glm::scale(glm::vec3(mesh.p[4], mesh.p[5], mesh.p[6]));

	const glm::mat4 rot = glm::mat4(1.0f);

	// rotate the object (x, y, z) (0 - 6.4, to the right)
	mesh.xrotation = glm::rotate(rot, glm::radians(mesh.p[7]), glm::vec3(mesh.p[8], mesh.p[9], mesh.p[10]));
	mesh.yrotation = glm::rotate(rot, glm::radians(mesh.p[11]), glm::vec3(mesh.p[12], mesh.p[13], mesh.p[14]));
	mesh.zrotation = glm::rotate(rot, glm::radians(mesh.p[15]), glm::vec3(mesh.p[16], mesh.p[17], mesh.p[18]));


	// move the object (x, y, z)
	mesh.translation = glm::translate(glm::vec3(mesh.p[19], mesh.p[20], mesh.p[21]));

	mesh.model = mesh.translation * mesh.xrotation * mesh.zrotation * mesh.yrotation * mesh.scale;

	mesh.gUVScale = glm::vec2(mesh.p[22], mesh.p[23]);
}




void BuildShape::UTranslator(GLMesh& mesh)
{
	constexpr GLuint floatsPerVertex = 3;
	constexpr GLuint floatsPerColor = 4;
	constexpr GLuint floatsPerUV = 2;


	mesh.nIndices = mesh.v.size() / (floatsPerVertex + floatsPerUV + floatsPerColor);

	glGenVertexArrays(1, &mesh.vao);
	glBindVertexArray(mesh.vao);

	//Create VBO
	glGenBuffers(1, &mesh.vbo);
	glBindBuffer(GL_ARRAY_BUFFER, mesh.vbo);	//Activates the buffer

	//use vector instead of array
	glBufferData(
		GL_ARRAY_BUFFER,
		mesh.v.size() * sizeof(float),
		&mesh.v.front(),
		GL_STATIC_DRAW
	);


	// Sends vertex or coordinate data to the GPU
	// Strides between vertex coordinates
	constexpr GLint stride = sizeof(float) * (floatsPerVertex + floatsPerUV + floatsPerColor);

	// Create Vertex Attribute Pointers
	glVertexAttribPointer(0, floatsPerVertex, GL_FLOAT, GL_FALSE, stride, (void*)0);
	glEnableVertexAttribArray(0);
	glVertexAttribPointer(1, floatsPerColor, GL_FLOAT, GL_FALSE, stride, (void*)(3 * sizeof(float)));
	glEnableVertexAttribArray(1);
	glVertexAttribPointer(2, floatsPerUV, GL_FLOAT, GL_FALSE, stride, (void*)(7 * sizeof(float)));
	glEnableVertexAttribArray(2);

	if (UBoxMesh) 
		mesh.shapeCase = 'A';
	
	if (UBottleMesh)
		mesh.shapeCase = 'B';
	
	if (UCylinderMesh) 
		mesh.shapeCase = 'C';
	
	if (UPlaneMesh) 
		mesh.shapeCase = 'D';
		

	//scale the object
	mesh.scale = glm::scale(glm::vec3(mesh.p[4], mesh.p[5], mesh.p[6]));

	const glm::mat4 rot = glm::mat4(1.0f);

	// rotate the object (x, y, z) (0 - 6.4, to the right)
	mesh.xrotation = glm::rotate(rot, glm::radians(mesh.p[7]), glm::vec3(mesh.p[8], mesh.p[9], mesh.p[10]));
	mesh.yrotation = glm::rotate(rot, glm::radians(mesh.p[11]), glm::vec3(mesh.p[12], mesh.p[13], mesh.p[14]));
	mesh.zrotation = glm::rotate(rot, glm::radians(mesh.p[15]), glm::vec3(mesh.p[16], mesh.p[17], mesh.p[18]));


	// move the object (x, y, z)
	mesh.translation = glm::translate(glm::vec3(mesh.p[19], mesh.p[20], mesh.p[21]));

	mesh.model = mesh.translation * mesh.xrotation * mesh.zrotation * mesh.yrotation * mesh.scale;

	mesh.gUVScale = glm::vec2(mesh.p[22], mesh.p[23]);
	//mesh.gUVScale = glm::vec2(2.0, 2.0f);

	
}

