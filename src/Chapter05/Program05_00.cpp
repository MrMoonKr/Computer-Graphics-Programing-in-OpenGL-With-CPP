
#include "GLApp.h"
#include "GLAppState.h"

class MenuState : public GLAppState
{
public:
    MenuState( GLApp* app )
    : GLAppState( app )
    {
    }

    void onEnter() override
    {
        glClearColor( 0.3f, 0.3f, 0.3f, 1.0f );
    }

    void onExit() override
    {
        //
    }

    void onInput( GLFWwindow* window ) override
    {
        // Handle input events here
    }

    void onUpdate( GLFWwindow* window, float deltaTime ) override
    {
        // Update logic here
    }

    void onRender( GLFWwindow* window ) override
    {
        // Render logic here

        glClear( GL_COLOR_BUFFER_BIT );
    }
};

int main( int argc, char* argv[] )
{
    GLApp* theApp = new GLApp();

    theApp->init();
    theApp->runWith( new MenuState( theApp ) );
    theApp->term();

    delete theApp;

    return 0;
}