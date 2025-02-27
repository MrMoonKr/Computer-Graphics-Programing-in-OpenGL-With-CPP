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

void display( GLFWwindow* window )
{
    glClear( GL_COLOR_BUFFER_BIT );
    //glfwSwapBuffers( window );
}

int main( int argc, char** argv )
{
    if ( GLFW_TRUE != glfwInit() )
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

    glfwSwapInterval( 1 );

    init( window );
    
    while ( !glfwWindowShouldClose( window ) )
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
        else if ( GLFW_PRESS == glfwGetKey( window, GLFW_KEY_4 ) )
        {
            float r = getRandomFloat( 0.0f, 1.0f );
            float g = getRandomFloat( 0.0f, 1.0f );
            float b = getRandomFloat( 0.0f, 1.0f );
            glClearColor( r, g, b, 1.0f );
        }
        
        
        display( window );

        glfwSwapBuffers( window );
    }

    glfwDestroyWindow( window );
    glfwTerminate();

    return 0;
}
