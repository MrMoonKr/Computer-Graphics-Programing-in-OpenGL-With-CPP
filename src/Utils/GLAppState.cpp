#include "GLAppState.h"

GLAppState::GLAppState( GLApp* owner )
: m_Owner( owner )
{
}

void GLAppState::onEnter()
{
}

void GLAppState::onExit()
{
}

void GLAppState::onInput( GLFWwindow* window )
{
}

void GLAppState::onResize( int width, int height )
{
}

void GLAppState::onUpdate( GLFWwindow* window, float deltaTime )
{
}

void GLAppState::onRender( GLFWwindow* window )
{
}
