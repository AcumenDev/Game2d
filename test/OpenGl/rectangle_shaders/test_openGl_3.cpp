#ifdef _WIN32
#include <windows.h>

#endif
#include <memory>
#include <iostream>
#include <fstream>
#include <vector>
#include <SDL.h>
#include "GL/glew.h"

const int SCREEN_WIDTH = 640;
const int SCREEN_HEIGHT = 480;

using std::cout;
using std::endl;

#define OpenGLCheckErrorMacro()( OpenGLCheckError(__FILE__, __LINE__))

void OpenGLCheckError(std::string file, int rowNuber) {
    GLenum errorCode = glGetError();
    if (errorCode != GL_NO_ERROR) {
        std::string resultError;
        switch (errorCode) {
            case
                GL_INVALID_ENUM : {
                resultError = "GL_INVALID_ENUM : An unacceptable value is specified for an enumerated argument. The offending command is ignored and has no other side effect than to set the error flag.";
            }
            case
                GL_INVALID_VALUE: {
                resultError = "GL_INVALID_VALUE : A numeric argument is out of range. The offending command is ignored and has no other side effect than to set the error flag.";
            }
            case
                GL_INVALID_OPERATION: {
                resultError = "GL_INVALID_OPERATION : The specified operation is not allowed in the current state. The offending command is ignored and has no other side effect than to set the error flag.";
            }
            case
                GL_INVALID_FRAMEBUFFER_OPERATION: {
                resultError = "GL_INVALID_FRAMEBUFFER_OPERATION : The framebuffer object is not complete. The offending command is ignored and has no other side effect than to set the error flag.";
            }
            case
                GL_OUT_OF_MEMORY: {
                resultError = "GL_OUT_OF_MEMORY : There is not enough memory left to execute the command. The state of the GL is undefined, except for the state of the error flags, after this error is recorded.";
            }
            case
                GL_STACK_UNDERFLOW: {
                resultError = "GL_STACK_UNDERFLOW : An attempt has been made to perform an operation that would cause an internal stack to underflow.";
            }
            case
                GL_STACK_OVERFLOW: {
                resultError = "GL_STACK_OVERFLOW : An attempt has been made to perform an operation that would cause an internal stack to overflow.";
            }
            default:
                resultError = "OpenGL ERROR ";
        }
        cout << "Ошибка OpenGL: " << errorCode << " " << resultError << " Файл: " << file << " Строка " << rowNuber << endl;
    }
}
enum ShaderType {
    Vertex,
    Fragment
};


class Shader {

public:

    Shader(GLuint _shaderId) : _shaderId(_shaderId) {
    }

    GLuint get_shaderId() const {
        return _shaderId;
    }

    virtual ~Shader() {
        glDeleteShader(_shaderId);
    }
private:
    GLuint _shaderId;
};

class ShaderManager {
public:
    std::shared_ptr<Shader> GetShader(std::string path, ShaderType type) {

        std::string shaderCode;
        std::ifstream shaderStream(path, std::ios::in);
        if (shaderStream.is_open()) {
            std::string line = "";
            while (getline(shaderStream, line)) {
                shaderCode += "\n" + line;
            }
            shaderStream.close();
        } else {
            cout << "Не смогли открыть файл с шейдером : " << path.c_str() << endl;
        }


        GLuint shaderId;
        if (type == ShaderType::Fragment) {
            shaderId = glCreateShader(GL_FRAGMENT_SHADER);
        } else {
            shaderId = glCreateShader(GL_VERTEX_SHADER);
        }


        GLint Result = GL_FALSE;
        int InfoLogLength;

        cout << "Компиляция шейдера : " << path.c_str() << endl;
        char const *shaderSourcePointer = shaderCode.c_str();
        glShaderSource(shaderId, 1, &shaderSourcePointer, NULL);
        glCompileShader(shaderId);

        glGetShaderiv(shaderId, GL_COMPILE_STATUS, &Result);
        glGetShaderiv(shaderId, GL_INFO_LOG_LENGTH, &InfoLogLength);
        std::vector<char> shaderErrorMessage(InfoLogLength);
        glGetShaderInfoLog(shaderId, InfoLogLength, NULL, &shaderErrorMessage[0]);
        if (Result == GL_FALSE) {
            cout << "Ошибка при компиляция шейдера : " << &shaderErrorMessage[0] << endl;
        }

        return std::make_shared<Shader>(shaderId);

    }
};


class ShaderProgram {

public:
    ShaderProgram() {
        _programID = glCreateProgram();
    }
    ShaderProgram &AttachShader(const std::shared_ptr<Shader> shader) {
        glAttachShader(_programID, shader->get_shaderId());
        return *this;
    }
    void Link() {
        cout << "Линкуем  шейдерную программу" << endl;
        glLinkProgram(_programID);
        GLint Result = GL_FALSE;
        int InfoLogLength;

        glGetProgramiv(_programID, GL_LINK_STATUS, &Result);
        glGetProgramiv(_programID, GL_INFO_LOG_LENGTH, &InfoLogLength);
        std::vector<char> ProgramErrorMessage(std::max(InfoLogLength, int(1)));
        glGetProgramInfoLog(_programID, InfoLogLength, NULL, &ProgramErrorMessage[0]);
        if (Result == GL_FALSE) {
            cout << "Ошибка при линковании шейдерной программы : " << &ProgramErrorMessage[0] << endl;
        }
    }
    void Use() {
        glUseProgram(_programID);
    }

