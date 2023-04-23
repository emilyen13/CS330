#include "buildShape.h"
#include "meshes (1).h"
#include "buildScene.h"

//image
#define STB_IMAGE_IMPLEMENTATION
#include "stb_image.h" 


/*shader program macro*/
#ifndef GLSL
#define GLSL(Version, Source) "#version " #Version " core \n" #Source
#endif

//standard namespace
using namespace std;

//macro for window title - specified window title
const char* const WINDOW_TITLE = "Nagorski - CS330";

//variable for windwo width & height 
const int WINDOW_WIDTH = 800;
const int WINDOW_HEIGHT = 600;

struct GLightMesh {
	GLuint vao;
	GLuint vbo;
	GLuint nVertices;
};

//light programs
GLightMesh fillLightMesh;
GLightMesh keyLightMesh;

BuildShape builder;

//main GLFW window
GLFWwindow* gWindow = nullptr;

//shader programs
GLuint gShaderProgram;
GLuint gLightProgramId;

//scene vector for drawing shapes
vector<GLMesh> scene;

//variable for perspective change (perspective default, can change to ortho)
bool perspective = false;

//camera
Camera gCamera(glm::vec3(0.0f, 3.5f, 8.0f), glm::vec3(0.0f, 1.0f, 0.0f), -90.0f, -25.0f);
float lastX = WINDOW_WIDTH / 2.0f;
float lastY = WINDOW_HEIGHT / 2.0f;
bool firstMouse = true;

//time
float deltaTime = 0.0f;
float lastFrame = 0.0f;


/* User-defined function prototypes to: initialize the program,
set the window size, redraw graphics on the window when
resized, and render graphics on the scene*/

bool UInitialize(int, char* [], GLFWwindow** window);												  	 //initialize program
void UResizeWindow(GLFWwindow* window, int width, int height);											 //set window size
void UProcessInput(GLFWwindow* window);																	 //process user input
void URender(vector<GLMesh> scene);																		 //render graphics
bool UCreateShaderProgram(const char* vtxShaderSource, const char* fragShaderSource, GLuint& programId); //compile shaders
void UDestroyTextureProgram(GLuint textureId);
void UDestroyMesh(GLMesh& mesh);
void UDestroyShaderProgram(GLuint programId);


//keyboard/mouse input functions
void UMouseCallback(GLFWwindow* window, double xpos, double ypos);
void UMouseScrollCallback(GLFWwindow* window, double xoffset, double yoffset);

//function for texture
bool UCreateTextureProgram(const char* filename, GLuint& textureId);
//function for light mesh
void UCreateLightMesh(GLightMesh& lightMesh);


///////////////////////////////////////////////////////////////////////////////////////////////////////
/* Surface Vertex Shader Source Code*/
const GLchar* surfaceVertexShaderSource = GLSL(440,


	layout(location = 0) in vec3 vertexPosition;		// VAP position 0 for vertex position data
	layout(location = 1) in vec3 vertexNormal;			// VAP position 1 for normals
	layout(location = 2) in vec2 textureCoordinate;
	
	out vec3 vertexFragmentNormal;						// For outgoing normals to fragment shader
	out vec3 vertexFragmentPos;							// For outgoing color / pixels to fragment shader
	out vec2 vertexTextureCoordinate;
	
	//Uniform / Global variables for the  transform matrices
	uniform mat4 model;
	uniform mat4 view;
	uniform mat4 projection;

void main()
{
	gl_Position = projection * view * model * vec4(vertexPosition, 1.0f);	// Transforms vertices into clip coordinates

	vertexFragmentPos = vec3(model * vec4(vertexPosition, 1.0f));			// Gets fragment / pixel position in world space only (exclude view and projection)

	vertexFragmentNormal = mat3(transpose(inverse(model))) * vertexNormal;	// get normal vectors in world space only and exclude normal translation properties
	vertexTextureCoordinate = textureCoordinate;
}
);

