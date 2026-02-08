//#define _CRT_SECURE_NO_WARNINGS
//
//#include <iostream>
//#include <vector>
//#include <cstdlib>
//
//#include <GL/glew.h>
//#include <GLFW/glfw3.h>
//
//#include <glm/glm.hpp>
//#include <glm/gtc/type_ptr.hpp>
//#include <glm/gtc/matrix_transform.hpp>
//
//#include "shader.hpp"
//#include "model.hpp"
//
//const unsigned int wWidth = 1200;
//const unsigned int wHeight = 900;
//
//// ================= GLOBAL STATE =================
//bool chestOpen = false;
//float chest_lid_angle = 0.0f;
//
//glm::vec3 fish1Pos(0.3f, 0.0f, 0.3f);
//glm::vec3 fish2Pos(-0.3f, 0.0f, -0.3f);
//float fish1RotY = 0.0f;
//float fish2RotY = 180.0f;
//
//std::vector<glm::vec3> foodPositions;
//std::vector<glm::vec3> algaePositions;
//
//struct Bubble {
//    glm::vec3 pos;
//    float speed;
//    float radius;
//};
//std::vector<Bubble> bubbles;
//
//// ================= INPUT =================
//void keyCallback(GLFWwindow* window, int key, int, int action, int)
//{
//    if (key == GLFW_KEY_C && action == GLFW_PRESS)
//        chestOpen = !chestOpen;
//
//    if (key == GLFW_KEY_F && action == GLFW_PRESS) {
//        float x = ((rand() % 100) / 100.0f - 0.5f) * 1.5f;
//        float z = ((rand() % 100) / 100.0f - 0.5f) * 1.5f;
//        foodPositions.emplace_back(x, 0.8f, z);
//    }
//}
//
//// ================= MAIN =================
//int main()
//{
//    if (!glfwInit()) return -1;
//
//    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
//    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
//    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
//
//    GLFWwindow* window =
//        glfwCreateWindow(wWidth, wHeight, "3D Aquarium", nullptr, nullptr);
//    if (!window) return -2;
//
//    glfwMakeContextCurrent(window);
//    glfwSetKeyCallback(window, keyCallback);
//
//    if (glewInit() != GLEW_OK) return -3;
//
//    glEnable(GL_DEPTH_TEST);
//    glEnable(GL_BLEND);
//    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
//
//    // ================= MODELS =================
//    Model clown("res/clown-fish.obj");
//    Model puffer("res/puffer-fish.obj");
//
//    // ================= SHADER =================
//    Shader unifiedShader("basic.vert", "basic.frag");
//    unifiedShader.use();
//
//    unifiedShader.setVec3("uLightPos", 0.0f, 1.0f, 3.0f);
//    unifiedShader.setVec3("uViewPos", 0.0f, 0.0f, 3.0f);
//    unifiedShader.setVec3("uLightColor", 1.0f, 1.0f, 1.0f);
//
//    glm::mat4 projection =
//        glm::perspective(glm::radians(50.0f),
//            (float)wWidth / (float)wHeight,
//            0.1f, 100.0f);
//
//    glm::mat4 view =
//        glm::lookAt(glm::vec3(0, 0, 3),
//            glm::vec3(0, 0, 0),
//            glm::vec3(0, 1, 0));
//
//    unifiedShader.setMat4("uP", projection);
//    unifiedShader.setMat4("uV", view);
//
//    // ================= INIT SCENE =================
//    for (int i = 0; i < 5; ++i) {
//        float x = ((rand() % 100) / 100.0f - 0.5f) * 1.8f;
//        float z = ((rand() % 100) / 100.0f - 0.5f) * 1.8f;
//        algaePositions.emplace_back(x, -0.9f, z);
//    }
//
//    for (int i = 0; i < 10; ++i) {
//        Bubble b;
//        b.pos = glm::vec3(
//            ((rand() % 100) / 100.0f - 0.5f) * 1.8f,
//            -0.9f + (rand() % 100) / 100.0f * 1.8f,
//            ((rand() % 100) / 100.0f - 0.5f) * 1.8f);
//        b.speed = 0.0005f;
//        b.radius = 0.03f;
//        bubbles.push_back(b);
//    }
//
//    // ================= RENDER LOOP =================
//    while (!glfwWindowShouldClose(window))
//    {
//        if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
//            glfwSetWindowShouldClose(window, true);
//
//        // Fish 1
//        if (glfwGetKey(window, GLFW_KEY_W) == GLFW_PRESS) fish1Pos.z -= 0.002f;
//        if (glfwGetKey(window, GLFW_KEY_S) == GLFW_PRESS) fish1Pos.z += 0.002f;
//        if (glfwGetKey(window, GLFW_KEY_A) == GLFW_PRESS) fish1Pos.x -= 0.002f;
//        if (glfwGetKey(window, GLFW_KEY_D) == GLFW_PRESS) fish1Pos.x += 0.002f;
//
//        // Fish 2
//        if (glfwGetKey(window, GLFW_KEY_UP) == GLFW_PRESS) fish2Pos.z -= 0.002f;
//        if (glfwGetKey(window, GLFW_KEY_DOWN) == GLFW_PRESS) fish2Pos.z += 0.002f;
//        if (glfwGetKey(window, GLFW_KEY_LEFT) == GLFW_PRESS) fish2Pos.x -= 0.002f;
//        if (glfwGetKey(window, GLFW_KEY_RIGHT) == GLFW_PRESS) fish2Pos.x += 0.002f;
//
//        glClearColor(0.05f, 0.1f, 0.15f, 1.0f);
//        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
//
//        unifiedShader.use();
//
//        // ===== Fish 1 (Clown) =====
//        glm::mat4 model = glm::mat4(1.0f);
//        model = glm::translate(model, fish1Pos);
//        model = glm::scale(model, glm::vec3(0.15f));
//        unifiedShader.setMat4("uM", model);
//        clown.Draw(unifiedShader);
//
//        // ===== Fish 2 (Puffer) =====
//        model = glm::mat4(1.0f);
//        model = glm::translate(model, fish2Pos);
//        model = glm::scale(model, glm::vec3(0.15f));
//        unifiedShader.setMat4("uM", model);
//        puffer.Draw(unifiedShader);
//
//        glfwSwapBuffers(window);
//        glfwPollEvents();
//    }
//
//    glfwTerminate();
//    return 0;
//}
