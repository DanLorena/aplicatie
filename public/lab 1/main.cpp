#include <GL/freeglut.h>

int main(int argc, char **argv) {
 glutInit(&argc, argv);
 glutInitDisplayMode(GLUT_DEPTH | GLUT_DOUBLE | GLUT_RGBA) ;
 glutInitWindowSize( 600, 400);
 glutCreateWindow ("Test Window");
 glutMainLoop() ; // Never returns
 return EXIT_SUCCESS;
}