////////////////////////////////////////////////////////////////////////////////////////////////////////
/* Surface Fragment Shader Source Code*/
const GLchar* surfaceFragmentShaderSource = GLSL(440,


	in vec3 vertexFragmentNormal;		// For incoming normals
	in vec3 vertexFragmentPos;			// For incoming fragment position
	in vec2 vertexTextureCoordinate;

	out vec4 fragmentColor;				// For outgoing cube color to the GPU

	// Uniform / Global variables for object color, light color, light position, and camera/view position
	uniform vec4 objectColor;
	uniform vec3 ambientColor;
	uniform vec3 light1Color;
	uniform vec3 light1Position;
	uniform vec3 light2Color;
	uniform vec3 light2Position;
	uniform vec3 viewPosition;
	uniform sampler2D uTexture;				// Useful when working with multiple textures
	uniform vec2 uvScale;
	uniform bool ubHasTexture;
	uniform float ambientStrength = 1.0f;	// Set ambient or global lighting strength
	uniform float specularIntensity1 = 0.8f;
	uniform float highlightSize1 = 1.0f;
	uniform float specularIntensity2 = 0.8f;
	uniform float highlightSize2 = 1.0f;



void main()
{

	//Calculate Ambient lighting
	vec3 ambient = ambientStrength * ambientColor; // Generate ambient light color

	//**Calculate Diffuse lighting**
	vec3 norm = normalize(vertexFragmentNormal); // Normalize vectors to 1 unit
	vec3 light1Direction = normalize(light1Position - vertexFragmentPos); // Calculate distance (light direction) between light source and fragments/pixels on cube
	float impact1 = max(dot(norm, light1Direction), 0.0);// Calculate diffuse impact by generating dot product of normal and light
	vec3 diffuse1 = impact1 * light1Color; // Generate diffuse light color
	vec3 light2Direction = normalize(light2Position - vertexFragmentPos); // Calculate distance (light direction) between light source and fragments/pixels on cube
	float impact2 = max(dot(norm, light2Direction), 0.0);// Calculate diffuse impact by generating dot product of normal and light
	vec3 diffuse2 = impact2 * light2Color; // Generate diffuse light color

	//**Calculate Specular lighting**
	vec3 viewDir = normalize(viewPosition - vertexFragmentPos); // Calculate view direction
	vec3 reflectDir1 = reflect(-light1Direction, norm);// Calculate reflection vector
	//Calculate specular component
	float specularComponent1 = pow(max(dot(viewDir, reflectDir1), 0.0), highlightSize1);
	vec3 specular1 = specularIntensity1 * specularComponent1 * light1Color;
	vec3 reflectDir2 = reflect(-light2Direction, norm);// Calculate reflection vector
	//Calculate specular component
	float specularComponent2 = pow(max(dot(viewDir, reflectDir2), 0.0), highlightSize2);
	vec3 specular2 = specularIntensity2 * specularComponent2 * light2Color;

	//**Calculate phong result**
	//Texture holds the color to be used for all three components
	vec4 textureColor = texture(uTexture, vertexTextureCoordinate * uvScale);
	vec3 phong1;
	vec3 phong2;

	if (ubHasTexture == true)
	{
		phong1 = (ambient + diffuse1 + specular1) * textureColor.xyz;
		phong2 = (ambient + diffuse2 + specular2) * textureColor.xyz;
	}
	else
	{
		phong1 = (ambient + diffuse1 + specular1) * objectColor.xyz;
		phong2 = (ambient + diffuse2 + specular2) * objectColor.xyz;
	}

	fragmentColor = vec4(phong1 + phong2, 1.0); // Send lighting results to GPU
}
);

/////////////////////////////////////////////////////////////////////////////////////////////////////////
/* Light Object Shader Source Code*/
const GLchar* lightVertexShaderSource = GLSL(330,


	layout(location = 0) in vec3 position; // VAP position 0 for vertex position data

	uniform mat4 model;
	uniform mat4 view;
	uniform mat4 projection;

void main()
{
	gl_Position = projection * view * model * vec4(position, 1.0); //transforms vertices to clip coordinates
}
);

/////////////////////////////////////////////////////////////////////////////////////////////////////////
/* Light Object Fragment Source Code*/
const GLchar* lightFragmentShaderSource = GLSL(330,

	out vec4 fragmentColor;


void main()
{
	fragmentColor = vec4(1.0);		// set all 4 vector values to 1.0
}
);


