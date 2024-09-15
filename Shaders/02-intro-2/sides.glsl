void sideLengths(highp float hypotenuse, highp float angleInDegrees, out highp float opposite, out highp float adjacent)
{
  //TODO: Calculate side lengths here
  // Convert the angle from degrees to radians
  highp float angleInRadians = radians(angleInDegrees);
    
  // Calculate the opposite side using sine
  opposite = hypotenuse * sin(angleInRadians);
  
  // Calculate the adjacent side using cosine
  adjacent = hypotenuse * cos(angleInRadians);

}

//Do not change this line
#pragma glslify: export(sideLengths)
