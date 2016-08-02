//
//  Shader.hpp
//  HelloWindow
//
//  Created by liyipeng on 16/8/2.
//  Copyright © 2016年 us. All rights reserved.
//

#ifndef Shader_hpp
#define Shader_hpp

#include <string>
#include <fstream>
#include <sstream>
#include <iostream>

#include <GL/glew.h>

class Shader {
    
    
public:
    GLuint program;
    
    Shader(const GLchar *vertexPath, const GLchar *fragmentPath);
    
    void use();
};

#endif /* Shader_hpp */
