#include <iostream>
#include <vector>
#include <GLFW/glfw3.h>
#include <cmath>

float screenWidth = 600.0f;
float screenHeight = 800.0f;

GLFWwindow* StartGLFW();
void draw_circle(float centerX, float centerY, float radius, int res);

int main() {
  GLFWwindow* window = StartGLFW();
  float centerX = screenWidth / 2.0f;
  float centerY = screenHeight / 2.0f;
  float radius = 50.0f;
  int res = 100;

  std::vector<float> position = {400.0f, 300.0f};
  std::vector<float> velocity = {0.0f, 0.0f};

  while (!glfwWindowShouldClose(window)) {
    draw_circle(position[0], position[1], radius, res);
    position[0] += velocity[0];
    position[1] += velocity[1];
    velocity[1] += -9.81 / 20.0f;

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

void draw_circle(float centerX, float centerY, float radius, int res) {
  // Set up orthographic projection (pixel coords)
  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();
  glOrtho(0, 800, 0, 600, -1, 1);
  glMatrixMode(GL_MODELVIEW);
  glLoadIdentity();
 
  glClear(GL_COLOR_BUFFER_BIT);

  glBegin(GL_TRIANGLE_FAN);
  glVertex2f(centerX, centerY);

  for (int i = 0; i <= res; ++i) {
    float angle = 2.0f * 3.141592653589 * (static_cast<float>(i) / res);
    float x = centerX + cos(angle) * radius;
    float y = centerY + sin(angle) * radius;
    glVertex2f(x, y);
  }

  glEnd();
}
