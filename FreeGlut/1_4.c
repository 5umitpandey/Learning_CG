//Draw a triangle on black background 
#include <GL/freeglut.h>

void display() {
    glClearColor(0.0, 0.0, 0.0, 1.0); // Black background
    glClear(GL_COLOR_BUFFER_BIT);

    glColor3f(1.0, 0.0, 0.0); // Red color

    glBegin(GL_TRIANGLES);
    glVertex2f(-0.5f, -0.5f);
    glVertex2f(0.5f, -0.5f);
    glVertex2f(0.0f, 0.5f);
    glEnd();

    glFlush();
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(800, 600);
    glutCreateWindow("Triangle on Black Background");
    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
}

//gcc -c -o 1_4.o 1_4.c -I"D:\TIET\CG\Lab\Freeglut\include"
//gcc -o 1_4.exe 1_4.o -L"D:\TIET\CG\Lab\Freeglut\lib" -lfreeglut -lopengl32 -Wl,--subsystem,windows