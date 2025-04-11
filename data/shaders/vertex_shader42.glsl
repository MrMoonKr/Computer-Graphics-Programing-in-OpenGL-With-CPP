#version 410
#extension GL_ARB_gpu_shader5 : enable

// 정점 속성
layout ( location=0 ) in vec3 aPosition ;

// 유니폼 속성
uniform mat4 uViewMatrix ;
uniform mat4 uProjectionMatrix ;
uniform float uTimeFactor;

// 출력 속성
out vec4 vertexColor ;

mat4 buildRotateX( float rad );
mat4 buildRotateY( float rad );
mat4 buildRotateZ( float rad );
mat4 buildTranslate( float x, float y, float z );

/**
 * @brief Vertex Shader
 * @details
 *  - gl_InstanceID : 인스턴스의 ID를 가져온다.
 *  - gl_Position   : 정점의 위치를 설정한다.
 *  - vertexColor   : 정점의 색상을 설정한다.
 */
void main( void ) 
{
    float i = 0.0 ;
    i = gl_InstanceID + uTimeFactor ;  // value based on time factor, but different for each cube instance
    
    float a = sin( 203.0 * i /  800.0 ) * 403.0 ;
    float b = sin( 301.0 * i / 4001.0 ) * 401.0 ;
    float c = sin( 400.0 * i / 6003.0 ) * 405.0 ;
    
    mat4 localRotX  = buildRotateX( 1000 * i ) ;
    mat4 localRotY  = buildRotateY( 1000 * i ) ;
    mat4 localRotZ  = buildRotateZ( 1000 * i ) ;
    mat4 localTrans = buildTranslate( a, b, c ) ;
    
    // build the model matrix and then the model-view matrix
    mat4 newM_matrix = localTrans * localRotX * localRotY * localRotZ ;
    mat4 mv_matrix   = uViewMatrix * newM_matrix ;
    
    gl_Position = uProjectionMatrix * mv_matrix * vec4( aPosition, 1.0 );  // right-to-left
    vertexColor = vec4( aPosition, 1.0 ) * 1.0 + vec4( 0.2, 0.1, 0.3, 0.1 );
}

// builds and returns a matrix that performs a rotation around the X axis
mat4 buildRotateX( float rad ) 
{
    mat4 xrot = mat4(
        1.0, 0.0,      0.0,       0.0,
        0.0, cos(rad), -sin(rad), 0.0,
        0.0, sin(rad), cos(rad),  0.0,
        0.0, 0.0,      0.0,       1.0
    );

    return xrot;
}

// builds and returns a matrix that performs a rotation around the Y axis
mat4 buildRotateY( float rad ) 
{
    mat4 yrot = mat4(
        cos(rad),  0.0, sin(rad), 0.0,
        0.0,       1.0, 0.0,      0.0,
        -sin(rad), 0.0, cos(rad), 0.0,
        0.0,       0.0, 0.0,      1.0
    );

    return yrot;
}

// builds and returns a matrix that performs a rotation around the Z axis
mat4 buildRotateZ( float rad )
{
    mat4 zrot = mat4(
        cos(rad), -sin(rad), 0.0, 0.0,
        sin(rad),  cos(rad), 0.0, 0.0,
             0.0,       0.0, 1.0, 0.0,
             0.0,       0.0, 0.0, 1.0
    );

    return zrot;
}

// builds and returns a translation matrix
mat4 buildTranslate( float x, float y, float z )
{
    mat4 trans = mat4(
        1.0, 0.0, 0.0, 0.0,
        0.0, 1.0, 0.0, 0.0,
        0.0, 0.0, 1.0, 0.0,
          x,   y,   z, 1.0
    );

    return trans;
} 