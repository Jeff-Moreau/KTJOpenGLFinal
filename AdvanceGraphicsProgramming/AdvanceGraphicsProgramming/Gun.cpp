#include "Gun.h"


Gun::Gun(int width, int height, const std::string& title)
    : width(width), height(height), gunX(400.0f), gunY(100.0f), bulletX(gunX), bulletY(gunY),
    bulletSpeed(5.0f), lastTime(glfwGetTime()), window(nullptr) {
    if (!glfwInit()) {
        std::cerr << "Failed to initialize GLFW." << std::endl;
        exit(-1);
    }

    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    window = glfwCreateWindow(width, height, title.c_str(), nullptr, nullptr);

    if (!window) {
        std::cerr << "Failed to create GLFW window." << std::endl;
        glfwTerminate();
        exit(-1);
    }

    glfwMakeContextCurrent(window);
    glfwSetFramebufferSizeCallback(window, [](GLFWwindow* window, int newWidth, int newHeight) {
        glViewport(0, 0, newWidth, newHeight);
        });
}

Gun::~Gun() {
    glfwTerminate();
}

void Gun::init() {
    glClearColor(0.0f, 0.0f, 0.0f, 1.0f);

    gunVertices[0] = 0.0f; gunVertices[1] = 0.0f; gunVertices[2] = 0.0f;
    gunVertices[3] = 20.0f; gunVertices[4] = 0.0f; gunVertices[5] = 0.0f;
    gunVertices[6] = 10.0f; gunVertices[7] = 50.0f; gunVertices[8] = 0.0f;

    bulletVertices[0] = 0.0f; bulletVertices[1] = 0.0f; bulletVertices[2] = 0.0f;
    bulletVertices[3] = 5.0f; bulletVertices[4] = 0.0f; bulletVertices[5] = 0.0f;
    bulletVertices[6] = 2.5f; bulletVertices[7] = 10.0f; bulletVertices[8] = 0.0f;

    glGenVertexArrays(1, &gunVAO);
    glGenVertexArrays(1, &bulletVAO);

    glBindVertexArray(gunVAO);
    GLuint gunVBO;
    glGenBuffers(1, &gunVBO);
    glBindBuffer(GL_ARRAY_BUFFER, gunVBO);
    glBufferData(GL_ARRAY_BUFFER, sizeof(gunVertices), gunVertices, GL_STATIC_DRAW);
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
    glEnableVertexAttribArray(0);

    glBindVertexArray(bulletVAO);
    GLuint bulletVBO;
    glGenBuffers(1, &bulletVBO);
    glBindBuffer(GL_ARRAY_BUFFER, bulletVBO);
    glBufferData(GL_ARRAY_BUFFER, sizeof(bulletVertices), bulletVertices, GL_STATIC_DRAW);
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
    glEnableVertexAttribArray(0);

    // Load shaders and create shader program (you need to provide your shader code)
    GLuint vertexShader = glCreateShader(GL_VERTEX_SHADER);
    const char* vertexShaderSource = R"(
        #version 330 core
        layout (location = 0) in vec3 aPos;
        uniform mat4 model;
        uniform mat4 view;
        uniform mat4 projection;
        void main() {
            gl_Position = projection * view * model * vec4(aPos, 1.0);
        }
    )";
    glShaderSource(vertexShader, 1, &vertexShaderSource, nullptr);
    glCompileShader(vertexShader);

    GLuint fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
    const char* fragmentShaderSource = R"(
        #version 330 core
        out vec4 FragColor;
        uniform vec3 color;
        void main() {
            FragColor = vec4(color, 1.0);
        }
    )";
    glShaderSource(fragmentShader, 1, &fragmentShaderSource, nullptr);
    glCompileShader(fragmentShader);

    shaderProgram = glCreateProgram();
    glAttachShader(shaderProgram, vertexShader);
    glAttachShader(shaderProgram, fragmentShader);
    glLinkProgram(shaderProgram);

    glDeleteShader(vertexShader);
    glDeleteShader(fragmentShader);
}

void Gun::processInput() {
    if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
        glfwSetWindowShouldClose(window, true);
}

void Gun::update() {
    double currentTime = glfwGetTime();
    double deltaTime = currentTime - lastTime;
    lastTime = currentTime;

    bulletY += bulletSpeed * static_cast<float>(deltaTime);

    if (bulletY > height) {
        bulletX = gunX;
        bulletY = gunY;
    }
}

void Gun::render() {
    glClear(GL_COLOR_BUFFER_BIT);

    glUseProgram(shaderProgram);

    // Render gun
    glBindVertexArray(gunVAO);
    glUniformMatrix4fv(glGetUniformLocation(shaderProgram, "model"), 1, GL_FALSE, glm::value_ptr(glm::mat4(1.0f)));
    glUniformMatrix4fv(glGetUniformLocation(shaderProgram, "view"), 1, GL_FALSE, glm::value_ptr(glm::mat4(1.0f)));
    glUniformMatrix4fv(glGetUniformLocation(shaderProgram, "projection"), 1, GL_FALSE, glm::value_ptr(glm::mat4(1.0f)));
    glUniform3f(glGetUniformLocation(shaderProgram, "color"), 1.0f, 0.0f, 0.0f);
    glDrawArrays(GL_TRIANGLES, 0, 3);

    // Render bullet
    glBindVertexArray(bulletVAO);
    glUniformMatrix4fv(glGetUniformLocation(shaderProgram, "model"), 1, GL_FALSE, glm::value_ptr(glm::translate(glm::mat4(1.0f), glm::vec3(bulletX, bulletY, 0.0f))));
    glUniformMatrix4fv(glGetUniformLocation(shaderProgram, "view"), 1, GL_FALSE, glm::value_ptr(glm::mat4(1.0f)));
    glUniformMatrix4fv(glGetUniformLocation(shaderProgram, "projection"), 1, GL_FALSE, glm::value_ptr(glm::mat4(1.0f)));
    glUniform3f(glGetUniformLocation(shaderProgram, "color"), 0.0f, 0.0f, 1.0f);
    glDrawArrays(GL_TRIANGLES, 0, 3);

    glBindVertexArray(0);
    glUseProgram(0);

    glfwSwapBuffers(window);
}

bool Gun::shouldClose() const {
    return glfwWindowShouldClose(window);
}