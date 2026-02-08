//#define _CRT_SECURE_NO_WARNINGS
//
//#include <iostream>
//#include <vector>
//#include <cstdlib>
//#include <cmath>
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
//const unsigned int wWidth = 1920;
//const unsigned int wHeight = 1080;
//
//const double TARGET_FPS = 75.0;
//const double FRAME_TIME = 1.0 / TARGET_FPS;
//
//bool depthTestEnabled = true;
//bool cullFaceEnabled = true;
//
//bool chestOpen = false;
//float chest_lid_angle = 0.0f;
//
//glm::vec3 fish1Pos(0.3f, 0.0f, 0.3f);
//glm::vec3 fish2Pos(-0.3f, 0.0f, -0.3f);
//float fish1RotY = 0.0f;
//float fish2RotY = 180.0f;
//glm::vec3 fish1PrevPos = fish1Pos;
//glm::vec3 fish2PrevPos = fish2Pos;
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
//void keyCallback(GLFWwindow* window, int key, int, int action, int)
//{
//    if (key == GLFW_KEY_C && action == GLFW_PRESS) chestOpen = !chestOpen;
//    if (key == GLFW_KEY_F && action == GLFW_PRESS) {
//        float x = ((rand() % 100) / 100.0f - 0.5f) * 1.5f;
//        float z = ((rand() % 100) / 100.0f - 0.5f) * 1.5f;
//        foodPositions.emplace_back(x, 0.8f, z);
//    }
//
//    if (key == GLFW_KEY_R && action == GLFW_PRESS) {
//        Bubble b;
//        b.pos = fish1Pos;
//        b.speed = 0.007f;
//        b.radius = 0.025f;
//        bubbles.push_back(b);
//    }
//
//    if (key == GLFW_KEY_T && action == GLFW_PRESS) {
//        Bubble b;
//        b.pos = fish2Pos;
//        b.speed = 0.007f;
//        b.radius = 0.025f;
//        bubbles.push_back(b);
//    }
//
//    if (key == GLFW_KEY_Z && action == GLFW_PRESS) {
//        depthTestEnabled = !depthTestEnabled;
//        if (depthTestEnabled) {
//            glEnable(GL_DEPTH_TEST);
//            std::cout << "Depth test: ON\n";
//        }
//        else {
//            glDisable(GL_DEPTH_TEST);
//            std::cout << "Depth test: OFF\n";
//        }
//    }
//
//    if (key == GLFW_KEY_X && action == GLFW_PRESS) {
//        cullFaceEnabled = !cullFaceEnabled;
//        if (cullFaceEnabled) {
//            glEnable(GL_CULL_FACE);
//            std::cout << "Face culling: ON\n";
//        }
//        else {
//            glDisable(GL_CULL_FACE);
//            std::cout << "Face culling: OFF\n";
//        }
//    }
//}
//
//unsigned int createCube() {
//    float vertices[] = {
//        -0.5f,-0.5f,0.5f,0,0,1,0,0, 0.5f,-0.5f,0.5f,0,0,1,1,0, 0.5f,0.5f,0.5f,0,0,1,1,1, -0.5f,0.5f,0.5f,0,0,1,0,1,
//        -0.5f,-0.5f,-0.5f,0,0,-1,1,0, 0.5f,-0.5f,-0.5f,0,0,-1,0,0, 0.5f,0.5f,-0.5f,0,0,-1,0,1, -0.5f,0.5f,-0.5f,0,0,-1,1,1,
//        -0.5f,-0.5f,-0.5f,-1,0,0,0,0, -0.5f,-0.5f,0.5f,-1,0,0,1,0, -0.5f,0.5f,0.5f,-1,0,0,1,1, -0.5f,0.5f,-0.5f,-1,0,0,0,1,
//        0.5f,-0.5f,-0.5f,1,0,0,1,0, 0.5f,-0.5f,0.5f,1,0,0,0,0, 0.5f,0.5f,0.5f,1,0,0,0,1, 0.5f,0.5f,-0.5f,1,0,0,1,1,
//        -0.5f,0.5f,-0.5f,0,1,0,0,1, -0.5f,0.5f,0.5f,0,1,0,0,0, 0.5f,0.5f,0.5f,0,1,0,1,0, 0.5f,0.5f,-0.5f,0,1,0,1,1,
//        -0.5f,-0.5f,-0.5f,0,-1,0,0,0, -0.5f,-0.5f,0.5f,0,-1,0,0,1, 0.5f,-0.5f,0.5f,0,-1,0,1,1, 0.5f,-0.5f,-0.5f,0,-1,0,1,0
//    };
//    unsigned int indices[] = { 0,1,2,2,3,0,4,5,6,6,7,4,8,9,10,10,11,8,12,13,14,14,15,12,16,17,18,18,19,16,20,21,22,22,23,20 };
//    unsigned int VAO, VBO, EBO;
//    glGenVertexArrays(1, &VAO); glGenBuffers(1, &VBO); glGenBuffers(1, &EBO);
//    glBindVertexArray(VAO);
//    glBindBuffer(GL_ARRAY_BUFFER, VBO); glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);
//    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO); glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);
//    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)0); glEnableVertexAttribArray(0);
//    glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)(3 * sizeof(float))); glEnableVertexAttribArray(1);
//    glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)(6 * sizeof(float))); glEnableVertexAttribArray(2);
//    glBindVertexArray(0);
//    return VAO;
//}
//
//unsigned int createSphere(float radius, int sectors, int stacks) {
//    std::vector<float> vertices;
//    std::vector<unsigned int> indices;
//    float sectorStep = 2 * 3.14159265359f / sectors, stackStep = 3.14159265359f / stacks;
//    for (int i = 0; i <= stacks; ++i) {
//        float stackAngle = 3.14159265359f / 2 - i * stackStep;
//        float xy = radius * cosf(stackAngle), z = radius * sinf(stackAngle);
//        for (int j = 0; j <= sectors; ++j) {
//            float sectorAngle = j * sectorStep;
//            float x = xy * cosf(sectorAngle), y = xy * sinf(sectorAngle);
//            vertices.insert(vertices.end(), { x,y,z,x / radius,y / radius,z / radius,(float)j / sectors,(float)i / stacks });
//        }
//    }
//    for (int i = 0; i < stacks; ++i) {
//        int k1 = i * (sectors + 1), k2 = k1 + sectors + 1;
//        for (int j = 0; j < sectors; ++j, ++k1, ++k2) {
//            if (i != 0) { indices.insert(indices.end(), { (unsigned)k1,(unsigned)k2,(unsigned)(k1 + 1) }); }
//            if (i != stacks - 1) { indices.insert(indices.end(), { (unsigned)(k1 + 1),(unsigned)k2,(unsigned)(k2 + 1) }); }
//        }
//    }
//    unsigned int VAO, VBO, EBO;
//    glGenVertexArrays(1, &VAO); glGenBuffers(1, &VBO); glGenBuffers(1, &EBO);
//    glBindVertexArray(VAO);
//    glBindBuffer(GL_ARRAY_BUFFER, VBO); glBufferData(GL_ARRAY_BUFFER, vertices.size() * sizeof(float), &vertices[0], GL_STATIC_DRAW);
//    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO); glBufferData(GL_ELEMENT_ARRAY_BUFFER, indices.size() * sizeof(unsigned), &indices[0], GL_STATIC_DRAW);
//    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)0); glEnableVertexAttribArray(0);
//    glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)(3 * sizeof(float))); glEnableVertexAttribArray(1);
//    glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)(6 * sizeof(float))); glEnableVertexAttribArray(2);
//    glBindVertexArray(0);
//    return VAO;
//}
//
//unsigned int createPlane() {
//    float vertices[] = {
//        -1,0,-1,0,1,0,0,0, 1,0,-1,0,1,0,3,0, 1,0,1,0,1,0,3,3, -1,0,1,0,1,0,0,3
//    };
//    unsigned int indices[] = { 0,1,2,2,3,0 };
//    unsigned int VAO, VBO, EBO;
//    glGenVertexArrays(1, &VAO); glGenBuffers(1, &VBO); glGenBuffers(1, &EBO);
//    glBindVertexArray(VAO);
//    glBindBuffer(GL_ARRAY_BUFFER, VBO); glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);
//    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO); glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);
//    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)0); glEnableVertexAttribArray(0);
//    glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)(3 * sizeof(float))); glEnableVertexAttribArray(1);
//    glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)(6 * sizeof(float))); glEnableVertexAttribArray(2);
//    glBindVertexArray(0);
//    return VAO;
//}
//
//unsigned int createQuad() {
//    float vertices[] = {
//        -1.0f,  1.0f,     0.0f, 1.0f,
//        -1.0f,  0.5f,     0.0f, 0.0f,
//        -0.7f,  0.5f,     1.0f, 0.0f,
//        -0.7f,  1.0f,     1.0f, 1.0f
//    };
//    unsigned int indices[] = { 0,1,2, 2,3,0 };
//    unsigned int VAO, VBO, EBO;
//    glGenVertexArrays(1, &VAO);
//    glGenBuffers(1, &VBO);
//    glGenBuffers(1, &EBO);
//    glBindVertexArray(VAO);
//    glBindBuffer(GL_ARRAY_BUFFER, VBO);
//    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);
//    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
//    glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);
//    glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, 4 * sizeof(float), (void*)0);
//    glEnableVertexAttribArray(0);
//    glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, 4 * sizeof(float), (void*)(2 * sizeof(float)));
//    glEnableVertexAttribArray(1);
//    glBindVertexArray(0);
//    return VAO;
//}
//
//int main()
//{
//    if (!glfwInit()) return -1;
//    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
//    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
//    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
//
//    GLFWmonitor* monitor = glfwGetPrimaryMonitor();
//    const GLFWvidmode* mode = glfwGetVideoMode(monitor);
//    GLFWwindow* window = glfwCreateWindow(mode->width, mode->height, "3D Aquarium - Fullscreen", monitor, nullptr);
//    if (!window) return -2;
//
//    glfwMakeContextCurrent(window);
//    glfwSetKeyCallback(window, keyCallback);
//    if (glewInit() != GLEW_OK) return -3;
//
//    glEnable(GL_DEPTH_TEST);
//    glEnable(GL_BLEND);
//    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
//
//    Model clown("res/clown-fish.obj");
//    Model puffer("res/puffer-fish.obj");
//    Model grass("res/grass.obj");
//
//    unsigned int cubeVAO = createCube();
//    unsigned int sphereVAO = createSphere(1.0f, 20, 20);
//    unsigned int planeVAO = createPlane();
//
//    // Create textures
//    unsigned int sandTexture = createSandTexture();
//    unsigned int woodTexture = createWoodTexture();
//    unsigned int signatureTexture = loadTexture("res/signature-cyrillic.png");
//
//    Shader shader("basic.vert", "basic.frag");
//    shader.use();
//
//    shader.setVec3("uLightPos", 0.0f, 3.0f, 2.0f);
//    shader.setVec3("uViewPos", 0.0f, 0.5f, 4.0f);
//    shader.setVec3("uLightColor", 1.2f, 1.2f, 1.1f);
//
//    glm::mat4 projection = glm::perspective(glm::radians(45.0f), (float)wWidth / (float)wHeight, 0.1f, 100.0f);
//    glm::mat4 view = glm::lookAt(glm::vec3(0, 0.5f, 4), glm::vec3(0, 0, 0), glm::vec3(0, 1, 0));
//    shader.setMat4("uP", projection);
//    shader.setMat4("uV", view);
//
//    for (int i = 0; i < 8; ++i) {
//        float x = ((rand() % 100) / 100.0f - 0.5f) * 1.7f;
//        float z = ((rand() % 100) / 100.0f - 0.5f) * 1.7f;
//        algaePositions.emplace_back(x, -0.9f, z);
//    }
//
//
//    std::cout << "=== Controls ===\n";
//    std::cout << "WASD - Fish 1 | Arrows - Fish 2\n";
//    std::cout << "C - Chest | F - Food | ESC - Exit\n\n";
//
//    int frameCounter = 0;
//    double lastTime = glfwGetTime();
//
//    while (!glfwWindowShouldClose(window))
//    {
//        double currentTime = glfwGetTime();
//        double deltaTime = currentTime - lastTime;
//
//        if (deltaTime < FRAME_TIME) {
//            continue;
//        }
//        lastTime = currentTime;
//
//        if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS) glfwSetWindowShouldClose(window, true);
//
//        fish1PrevPos = fish1Pos;
//        fish2PrevPos = fish2Pos;
//
//        if (glfwGetKey(window, GLFW_KEY_W) == GLFW_PRESS) fish1Pos.z -= 0.007f;
//        if (glfwGetKey(window, GLFW_KEY_S) == GLFW_PRESS) fish1Pos.z += 0.007f;
//        if (glfwGetKey(window, GLFW_KEY_A) == GLFW_PRESS) fish1Pos.x -= 0.007f;
//        if (glfwGetKey(window, GLFW_KEY_D) == GLFW_PRESS) fish1Pos.x += 0.007f;
//        if (glfwGetKey(window, GLFW_KEY_Q) == GLFW_PRESS) fish1Pos.y += 0.007f;
//        if (glfwGetKey(window, GLFW_KEY_E) == GLFW_PRESS) fish1Pos.y -= 0.007f;
//        if (glfwGetKey(window, GLFW_KEY_UP) == GLFW_PRESS) fish2Pos.z -= 0.007f;
//        if (glfwGetKey(window, GLFW_KEY_DOWN) == GLFW_PRESS) fish2Pos.z += 0.007f;
//        if (glfwGetKey(window, GLFW_KEY_LEFT) == GLFW_PRESS) fish2Pos.x -= 0.007f;
//        if (glfwGetKey(window, GLFW_KEY_RIGHT) == GLFW_PRESS) fish2Pos.x += 0.007f;
//        if (glfwGetKey(window, GLFW_KEY_K) == GLFW_PRESS) fish2Pos.y += 0.007f;
//        if (glfwGetKey(window, GLFW_KEY_L) == GLFW_PRESS) fish2Pos.y -= 0.007f;
//
//        fish1Pos = glm::clamp(fish1Pos, glm::vec3(-0.85f, -0.8f, -0.85f), glm::vec3(0.85f, 0.8f, 0.85f));
//        fish2Pos = glm::clamp(fish2Pos, glm::vec3(-0.85f, -0.8f, -0.85f), glm::vec3(0.85f, 0.8f, 0.85f));
//
//        glm::vec3 fish1Dir = fish1Pos - fish1PrevPos;
//        if (glm::length(fish1Dir) > 0.001f) fish1RotY = atan2f(fish1Dir.x, fish1Dir.z) * 180.0f / 3.14159265359f;
//        glm::vec3 fish2Dir = fish2Pos - fish2PrevPos;
//        if (glm::length(fish2Dir) > 0.001f) fish2RotY = atan2f(fish2Dir.x, fish2Dir.z) * 180.0f / 3.14159265359f;
//
//        if (chestOpen && chest_lid_angle < 120.0f) chest_lid_angle += 1.5f;
//        else if (!chestOpen && chest_lid_angle > 0.0f) chest_lid_angle -= 1.5f;
//
//        for (auto it = bubbles.begin(); it != bubbles.end(); )
//        {
//            it->pos.y += it->speed;
//            if (it->pos.y > 0.95f)
//                it = bubbles.erase(it);
//            else
//                ++it;
//        }
//
//        frameCounter++;
//
//
//        for (auto it = foodPositions.begin(); it != foodPositions.end();) {
//            if (it->y > -0.85f)
//            {
//                it->y -= 0.007f;
//                if (it->y < -0.85f)
//                    it->y = -0.85f;
//            }
//            bool eaten = (it->y < -0.85f) || (glm::distance(*it, fish1Pos) < 0.15f) || (glm::distance(*it, fish2Pos) < 0.15f);
//            if (eaten) it = foodPositions.erase(it);
//            else ++it;
//        }
//
//        glClearColor(0.05f, 0.15f, 0.2f, 1.0f);
//        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
//        shader.use();
//
//        //float treasureIntensity = chestOpen ? (chest_lid_angle / 120.0f) * 0.5f : 0.0f;
//        //glm::vec3 treasureLightPos(0.6f, -0.7f, 0.5f);
//        //shader.setVec3("uTreasureLightPos", treasureLightPos);
//        //shader.setVec3("uTreasureLightColor", treasureIntensity * 1.0f, treasureIntensity * 0.84f, treasureIntensity * 0.3f);
//
//
//        // Sand floor with texture
//        glBindVertexArray(planeVAO);
//        glActiveTexture(GL_TEXTURE0);
//        glBindTexture(GL_TEXTURE_2D, sandTexture);
//        shader.setInt("uUseTexture", 1);
//        glm::mat4 model = glm::scale(glm::translate(glm::mat4(1), glm::vec3(0, -1, 0)), glm::vec3(2, 1, 2));
//        shader.setMat4("uM", model);
//        glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
//
//        // Black base
//        glBindVertexArray(cubeVAO);
//        shader.setInt("uUseTexture", 0);
//        shader.setVec3("uObjectColor", 0.05f, 0.05f, 0.05f);
//        model = glm::scale(glm::translate(glm::mat4(1), glm::vec3(0, -1.05f, 0)), glm::vec3(2.2f, 0.1f, 2.2f));
//        shader.setMat4("uM", model);
//        glDrawElements(GL_TRIANGLES, 36, GL_UNSIGNED_INT, 0);
//
//        // Corner posts
//        float corners[4][2] = { {-1.05f,-1.05f},{-1.05f,1.05f},{1.05f,-1.05f},{1.05f,1.05f} };
//        for (int i = 0; i < 4; ++i) {
//            model = glm::scale(glm::translate(glm::mat4(1), glm::vec3(corners[i][0], 0, corners[i][1])), glm::vec3(0.08f, 2.2f, 0.08f));
//            shader.setMat4("uM", model);
//            glDrawElements(GL_TRIANGLES, 36, GL_UNSIGNED_INT, 0);
//        }
//
//        // Chest with wood texture
//        glActiveTexture(GL_TEXTURE0);
//        glBindTexture(GL_TEXTURE_2D, woodTexture);
//        shader.setInt("uUseTexture", 1);
//        model = glm::scale(glm::translate(glm::mat4(1), glm::vec3(0.6f, -0.78f, 0.5f)), glm::vec3(0.25f, 0.15f, 0.25f));
//        shader.setMat4("uM", model);
//        glDrawElements(GL_TRIANGLES, 36, GL_UNSIGNED_INT, 0);
//
//        // Chest lid
//        model = glm::mat4(1);
//        model = glm::translate(model, glm::vec3(0.6f, -0.78f, 0.5f));
//        model = glm::translate(model, glm::vec3(0, 0.075f, -0.125f));
//        model = glm::rotate(model, glm::radians(-chest_lid_angle), glm::vec3(1, 0, 0));
//        model = glm::translate(model, glm::vec3(0, 0.04f, 0));
//        model = glm::scale(model, glm::vec3(0.25f, 0.08f, 0.25f));
//        shader.setMat4("uM", model);
//        glDrawElements(GL_TRIANGLES, 36, GL_UNSIGNED_INT, 0);
//
//        shader.setInt("uUseTexture", 0);
//
//        // Treasure
//        if (chestOpen) {
//            glBindVertexArray(sphereVAO);
//            shader.setVec3("uObjectColor", 1.0f, 0.84f, 0.0f);
//            model = glm::scale(glm::translate(glm::mat4(1), glm::vec3(0.6f, -0.7f, 0.5f)), glm::vec3(0.08f));
//            shader.setMat4("uM", model);
//            glDrawElements(GL_TRIANGLES, 20 * 20 * 6, GL_UNSIGNED_INT, 0);
//        }
//
//        // Algae
//        //glBindVertexArray(cubeVAO);
//        //shader.setVec3("uObjectColor", 0.1f, 0.6f, 0.2f);
//        //for (const auto& pos : algaePositions) {
//        //    model = glm::scale(glm::translate(glm::mat4(1), pos), glm::vec3(0.04f, 0.25f, 0.04f));
//        //    shader.setMat4("uM", model);
//        //    glDrawElements(GL_TRIANGLES, 36, GL_UNSIGNED_INT, 0);
//        //}
//
//        shader.setInt("uUseTexture", 1);
//        for (const auto& pos : algaePositions) {
//            model = glm::mat4(1);
//            model = glm::translate(model, pos);
//            model = glm::scale(model, glm::vec3(0.08f));
//            shader.setMat4("uM", model);
//            grass.Draw(shader);
//        }
//
//        shader.setInt("uUseTexture", 0);
//
//        // Food
//        shader.setVec3("uObjectColor", 0.9f, 0.7f, 0.3f);
//        for (const auto& pos : foodPositions) {
//            model = glm::scale(glm::translate(glm::mat4(1), pos), glm::vec3(0.03f));
//            shader.setMat4("uM", model);
//            glDrawElements(GL_TRIANGLES, 36, GL_UNSIGNED_INT, 0);
//        }
//
//        shader.setInt("uUseTexture", 1);
//        model = glm::translate(glm::mat4(1), fish1Pos);
//        model = glm::rotate(model, glm::radians(fish1RotY - 90.0f), glm::vec3(0, 1, 0));
//        model = glm::rotate(model, glm::radians(90.0f), glm::vec3(0, 0, 1));
//        model = glm::scale(model, glm::vec3(0.015f));
//        shader.setMat4("uM", model);
//        clown.Draw(shader);
//
//        model = glm::translate(glm::mat4(1), fish2Pos);
//        model = glm::rotate(model, glm::radians(fish2RotY + 90.0f), glm::vec3(0, 1, 0));
//        model = glm::rotate(model, glm::radians(90.0f), glm::vec3(0, 0, 1));
//        model = glm::scale(model, glm::vec3(0.015f));
//        shader.setMat4("uM", model);
//        puffer.Draw(shader);
//
//        shader.setInt("uUseTexture", 0);
//
//        // Bubbles
//        glBindVertexArray(sphereVAO);
//        shader.setVec3("uObjectColor", 0.7f, 0.9f, 1.0f);
//        for (const auto& b : bubbles) {
//            model = glm::scale(glm::translate(glm::mat4(1), b.pos), glm::vec3(b.radius));
//            shader.setMat4("uM", model);
//            glDrawElements(GL_TRIANGLES, 20 * 20 * 6, GL_UNSIGNED_INT, 0);
//        }
//
//        // Glass walls
//        glBindVertexArray(cubeVAO);
//        shader.setVec3("uObjectColor", 0.3f, 0.5f, 0.7f);
//        shader.setFloat("uAlpha", 0.2f);
//        model = glm::scale(glm::translate(glm::mat4(1), glm::vec3(0, 0, 1)), glm::vec3(2, 2, 0.02f));
//        shader.setMat4("uM", model);
//        glDrawElements(GL_TRIANGLES, 36, GL_UNSIGNED_INT, 0);
//        model = glm::scale(glm::translate(glm::mat4(1), glm::vec3(0, 0, -1)), glm::vec3(2, 2, 0.02f));
//        shader.setMat4("uM", model);
//        glDrawElements(GL_TRIANGLES, 36, GL_UNSIGNED_INT, 0);
//        model = glm::scale(glm::translate(glm::mat4(1), glm::vec3(-1, 0, 0)), glm::vec3(0.02f, 2, 2));
//        shader.setMat4("uM", model);
//        glDrawElements(GL_TRIANGLES, 36, GL_UNSIGNED_INT, 0);
//        model = glm::scale(glm::translate(glm::mat4(1), glm::vec3(1, 0, 0)), glm::vec3(0.02f, 2, 2));
//        shader.setMat4("uM", model);
//        glDrawElements(GL_TRIANGLES, 36, GL_UNSIGNED_INT, 0);
//
//        glfwSwapBuffers(window);
//        glfwPollEvents();
//    }
//
//    glDeleteVertexArrays(1, &cubeVAO);
//    glDeleteVertexArrays(1, &sphereVAO);
//    glDeleteVertexArrays(1, &planeVAO);
//    glDeleteTextures(1, &sandTexture);
//    glDeleteTextures(1, &woodTexture);
//    glfwTerminate();
//    return 0;
//}