//Draw a point of width 20 pixel

#include <GL/freeglut.h>

void display() {
    glClearColor(0.0, 0.0, 0.0, 1.0); // Black background
    glClear(GL_COLOR_BUFFER_BIT);

    glPointSize(20.0);
    glColor3f(1.0, 1.0, 1.0); // White color

    glBegin(GL_POINTS);
    glVertex2f(0.0f, 0.0f);
    glEnd();

    glFlush();
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(800, 600);
    glutCreateWindow("Point of Width 20 Pixels");
    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
}

//gcc -c -o 1_2.o 1_2.c -I"D:\TIET\CG\Lab\Freeglut\include"
//gcc -o 1_2.exe 1_2.o -L"D:\TIET\CG\Lab\Freeglut\lib" -lfreeglut -lopengl32 -Wl,--subsystem,windows