
#include "core.h"


// global variables

// Window size
const unsigned int initWidth = 512;
const unsigned int initHeight = 512;

// Function prototypes
void renderScene();
void resizeWindow(GLFWwindow* window, int width, int height);
void keyboardHandler(GLFWwindow* window, int key, int scancode, int action, int mods);
void updateScene();
void DrawRightTriangle(float x, float y, float a, float b); //x,y is the top corner, a,b is the right corner
void DrawITriangle(float x, float y, float a, float b); //x,y is top corner, a,b is the bottom left corner
void DrawQuad(float x, float y, float a, float b);  //x,y is the top left, a,b is the bottom right

int main() {

	//
	// 1. Initialisation
	//
	

	// Initialise glfw and setup window
	glfwInit();

	glfwWindowHint(GLFW_OPENGL_DEBUG_CONTEXT, GLFW_TRUE);
	glfwWindowHint(GLFW_OPENGL_COMPAT_PROFILE, GLFW_TRUE);

	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 1);

	GLFWwindow* window = glfwCreateWindow(initWidth, initHeight, "Real-Time Computer Graphics", NULL, NULL);

	// Check window was created successfully
	if (window == NULL)
	{
		std::cout << "Failed to create GLFW window!\n";
		glfwTerminate();
		return -1;
	}
	glfwMakeContextCurrent(window);
	

	// Set callback functions to handle different events
	glfwSetFramebufferSizeCallback(window, resizeWindow); // resize window callback
	glfwSetKeyCallback(window, keyboardHandler); // Keyboard input callback


	// Initialise glew
	glewInit();

	
	// Setup window's initial size
	resizeWindow(window, initWidth, initHeight);

	// Initialise scene - geometry and shaders etc
	glClearColor(0.0f, 0.0f, 0.0f, 0.0f); // setup background colour to be black

	//gluOrtho2D(200, 250, 200, 240);

	//
	// 2. Main loop
	// 
	

	// Loop while program is not terminated.
	while (!glfwWindowShouldClose(window)) {

		updateScene();
		renderScene();						// Render into the current buffer
		glfwSwapBuffers(window);			// Displays what was just rendered (using double buffering).

		// Poll events (key presses, mouse events)
		// glfwWaitEvents();				// Use this if no animation.
		// glfwWaitEventsTimeout(1.0/60.0);	// Use this to animate at 60 frames/sec (timing is NOT reliable)
		glfwPollEvents();					// Use this version when animating as fast as possible
	}

	glfwTerminate();
	return 0;
}



// renderScene - function to render the current scene
void renderScene()
{
	// Clear the rendering window
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	// Render objects here...
	/*glBegin(GL_TRIANGLES);
		glVertex2f(-0.75f, 0.75f);
		glVertex2f(-0.75f, -0.75f);
		glVertex2f(0.0f, -0.75f);
		glVertex2f(-0.75f, 0.75f);
		glVertex2f(0.0f, -0.75f);
		glVertex2f(0.0f, 0.75f);
	glEnd();*/

	DrawRightTriangle(-0.5f, 0.5f, 0.0f, 0.0f);
	DrawQuad(0.15f, -0.15f, 0.75f, -0.75f);  
	DrawITriangle(-0.5f, -0.25f, -0.75f, -0.75f);
}


// Function to call when window resized
void resizeWindow(GLFWwindow* window, int width, int height)
{
	glViewport(0, 0, width, height);		// Draw into entire window
}


// Function to call to handle keyboard input
void keyboardHandler(GLFWwindow* window, int key, int scancode, int action, int mods)
{
	if (action == GLFW_PRESS) {

		// check which key was pressed...
		switch (key)
		{
			case GLFW_KEY_ESCAPE:
				glfwSetWindowShouldClose(window, true);
				break;

			default:
			{
			}
		}
	}
	else if (action == GLFW_RELEASE) {
		// handle key release events
	}
}


// Function called to animate elements in the scene
void updateScene() {
}

void DrawRightTriangle(float x, float y, float a, float b)
{
	glBegin(GL_TRIANGLES);
	glVertex2f(x, y); 
	glVertex2f(x, b); 
	glVertex2f(a, b); 
	glEnd();
}

void DrawITriangle(float x, float y, float a, float b)
{
	glBegin(GL_TRIANGLES); 
	glVertex2f(x, y); 
	glVertex2f(a, b);  
	glVertex2f(x, b);  
	glVertex2f(x, y); 
	glVertex2f(x, b); 
	glVertex2f(x + (x - a), b);   
	glEnd(); 
}

void DrawQuad(float x, float y, float a, float b)  
{
	glBegin(GL_QUADS);
	glVertex2f(x, y); 
	glVertex2f(x, b); 
	glVertex2f(a, b); 
	glVertex2f(a, y);  
	glEnd();
}

