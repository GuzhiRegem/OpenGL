#include "head.h"

int main()
{
	GLFWwindow *window;
	
	glfwInit();
	window = init();
	if (!window)
		return (1);

	while(!glfwWindowShouldClose(window))
	{
		glfwSwapBuffers(window);
	    glfwPollEvents();
	}
	glfwTerminate();
	return (0);
}
