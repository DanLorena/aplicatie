
#include <GL/freeglut.h>

void display (void)
{
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(1.0, 0.0, 0.0);
    glBegin(GL_LINES);
    glVertex2f(0.25, 0.50);
    glVertex2f(0.50, 0.50);
    glEnd();
    glFlush();
}



void init (void)
{
    glClearColor(1.0,1.0,1.0,0.0);
}




int main (int argc, char *argv[])
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGBA);
    glutInitWindowSize(400, 300);
    glutInitWindowPosition(100, 150);
    glutCreateWindow("My first openGL program");
    init();
    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
}