//Images are loaded with Y axis going down, but opengl's Y axis goes up, this will flip it
void flipImageVertically(unsigned char* image, int width, int height, int channels)
{
	for (int j = 0; j < height / 2; ++j)
	{
		int index1 = j * width * channels;
		int index2 = (height - 1 - j) * width * channels;

		for (int i = width * channels; i > 0; --i)
		{
			unsigned char tmp = image[index1];
			image[index1] = image[index2];
			image[index2] = tmp;
			++index1;
			++index2;
		}
	}
}


//main function, entry point to OpenGl program
int main(int argc, char* argv[])
{
	if (!UInitialize(argc, argv, &gWindow))
		return EXIT_FAILURE;

	//build scene
	BuildScene::UBuildScene(scene);

	//create the shader programs
	if (!UCreateShaderProgram(surfaceVertexShaderSource, surfaceFragmentShaderSource, gShaderProgram))
		return EXIT_FAILURE;

	if (!UCreateShaderProgram(lightVertexShaderSource, lightFragmentShaderSource, gLightProgramId))
		return EXIT_FAILURE;

	//load textures
	for (auto& m : scene)
	{
		if (!UCreateTextureProgram(m.texFilename, m.textureId))
		{
			cout << "Texture failure: " << m.texFilename << endl;
			return EXIT_FAILURE;
		}
	}

	// create light objects
	UCreateLightMesh(fillLightMesh);
	UCreateLightMesh(keyLightMesh);

	//tell opengl for each sampler to which texture unit it belongs to (only has to be done once)
	glUseProgram(gShaderProgram);
	//We set the texture as texture unit 0 
	glUniform1i(glGetUniformLocation(gShaderProgram, "uTexture"), 0);
	

	//render loop, verify window has not yet closed
	while (!glfwWindowShouldClose(gWindow))
	{
		//sets the background color of the window to light blue (it will be implicitely used by glClear) 
		glClearColor(0.9f, 0.95f, 1.0f, 1.0);

		float currentFrame = glfwGetTime();
		deltaTime = currentFrame - lastFrame;
		lastFrame = currentFrame;

		UProcessInput(gWindow);				//process input
		URender(scene);						//render frame

		glfwPollEvents();
	}

	//release mesh data
	for (auto& m : scene)
	{
		UDestroyMesh(m);
	}

	scene.clear();
	UDestroyShaderProgram(gShaderProgram);
	UDestroyShaderProgram(gLightProgramId);

	//terminates the program successfully
	exit(EXIT_SUCCESS);

}

//Initialize GLFW, GLEW, and create a window
bool UInitialize(int argc, char* argv[], GLFWwindow** window)
{
	//GLFW: initialize and configure
	glfwInit();
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 4);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

	//GLFW: window creation
	*window = glfwCreateWindow(WINDOW_WIDTH, WINDOW_HEIGHT, WINDOW_TITLE, NULL, NULL);
	if (*window == NULL)
	{
		std::cout << "Failed to create GLFW window" << std::endl;
		glfwTerminate();
		return false;
	}

	glfwMakeContextCurrent(*window);
	glfwSetFramebufferSizeCallback(*window, UResizeWindow);
	glfwSetCursorPosCallback(*window, UMouseCallback);
	glfwSetScrollCallback(*window, UMouseScrollCallback);
	glfwSetInputMode(*window, GLFW_CURSOR, GLFW_CURSOR_DISABLED);

	//GLEW: initialize
	glewExperimental = GL_TRUE;
	GLenum GlewInitResult = glewInit();

	if (GLEW_OK != GlewInitResult)
	{
		std::cerr << glewGetErrorString(GlewInitResult) << std::endl;
		return false;
	}

	return true;
}