    ~ShaderProgram() {
        glDeleteProgram(_programID);
    }

private:
    GLuint _programID;
};

void PrintOpenGlVersion() {
    const GLubyte *version = glGetString(GL_VERSION);
    const GLubyte *vendor = glGetString(GL_VENDOR);
    const GLubyte *renderer = glGetString(GL_RENDERER);

    const GLubyte *glslVersion = glGetString(GL_SHADING_LANGUAGE_VERSION);

    cout << "Renderer: " << renderer << endl;
    cout << "Vendor: " << vendor << endl;
    cout << "OpenGL Version: " << version << endl;
    cout << "glsl Version: " << glslVersion << endl;

    GLint numb_extensions;

    glGetIntegerv(GL_NUM_EXTENSIONS, &numb_extensions);
    cout << "Extensions: " << numb_extensions << " \n" << endl;
}


// Это будет идентификатором нашего буфера вершин
GLuint vertexbuffer;


void Draw() {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

// Указываем, что первым буфером атрибутов будут вершины
    glEnableVertexAttribArray(0);
    glBindBuffer(GL_ARRAY_BUFFER, vertexbuffer);

    glVertexAttribPointer(
            0,                  // Атрибут 0. Подробнее об этом будет рассказано в части, посвященной шейдерам.
            3,                  // Размер
            GL_FLOAT,           // Тип
            GL_FALSE,           // Указывает, что значения не нормализованы
            0,                  // Шаг
            (void *) 0            // Смещение массива в буфере
    );

// Вывести треугольник!
   glDrawArrays(GL_TRIANGLES, 0, 4); // Начиная с вершины 0, всего 3 вершины -> один треугольник

    glDisableVertexAttribArray(0);
}

#ifdef _WIN32
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nShowCmd)
#else
int main(int argc, char* argv[])
#endif
{
    SDL_Window *gWindow = SDL_CreateWindow("Game", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN | SDL_WINDOW_OPENGL);
    if (gWindow == nullptr) {
        //_log-> Error("Window could not be created! SDL Error: "+ std::string(SDL_GetError()));

    }

    SDL_GLContext glContext = SDL_GL_CreateContext(gWindow);
    if (glContext == nullptr) {
        //  _log-> Error("GLContext could not be created! SDL Error: "+ std::string(SDL_GetError()));

    }

    SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1);

    PrintOpenGlVersion();

    // Initialize GLEW
    glewExperimental = true; // Needed for core profile
    if (glewInit() != GLEW_OK) {
        fprintf(stderr, "Failed to initialize GLEW\n");

    }

    GLuint VertexArrayID;
    glGenVertexArrays(1, &VertexArrayID);
    glBindVertexArray(VertexArrayID);

// Массив 3 векторов, которые являются вершинами треугольника
    static const GLfloat g_vertex_buffer_data[] = {
            -1.0f, -1.0f, 0.0f,
            1.0f, -1.0f, 0.0f,
            0.0f, 1.0f, 0.0f,
    };

// Создадим 1 буфер и поместим в переменную vertexbuffer его идентификатор
    glGenBuffers(1, &vertexbuffer);

// Сделаем только что созданный буфер текущим
    glBindBuffer(GL_ARRAY_BUFFER, vertexbuffer);

// Передадим информацию о вершинах в OpenGL
    glBufferData(GL_ARRAY_BUFFER, sizeof(g_vertex_buffer_data), g_vertex_buffer_data, GL_STATIC_DRAW);

    ShaderManager shaderManager;

    auto vertexShader = shaderManager.GetShader("../code/test/OpenGl/rectangle_shaders/Simple.vertex.glsl", ShaderType::Vertex);
    OpenGLCheckErrorMacro();
    auto fragmentShader = shaderManager.GetShader("../code/test/OpenGl/rectangle_shaders/Simple.fragment.glsl", ShaderType::Fragment);
    OpenGLCheckErrorMacro();
    ShaderProgram shaderProgram;
    OpenGLCheckErrorMacro();
    shaderProgram.AttachShader(vertexShader).AttachShader(fragmentShader).Link();
    OpenGLCheckErrorMacro();
    shaderProgram.Use();
    OpenGLCheckErrorMacro();
    bool _run = true;
    while (_run) {

        SDL_Event event;
        if (SDL_PollEvent(&event) == 0) {
            continue;
        }

        switch (event.type) {
            case SDL_QUIT : {
                _run = false;
                break;
            }
        }
        Draw();

        SDL_GL_SwapWindow(gWindow);
    }

    return 0;
}