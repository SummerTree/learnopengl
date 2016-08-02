//
//  TriangleMe.cpp
//  HelloWindow
//
//  Created by liyipeng on 16/8/2.
//  Copyright © 2016年 us. All rights reserved.
//

#include <iostream>
 #include <math.h>

#define GLEW_STATIC
#include <GL/glew.h>

#include <GLFW/glfw3.h>

#include "Shaders/Shader.hpp"

const GLint WIDTH = 800, HEIGHT = 600;

//const GLchar *vertexShaderSource = "#version 330 core\n layout (location = 0) in vec3 position; layout(location = 1) in vec3 color;out vec3 vertexColor; void main() {gl_Position = vec4(position.x, position.y, position.z, 1.0); vertexColor = color;}\0";
//
//const GLchar *fragmentShaderSource = "#version 330 core\n out vec4 color; in vec3 vertexColor;void main() { color = vec4(vertexColor, 1.0);}\0";
//
//const GLchar *fragmentShaderSource2 = "#version 330 core\n out vec4 color; uniform vec4 ourColor; void main() { color = ourColor;}\0";

int main()
{
    glfwInit();
    
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
    
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    
    glfwWindowHint(GLFW_RESIZABLE, GL_FALSE);
    
    GLFWwindow *window = glfwCreateWindow(WIDTH, HEIGHT, "LearnOpenGL", nullptr, nullptr);
    
    if (window == nullptr) {
        glfwTerminate();
        return -1;
    }
    
    glfwMakeContextCurrent(window);
    
    glewExperimental = GL_TRUE;
    
    glewInit();
    
    int width, height;
    
    glfwGetFramebufferSize(window, &width, &height);
    
    glViewport(0, 0, width, height);
    
    Shader shader = Shader("/Users/liyipeng/Documents/learn/learnopengl/src/HelloWindow/Shaders/triangle.vsh", "/Users/liyipeng/Documents/learn/learnopengl/src/HelloWindow/Shaders/triangle.fsh");
    
    Shader shader2 = Shader("/Users/liyipeng/Documents/learn/learnopengl/src/HelloWindow/Shaders/triangle.vsh", "/Users/liyipeng/Documents/learn/learnopengl/src/HelloWindow/Shaders/triangle2.fsh");
    
    GLfloat vertices[] = {
        -0.5, -0.5, 0.0,    1.0, 0.0, 0.0,
        0.5, -0.5, 0.0,     0.0, 1.0, 0.0,
        0.0, 0.0, 0.0,      0.0, 0.0, 1.0
    };
    
    
    
    
    GLuint VBO, VAO;
    
    glGenVertexArrays(1, &VAO);
    glGenBuffers(1, &VBO);
    
    glBindVertexArray(VAO);
    
    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);
    
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(GLfloat), (GLvoid*)0);
    
    glEnableVertexAttribArray(0);
    
    glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(GLfloat), (GLvoid*)(3 * sizeof(GLfloat)));
    
    glEnableVertexAttribArray(1);
    
    glBindVertexArray(0);
    
    
    GLfloat vertices2[] = {
        0.0, 0.0, 0.0,
        0.5, 0.0, 0.0,
        0.5, 0.5, 0.0
    };
    
    GLuint VBO2, VAO2;
    
    glGenVertexArrays(1, &VAO2);
    glGenBuffers(1, &VBO2);
    
    glBindVertexArray(VAO2);
    
    glBindBuffer(GL_ARRAY_BUFFER, VBO2);
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices2), vertices2, GL_STATIC_DRAW);
    
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(GLfloat), (GLvoid*)0);
    
    glEnableVertexAttribArray(0);
    
    glBindVertexArray(0);
    
    shader.use();
    
    GLint xOffsetLocation = glGetUniformLocation(shader.program, "xOffset");
    
    glUniform1f(xOffsetLocation, -0.5);
    
    while (!glfwWindowShouldClose(window)) {
        
       
        glfwPollEvents();
        
        glClearColor(0.2, 0.3, 0.3, 1.0);
        
        glClear(GL_COLOR_BUFFER_BIT);
        
        shader.use();
        
        glBindVertexArray(VAO);
        
        glDrawArrays(GL_TRIANGLES, 0, 3);
        
        
        GLfloat timeValue = glfwGetTime();
        
        GLfloat greenValue = (sin(timeValue)/2) + 0.5;
        
        GLint vertexColorLocation = glGetUniformLocation(shader2.program, "ourColor");
        
        shader2.use();
        
        glUniform4f(vertexColorLocation, 0.0f, greenValue, 0.0, 1.0);
        
        glBindVertexArray(VAO2);
        
        glDrawArrays(GL_TRIANGLES, 0, 3);
        
        glBindVertexArray(0);
        
        glfwSwapBuffers(window);
        
    }
    
    glDeleteVertexArrays(1, &VAO);
    
    glDeleteBuffers(1, &VBO);
    
    glfwTerminate();
    
    return 0;
    
}











