//implemnts the UCreateShader function
bool UCreateShaderProgram(const char* vtxShaderSource, const char* fragShaderSource, GLuint& programId)
{
	//compilation and linkage error reporting
	int success = 0;
	char infoLog[512];

	//create shader program object
	programId = glCreateProgram();

	//create vertex and frag shader objects
	GLuint vertexShaderId = glCreateShader(GL_VERTEX_SHADER);
	GLuint fragmentShaderId = glCreateShader(GL_FRAGMENT_SHADER);

	//retrieve shader source
	glShaderSource(vertexShaderId, 1, &vtxShaderSource, NULL);
	glShaderSource(fragmentShaderId, 1, &fragShaderSource, NULL);

	//compile vertex shader and print compilation errors (if any)
	glCompileShader(vertexShaderId);

	//check for shader compile errors
	glGetShaderiv(vertexShaderId, GL_COMPILE_STATUS, &success);
	if (!success)
	{
		glGetShaderInfoLog(vertexShaderId, 512, NULL, infoLog);
		std::cout << "ERROR::SHADER::VERTEX::COMPILATION_FAILED\n" << infoLog << std::endl;

		return false;
	}

	//compile frag shader
	glCompileShader(fragmentShaderId);

	//check for errors
	glGetShaderiv(fragmentShaderId, GL_COMPILE_STATUS, &success);
	if (!success)
	{
		glGetShaderInfoLog(fragmentShaderId, sizeof(infoLog), NULL, infoLog);
		std::cout << "ERROR::SHADER::FRAGMENT::COMPILATION_FAILED\n" << infoLog << std::endl;

		return false;
	}

	//shaders compiled, attach to shader program object from above
	glAttachShader(programId, vertexShaderId);
	glAttachShader(programId, fragmentShaderId);

	//link the program object
	glLinkProgram(programId);

	//check for linking errors
	glGetProgramiv(programId, GL_LINK_STATUS, &success);
	if (!success)
	{
		glGetProgramInfoLog(programId, sizeof(infoLog), NULL, infoLog);
		std::cout << "ERROR::SHADER::PROGRAM::LINKING_FAILED\n" << infoLog << std::endl;

		return false;
	}

	//uses the shader program
	glUseProgram(programId);
	return true;
}

//process all keyboard input for horizontal, vertaical, depth and ortho/perscpective movemnent
void UProcessInput(GLFWwindow* window)
{

	if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
		glfwSetWindowShouldClose(window, true);

	if (glfwGetKey(window, GLFW_KEY_E) == GLFW_PRESS)
		gCamera.ProcessKeyboard(UP, deltaTime);
	if (glfwGetKey(window, GLFW_KEY_Q) == GLFW_PRESS)
		gCamera.ProcessKeyboard(DOWN, deltaTime);
	if (glfwGetKey(window, GLFW_KEY_W) == GLFW_PRESS)
		gCamera.ProcessKeyboard(FORWARD, deltaTime);
	if (glfwGetKey(window, GLFW_KEY_S) == GLFW_PRESS)
		gCamera.ProcessKeyboard(BACKWARD, deltaTime);
	if (glfwGetKey(window, GLFW_KEY_A) == GLFW_PRESS)
		gCamera.ProcessKeyboard(LEFT, deltaTime);
	if (glfwGetKey(window, GLFW_KEY_D) == GLFW_PRESS)
		gCamera.ProcessKeyboard(RIGHT, deltaTime);


	if (glfwGetKey(window, GLFW_KEY_P) == GLFW_PRESS)
		perspective = false;
	if (glfwGetKey(window, GLFW_KEY_O) == GLFW_PRESS)
		perspective = true;

}

//glfw: whenever the window size changes (by OS or user rize) this callback function executes
void UResizeWindow(GLFWwindow* window, int width, int height)
{
	glViewport(0, 0, width, height);
}

//mouse movement callback
void UMouseCallback(GLFWwindow* window, double xpos, double ypos)
{
	if (firstMouse)
	{
		lastX = xpos;
		lastY = ypos;
		firstMouse = false;
	}

	float xoffset = xpos - lastX;
	float yoffset = lastY - ypos; //reversed since y-coordinates go from bottom to top

	lastX = xpos;
	lastY = ypos;

	gCamera.ProcessMouseMovement(xoffset, yoffset);
}

//mouse scroll callback
void UMouseScrollCallback(GLFWwindow* window, double xoffset, double yoffset)
{
	gCamera.ProcessMouseScroll(yoffset);
}

