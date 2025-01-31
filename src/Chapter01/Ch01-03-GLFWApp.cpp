#include <iostream>

#include <glad/glad.h>
#include <GLFW/glfw3.h>

int main( int argc, char** argv )
{
    std::cout << "Hello, GLFW!, 안녕, 지엘에프더블유" << std::endl;

    if ( GLFW_TRUE != glfwInit() )
    {
        std::cout << "failed to initialize GLFW" << std::endl;
        return -1;
    }

    glfwWindowHint( GLFW_CONTEXT_VERSION_MAJOR, 4 );
    glfwWindowHint( GLFW_CONTEXT_VERSION_MINOR, 3 );
    glfwWindowHint( GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE );
    glfwWindowHint( GLFW_OPENGL_FORWARD_COMPAT, GLFW_TRUE );

    GLFWwindow* window = glfwCreateWindow( 1024, 768, "GLFW Application", nullptr, nullptr );
    if ( nullptr == window )
    {
        std::cout << "failed to create window" << std::endl;
        glfwTerminate();
        return -1;
    }

    glfwMakeContextCurrent( window );

    // Initialize GLAD to load OpenGL functions
    if ( 0 == gladLoadGLLoader( (GLADloadproc)glfwGetProcAddress ) )
    {
        std::cout << "failed to initialize GLAD " << std::endl;
        return -1;
    }

    glClearColor( 0.3f, 0.3f, 0.3f, 1.0f );

    while ( !glfwWindowShouldClose( window ) )
    {
        glfwPollEvents();
        if ( GLFW_PRESS == glfwGetKey( window, GLFW_KEY_ESCAPE ) )
        {
            glfwSetWindowShouldClose( window, GLFW_TRUE );
        }

        glClear( GL_COLOR_BUFFER_BIT );

        glfwSwapBuffers( window );
    }

    glfwDestroyWindow( window );
    glfwTerminate();

    return 0;
}
