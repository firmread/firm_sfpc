#version 120

//uniform sampler2DRect texBit;
//varying vec2 texCoordVarying;

uniform float time;
uniform vec2 windowSize;
uniform vec2 mousePos;

uniform float vol;


void main( void )
{
    
//    float value = texture2DRect(texBit, gl_FragCoord.xy).b;
//    
//    
//    if (value > 0.0) {
    

        float colors[3];
        float speed = vol + 0.5;
        float delay = 0.0018; 
        //float delay = 1.001;
        float amplifier = 0.2;

        int row = 10;
        int col = 10;
        int count = 100;
        
        vec2 centerPoints[100];
        float dists[25];
        for(int x = 0; x < 5; x++) {
          for(int y = 0; y < 5; y++) {
            int index = (x * 5) + y;
            vec2 p;
            p.x = windowSize.x / 5.0 * x;
            p.y = windowSize.y / 10.0 * y;
            // centerPoints[index].x = windowSize.x / 10.0 * x;
            // centerPoints[index].y = windowSize.y / 10.0 * y;
            dists[index] = distance(gl_FragColor.xy, p);
          }
        }

        vec2 center;
        center.x = windowSize.x / 2.0;
        center.y = windowSize.y / 2.0;

        vec2 center2;
        center2.x = windowSize.x / 4.0;
        center2.y = windowSize.y / 4.0;

        float dist = distance(gl_FragCoord.xy, center);
        float dist2 = distance(gl_FragCoord.xy, center2);
        
    // float r = 0.0; //mousePos.x / windowSize.x;
    // float g = 0.0; //mousePos.y / windowSize.y;
    // float b = 0.0; //(sin(time) + 1.0) * 0.5;
         float r = mousePos.x / windowSize.x;
         float g = mousePos.y / windowSize.y;
         float b = (sin(time) + 1.0) * 0.5;

        for(int i = 0; i < 3; i++) {
          float temp = sin(gl_FragCoord.x * speed * delay * (i + 1) + time) * amplifier - cos(gl_FragCoord.y * speed * delay * (i + 1) + time) * amplifier;
          float temp2;
          // colors[i] *= mousePos.x / windowSize.x;
          temp *= (sin((3 - i) / 1.04 * time) + 1) * 0.45 + 0.05;
          temp /= (i + 1) * 0.03; // You shouldn't do that DIVIDED BY ZERO.
          temp2 = temp * dist / 500.0;
          if(temp2 > 0.05) {
            temp = temp2 / 0.9;
          } else {
            temp = temp2;
          }
          temp2 = temp * dist2 / 500.0;
          if(temp2 > 0.05) {
            temp = temp2 / 0.9;
          } else {
            temp = temp2;
          }

          colors[i] = temp + 0.2;
        }
          
          gl_FragColor = vec4((colors[0]+r)/2, (colors[1]+g)/2, (colors[2]+b)/2, 1.0);
//    }
//    else {
//        gl_FragColor = vec4(0.0, 0.0, 0.0, 1.0);
//    }
}
