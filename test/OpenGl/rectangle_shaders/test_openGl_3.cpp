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

// Это будет идентификатором нашего буфера вершин
GLuint vertexbuffer;



GLuint LoadShaders(const char * vertex_file_path,const char * fragment_file_path){

    GLuint ProgramID = glCreateProgram();

    // Создаем шейдеры
    GLuint VertexShaderID = glCreateShader(GL_VERTEX_SHADER);
    GLuint FragmentShaderID = glCreateShader(GL_FRAGMENT_SHADER);

    // Загружаем код Вершинного Шейдера из файла
    std::string VertexShaderCode;
    std::ifstream VertexShaderStream(vertex_file_path, std::ios::in);
    if(VertexShaderStream.is_open())
    {
        std::string Line = "";
        while(getline(VertexShaderStream, Line))
            VertexShaderCode += "\n" + Line;
        VertexShaderStream.close();
    }else
    {
        printf("Не смогли открыть вершинный шейдер : %s\n", vertex_file_path);
    }

    // Загружаем код Фрагментного шейдера из файла
    std::string FragmentShaderCode;
    std::ifstream FragmentShaderStream(fragment_file_path, std::ios::in);
    if(FragmentShaderStream.is_open()){
        std::string Line = "";
        while(getline(FragmentShaderStream, Line))
            FragmentShaderCode += "\n" + Line;
        FragmentShaderStream.close();
    }else
    {
        printf("Не смогли открыть Фрагментный шейдер : %s\n", vertex_file_path);

    }

    GLint Result = GL_FALSE;
     int InfoLogLength;

    // Компилируем Вершинный шейдер
    printf("Компиляция шейдера: %s\n", vertex_file_path);
    char const * VertexSourcePointer = VertexShaderCode.c_str();
    glShaderSource(VertexShaderID, 1, &VertexSourcePointer , NULL);
    glCompileShader(VertexShaderID);

    // Выполняем проверку Вершинного шейдера
    glGetShaderiv(VertexShaderID, GL_COMPILE_STATUS, &Result);
    glGetShaderiv(VertexShaderID, GL_INFO_LOG_LENGTH, &InfoLogLength);
    std::vector<char> VertexShaderErrorMessage(InfoLogLength);
    glGetShaderInfoLog(VertexShaderID, InfoLogLength, NULL, &VertexShaderErrorMessage[0]);
    if(Result == GL_FALSE) {
        fprintf(stdout, "%s\n", &VertexShaderErrorMessage[0]);
    }
    // Компилируем Фрагментный шейдер
    printf("Компиляция шейдера: %s\n", fragment_file_path);
    char const * FragmentSourcePointer = FragmentShaderCode.c_str();
    glShaderSource(FragmentShaderID, 1, &FragmentSourcePointer , NULL);
    glCompileShader(FragmentShaderID);

    // Проверяем Фрагментный шейдер
    glGetShaderiv(FragmentShaderID, GL_COMPILE_STATUS, &Result);
    glGetShaderiv(FragmentShaderID, GL_INFO_LOG_LENGTH, &InfoLogLength);
    std::vector<char> FragmentShaderErrorMessage(InfoLogLength);
    glGetShaderInfoLog(FragmentShaderID, InfoLogLength, NULL, &FragmentShaderErrorMessage[0]);
    if(Result == GL_FALSE) {
        fprintf(stdout, "%s\n", &FragmentShaderErrorMessage[0]);
    }
    // Создаем шейдерную программу и привязываем шейдеры к ней
    fprintf(stdout, "Создаем шейдерную программу и привязываем шейдеры к ней\n");

    glAttachShader(ProgramID, VertexShaderID);
    glAttachShader(ProgramID, FragmentShaderID);
    glLinkProgram(ProgramID);

    // Проверяем шейдерную программу
    glGetProgramiv(ProgramID, GL_LINK_STATUS, &Result);
    glGetProgramiv(ProgramID, GL_INFO_LOG_LENGTH, &InfoLogLength);
    std::vector<char> ProgramErrorMessage( std::max(InfoLogLength, int(1)) );
    glGetProgramInfoLog(ProgramID, InfoLogLength, NULL, &ProgramErrorMessage[0]);
    if(Result == GL_FALSE) {
        fprintf(stdout, "%s\n", &ProgramErrorMessage[0]);
    }
    glDeleteShader(VertexShaderID);
    glDeleteShader(FragmentShaderID);

    return ProgramID;
}

