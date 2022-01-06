#include "head.h"

void processInput(GLFWwindow *window, t_state *state);

int main()
{
	GLFWwindow *window;
	t_player player = {{0.0, 0.0, 0.0}, {0.0, 0.0}};
	t_state state = {&player};
	
	glfwInit();
	window = init();
	if (!window)
		return (1);
	
	GLuint VertexArrayID;
	glGenVertexArrays(1, &VertexArrayID);
	glBindVertexArray(VertexArrayID);

	static const GLfloat g_vertex_buffer_data[] = {
		-1.0f, -1.0f, 0.0f,
		1.0f, -1.0f, 0.0f,
		1.0f,  1.0f, 0.0f,
		-1.0f, -1.0f, 0.0f,
		-1.0f, 1.0f, 0.0f,
		1.0f,  1.0f, 0.0f,
	};

	// Identificar el vertex buffer
	GLuint vertexbuffer;
	// Generar un buffer, poner el resultado en el vertexbuffer que acabamos de crear
	glGenBuffers(1, &vertexbuffer);
	// Los siguientes comandos le darán características especiales al 'vertexbuffer' 
	glBindBuffer(GL_ARRAY_BUFFER, vertexbuffer);
	// Darle nuestros vértices a  OpenGL.
	glBufferData(GL_ARRAY_BUFFER, sizeof(g_vertex_buffer_data), g_vertex_buffer_data, GL_STATIC_DRAW);

	GLuint programID = LoadShaders( "vertexshader", "fragmentshader" );
	while(!glfwWindowShouldClose(window))
	{
		float currentFrame = glfwGetTime();
		processInput(window, &state);
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		glUseProgram(programID);
		glUniform1f(glGetUniformLocation(programID, "iTime"), (int)currentFrame % 60);
		// 1rst attribute buffer : vértices
		glEnableVertexAttribArray(0);
		glBindBuffer(GL_ARRAY_BUFFER, vertexbuffer);
		glVertexAttribPointer(
		0,                  // atributo 0. No hay razón particular para el 0, pero debe corresponder en el shader.
		3,                  // tamaño
		GL_FLOAT,           // tipo
		GL_FALSE,           // normalizado?
		0,                    // Paso
		(void*)0            // desfase del buffer
		);
		// Dibujar el triángulo !
		glDrawArrays(GL_TRIANGLES, 0, 6); // Empezar desde el vértice 0S; 3 vértices en total -> 1 triángulo
		glDisableVertexAttribArray(0);

		printf("x: %g y: %g z: %g dir_x: %g dir_y: %g\n", player.pos.x, player.pos.y, player.pos.z, player.dir.x, player.dir.y);
		glfwSwapBuffers(window);
	    glfwPollEvents();
	}
	glfwTerminate();
	return (0);
}
