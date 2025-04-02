#include <iostream>
#include <sstream>          // stringstream
#include <string>           // string

#include <glad/glad.h>      // Library for handling the loading of OpenGL functions, must be included before GLFW
#include <GLFW/glfw3.h>     // Library for handling window and user input


std::string g_Title = "2-3. GPU 셰이더 관련 에러 처리";
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

/**
 * @brief 셰이더 프로그램 생성 함수
 * @return 셰이더 프로그램 핸들
 */
GLuint createShaderProgram()
{
    const char* vshaderSource = R"(
        #version 430

        void main( void )
        {
            gl_Position = vec4( 0.0, 0.0, 0.0, 1.0 );
        }
    )";

    const char* fshaderSource = R"(
        #version 430
        
        out vec4 color;
        void main( void )
        {
            color = vec4( 1.0, 1.0, 0.0, 1.0 );
        }
    )";

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


/**
 * @brief 애플케이션 초기화 함수
 * @param window GLFW 윈도우 핸들
 */
void app_init( GLFWwindow* window )
{
    glClearColor( 0.3f, 0.3f, 0.3f, 1.0f );

    g_RenderingProgram = createShaderProgram();

    glGenVertexArrays( 1, &g_VAO );
    glBindVertexArray( g_VAO );
}

/**
 * @brief 애플케이션 사용자 입력 처리 함수
 * @param window GLFW 윈도우 핸들
 */
void app_checkInput( GLFWwindow* window )
{
    //window->setTitle( g_Title + " " + g_FPS );
    glfwSetWindowTitle( window, ( g_Title + " [ " + g_FPS + " ]" ).c_str() );

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

/**
 * @brief 애플케이션 업데이트 함수
 * @param deltaTime 프레임 간격 ( 초 단위 )
 */
void app_update( float deltaTime )
{
    // Do nothing
}

/**
 * @brief 애플케이션 렌더링 함수 ( 화면 그리기 )
 */
void app_display()
{
    glClear( GL_COLOR_BUFFER_BIT ); // 화면 지우기

    glPointSize( 64.0f );

    glUseProgram( g_RenderingProgram );
    glDrawArrays( GL_POINTS, 0, 1 );
}

/**
 * @brief 애플케이션 종료 함수
 * @param window GLFW 윈도우 핸들
 */
void app_term( GLFWwindow* window )
{
    // Do nothing
}

/**
 * @brief 메인 함수
 * @param argc 명령행 인자들 개수
 * @param argv 명령행 인자들 배열
 */
int main( int argc, char** argv )
{
    if ( GLFW_TRUE != glfwInit() )
    {
        std::cout << "[에러] failed to initialize GLFW" << std::endl;
        return -1;
    }

    // 여기서 호출시 에러 발생. 
    // 윈도우 생성 후에 호출 필요함.
    // if ( 0 == gladLoadGLLoader( (GLADloadproc)glfwGetProcAddress ) )
    // {
    //     std::cout << "failed to initialize GLAD " << std::endl;
    //     return -1;
    // }

    glfwWindowHint( GLFW_CONTEXT_VERSION_MAJOR, 4 );
    glfwWindowHint( GLFW_CONTEXT_VERSION_MINOR, 3 );
    glfwWindowHint( GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE );
    glfwWindowHint( GLFW_OPENGL_FORWARD_COMPAT, GLFW_TRUE );

    glfwWindowHint( GLFW_SCALE_TO_MONITOR, GLFW_TRUE );

    GLFWwindow* window = glfwCreateWindow( 800, 600, "0장. GLFW3 Application", nullptr, nullptr );
    if ( nullptr == window )
    {
        std::cout << "[에러] failed to create window" << std::endl;
        glfwTerminate();
        return -1;
    }

    glfwMakeContextCurrent( window );

    if ( 0 == gladLoadGLLoader( (GLADloadproc)glfwGetProcAddress ) )
    {
        std::cout << "[에러] failed to initialize GLAD " << std::endl;
        return -1;
    }

    glfwSwapInterval( 0 ); // 최대한 빠르게 화면 출력 ( 수직동기화 해제 )

    app_init( window );

    double currentTime  = glfwGetTime();
    double previousTime = currentTime;
    double deltaTime    = 0.0;
    int frameCount      = 0;
    double frameTime    = 0.0;
    
    while ( !glfwWindowShouldClose( window ) ) // 메인 루프 ( 게임 루프, 시뮬레이션 루프 )
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
            //std::cout << g_FPS << std::endl;

            frameCount  = 0;
            frameTime   = 0.0;
        }

        app_checkInput( window );       // 애플리케이션 사용자 입력 처리
        app_update( (float)deltaTime ); // 애플리케이션 업데이트
        app_display();                  // 애플리케이션 렌더링 ( 화면 그리기 )

        glfwSwapBuffers( window );      // 화면 출력 요청
        glfwPollEvents();               // 이벤트 읽어서 버퍼에 저장
    }

    app_term( window );                 // 애플리케이션 종료

    glfwDestroyWindow( window );
    glfwTerminate();

    return 0;
}
