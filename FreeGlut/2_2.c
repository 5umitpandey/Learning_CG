//Draw a line using Bresenham's line algorithm
//Brown line, Yellow background

#include <GL/freeglut.h>
#include <math.h>

// Initialize function
void init() {
    glClearColor(1.0, 1.0, 0.0, 1.0); // Set background color to yellow
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0.0, 800.0, 0.0, 600.0); // Define the 2D orthographic projection
}

// Display function implementing Bresenham's line algorithm
void display() {
    glClear(GL_COLOR_BUFFER_BIT);
    
    int x1 = 100, y1 = 100, x2 = 700, y2 = 500;
    int dx = abs(x2 - x1), dy = abs(y2 - y1);
    int sx = (x1 < x2) ? 1 : -1;
    int sy = (y1 < y2) ? 1 : -1;
    int err = dx - dy;
    
    glColor3f(0.6, 0.3, 0.0); // Brown color for the line
    glBegin(GL_POINTS);

    while(1)
    {
        glVertex2i(x1, y1);
        if (x1 == x2 && y1 == y2) break;
        int e2 = 2 * err;
        if (e2 > -dy) {
            err -= dy;
            x1 += sx;
        }
        if (e2 < dx) {
            err += dx;
            y1 += sy;
        }
    }
    
    glEnd();
    glFlush();
}

// Main function
int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(800, 600);
    glutInitWindowPosition(100, 100); // Set window position
    glutCreateWindow("Bresenham's Line Drawing Algorithm");
    init();
    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
}


//gcc -c -o 2_2.o 2_2.c -I"D:\TIET\CG\Lab\Freeglut\include"
//gcc -o 2_2.exe 2_2.o -L"D:\TIET\CG\Lab\Freeglut\lib" -lfreeglut -lopengl32 -lglu32 -Wl,--subsystem,windows