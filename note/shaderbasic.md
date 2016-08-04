## Basic thing need to know about shader
1. the most common use shader is vertex shader and fragment shader.To use a shader you need to write it as a string variable in OpenGL program source file or as a separate file.Then create the shader use glCreateShader -> glShaderSource -> glCompileShader -> check compile result -> create a shader programe glCreateProgram -> attach to the program glAttachShader -> link glLinkProgram, check result -> last glUseProgram
2. We can pass data from vertex shader to fragment shader,by use `out` and `in` keyword,the out and in variable must have the same type and name,such as `out vec3 vertexColor` in vertex shader and `in vec3 vertexColor` in fragment shader.
3. We can use `uniform` keyword to pass data from OpenGL program to vertex shader and fragment shader,by using glGetUniformLocation to get uniform location and glUniform4f to set value to it.