void  Draw()
{
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
            (void*)0            // Смещение массива в буфере
    );

// Вывести треугольник!
    glDrawArrays(GL_TRIANGLES, 0, 3); // Начиная с вершины 0, всего 3 вершины -> один треугольник

    glDisableVertexAttribArray(0);
}


void InitGlDraw() {
    GLuint VertexArrayID;
    glGenVertexArrays(1, &VertexArrayID);
    glBindVertexArray(VertexArrayID);
}
void Init(int width, int height)
{
    glViewport(0, 0, (GLsizei) width, (GLsizei) height);
    glEnable(GL_DEPTH_TEST);
    glDepthMask(GL_TRUE);
    glDepthFunc(GL_LEQUAL);
    glDepthRange(0.0f, 10.0f);

    glEnable (GL_BLEND);
    glBlendFunc (GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
}

#ifdef _WIN32
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nShowCmd)
#else
int main(int argc, char* argv[])
#endif
{
  //  auto _log = std::make_shared<Logger>();

    SDL_Window * gWindow = SDL_CreateWindow("Game", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN | SDL_WINDOW_OPENGL);
    if( gWindow == nullptr ) {
        //_log-> Error("Window could not be created! SDL Error: "+ std::string(SDL_GetError()));

    }

    SDL_GLContext  glContext  =  SDL_GL_CreateContext(gWindow);
    if( glContext == nullptr ) {
      //  _log-> Error("GLContext could not be created! SDL Error: "+ std::string(SDL_GetError()));

    }


    SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1);
    SDL_GL_SetAttribute(SDL_GL_DEPTH_SIZE, 24);

    SDL_GL_SetAttribute(SDL_GL_MULTISAMPLEBUFFERS,1);

    const GLubyte *version=glGetString(GL_VERSION);
    const GLubyte *vendor= glGetString(GL_VENDOR);
    const GLubyte *renderer=glGetString(GL_RENDERER);

    const GLubyte  *glslVersion =glGetString(GL_SHADING_LANGUAGE_VERSION);

    cout<<"Renderer: " << renderer<<endl;
    cout<<"Vendor: " << vendor<<endl;
    cout<<"OpenGL Version: " << version<<endl;
    cout<<"glsl Version: " << glslVersion<<endl;


    GLint nombre_extensions;

    glGetIntegerv(GL_NUM_EXTENSIONS, &nombre_extensions);
    cout<<"Extensions: " <<nombre_extensions<<" \n"<<endl;

// Initialize GLEW
    glewExperimental = true; // Needed for core profile
    if (glewInit() != GLEW_OK) {
        fprintf(stderr, "Failed to initialize GLEW\n");

    }
    Init(SCREEN_WIDTH, SCREEN_HEIGHT);
    InitGlDraw();

// Массив 3 векторов, которые являются вершинами треугольника
    static const GLfloat g_vertex_buffer_data[] = {
            -1.0f, -1.0f, 0.0f,
            1.0f, -1.0f, 0.0f,
            0.0f,  1.0f, 0.0f,
    };



// Создадим 1 буфер и поместим в переменную vertexbuffer его идентификатор
    glGenBuffers(1, &vertexbuffer);

// Сделаем только что созданный буфер текущим
    glBindBuffer(GL_ARRAY_BUFFER, vertexbuffer);

// Передадим информацию о вершинах в OpenGL
    glBufferData(GL_ARRAY_BUFFER, sizeof(g_vertex_buffer_data), g_vertex_buffer_data, GL_STATIC_DRAW);


// Создать и откомпилировать нашу шейдерную программу
    GLuint programID = LoadShaders( "../code/test/OpenGl/rectangle_shaders/Simple.vertex.glsl", "../code/test/OpenGl/rectangle_shaders/Simple.fragment.glsl" );
// Устанавливаем наш шейдер текущим
    glUseProgram(programID);

    bool _run = true;
    while (_run) {

        SDL_Event event;
        if (SDL_PollEvent(&event) == 0) {
            continue;
        }

        switch (event.type) {
            case SDL_QUIT : {
                _run= false;
                break;
            }
        }
        Draw();

        SDL_GL_SwapWindow(gWindow);
    }

    return 0;
}
