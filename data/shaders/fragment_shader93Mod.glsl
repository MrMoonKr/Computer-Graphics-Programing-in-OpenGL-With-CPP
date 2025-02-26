#version 430

in vec3 vNormal;
in vec3 vVertPos;
out vec4 fragColor;

uniform vec3 eyePos;
layout (binding = 0) uniform samplerCube t;

void main(void)
{
    
    
    vec3 viewDir = normalize(vVertPos - eyePos);
    vec3 r = reflect(viewDir, normalize(vNormal));
    fragColor = vec4(texture(t, r).rgb, 1.0);
    
}