//function called to render the scene
void URender(vector<GLMesh> scene)
{
	GLint modelLoc;
	GLint viewLoc;
	GLint projLoc;
	GLint viewPosLoc;
	GLint ambStrLoc;
	GLint ambColLoc;
	GLint light1ColLoc;
	GLint light1PosLoc;
	GLint light2ColLoc;
	GLint light2PosLoc;
	GLint objColLoc;
	GLint specInt1Loc;
	GLint highlghtSz1Loc;
	GLint specInt2Loc;
	GLint highlghtSz2Loc;
	GLint uHasTextureLoc;
	bool ubHasTextureVal;
	glm::mat4 scale;
	glm::mat4 rotation;
	glm::mat4 translation;
	glm::mat4 model;
	glm::mat4 view;

	//Enable z-depth
	glEnable(GL_DEPTH_TEST);
	// Clear the background
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	view = gCamera.GetViewMatrix();

	// Retrieves and passes transform matrices to the Shader program
	viewPosLoc = glGetUniformLocation(gShaderProgram, "viewPosition");
	ambStrLoc = glGetUniformLocation(gShaderProgram, "ambientStrength");
	ambColLoc = glGetUniformLocation(gShaderProgram, "ambientColor");
	light1ColLoc = glGetUniformLocation(gShaderProgram, "light1Color");
	light1PosLoc = glGetUniformLocation(gShaderProgram, "light1Position");
	light2ColLoc = glGetUniformLocation(gShaderProgram, "light2Color");
	light2PosLoc = glGetUniformLocation(gShaderProgram, "light2Position");
	objColLoc = glGetUniformLocation(gShaderProgram, "objectColor");
	specInt1Loc = glGetUniformLocation(gShaderProgram, "specularIntensity1");
	highlghtSz1Loc = glGetUniformLocation(gShaderProgram, "highlightSize1");
	specInt2Loc = glGetUniformLocation(gShaderProgram, "specularIntensity2");
	highlghtSz2Loc = glGetUniformLocation(gShaderProgram, "highlightSize2");
	uHasTextureLoc = glGetUniformLocation(gShaderProgram, "ubHasTexture");


	//set ambient lighting strength : lighting source one
	glUniform1f(ambStrLoc, 0.3f);
	//set ambient color
	glUniform3f(ambColLoc, 1.0f, 1.0f, 1.0f);
	glUniform3f(light1ColLoc, 0.7f, 0.5f, 0.5f);	//pink light - fufilling colored light requirement
	glUniform3f(light1PosLoc, -1.0f, 1.0f, -1.0f);
	glUniform3f(light2ColLoc, 0.5f, 0.5f, 0.7f);
	glUniform3f(light2PosLoc, 1.0f, 10.0f, 20.0f);
	//set specular intensity
	glUniform1f(specInt1Loc, 0.01f);
	glUniform1f(specInt2Loc, 0.01f);
	//set specular highlight size
	glUniform1f(highlghtSz1Loc, 0.05f);
	glUniform1f(highlghtSz2Loc, 0.05f);

	ubHasTextureVal = true;
	glUniform1i(uHasTextureLoc, ubHasTextureVal);


	//default perspective view
	glm::mat4 projection;
	if (!perspective)
	{
		//perspcetive
		projection = glm::perspective(glm::radians(gCamera.Zoom), (GLfloat)WINDOW_WIDTH / (GLfloat)WINDOW_HEIGHT, 0.1f, 100.0f);
	}
	else
		//orthographic for use by user input
		projection = glm::ortho(-5.0f, 5.0f, -5.0f, 5.0f, 0.1f, 100.0f);


	//draw shape -> loop through each shape mesh
	for (auto i = 0; i < scene.size(); ++i)
	{
		auto mesh = scene[i];

	
		//set the shader to be used
		glUseProgram(gShaderProgram);

		//retrieves and passes transform matrices to the shader program
		modelLoc = glGetUniformLocation(gShaderProgram, "model");
		viewLoc = glGetUniformLocation(gShaderProgram, "view");
		projLoc = glGetUniformLocation(gShaderProgram, "projection");


		glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(mesh.model));
		glUniformMatrix4fv(viewLoc, 1, GL_FALSE, glm::value_ptr(view));
		glUniformMatrix4fv(projLoc, 1, GL_FALSE, glm::value_ptr(projection));

		GLint UVScaleLoc = glGetUniformLocation(gShaderProgram, "uvScale");
		glUniform2fv(UVScaleLoc, 1, glm::value_ptr(mesh.gUVScale));

		//activate the VBOs contained within the mesh's VAO
		glBindVertexArray(mesh.vao);

		glActiveTexture(GL_TEXTURE0);
		glBindTexture(GL_TEXTURE_2D, mesh.textureId);

		// Draws the triangles for each shape
		
		switch (mesh.shapeCase) {
		case 'A' :
			glDrawArrays(GL_TRIANGLES, 0, mesh.nIndices);
			break;

		case 'B' :
			glDrawArrays(GL_TRIANGLES, 0, mesh.nIndices);
			break;

		case 'C' :
			glDrawArrays(GL_TRIANGLES, 0, mesh.nIndices);
			glDrawArrays(GL_TRIANGLE_FAN, 0, 36);
			glDrawArrays(GL_TRIANGLE_FAN, 36, 36);
			glDrawArrays(GL_TRIANGLE_STRIP, 72, 146);
			break;

		case 'D' :
			glDrawArrays(GL_TRIANGLES, 0, mesh.nIndices);
			break;

		case 'E' :
			glDrawArrays(GL_TRIANGLES, 0, mesh.nIndices);
			glDrawArrays(GL_TRIANGLES, 0, mesh.nVertices);
			break;

		case 'F' :
			glDrawArrays(GL_TRIANGLES, 0, mesh.nIndices);
			glDrawElements(GL_TRIANGLES, mesh.nIndices, GL_UNSIGNED_INT, (void*)0);
			break;

		default :
			glDrawArrays(GL_TRIANGLES, 0, mesh.nIndices);
			
		}
		glDrawArrays(GL_TRIANGLE_FAN, 0, 36);
		glDrawArrays(GL_TRIANGLE_FAN, 36, 36);
		glDrawArrays(GL_TRIANGLE_STRIP, 72, 146);
			

	}

	//lighting source two - colored light
	// Set the shader to be used
	glUseProgram(gLightProgramId);
	// Activate the VBOs contained within the mesh's VAO
	glBindVertexArray(fillLightMesh.vao);
	

	modelLoc = glGetUniformLocation(gLightProgramId, "model");
	viewLoc = glGetUniformLocation(gLightProgramId, "view");
	projLoc = glGetUniformLocation(gLightProgramId, "projection");

	// Retrieves and passes transform matrices to the Shader program
	
	glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(model));
	glUniformMatrix4fv(viewLoc, 1, GL_FALSE, glm::value_ptr(view));
	glUniformMatrix4fv(projLoc, 1, GL_FALSE, glm::value_ptr(projection));

	// 1. Scales the object
	scale = glm::scale(glm::vec3(0.4f, 0.4f, 0.4f));
	// 2. Rotates shape on the x axis
	rotation = glm::rotate(-0.2f, glm::vec3(1.0, 0.0f, 0.0f));
	// 3. Moves shape with respect to the origin
	translation = glm::translate(glm::vec3(-2.0f, 1.0f, -1.0f));
	// Model matrix: transformations are applied right-to-left order
	model = translation * rotation * scale;

	glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(model));

	glDrawArrays(GL_TRIANGLE_STRIP, 0, fillLightMesh.nVertices);


	//lighting source three
	glBindVertexArray(keyLightMesh.vao);

	modelLoc = glGetUniformLocation(gLightProgramId, "model");
	viewLoc = glGetUniformLocation(gLightProgramId, "view");
	projLoc = glGetUniformLocation(gLightProgramId, "projection");

	// Retrieves and passes transform matrices to the Shader program

	glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(model));
	glUniformMatrix4fv(viewLoc, 1, GL_FALSE, glm::value_ptr(view));
	glUniformMatrix4fv(projLoc, 1, GL_FALSE, glm::value_ptr(projection));

	// Retrieves and passes transform matrices to the Shader program
	// 1. Scales the object
	scale = glm::scale(glm::vec3(0.4f, 0.4f, 0.4f));
	// 2. Rotates shape on the x axis
	rotation = glm::rotate(-0.2f, glm::vec3(1.0, 0.0f, 0.0f));
	// 3. Moves shape with respect to the origin
	translation = glm::translate(glm::vec3(2.0f, 3.0f, -1.0f));
	// Model matrix: transformations are applied right-to-left order
	model = translation * rotation * scale;

	glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(model));

	glDrawArrays(GL_TRIANGLE_STRIP, 0, keyLightMesh.nVertices);


	// Deactivate the Vertex Array Object
	glBindVertexArray(0);
	glUseProgram(0);

	//glfw: swap buffers and poll IO events (keys pressed/released, mouse moved etc.)
	glfwSwapBuffers(gWindow);		//flips the back buffer with the front buffer every frame
}


