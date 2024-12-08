//Draw an ellipse using Midpoint ellipse algorithm 
//Black Ellipse line, Gray Background

#include <GL/freeglut.h>

// Initialize function
void init() {
    glClearColor(0.5, 0.5, 0.5, 1.0); // Set background color to gray
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0.0, 800.0, 0.0, 600.0); // Define the 2D orthographic projection
}

// Function to plot the ellipse points in all quadrants
void plotEllipsePoints(int xc, int yc, int x, int y) {
    glVertex2i(xc + x, yc + y);
    glVertex2i(xc - x, yc + y);
    glVertex2i(xc + x, yc - y);
    glVertex2i(xc - x, yc - y);
}

// Function implementing the Midpoint Ellipse Algorithm
void midpointEllipse(int xc, int yc, int rx, int ry) {
    int rxSq = rx * rx;
    int rySq = ry * ry;
    int x = 0, y = ry;
    int p1 = rySq - (rxSq * ry) + (0.25 * rxSq);
    int dx = 2 * rySq * x;
    int dy = 2 * rxSq * y;

    glBegin(GL_POINTS);

    // Region 1
    while (dx < dy) {
        plotEllipsePoints(xc, yc, x, y);
        if (p1 < 0) {
            x++;
            dx = dx + (2 * rySq);
            p1 = p1 + dx + rySq;
        } else {
            x++;
            y--;
            dx = dx + (2 * rySq);
            dy = dy - (2 * rxSq);
            p1 = p1 + dx - dy + rySq;
        }
    }

    // Region 2
    int p2 = (rySq) * ((x + 0.5) * (x + 0.5)) + (rxSq) * ((y - 1) * (y - 1)) - (rxSq * rySq);
    while (y >= 0) {
        plotEllipsePoints(xc, yc, x, y);
        if (p2 > 0) {
            y--;
            dy = dy - (2 * rxSq);
            p2 = p2 + rxSq - dy;
        } else {
            y--;
            x++;
            dx = dx + (2 * rySq);
            dy = dy - (2 * rxSq);
            p2 = p2 + dx - dy + rxSq;
        }
    }

    glEnd();
    glFlush();
}

// Display function
void display() {
    glClear(GL_COLOR_BUFFER_BIT);

    int xc = 400, yc = 300, rx = 300, ry = 200;
    glColor3f(0.0, 0.0, 0.0); // Black color for the ellipse
    midpointEllipse(xc, yc, rx, ry);

    glFlush();
}

// Main function
int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(800, 600);
    glutInitWindowPosition(100, 100); // Set window position
    glutCreateWindow("Midpoint Ellipse Drawing Algorithm");
    init();
    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
}


//gcc -c -o 3_2.o 3_2.c -I"D:\TIET\CG\Lab\Freeglut\include"
//gcc -o 3_2.exe 3_2.o -L"D:\TIET\CG\Lab\Freeglut\lib" -lfreeglut -lopengl32 -lglu32 -Wl,--subsystem,windows
