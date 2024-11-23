//Create empty window (Black, White and different Colors) 
#include <GL/freeglut.h>

void display() {
    glClear(GL_COLOR_BUFFER_BIT);
    glFlush();
}

void init() {
    glClearColor(1.0, 0.0, 0.0, 1.0); // Set background color to red
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0.0, 100.0, 0.0, 100.0); // Setting up a 2D orthographic viewing region
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(800, 600);
    glutInitWindowPosition(100, 100); // Set window position
    glutCreateWindow("Empty Red Window");
    init();
    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
}


//gcc -c -o 1_1.o 1_1.c -I"D:\TIET\CG\Lab\Freeglut\include"
//gcc -o 1_1.exe 1_1.o -L"D:\TIET\CG\Lab\Freeglut\lib" -lfreeglut -lopengl32 -lglu32 -Wl,--subsystem,windows
