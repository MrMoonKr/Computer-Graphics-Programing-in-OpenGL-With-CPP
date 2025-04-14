#include "GLApp.h"
#include "GLAppState.h"

#include <string>
#include <sstream>

GLApp::GLApp()
: window( nullptr )
, current( nullptr )
{
}

GLApp::~GLApp()
{
}

void GLApp::init()
{
    glfwInit();

    glfwWindowHint( GLFW_CONTEXT_VERSION_MAJOR, 4 );
    glfwWindowHint( GLFW_CONTEXT_VERSION_MINOR, 3 );
    glfwWindowHint( GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE );
    glfwWindowHint( GLFW_OPENGL_FORWARD_COMPAT, GLFW_TRUE );
    glfwWindowHint( GLFW_SCALE_TO_MONITOR, GLFW_TRUE );

    
    window = glfwCreateWindow( 800, 600, "0장. GLFW3 Application", nullptr, nullptr );


    glfwMakeContextCurrent( window );

    gladLoadGLLoader( (GLADloadproc)glfwGetProcAddress );


    glfwSwapInterval( 0 ); // 최대한 빠르게 화면 출력 ( 수직동기화 해제 )
}

void GLApp::run()
{
    //this->init();

    double currentTime  = glfwGetTime();
    double previousTime = currentTime;
    double deltaTime    = 0.0;
    int frameCount      = 0;
    double frameTime    = 0.0;

    std::string g_FPS = "";
    
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

        // app_checkInput( window );       // 애플리케이션 사용자 입력 처리
        // app_update( (float)deltaTime ); // 애플리케이션 업데이트
        // app_display( window );          // 애플리케이션 렌더링 ( 화면 그리기 )
        if ( current )
        {
            current->onInput( window );
            current->onUpdate( window, (float)deltaTime );
            current->onRender( window );
        }

        glfwSwapBuffers( window );      // 화면 출력 요청
        glfwPollEvents();               // 이벤트 읽어서 버퍼에 저장
    }

    //this->term();
}

void GLApp::runWith( GLAppState* state )
{
    this->startWith( state );
    //this->changeState( state );
    this->run();
    //this->startWith( state );
    //this->changeState( state );
}

void GLApp::startWith( GLAppState* state )
{
    current = state;
    current->onEnter();
}

void GLApp::changeState( GLAppState* state )
{
    if ( current )
    {
        current->onExit();
    }

    current = state;
    current->onEnter();
}

void GLApp::term()
{
    glfwDestroyWindow( window );
    glfwTerminate();
    window = nullptr;
}





