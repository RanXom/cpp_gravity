#include <iostream>
#include <GLFW/glfw3.h>

GLFWwindow* StartGLFW();

int main() {
  GLFWwindow* window = StartGLFW();

  float centerX = screenWidth / 2.0f;
  float centerY = screenHeight / 2.0f;
  float radius = 50.0;
  int res = 100;
 
  while (!glfwWindowShouldClose(window)) {
    glfwSwapBuffers(window);
    glfwPollEvents();
  }
}

GLFWwindow* StartGLFW() {
  if (!glfwInit()) {
    std::cerr << "Failed to initialise glfw, panic!" << std::endl;
    return nullptr;
  }

  GLFWwindow* window = glfwCreateWindow(800, 600, "Gravity Sim", NULL, NULL);
  if (!window) {
    std::cerr << "Failed to create GLFW window!\n";
    glfwTerminate();
    return nullptr;
  }

  glfwMakeContextCurrent(window);
  return window;
}
