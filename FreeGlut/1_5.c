//Draw a rectangle on white background
#include <GL/freeglut.h>

void display() {
    glClearColor(1.0, 1.0, 1.0, 1.0); // White background
    glClear(GL_COLOR_BUFFER_BIT);

    glColor3f(0.0, 0.0, 1.0); // Blue color

    glBegin(GL_QUADS);
    glVertex2f(-0.5f, -0.5f);
    glVertex2f(0.5f, -0.5f);
    glVertex2f(0.5f, 0.5f);
    glVertex2f(-0.5f, 0.5f);
    glEnd();

    glFlush();
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(800, 600);
    glutCreateWindow("Rectangle on White Background");
    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
}

//gcc -c -o 1_5.o 1_5.c -I"D:\TIET\CG\Lab\Freeglut\include"
//gcc -o 1_5.exe 1_5.o -L"D:\TIET\CG\Lab\Freeglut\lib" -lfreeglut -lopengl32 -Wl,--subsystem,windows