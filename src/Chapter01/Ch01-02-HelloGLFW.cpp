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

    // Initialize GLAD to load OpenGL functions
    if ( 0 == gladLoadGLLoader( (GLADloadproc)glfwGetProcAddress ) )
    {
        std::cout << "failed to initialize GLAD " << std::endl;
        return -1;
    }

    glfwTerminate();

    return 0;
}
