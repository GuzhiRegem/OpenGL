#include "head.h"

GLuint LoadShaders(const char * vertex_file_path,const char * fragment_file_path){

	// Crear los shaders
	GLuint VertexShaderID = glCreateShader(GL_VERTEX_SHADER);
	GLuint FragmentShaderID = glCreateShader(GL_FRAGMENT_SHADER);

	
	

	GLint Result = GL_FALSE;
	int InfoLogLength = 4096;
    char *VertexShaderErrorMessage = malloc(InfoLogLength);
    char *FragmentShaderErrorMessage = malloc(InfoLogLength);
    char *ProgramErrorMessage = malloc(InfoLogLength);
    char *VertexShaderCode = malloc(InfoLogLength);
    char *FragmentShaderCode = malloc(InfoLogLength);

    int fd = open(vertex_file_path, O_RDONLY);
    read(fd, VertexShaderCode, (size_t)InfoLogLength);
    close(fd);
    fd = open(fragment_file_path, O_RDONLY);
    read(fd, FragmentShaderCode, (size_t)InfoLogLength);
    close(fd);


	// Compilar Vertex Shader
	printf("Compiling shader : %s\n", vertex_file_path);
	char const * VertexSourcePointer = VertexShaderCode;
	glShaderSource(VertexShaderID, 1, &VertexSourcePointer , NULL);
	glCompileShader(VertexShaderID);

	// Compilar Fragment Shader
	printf("Compiling shader : %s\n", fragment_file_path);
	char const * FragmentSourcePointer = FragmentShaderCode;
	glShaderSource(FragmentShaderID, 1, &FragmentSourcePointer , NULL);
	glCompileShader(FragmentShaderID);


	// Vincular el programa por medio del ID
	printf("Linking program\n");
	GLuint ProgramID = glCreateProgram();
	glAttachShader(ProgramID, VertexShaderID);
	glAttachShader(ProgramID, FragmentShaderID);
	glLinkProgram(ProgramID);

	// Revisar el programa
	glGetProgramiv(ProgramID, GL_LINK_STATUS, &Result);
	glGetProgramiv(ProgramID, GL_INFO_LOG_LENGTH, &InfoLogLength);
	if ( InfoLogLength > 0 ){
		glGetProgramInfoLog(ProgramID, InfoLogLength, NULL, &ProgramErrorMessage[0]);
		printf("%s\n", &ProgramErrorMessage[0]);
	}

	
	glDetachShader(ProgramID, VertexShaderID);
	glDetachShader(ProgramID, FragmentShaderID);
	
	glDeleteShader(VertexShaderID);
	glDeleteShader(FragmentShaderID);

	return ProgramID;
}
