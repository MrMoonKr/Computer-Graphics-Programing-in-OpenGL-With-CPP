#include <iostream>
#include <sstream>          // stringstream
#include <fstream>          // ifstream

#include <glad/glad.h>      // Library for handling the loading of OpenGL functions, must be included before GLFW
#include <GLFW/glfw3.h>     // Library for handling window and user input

std::string g_Title = "2-6. 애니메이션 : 셰이더의 유니폼 변수 사용 예제";
std::string g_FPS   = "";

GLuint g_RenderingProgram;
GLuint g_VAO;

float getRandomFloat( float min, float max )
{
    return ( ( float )rand() / RAND_MAX ) * ( max - min ) + min;
}

void printShaderLog( GLuint shader )
{
    int logLength = 0;
    int writtenLength = 0;
    char* log;
    glGetShaderiv( shader, GL_INFO_LOG_LENGTH, &logLength );
    if ( logLength > 0 )
    {
        log = (char*)malloc( logLength );
        glGetShaderInfoLog( shader, logLength, &writtenLength, log );
        std::cout << "[에러] ShaderInfoLog : " << log << std::endl;
        free( log );
    }
}

void printProgramLog( GLuint program )
{
    int logLength = 0;
    int writtenLength = 0;
    char* log;
    glGetProgramiv( program, GL_INFO_LOG_LENGTH, &logLength );
    if ( logLength > 0 ) 
    {
        log = (char*)malloc( logLength );
        glGetProgramInfoLog( program, logLength, &writtenLength, log );
        std::cout << "[에러] ProgramInfoLog : " << log << std::endl;
        free( log );
    }
}

bool checkOpenGLError()
{
    bool foundError = false;
    int glErr = glGetError();
    while ( glErr != GL_NO_ERROR ) 
    {
        std::cout << "[에러] glError : " << glErr << std::endl;
        foundError = true;
        glErr = glGetError();
    }
    return foundError;
}

std::string readShaderSource( const char* filePath )
{
    std::string content = "";
    std::ifstream fileStream( filePath, std::ios::in );

    if ( false == fileStream.is_open() )
    {
        std::cerr << "Could not read file " << filePath << ". File does not exist." << std::endl;
        return "";
    }

    std::string line = "";
    while ( !fileStream.eof() )
    {
        getline( fileStream, line );
        content.append( line + "\n" );
    }

    fileStream.close();
    return content;
}

GLuint createShaderProgram()
{
    std::string vShaderStr = readShaderSource( "./data/shaders/vertex_shader24.glsl" );
    std::string fShaderStr = readShaderSource( "./data/shaders/fragment_shader24.glsl" );

    const char* vshaderSource = vShaderStr.c_str();
    const char* fshaderSource = fShaderStr.c_str();

    GLuint vShader = glCreateShader( GL_VERTEX_SHADER );
    GLuint fShader = glCreateShader( GL_FRAGMENT_SHADER );

    glShaderSource( vShader, 1, &vshaderSource, NULL );
    glShaderSource( fShader, 1, &fshaderSource, NULL );

    GLint vertCompiled;
    GLint fragCompiled;
    GLint linked;

    glCompileShader( vShader );
    checkOpenGLError();
    glGetShaderiv( vShader, GL_COMPILE_STATUS, &vertCompiled );
    if ( vertCompiled != 1 )
    {
        std::cout << "[에러] vertex compilation failed" << std::endl;
        printShaderLog( vShader );
    }

    glCompileShader( fShader );
    checkOpenGLError();
    glGetShaderiv( fShader, GL_COMPILE_STATUS, &fragCompiled );
    if ( fragCompiled != 1 )
    {
        std::cout << "[에러] fragment compilation failed" << std::endl;
        printShaderLog( fShader );
    }

    GLint vfProgram = glCreateProgram();
    glAttachShader( vfProgram, vShader );
    glAttachShader( vfProgram, fShader );

    glLinkProgram( vfProgram );
    checkOpenGLError();
    glGetProgramiv( vfProgram, GL_LINK_STATUS, &linked );
    if ( linked != 1 )
    {
        std::cout << "[에러] linking failed" << std::endl;
        printProgramLog( vfProgram );
    }

    return vfProgram;
}


