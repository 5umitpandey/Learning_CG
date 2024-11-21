#include <GL/freeglut.h>

void display() {
    glClear(GL_COLOR_BUFFER_BIT);

    // Set the color of the text (RGB)
    glColor3f(1.0, 0.0, 0.0); // Red color

    // Set the position of the text
    glRasterPos2f(-0.5f, 0.0f);

    // Display the text
    const char *text = "FreeGLUT is Working!";
    while (*text) 
    {
        glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, *text++);
    }

    glFlush();
}

int main(int argc, char** argv) 
{
    // Initialize GLUT and create window
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(800, 600);
    glutCreateWindow("FreeGLUT Test");

    // Set display callback
    glutDisplayFunc(display);

    // Enter the GLUT event loop
    glutMainLoop();
    return 0;
}

//CMD command to execute the above code
//gcc -c -o 1_1.o 1_1.c -I"D:\TIET\CG\Lab\Freeglut\include"
//gcc -o 1_1.exe 1_1.o -L"D:\TIET\CG\Lab\Freeglut\lib" -lfreeglut -lopengl32 -Wl,--subsystem,windows
