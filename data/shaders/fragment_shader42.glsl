#version 410

// 입력 속성
in vec4 vertexColor ;

// 출력 속성
out vec4 finalColor ;

/**
 * @brief Fragment Shader
 * @details
 *  - vertexColor : 정점의 색상이 전달된다.
 *  - finalColor  : 최종 색상을 설정한다.
 */
void main( void ) 
{
    finalColor = vertexColor;
}
