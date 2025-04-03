#version 410

// 입력 속성
in vec4 vertexColor ;

// 유니폼 속성
uniform mat4 uModelViewMatrix ;
uniform mat4 uProjectionMatrix ;

// 최종 색상
out vec4 finalColor ;

void main( void )
{
    finalColor = vertexColor;
}
