#include <iostream>
#include <sstream>          // stringstream
#include <string>           // string

#include <glad/glad.h>      // Library for handling the loading of OpenGL functions, must be included before GLFW
#include <GLFW/glfw3.h>     // Library for handling window and user input


std::string g_Title = "1-1. GLFW3 Application 구조 정하기";
std::string g_FPS   = "";

/**
 * @brief 애플케이션 초기화 함수
 * @param window GLFW 윈도우 핸들
 */
void app_init( GLFWwindow* window )
{
    glClearColor( 0.3f, 0.3f, 0.3f, 1.0f );
}

/**
 * @brief 애플케이션 사용자 입력 처리 함수
 * @param window GLFW 윈도우 핸들
 */
void app_checkInput( GLFWwindow* window )
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
            std::cout << g_FPS << std::endl;

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