void init( GLFWwindow* window )
{
    g_RenderingProgram = createShaderProgram();

    glGenVertexArrays( 1, &g_VAO );
    glBindVertexArray( g_VAO );

    glClearColor( 0.3f, 0.3f, 0.3f, 1.0f );
}

void checkInput( GLFWwindow* window )
{
    if ( GLFW_PRESS == glfwGetKey( window, GLFW_KEY_ESCAPE ) )
    {
        glfwSetWindowShouldClose( window, GLFW_TRUE );
    }
    else if ( GLFW_PRESS == glfwGetKey( window, GLFW_KEY_1 ) )
    {
        glClearColor( 1.0f, 0.0f, 0.0f, 1.0f );
    }
    else if ( GLFW_PRESS == glfwGetKey( window, GLFW_KEY_2 ) )
    {
        glClearColor( 0.0f, 1.0f, 0.0f, 1.0f );
    }
    else if ( GLFW_PRESS == glfwGetKey( window, GLFW_KEY_3 ) )
    {
        glClearColor( 0.0f, 0.0f, 1.0f, 1.0f );
    }
    else if ( GLFW_PRESS == glfwGetKey( window, GLFW_KEY_4 ) )
    {
        float r = getRandomFloat( 0.0f, 1.0f );
        float g = getRandomFloat( 0.0f, 1.0f );
        float b = getRandomFloat( 0.0f, 1.0f );
        glClearColor( r, g, b, 1.0f );
    }
}

void update( float deltaTime )
{
    // Do nothing
}

void display()
{
    glClear( GL_COLOR_BUFFER_BIT ); // 화면 지우기

    glPointSize( 64.0f );

    glUseProgram( g_RenderingProgram );
    glDrawArrays( GL_POINTS, 0, 1 );
}

int main( int argc, char** argv )
{
    if ( GLFW_TRUE != glfwInit() ) // GLFW 초기화
    {
        std::cout << "failed to initialize GLFW" << std::endl;
        return -1;
    }

    glfwWindowHint( GLFW_CONTEXT_VERSION_MAJOR, 4 );
    glfwWindowHint( GLFW_CONTEXT_VERSION_MINOR, 3 );
    glfwWindowHint( GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE );
    glfwWindowHint( GLFW_OPENGL_FORWARD_COMPAT, GLFW_TRUE );
    glfwWindowHint( GLFW_SCALE_TO_MONITOR, GLFW_TRUE );

    GLFWwindow* window = glfwCreateWindow( 800, 600, g_Title.c_str(), nullptr, nullptr );
    if ( nullptr == window )
    {
        std::cout << "failed to create window" << std::endl;
        glfwTerminate();
        return -1;
    }

    glfwMakeContextCurrent( window );

    if ( 0 == gladLoadGLLoader( (GLADloadproc)glfwGetProcAddress ) )
    {
        std::cout << "failed to initialize GLAD " << std::endl;
        return -1;
    }

    glfwSwapInterval( 0 ); // 수직동기화 해제

    init( window );

    double currentTime  = glfwGetTime();
    double previousTime = currentTime;
    double deltaTime    = 0.0;
    int frameCount      = 0;
    double frameTime    = 0.0;

    while ( !glfwWindowShouldClose( window ) )
    {
        currentTime     = glfwGetTime();
        deltaTime       = currentTime - previousTime;
        previousTime    = currentTime;

        frameCount++;
        frameTime += deltaTime;
        if ( frameTime >= 1.0 )
        {
            std::stringstream ss ;
            ss << "FPS : " << frameCount ;
            g_FPS = ss.str() ;
            std::cout << g_FPS << std::endl;

            frameCount  = 0;
            frameTime   = 0.0;
        }

        glfwPollEvents();       // 이벤트 읽기

        checkInput( window );   // 이벤트 처리
        update( deltaTime );    // 업데이트
        display();              // 화면 그리기

        glfwSwapBuffers( window );
    }

    glfwDestroyWindow( window );
    glfwTerminate();

    return 0;
}
