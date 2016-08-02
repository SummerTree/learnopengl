//
//  TriangleMe.cpp
//  HelloWindow
//
//  Created by liyipeng on 16/8/2.
//  Copyright © 2016年 us. All rights reserved.
//

#include <iostream>

#define GLEW_STATIC
#include <GL/glew.h>

#include <GLFW/glfw3.h>

const GLint WIDTH = 800, HEIGHT = 600;

const GLchar *vertexShaderSource = "#version 330 core\n layout (location = 0) in vec3 position; void main() {gl_Position = vec4(position.x, position.y, position.z, 1.0);}\0";

const GLchar *fragmentShaderSource = "#version 330 core\n out vec4 color; void main() { color = vec4(1.0f, 0.5f, 0.2f, 1.0f);}\0";

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
    
    
    GLuint vertexShader = glCreateShader(GL_VERTEX_SHADER);
    glShaderSource(vertexShader, 1, &vertexShaderSource, NULL);
    glCompileShader(vertexShader);
    
    GLint success;
    GLchar infoLog[512];
    
    glGetShaderiv(vertexShader, GL_COMPILE_STATUS, &success);
    
    if (!success) {
        glGetShaderInfoLog(vertexShader, 512, NULL, infoLog);
        std::cout << infoLog << std::endl;
    }
    
    GLuint fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
    glShaderSource(fragmentShader, 1, &fragmentShaderSource, NULL);
    glCompileShader(fragmentShader);
    
    glGetShaderiv(fragmentShader, GL_COMPILE_STATUS, &success);
    
    if (!success) {
        glGetShaderInfoLog(fragmentShader, 512, NULL, infoLog);
        std::cout << infoLog << std::endl;
    }
    
    GLuint program = glCreateProgram();
    glAttachShader(program, vertexShader);
    glAttachShader(program, fragmentShader);
    glLinkProgram(program);
    
    glGetProgramiv(program, GL_LINK_STATUS, &success);
    
    if (!success) {
        glGetProgramInfoLog(program, 512, NULL, infoLog);
        std::cout << infoLog << std::endl;
    }
    
    
    glDeleteShader(vertexShader);
    glDeleteShader(fragmentShader);
    
    
   
    
    
    GLfloat vertices[] = {
        -0.5, -0.5, 0.0,
        0.5, -0.5, 0.0,
        -0.5, 0.5, 0.0,
        0.5, -0.5, 0.0,
        0.5, 0.5, 0.0,
        -0.5, 0.5, 0.0
        
    };
    
    GLuint indices[] = {
        0, 1, 3,
        1, 2, 3
        
    };
    
    GLuint VBO, VAO, EBO;
    
    glGenVertexArrays(1, &VAO);
    glGenBuffers(1, &VBO);
    glGenBuffers(1, &EBO);
    
    glBindVertexArray(VAO);
    
    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);
    
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);

    
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(GLfloat), (GLvoid*)0);
    
    glEnableVertexAttribArray(0);
    
    glBindVertexArray(0);
    
    
    bool b = true;
    
    int i = 0;
    
    while (!glfwWindowShouldClose(window)) {
        
        glfwPollEvents();
        
        glClearColor(0.2, 0.3, 0.3, 1.0);
        
        glClear(GL_COLOR_BUFFER_BIT);
        
        glUseProgram(program);
        
        glBindVertexArray(VAO);
        
        if (b) {
            glDrawArrays(GL_TRIANGLES, 0, 3);
        } else {
            glDrawArrays(GL_TRIANGLES, 3, 3);
        }
        
        i++;
        
        if (i > 100) {
            b = !b;
            i = 0;
        }
        
        
        
//        glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
        
        
        
        glBindVertexArray(0);
        
        glfwSwapBuffers(window);
        
    }
    
    glDeleteVertexArrays(1, &VAO);
    
    glDeleteBuffers(1, &VBO);
    
    glfwTerminate();
    
    return 0;
    
}











































