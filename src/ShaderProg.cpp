#include "shaderprog.h"
#include <glad.h>
#include <fstream>
ShaderProg::ShaderProg()
{
    // constructor

    m_pId = glCreateProgram();
}
ShaderProg::~ShaderProg(){
    //destructor
    glDeleteProgram(m_pId);
}

void ShaderProg::link()
{
    // links the shader object into the program object
    glLinkProgram(m_pId);
}

void ShaderProg::use()
{
    glUseProgram(m_pId);
}

void ShaderProg::attach(const char *fileName, unsigned int shaderType)
{
    // create a shader object
    unsigned int shaderId = glCreateShader(shaderType);
    // get shader code
    std::string srcCode = readShaderFromFile(fileName);
    // define shader code
    const char *chSrcCode = &srcCode[0];
    glShaderSource(shaderId, 1, &chSrcCode, 0);
    // compile the shader object
    glCompileShader(shaderId);
    // attach shader object to the program object
    glAttachShader(m_pId, shaderId);
    // after adding the shader object, we don't need it anymore
    glDeleteShader(shaderId);
}

std::string ShaderProg::readShaderFromFile(const char *fileName)
{
    // reads the source code from the shader source file

    std::ifstream file(fileName);
    std::string stringData;
    if (file.is_open())
    {
        char aChar;
        // read each character one by one
        while ((aChar = file.get()) != EOF)
        {
            stringData += aChar;
        }
        file.close();
    }
    return stringData;
}