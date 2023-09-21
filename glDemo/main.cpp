
#include "core.h"
#include <math.h>
#include <iostream>

/////////////////////////////////////////////////////////////////////////////////////
// global variables
/////////////////////////////////////////////////////////////////////////////////////

// Window size
unsigned int initWidth = 500;
unsigned int initHeight = 500;


/////////////////////////////////////////////////////////////////////////////////////
// Function to call when window resized
/////////////////////////////////////////////////////////////////////////////////////
void resize(GLFWwindow* window, int width, int height)
{
	glViewport(0, 0, width, height);		// Draw into entire window
}


/////////////////////////////////////////////////////////////////////////////////////
// Function to call to handle keyboard input
/////////////////////////////////////////////////////////////////////////////////////
void keyboard(GLFWwindow* window, int key, int scancode, int action, int mods) 
{
	// ignore key up (key release) events
	if (action == GLFW_RELEASE) 
		return;	

	// process keyboard inputs here..
	switch (key)
	{
		case GLFW_KEY_ESCAPE:
		case GLFW_KEY_X:
			glfwSetWindowShouldClose(window, true);
		break;

		default:
		{
		}
	}
}


/////////////////////////////////////////////////////////////////////////////////////
// renderScene
/////////////////////////////////////////////////////////////////////////////////////
void renderScene()
{
	// Clear the rendering window
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	////////////////////////////////////////////////////////////////////////////////
	// Render mesh objects here..
	////////////////////////////////////////////////////////////////////////////////

	glBegin(GL_TRIANGLES);

	glColor3ub(255, 0, 0);
	glVertex2f(-0.5f, -0.5f);

	glColor3ub(0, 255, 0);
	glVertex2f(0.0f, 0.5f);

	glColor3ub(0, 0, 255);
	glVertex2f(0.5f, -0.5f);

	glEnd();

	glBindVertexArray(0);       	
}

/////////////////////////////////////////////////////////////////////////////////////
// main()
/////////////////////////////////////////////////////////////////////////////////////
int main() 
{
	// initialise glfw
	glfwInit();

	glfwWindowHint(GLFW_OPENGL_DEBUG_CONTEXT, true);

	GLFWwindow* window = glfwCreateWindow(initWidth, initHeight, "GraphicsTemplate - Fixed Function Pipeline", NULL, NULL);
	if (window == NULL)
	{
		fprintf(stdout, "Failed to create GLFW window!\n");
		glfwTerminate();
		return -1;
	}
	glfwMakeContextCurrent(window);
	
	
	// initialise glew
	glewInit();


	// Set callback function for resizing the window
	glfwSetFramebufferSizeCallback(window, resize);

	// Set callback for keyboard events
	glfwSetKeyCallback(window, keyboard);


	resize(window, initWidth, initHeight);

	////////////////////////////////////////////////////
	// initialise scene - geometry and shaders etc
	////////////////////////////////////////////////////
	glClearColor(0.0f, 0.0f, 0.0f, 0.0f);



	// Loop while program is not terminated.
	while (!glfwWindowShouldClose(window)) {

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
