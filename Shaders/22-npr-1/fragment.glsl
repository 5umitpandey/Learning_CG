precision mediump float;

uniform mat4 model;
uniform mat4 view;
uniform mat4 projection;

uniform mat4 inverseModel;
uniform mat4 inverseView;
uniform mat4 inverseProjection;

uniform vec3 diffuse;
uniform vec3 lightDirection;
uniform float numBands;

void main() 
{
  gl_FragColor = vec4(1,1,1,1);
}
