//Draw a green color line from (15,10) to (50,50)
#include <GL/freeglut.h>

void display() {
    glClearColor(0.0, 0.0, 0.0, 1.0); // Black background
    glClear(GL_COLOR_BUFFER_BIT);

    glColor3f(0.0, 1.0, 0.0); // Green color

    glBegin(GL_LINES);
    glVertex2f(15.0f, 10.0f); // Coordinates in the orthographic projection
    glVertex2f(50.0f, 50.0f);
    glEnd();

    glFlush();
}

void init() {
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0.0, 100.0, 0.0, 100.0); // Setting up a 2D orthographic viewing region
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(800, 600);
    glutInitWindowPosition(100, 100); // Set window position
    glutCreateWindow("Green Line from (15,10) to (50,50)");
    init();
    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
}


//gcc -c -o 1_3.o 1_3.c -I"D:\TIET\CG\Lab\Freeglut\include"
//gcc -o 1_3.exe 1_3.o -L"D:\TIET\CG\Lab\Freeglut\lib" -lfreeglut -lopengl32 -lglu32 -Wl,--subsystem,windows