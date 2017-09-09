#ifndef __GLSLPROGRAM_H__
#define __GLSLPROGRAM_H__

#include "OpenGL_StdAfx.h"

namespace JCS_OpenGLEngine
{

    //====================================================================================-----------------------
    // Name : GLSLProgram
    // 
    // Description : This class handles the compilation, linking, and usage of a GLSL shader program.
    //        Reference: http://www.opengl.org/wiki/Shader_Compilation
    //====================================================================================-----------------------
    class GLSLProgram
    {
    private:
        int32 m_numAttributes;
        GLuint m_programId;

        GLuint m_vertexShaderId;
        GLuint m_fragmentShaderId;

    public:
        explicit GLSLProgram();
        ~GLSLProgram();

        void CompileShaders(const std::string& vertexShaderFilePath, const std::string& fragmentShaderFilepath);

        void LinkShaders();

        void AddAttribute(const std::string& attributeName);

        GLint GetUniformLocation(const std::string& uniformName);

        void Use();
        void Unuse();

    private:
        void CompileShader(const std::string& filePath, GLuint id);
    };

}

#endif // __GLSLPROGRAM_H__

