//Draw a circle using Midpoint circle algorithm 
//Blue Cirle line, White background

#include <GL/freeglut.h>

// Initialize function
void init() {
    glClearColor(1.0, 1.0, 1.0, 1.0); // Set background color to white
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0.0, 800.0, 0.0, 600.0); // Define the 2D orthographic projection
}

// Function to plot the circle points in all octants
void plotCirclePoints(int xc, int yc, int x, int y) {
    glVertex2i(xc + x, yc + y);
    glVertex2i(xc - x, yc + y);
    glVertex2i(xc + x, yc - y);
    glVertex2i(xc - x, yc - y);
    glVertex2i(xc + y, yc + x);
    glVertex2i(xc - y, yc + x);
    glVertex2i(xc + y, yc - x);
    glVertex2i(xc - y, yc - x);
}

// Function implementing the Midpoint Circle Algorithm
void midpointCircle(int xc, int yc, int r) {
    int x = 0, y = r;
    int d = 1 - r; // Initial decision parameter

    glBegin(GL_POINTS);

    plotCirclePoints(xc, yc, x, y);

    while (x < y) {
        if (d < 0) {
            d += 2 * x + 3;
        } else {
            d += 2 * (x - y) + 5;
            y--;
        }
        x++;
        plotCirclePoints(xc, yc, x, y);
    }

    glEnd();
    glFlush();
}

// Display function
void display() {
    glClear(GL_COLOR_BUFFER_BIT);

    int xc = 400, yc = 300, r = 200;
    glColor3f(0.0, 0.0, 1.0); // Blue color for the circle
    midpointCircle(xc, yc, r);

    glFlush();
}

// Main function
int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(800, 600);
    glutInitWindowPosition(100, 100); // Set window position
    glutCreateWindow("Midpoint Circle Drawing Algorithm");
    init();
    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
}

//gcc -c -o 3_1.o 3_1.c -I"D:\TIET\CG\Lab\Freeglut\include"
//gcc -o 3_1.exe 3_1.o -L"D:\TIET\CG\Lab\Freeglut\lib" -lfreeglut -lopengl32 -lglu32 -Wl,--subsystem,windows