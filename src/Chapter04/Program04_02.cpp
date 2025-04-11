#include <iostream>
#include <sstream>          // stringstream
#include <string>           // string
#include <fstream>          // ifstream

#include <glad/glad.h>      // Library for handling the loading of OpenGL functions, must be included before GLFW
#include <GLFW/glfw3.h>     // Library for handling window and user input
#include <glm/glm.hpp>      // Library for handling 3D math

#include "Utils.h"

using namespace std;

#define numVAOs 1
#define numVBOs 2

std::string g_Title = "4-2. glDrawArraysInstanced() 및 gl_InstanceID 사용하기";
std::string g_FPS   = "";

GLuint      g_RenderingProgram ;
GLuint      g_VAO[numVAOs];  // Vertex Array Object
GLuint      g_VBO[numVBOs]; // Vertex Buffer Object

float       g_CameraX = 0.0f ;
float       g_CameraY = 0.0f ;
float       g_CameraZ = 8.0f ;
float       g_CubeX = 0.0f ;
float       g_CubeY = -2.0f ;
float       g_CubeZ = 0.0f ;

GLuint      g_ProjectionMatrixLocation;
GLuint      g_ViewMatrixLocation;
GLuint      g_TimeFactorLocation;

//glm::mat4   g_RotationMatrix;
//glm::mat4   g_TranslationMatrix;
//glm::mat4   g_ModelMatrix;
glm::mat4   g_ViewMatrix;
glm::mat4   g_ProjectionMatrix;
//glm::mat4   g_ModelViewMatrix;

int g_Width = 800;
int g_Height = 600;
float g_Aspect = ( float )g_Width / ( float )g_Height;
float g_TimeFactor = 0.0f;


void setupVertices(void) 
{
    // 12 triangles ( 6 faces * 2 triangles ) * 3 vertices * 3 values (x, y, z)
    float vertexPositions[108] = 
    {
        -1.0f,  1.0f, -1.0f, -1.0f, -1.0f, -1.0f,  1.0f, -1.0f, -1.0f,
         1.0f, -1.0f, -1.0f,  1.0f,  1.0f, -1.0f, -1.0f,  1.0f, -1.0f,
         1.0f, -1.0f, -1.0f,  1.0f, -1.0f,  1.0f,  1.0f,  1.0f, -1.0f,
         1.0f, -1.0f,  1.0f,  1.0f,  1.0f,  1.0f,  1.0f,  1.0f, -1.0f,
         1.0f, -1.0f,  1.0f, -1.0f, -1.0f,  1.0f,  1.0f,  1.0f,  1.0f,
        -1.0f, -1.0f,  1.0f, -1.0f,  1.0f,  1.0f,  1.0f,  1.0f,  1.0f,
        -1.0f, -1.0f,  1.0f, -1.0f, -1.0f, -1.0f, -1.0f,  1.0f,  1.0f,
        -1.0f, -1.0f, -1.0f, -1.0f,  1.0f, -1.0f, -1.0f,  1.0f,  1.0f,
        -1.0f, -1.0f,  1.0f,  1.0f, -1.0f,  1.0f,  1.0f, -1.0f, -1.0f,
         1.0f, -1.0f, -1.0f, -1.0f, -1.0f, -1.0f, -1.0f, -1.0f,  1.0f,
        -1.0f,  1.0f, -1.0f,  1.0f,  1.0f, -1.0f,  1.0f,  1.0f,  1.0f,
         1.0f,  1.0f,  1.0f, -1.0f,  1.0f,  1.0f, -1.0f,  1.0f, -1.0f,
    };
    
    glGenVertexArrays( 1, g_VAO );  // creates VAO and returns the integer ID
    glBindVertexArray( g_VAO[0] );

    glGenBuffers( numVBOs, g_VBO );  // creates VBO and returns the integer ID
    glBindBuffer( GL_ARRAY_BUFFER, g_VBO[0] );
    glBufferData( GL_ARRAY_BUFFER, sizeof( vertexPositions ), vertexPositions, GL_STATIC_DRAW );

    GLenum err = glGetError();
    if ( err != GL_NO_ERROR ) 
    {
        std::cerr << "[에러] Error al configurar los vértices: " << err << std::endl;
    }
}

/**
 * @brief 애플케이션 초기화 함수
 * @param window GLFW 윈도우 핸들
 */
