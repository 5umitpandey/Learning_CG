//Draw a line using DDA algorithm
//Pink line, white background

#include <GL/freeglut.h>
#include <math.h>

void init() {
    glClearColor(1.0, 1.0, 1.0, 1.0); // Set background color to white
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0.0, 800.0, 0.0, 600.0); // Define the 2D orthographic projection
}

void display() {
    glClear(GL_COLOR_BUFFER_BIT);
    
    float x1 = 100.0, y1 = 100.0, x2 = 700.0, y2 = 500.0;
    float dx = x2 - x1, dy = y2 - y1;
    float steps = fmax(fabs(dx), fabs(dy));
    float xIncrement = dx / steps, yIncrement = dy / steps;
    
    float x = x1, y = y1;
    glColor3f(1.0, 0.0, 1.0); // Pink color for the line
    glBegin(GL_POINTS);
    
    for (int i = 0; i <= steps; ++i) {
        glVertex2f(x, y);
        x += xIncrement;
        y += yIncrement;
    }
    
    glEnd();
    glFlush();
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(800, 600);
    glutInitWindowPosition(100, 100); // Set window position
    glutCreateWindow("Pink Line Drawing using DDA Algorithm");
    init();
    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
}


//gcc -c -o 2_1.o 2_1.c -I"D:\TIET\CG\Lab\Freeglut\include"
//gcc -o 2_1.exe 2_1.o -L"D:\TIET\CG\Lab\Freeglut\lib" -lfreeglut -lopengl32 -lglu32 -Wl,--subsystem,windows