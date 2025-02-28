#include <iostream>

#include <glad/glad.h>      // Library for handling the loading of OpenGL functions, must be included before GLFW
#include <GLFW/glfw3.h>     // Library for handling window and user input

float getRandomFloat( float min, float max )
{
    return ( ( float )rand() / RAND_MAX ) * ( max - min ) + min;
}

void init( GLFWwindow* window )
{
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

    GLFWwindow* window = glfwCreateWindow( 800, 600, "2장. GLFW3 Application", nullptr, nullptr );
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
            std::cout << "FPS : " << frameCount << std::endl;
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
