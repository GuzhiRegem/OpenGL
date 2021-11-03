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

	while(!glfwWindowShouldClose(window))
	{
		processInput(window, &state);

		printf("x: %g y: %g z: %g dir_x: %g dir_y: %g\n", player.pos.x, player.pos.y, player.pos.z, player.dir.x, player.dir.y);
		glfwSwapBuffers(window);
	    glfwPollEvents();
	}
	glfwTerminate();
	return (0);
}

void processInput(GLFWwindow *window, t_state *state)
{
	t_player *player;
	double vel = 0.01;
	vec_3 mov = {0.0, 0.0, 0.0};
	vec_2 inp = {0.0, 0.0};
	vec_2 tmp;
	double dir;

	player = state->player;
    if(glfwGetKey(window, GLFW_KEY_SPACE) == GLFW_PRESS)
        mov.z += 0.01;
    if(glfwGetKey(window, GLFW_KEY_LEFT_SHIFT) == GLFW_PRESS)
        mov.z -= 0.01;
    if(glfwGetKey(window, GLFW_KEY_W) == GLFW_PRESS)
		inp.y += 1.0;
    if(glfwGetKey(window, GLFW_KEY_S) == GLFW_PRESS)
        inp.y -= 1.0;
    if(glfwGetKey(window, GLFW_KEY_A) == GLFW_PRESS)
		inp.x -= 1.0;
    if(glfwGetKey(window, GLFW_KEY_D) == GLFW_PRESS)
		inp.x += 1.0;
    if(glfwGetKey(window, GLFW_KEY_UP) == GLFW_PRESS)
		if (player->dir.y < 1.0)
			player->dir.y += 0.01;
    if(glfwGetKey(window, GLFW_KEY_DOWN) == GLFW_PRESS)
		if (player->dir.y > -1.0)
			player->dir.y -= 0.01;
    if(glfwGetKey(window, GLFW_KEY_LEFT) == GLFW_PRESS)
	{
		player->dir.x -= 0.01;
		if (player->dir.x < 0)
			player->dir.x += (2*M_PI);
	}
    if(glfwGetKey(window, GLFW_KEY_RIGHT) == GLFW_PRESS)
	{
		player->dir.x += 0.01;
		if (player->dir.x > (2*M_PI))
			player->dir.x -= (2*M_PI);
	}
	dir = sqrt(mov.x*mov.x + mov.y*mov.y);
	if (mov.x || mov.y)
	{
		mov.x /= dir;
		mov.y /= dir;
	}
	else
	{
		mov.x = 0.0;
		mov.y = 0.0;
	}
	tmp.x = (mov.x * cos(player->dir.x)) - (mov.y * sin(player->dir.x));
	tmp.y = (mov.x * sin(player->dir.x)) + (mov.y * sin(player->dir.x));
	tmp.x *= vel;
	tmp.y *= vel;
	player->pos.x += tmp.x;
	player->pos.y += tmp.y;
	player->pos.z += mov.z;
}
