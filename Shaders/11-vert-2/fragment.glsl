precision highp float;

varying vec4 fragPosition;
varying vec3 vColor;

void main() 
{
  //gl_FragColor = vec4(1,1,1,1);
  gl_FragColor = vec4(vColor, 1.0);
}
