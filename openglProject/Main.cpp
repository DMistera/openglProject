#include <iostream>

#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include "Renderer.h"
#include "App.h"
#include "InputManager.h"

int main(void)
{
	try {

		GLFWwindow* window;
		// Initialise GLFW
		if (!glfwInit())
		{
			fprintf(stderr, "Failed to initialize GLFW\n");
			getchar();
			return -1;
		}

		glfwWindowHint(GLFW_SAMPLES, 4);
		glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
		glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
		glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE); // To make MacOS happy; should not be needed
		glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

		bool fullscreen = true;
		if (fullscreen) {
			GLFWmonitor* monitor = glfwGetPrimaryMonitor();
			const GLFWvidmode* mode = glfwGetVideoMode(monitor);
			glfwWindowHint(GLFW_RED_BITS, mode->redBits);
			glfwWindowHint(GLFW_GREEN_BITS, mode->greenBits);
			glfwWindowHint(GLFW_BLUE_BITS, mode->blueBits);
			glfwWindowHint(GLFW_REFRESH_RATE, mode->refreshRate);

			// Open a window and create its OpenGL context
			window = glfwCreateWindow(mode->width, mode->height, "Funky", monitor, NULL);
		}
		else {
			window = glfwCreateWindow(1024, 768, "Funky", NULL, NULL);
		}
		if (window == NULL) {
			fprintf(stderr, "Failed to open GLFW window.\n");
			getchar();
			glfwTerminate();
			return -1;
		}
		glfwMakeContextCurrent(window);

		// Initialize GLEW
		glewExperimental = true; // Needed for core profile
		if (glewInit() != GLEW_OK) {
			fprintf(stderr, "Failed to initialize GLEW\n");
			getchar();
			glfwTerminate();
			return -1;
		}

		InputManager::init(window);

		bool shouldClose = false;

		InputManager::setKeyboardInputCallback([&](int key, int scancode, int action, int mods) {
			if (key == GLFW_KEY_ESCAPE) {
				shouldClose = true;
			}
		});

		Renderer renderer(window);
		renderer.init();

		App app;
		app.init(window);
		app.start();

		glfwSetTime(0);

		/* Loop until the user closes the window */
		while (!glfwWindowShouldClose(window) && !shouldClose)
		{
			app.update(glfwGetTime());
			glfwSetTime(0);

			glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
			/* Render here */
			glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

			app.draw(&renderer);

			/* Swap front and back buffers */
			glfwSwapBuffers(window);

			/* Poll for and process events */
			glfwPollEvents();
		
		}

		glfwTerminate();
		return 0;
	}
	catch (const std::invalid_argument& ia) {
		std::cerr << "Invalid argument: " << ia.what() << '\n';
	}
}