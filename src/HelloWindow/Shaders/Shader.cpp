//
//  Shader.cpp
//  HelloWindow
//
//  Created by liyipeng on 16/8/2.
//  Copyright © 2016年 us. All rights reserved.
//

#include "Shader.hpp"

Shader::Shader(const GLchar *vertextPath, const GLchar *fragmentPath)
{
    std::string vertexCode;
    std::string fragmentCode;
    
    std::ifstream vShaderFile;
    std::ifstream fShaderFile;
    
    
    
    vShaderFile.exceptions(std::ifstream::badbit);
    fShaderFile.exceptions(std::ifstream::badbit);
    
    try {
        vShaderFile.open(vertextPath);
        fShaderFile.open(fragmentPath);
        
        std::stringstream vShaderStream;
        std::stringstream fShaderStream;
        
        vShaderStream << vShaderFile.rdbuf();
        fShaderStream << fShaderFile.rdbuf();
        
        vShaderFile.close();
        fShaderFile.close();
        
        vertexCode = vShaderStream.str();
        fragmentCode = fShaderStream.str();
        
        
    } catch (std::ifstream::failure e) {
        std::cout << "shader error" << std::endl;
    }
    
    
    const GLchar *vShaderCode = vertexCode.c_str();
    const GLchar *fSahderCode = fragmentCode.c_str();
    
    
    GLuint vertex, fragment;
    
    GLint success;
    
    GLchar infoLog[512];
    
    vertex = glCreateShader(GL_VERTEX_SHADER);
    
    
    glShaderSource(vertex, 1, &vShaderCode, NULL);
    glCompileShader(vertex);
    
    glGetShaderiv(vertex, GL_COMPILE_STATUS, &success);
    
    if (!success) {
        glGetShaderInfoLog(vertex, 512, NULL, infoLog);
        std::cout << infoLog << std::endl;
    }
    
    fragment = glCreateShader(GL_FRAGMENT_SHADER);
    
    glShaderSource(fragment, 1, &fSahderCode, NULL);
    glCompileShader(fragment);
    
    glGetShaderiv(fragment, GL_COMPILE_STATUS, &success);
    
    if (!success) {
        glGetShaderInfoLog(fragment, 512, NULL, infoLog);
        std::cout << infoLog << std::endl;
    }
    
    
    program = glCreateProgram();
    glAttachShader(program, vertex);
    glAttachShader(program, fragment);
    glLinkProgram(program);
    
    glGetProgramiv(program, GL_LINK_STATUS, &success);
    
    if (!success) {
        glGetProgramInfoLog(program, 512, NULL, infoLog);
        
        std::cout << infoLog << std::endl;
    }
    
    glDeleteShader(vertex);
    glDeleteShader(fragment);
}

void Shader::use()
{
    glUseProgram(program);
}

















































