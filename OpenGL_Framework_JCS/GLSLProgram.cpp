#include "GLSLProgram.h"

#include <fstream>

#include <SDL_Framework_JCS\JCS_Errors.h>

namespace JCS_OpenGLEngine
{
    GLSLProgram::GLSLProgram()
        : m_numAttributes(0)
        , m_programId(0)
        , m_vertexShaderId(0)
        , m_fragmentShaderId(0)
    {

    }

    GLSLProgram::~GLSLProgram()
    {

    }

    //Compiles the shaders into a form that your GPU can understand
    void GLSLProgram::CompileShaders(const std::string& vertexShaderFilePath, const std::string& fragmentShaderFilepath)
    {
        //Vertex and fragment shaders are successfully compiled.
        //Now time to link them together into a program.
        //Get a program object.
        m_programId = glCreateProgram();

        //Create the vertex shader object, and store its ID
        m_vertexShaderId = glCreateShader(GL_VERTEX_SHADER);
        if (m_vertexShaderId == 0) {
            JCS_SDL_Engine::fatalError("Vertex shader failed to be created!");
        }

        //Create the fragment shader object, and store its ID
        m_fragmentShaderId = glCreateShader(GL_FRAGMENT_SHADER);
        if (m_fragmentShaderId == 0) {
            JCS_SDL_Engine::fatalError("Fragment shader failed to be created!");
        }

        //Compile each shader
        CompileShader(vertexShaderFilePath, m_vertexShaderId);
        CompileShader(fragmentShaderFilepath, m_fragmentShaderId);
    }

    void GLSLProgram::LinkShaders() 
    {

        //Attach our shaders to our program
        glAttachShader(m_programId, m_vertexShaderId);
        glAttachShader(m_programId, m_fragmentShaderId);

        //Link our program
        glLinkProgram(m_programId);

        //Note the different functions here: glGetProgram* instead of glGetShader*.
        GLint isLinked = 0;
        glGetProgramiv(m_programId, GL_LINK_STATUS, (int *)&isLinked);
        if (isLinked == GL_FALSE)
        {
            GLint maxLength = 0;
            glGetProgramiv(m_programId, GL_INFO_LOG_LENGTH, &maxLength);

            //The maxLength includes the NULL character
            std::vector<char> errorLog(maxLength);
            glGetProgramInfoLog(m_programId, maxLength, &maxLength, &errorLog[0]);



            //We don't need the program anymore.
            glDeleteProgram(m_programId);
            //Don't leak shaders either.
            glDeleteShader(m_vertexShaderId);
            glDeleteShader(m_fragmentShaderId);

            //print the error log and quit
            std::printf("%s\n", &(errorLog[0]));
            JCS_SDL_Engine::fatalError("Shaders failed to link!");
        }

        //Always detach shaders after a successful link.
        glDetachShader(m_programId, m_vertexShaderId);
        glDetachShader(m_programId, m_fragmentShaderId);
        glDeleteShader(m_vertexShaderId);
        glDeleteShader(m_fragmentShaderId);
    }

    //Adds an attribute to our shader. SHould be called between compiling and linking.
    void GLSLProgram::AddAttribute(const std::string& attributeName) {
        glBindAttribLocation(m_programId, m_numAttributes++, attributeName.c_str());
    }

    GLint GLSLProgram::GetUniformLocation(const std::string& uniformName) {
        GLint location = glGetUniformLocation(m_programId, uniformName.c_str());
        if (location == GL_INVALID_INDEX) {
            JCS_SDL_Engine::fatalError("Uniform " + uniformName + " not found in shader!");
        }
        return location;
    }

    //enable the shader, and all its attributes
    void GLSLProgram::Use() 
    {
        glUseProgram(m_programId);
        //enable all the attributes we added with addAttribute
        for (int i = 0; i < m_numAttributes; i++) {
            glEnableVertexAttribArray(i);
        }
    }

    //disable the shader
    void GLSLProgram::Unuse() 
    {
        glUseProgram(0);
        for (int i = 0; i < m_numAttributes; i++) {
            glDisableVertexAttribArray(i);
        }
    }

    //Compiles a single shader file
    void GLSLProgram::CompileShader(const std::string& filePath, GLuint id) 
    {

        //Open the file
        std::ifstream shaderFile(filePath);
        if (shaderFile.fail()) {
            perror(filePath.c_str());
            JCS_SDL_Engine::fatalError("Failed to open " + filePath);
        }

        //File contents stores all the text in the file
        std::string fileContents = "";
        //line is used to grab each line of the file
        std::string line;

        //Get all the lines in the file and add it to the contents
        while (std::getline(shaderFile, line)) {
            fileContents += line + "\n";
        }

        shaderFile.close();

        //get a pointer to our file contents c string;
        const char* contentsPtr = fileContents.c_str();
        //tell opengl that we want to use fileContents as the contents of the shader file
        glShaderSource(id, 1, &contentsPtr, nullptr);

        //compile the shader
        glCompileShader(id);

        //check for errors
        GLint success = 0;
        glGetShaderiv(id, GL_COMPILE_STATUS, &success);

        if (success == GL_FALSE)
        {
            GLint maxLength = 0;
            glGetShaderiv(id, GL_INFO_LOG_LENGTH, &maxLength);

            //The maxLength includes the NULL character
            std::vector<char> errorLog(maxLength);
            glGetShaderInfoLog(id, maxLength, &maxLength, &errorLog[0]);

            //Provide the infolog in whatever manor you deem best.
            //Exit with failure.
            glDeleteShader(id); //Don't leak the shader.

            //Print error log and quit
            std::printf("%s\n", &(errorLog[0]));
            JCS_SDL_Engine::fatalError("Shader " + filePath + " failed to compile");
        }
    }
}

