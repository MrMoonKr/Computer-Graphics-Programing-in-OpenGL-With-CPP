#version 410

// 정점 속성 
layout ( location=0 ) in vec3  aPosition ;

// 유니폼 속성
uniform mat4 uModelViewMatrix ;
uniform mat4 uProjectionMatrix ;

// 출력 속성
out vec4 vertexColor ;

/**
 * @brief Vertex Shader
 * @details
 *  - gl_Position   : 정점의 위치를 설정한다.
 *  - vertexColor   : 정점의 색상을 설정한다.
 */
void main( void ) 
{
    gl_Position =  uProjectionMatrix * uModelViewMatrix * vec4( aPosition, 1.0 ) ;
    vertexColor = vec4( aPosition, 1.0 ) * 0.5 + vec4( 0.5, 0.5, 0.5, 0.5 ) ;
}
