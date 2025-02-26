#include <iostream>

#include <glad/glad.h>      // Library for handling the loading of OpenGL functions, must be included before GLFW
#include <GLFW/glfw3.h>     // Library for handling window and user input

int main( int argc, char** argv )
{
    std::cout << "Hello, GLFW!, 안녕, 지엘에프더블유" << std::endl;

    if ( GLFW_TRUE != glfwInit() )
    {
        std::cout << "failed to initialize GLFW" << std::endl;
        return -1;
    }

    // Initialize GLAD to load OpenGL functions
    if ( 0 == gladLoadGLLoader( (GLADloadproc)glfwGetProcAddress ) )
    {
        std::cout << "failed to initialize GLAD " << std::endl;
        return -1;
    }

    glfwTerminate();

    return 0;
}
