#include <iostream>

#include <glad/glad.h>      // Library for handling the loading of OpenGL functions, must be included before GLFW
#include <GLFW/glfw3.h>     // Library for handling window and user input

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

    glClearColor( 0.3f, 0.3f, 0.3f, 1.0f );
    
    while ( !glfwWindowShouldClose( window ) ) // 메인 루프 ( 게임 루프, 시뮬레이션 루프 )
    {
        glfwPollEvents();
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
        
        glClear( GL_COLOR_BUFFER_BIT ); // 화면 지우기

        glfwSwapBuffers( window ); // 화면 출력
    }

    glfwDestroyWindow( window );
    glfwTerminate();

    return 0;
}
