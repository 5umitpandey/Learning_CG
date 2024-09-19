bool mandelbrot(highp vec2 c) {

  //Test if the point c is inside the mandelbrot set after 100 iterations
  vec2 z = vec2(0.0);
  
  for (int i = 0; i < 100; i++) 
  {
    z = vec2(z.x * z.x - z.y * z.y + c.x, 2.0 * z.x * z.y + c.y);
    if (dot(z, z) > 4.0) 
    {
      return false;
    }
  }
  return true;
}


//Do not change this line or the name of the above function
#pragma glslify: export(mandelbrot)
