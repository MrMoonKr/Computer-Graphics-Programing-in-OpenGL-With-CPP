#pragma once

#include "GLApp.h"

class GLAppState
{
public:
    GLApp* m_Owner;

public:
    GLAppState( GLApp* owner );

    virtual void onEnter();
    virtual void onExit();

    virtual void onInput( GLFWwindow* window );
    virtual void onResize( int width, int height );
    virtual void onUpdate( GLFWwindow* window, float deltaTime );
    virtual void onRender( GLFWwindow* window );

};