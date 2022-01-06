
# OpenGL
repository working with OpenGL3, GLWF and glut in c

## dependecies:
    sudo apt-get update
	sudo apt-get install cmake pkg-config
	sudo apt-get install mesa-utils libglu1-mesa-dev freeglut3-dev mesa-common-dev
	sudo apt-get install libglew-dev libglfw3-dev libglm-dev
	sudo apt-get install libao-dev libmpg123-dev
## glfw:

    cd /usr/local/lib/
	git clone https://github.com/glfw/glfw.git
	cd glfw
	cmake .
	make
	sudo make install
## GLAD:

 1. Head on to the GLAD web service.
 2. Set the language to C++ and choose the specification as OpenGL.
 3. In the API section, select gl version of at least 3.3, make sure the profile is set to Core, and that the Generate a loader option is ticked.
 4. Ignore the extensions and click Generate to produce the resulting library files.
 5. GLAD, by now, should have provided you a zip file: glad.zip containing two folders(include and src).
 6. Copy the folders inside include (glad and KHR) into your include(s) directory: `cp -R include/* /usr/include/`
 7. Now copy the file glad.c inside the src folder to your current working directory.