void UDestroyMesh(GLMesh& mesh)
{
	glDeleteVertexArrays(1, &mesh.vao);
	glDeleteBuffers(1, &mesh.vbo);
}
void UDestroyShaderProgram(GLuint programId)
{
	glDeleteProgram(programId);
}

//generate and load the texture
bool UCreateTextureProgram(const char* filename, GLuint& textureId)
{
	int width, height, channels;
	unsigned char* image = stbi_load(filename, &width, &height, &channels, 0);
	if (image)
	{
		flipImageVertically(image, width, height, channels);

		glGenTextures(1, &textureId);
		glBindTexture(GL_TEXTURE_2D, textureId);

		// set the texture wrapping parameters
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
		// set texture filtering parameters
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

		if (channels == 3)
			glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB8, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, image);
		else if (channels == 4)
			glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA8, width, height, 0, GL_RGBA, GL_UNSIGNED_BYTE, image);
		else
		{
			cout << "Not implemented to handle image with " << channels << " channels" << endl;
			return false;
		}

		glGenerateMipmap(GL_TEXTURE_2D);

		stbi_image_free(image);
		glBindTexture(GL_TEXTURE_2D, 0); // Unbind the texture

		return true;
	}

	// Error loading the image
	return false;
}
void UDestroyTextureProgram(GLuint textureId)
{
	glGenTextures(1, &textureId);
}

