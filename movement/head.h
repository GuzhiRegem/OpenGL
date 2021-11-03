#ifndef HEAD
#define HEAD

#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <glad/glad.h>
#include <GLFW/glfw3.h>

typedef struct s_vec2 {
	double x;
	double y;
} vec_2;
typedef struct s_vec3 {
	double x;
	double y;
	double z;
} vec_3;
typedef struct s_player {
	vec_3 pos;
	vec_2 dir;
} t_player;
typedef struct s_state {
	t_player *player;
} t_state;

void framebuffer_size_callback(GLFWwindow* window, int width, int height);
GLFWwindow *init(void);


#endif
