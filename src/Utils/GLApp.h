#pragma once


#include <glad/glad.h>
#include <GLFW/glfw3.h>

//#include "GLAppState.h"
class GLAppState;

class GLApp
{
public:
    GLFWwindow* window;
    GLAppState* current;

public:
    GLApp();
    ~GLApp();

    void init();
    void term();

    void run();
    void runWith( GLAppState* state );

    void startWith( GLAppState* state );
    void changeState( GLAppState* state );

private:



};