void UCreateLightMesh(GLightMesh& lightMesh)
{
	// Position and Color data
	GLfloat verts[] = {
		//Positions          //Normals
		// ------------------------------------------------------
		 //Back Face          //Negative Z Normal  Texture Coords.
		-0.5f, -0.5f, -0.5f,  0.0f,  0.0f, -1.0f,  0.0f, 0.0f,
		 0.5f, -0.5f, -0.5f,  0.0f,  0.0f, -1.0f,  1.0f, 0.0f,
		 0.5f,  0.5f, -0.5f,  0.0f,  0.0f, -1.0f,  1.0f, 1.0f,
		 0.5f,  0.5f, -0.5f,  0.0f,  0.0f, -1.0f,  1.0f, 1.0f,
		-0.5f,  0.5f, -0.5f,  0.0f,  0.0f, -1.0f,  0.0f, 1.0f,
		-0.5f, -0.5f, -0.5f,  0.0f,  0.0f, -1.0f,  0.0f, 0.0f,

		  //Front Face         //Positive Z Normal
		 -0.5f, -0.5f,  0.5f,  0.0f,  0.0f,  1.0f,  0.0f, 0.0f,
		  0.5f, -0.5f,  0.5f,  0.0f,  0.0f,  1.0f,  1.0f, 0.0f,
		  0.5f,  0.5f,  0.5f,  0.0f,  0.0f,  1.0f,  1.0f, 1.0f,
		  0.5f,  0.5f,  0.5f,  0.0f,  0.0f,  1.0f,  1.0f, 1.0f,
		 -0.5f,  0.5f,  0.5f,  0.0f,  0.0f,  1.0f,  0.0f, 1.0f,
		 -0.5f, -0.5f,  0.5f,  0.0f,  0.0f,  1.0f,  0.0f, 0.0f,

		  //Left Face          //Negative X Normal
		 -0.5f,  0.5f,  0.5f, -1.0f,  0.0f,  0.0f,  1.0f, 0.0f,
		 -0.5f,  0.5f, -0.5f, -1.0f,  0.0f,  0.0f,  1.0f, 1.0f,
		 -0.5f, -0.5f, -0.5f, -1.0f,  0.0f,  0.0f,  0.0f, 1.0f,
		 -0.5f, -0.5f, -0.5f, -1.0f,  0.0f,  0.0f,  0.0f, 1.0f,
		 -0.5f, -0.5f,  0.5f, -1.0f,  0.0f,  0.0f,  0.0f, 0.0f,
		 -0.5f,  0.5f,  0.5f, -1.0f,  0.0f,  0.0f,  1.0f, 0.0f,

		  //Right Face         //Positive X Normal
		  0.5f,  0.5f,  0.5f,  1.0f,  0.0f,  0.0f,  1.0f, 0.0f,
		  0.5f,  0.5f, -0.5f,  1.0f,  0.0f,  0.0f,  1.0f, 1.0f,
		  0.5f, -0.5f, -0.5f,  1.0f,  0.0f,  0.0f,  0.0f, 1.0f,
		  0.5f, -0.5f, -0.5f,  1.0f,  0.0f,  0.0f,  0.0f, 1.0f,
		  0.5f, -0.5f,  0.5f,  1.0f,  0.0f,  0.0f,  0.0f, 0.0f,
		  0.5f,  0.5f,  0.5f,  1.0f,  0.0f,  0.0f,  1.0f, 0.0f,

		  //Bottom Face        //Negative Y Normal
		 -0.5f, -0.5f, -0.5f,  0.0f, -1.0f,  0.0f,  0.0f, 1.0f,
		  0.5f, -0.5f, -0.5f,  0.0f, -1.0f,  0.0f,  1.0f, 1.0f,
		  0.5f, -0.5f,  0.5f,  0.0f, -1.0f,  0.0f,  1.0f, 0.0f,
		  0.5f, -0.5f,  0.5f,  0.0f, -1.0f,  0.0f,  1.0f, 0.0f,
		 -0.5f, -0.5f,  0.5f,  0.0f, -1.0f,  0.0f,  0.0f, 0.0f,
		 -0.5f, -0.5f, -0.5f,  0.0f, -1.0f,  0.0f,  0.0f, 1.0f,

		  //Top Face           //Positive Y Normal
		 -0.5f,  0.5f, -0.5f,  0.0f,  1.0f,  0.0f,  0.0f, 1.0f,
		  0.5f,  0.5f, -0.5f,  0.0f,  1.0f,  0.0f,  1.0f, 1.0f,
		  0.5f,  0.5f,  0.5f,  0.0f,  1.0f,  0.0f,  1.0f, 0.0f,
		  0.5f,  0.5f,  0.5f,  0.0f,  1.0f,  0.0f,  1.0f, 0.0f,
	     -0.5f,  0.5f,  0.5f,  0.0f,  1.0f,  0.0f,  0.0f, 0.0f,
		 -0.5f,  0.5f, -0.5f,  0.0f,  1.0f,  0.0f,  0.0f, 1.0f
	};

	const GLuint floatsPerVertex = 3;
	const GLuint floatsPerNormal = 3;
	const GLuint floatsPerUV = 2;

	lightMesh.nVertices = sizeof(verts) / (sizeof(verts[0]) * (floatsPerVertex + floatsPerNormal + floatsPerUV));

	// generate multiple VAOs or buffers at the same time
	glGenVertexArrays(1, &lightMesh.vao); 
	glBindVertexArray(lightMesh.vao);

	// Create 2 buffers: first one for the vertex data; second one for the indices
	glGenBuffers(1, &lightMesh.vbo);
	glBindBuffer(GL_ARRAY_BUFFER, lightMesh.vbo); // Activates the buffer
	glBufferData(GL_ARRAY_BUFFER, sizeof(verts), verts, GL_STATIC_DRAW); // Sends vertex or coordinate data to the GPU


	GLint stride = sizeof(float) * (floatsPerVertex + floatsPerNormal + floatsPerUV);// The number of floats before each

	// Create Vertex Attribute Pointers
	glVertexAttribPointer(0, floatsPerVertex, GL_FLOAT, GL_FALSE, stride, 0);
	glEnableVertexAttribArray(0);

	glVertexAttribPointer(1, floatsPerNormal, GL_FLOAT, GL_FALSE, stride, (void*)(sizeof(float) * floatsPerVertex));
	glEnableVertexAttribArray(1);

	glVertexAttribPointer(2, floatsPerUV, GL_FLOAT, GL_FALSE, stride, (void*)(sizeof(float) * (floatsPerVertex + floatsPerNormal)));
	glEnableVertexAttribArray(2);
}