void app_init( GLFWwindow* window )
{
    glClearColor( 0.3f, 0.3f, 0.3f, 1.0f );

    g_RenderingProgram = Utils::createShaderProgram( 
        "./data/shaders/vertex_shader42.glsl",
        "./data/shaders/fragment_shader42.glsl" 
    );
    if ( Utils::checkOpenGLError() )
    {
        std::cout << "[에러] 셰이더 프로그램 생성 실패" << std::endl;
    }

    glfwGetFramebufferSize( window, &g_Width, &g_Height );
    g_Aspect = ( float )g_Width / ( float )g_Height;

    g_ProjectionMatrix = glm::perspective<float>( glm::radians( 60.0f ), g_Aspect, 0.1f, 10000.0f );  // 1.0472 radians = 60 degrees
    g_CameraX   = 0.0f ;
    g_CameraY   = 0.0f ;
    g_CameraZ   = 8.0f ;
    g_CubeX     = 0.0f ;
    g_CubeY     = -2.0f ;
    g_CubeZ     = 0.0f ;

    setupVertices();
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
        float r = Utils::getRandomFloat( 0.0f, 1.0f );
        float g = Utils::getRandomFloat( 0.0f, 1.0f );
        float b = Utils::getRandomFloat( 0.0f, 1.0f );
        glClearColor( r, g, b, 1.0f );
    }

    if ( GLFW_PRESS == glfwGetKey( window, GLFW_KEY_UP ) )
    {
        g_CameraY += 0.01f;
    }
    else if ( GLFW_PRESS == glfwGetKey( window, GLFW_KEY_DOWN ) )
    {
        g_CameraY -= 0.01f;
    }
    else if ( GLFW_PRESS == glfwGetKey( window, GLFW_KEY_LEFT ) )
    {
        g_CameraX -= 0.01f;
    }
    else if ( GLFW_PRESS == glfwGetKey( window, GLFW_KEY_RIGHT ) )
    {
        g_CameraX += 0.01f;
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
void app_display( GLFWwindow* window )
{
    glClear( GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT ); // 화면 지우기

    glUseProgram( g_RenderingProgram );
    g_ViewMatrixLocation = glGetUniformLocation( g_RenderingProgram, "uViewMatrix" );
    g_ProjectionMatrixLocation = glGetUniformLocation( g_RenderingProgram, "uProjectionMatrix" );
    g_TimeFactorLocation = glGetUniformLocation( g_RenderingProgram, "uTimeFactor" );

    glfwGetFramebufferSize( window, &g_Width, &g_Height );
    g_Aspect = (float)g_Width / (float)g_Height;
    g_ProjectionMatrix = glm::perspective( 1.0472f, g_Aspect, 0.1f, 10000.0f );  // 1.0472 radians = 60 degrees

    g_ViewMatrix  = glm::translate( glm::mat4(1.0f), glm::vec3( -g_CameraX, -g_CameraY, -g_CameraZ ) );
    //g_ModelMatrix = glm::translate( glm::mat4(1.0f), glm::vec3( g_CubeX, g_CubeY, g_CubeZ ) );
    //g_ModelViewMatrix = g_ViewMatrix * g_ModelMatrix ;

    glUniformMatrix4fv( g_ViewMatrixLocation, 1, GL_FALSE, glm::value_ptr( g_ViewMatrix ) ) ;
    glUniformMatrix4fv( g_ProjectionMatrixLocation, 1, GL_FALSE, glm::value_ptr( g_ProjectionMatrix ) ) ;

    g_TimeFactor = glfwGetTime();
    glUniform1f( g_TimeFactorLocation, g_TimeFactor );

    glBindBuffer( GL_ARRAY_BUFFER, g_VBO[0] );  // makes the 0th buffer "active"
    glVertexAttribPointer( 0, 3, GL_FLOAT, GL_FALSE, 0, 0 );  // associates 0th attribute with buffer
    glEnableVertexAttribArray( 0 );  // enable the 0th vertex attribute
    
    glEnable( GL_DEPTH_TEST );
    glDepthFunc( GL_LEQUAL );

    //glDrawArrays( GL_TRIANGLES, 0, 36 ); // 3 * ( 2 * 6 ) = 36 triangles
    glDrawArraysInstanced( GL_TRIANGLES, 0, 36, 100000 ); // 3 * ( 2 * 6 ) = 36 triangles, 100000 instances
    
    GLenum err = glGetError();
    if ( err != GL_NO_ERROR ) 
    {
        std::cerr << "[에러] Error al renderizar : " << err << std::endl;
    }
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
        app_display( window );          // 애플리케이션 렌더링 ( 화면 그리기 )

        glfwSwapBuffers( window );      // 화면 출력 요청
        glfwPollEvents();               // 이벤트 읽어서 버퍼에 저장
    }

    app_term( window );                 // 애플리케이션 종료

    glfwDestroyWindow( window );
    glfwTerminate();

    return 0;
}
