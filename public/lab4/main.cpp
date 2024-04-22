/*#include <GL/glut.h>

GLdouble size = 1.0;
double rotate_y = 0;
double rotate_x = 0;

void display() {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glLoadIdentity();
    glTranslatef(0.0f, 0.0f, -5.0f);

    // Rotirea întregului cub
    glRotatef(rotate_x, 1.0, 0.0, 0.0);
    glRotatef(rotate_y, 0.0, 1.0, 0.0);

    // Calculăm pasul deplasării pentru a poziționa cuburile mici
    float step = size / 8.0; // Mai multe cuburi mici
    float offset = step * 0.5; // Spațiu mai mic între cuburi mici

    // Desenăm cuburile mici care formează cubul mare
    glPolygonMode(GL_FRONT_AND_BACK, GL_FILL); // Setăm modul de desenare pentru umplerea solidă
    glColor3f(1.0, 1.0, 1.0); // Setăm culoarea de umplere a cuburilor mici la alb

    for (float x = -size / 2.0; x <= size / 2.0; x += step + offset) {
        for (float y = -size / 2.0; y <= size / 2.0; y += step + offset) {
            for (float z = -size / 2.0; z <= size / 2.0; z += step + offset) {
                glPushMatrix();
                glTranslatef(x, y, z);
                glutSolidCube(step); // Desenăm cuburile mici cu umplere
                glPopMatrix();
            }
        }
    }

    // Desenăm liniile de contur ale cuburilor mici
    glPolygonMode(GL_FRONT_AND_BACK, GL_LINE); // Setăm modul de desenare pentru liniile de contur
    glColor3f(0.0, 0.0, 1.0); // Setăm culoarea liniilor de contur la albastru

    for (float x = -size / 2.0; x <= size / 2.0; x += step + offset) {
        for (float y = -size / 2.0; y <= size / 2.0; y += step + offset) {
            for (float z = -size / 2.0; z <= size / 2.0; z += step + offset) {
                glPushMatrix();
                glTranslatef(x, y, z);
                glutWireCube(step); // Desenăm liniile de contur ale cuburilor mici
                glPopMatrix();
            }
        }
    }

    glutSwapBuffers();
}

void reshape(int w, int h) {
    glViewport(0, 0, (GLsizei)w, (GLsizei)h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(45.0, (GLfloat)w / (GLfloat)h, 0.1, 100.0);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
}

void specialKeys(int key, int x, int y) {
    switch (key) {
        case GLUT_KEY_UP:
            rotate_x += 5;
            break;
        case GLUT_KEY_DOWN:
            rotate_x -= 5;
            break;
        case GLUT_KEY_LEFT:
            rotate_y -= 5;
            break;
        case GLUT_KEY_RIGHT:
            rotate_y += 5;
            break;
    }
    glutPostRedisplay();
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
    glutInitWindowSize(500, 500);
    glutCreateWindow("Cub 3D cu cuburi în interior");
    glEnable(GL_DEPTH_TEST);
    glutDisplayFunc(display);
    glutReshapeFunc(reshape);
    glutSpecialFunc(specialKeys);
    glutMainLoop();
    return 0;
}
*/
#include <GL/glut.h>

void drawCube(float size, float x, float y, float z) {
    glPushMatrix();
    glTranslatef(x, y, z);
    glutSolidCube(size);
    glPopMatrix();
}

void drawRobot() {
    // Corpul robotului
    glColor3f(0.0f, 0.0f, 1.0f); // Setăm culoarea la albastru
    drawCube(1.0f, 0.0f, 0.5f, 0.0f); // Corpul

    // Capul robotului
    glColor3f(1.0f, 0.0f, 0.0f); // Setăm culoarea la roșu
    drawCube(0.6f, 0.0f, 1.2f, 0.0f); // Capul

    // Brațele robotului
    glColor3f(0.0f, 1.0f, 0.0f); // Setăm culoarea la verde
    drawCube(0.2f, -0.7f, 0.5f, 0.0f); // Brațul stâng
    drawCube(0.2f, 0.7f, 0.5f, 0.0f); // Brațul drept

    // Legătura dintre corp și brațele robotului
    glColor3f(0.0f, 0.0f, 1.0f); // Setăm culoarea la albastru
    glLineWidth(3.0f); // Lățimea liniei
    glBegin(GL_LINES);
    glVertex3f(0.0f, 1.0f, 0.0f); // Punctul de legătură cu corpul
    glVertex3f(-0.7f, 0.5f, 0.0f); // Punctul de legătură cu brațul stâng
    glVertex3f(0.0f, 1.0f, 0.0f); // Punctul de legătură cu corpul
    glVertex3f(0.7f, 0.5f, 0.0f); // Punctul de legătură cu brațul drept
    glEnd();

    // Picioarele robotului
    glColor3f(1.0f, 1.0f, 0.0f); // Setăm culoarea la galben
    drawCube(0.3f, -0.3f, -0.7f, 0.0f); // Piciorul stâng
    drawCube(0.3f, 0.3f, -0.7f, 0.0f); // Piciorul drept
}

void display() {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glLoadIdentity();

    glTranslatef(0.0f, 0.0f, -5.0f); // Translatare pentru a-l aduce mai în față

    drawRobot(); // Desenăm robotul

    glutSwapBuffers();
}

void init() {
    glClearColor(0.0f, 0.0f, 0.0f, 1.0f); // Fundal negru
    glEnable(GL_DEPTH_TEST);
}

void reshape(int w, int h) {
    glViewport(0, 0, w, h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(45.0f, (float)w / (float)h, 0.1f, 100.0f);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
    glutInitWindowSize(800, 600);
    glutCreateWindow("Robot");
    init();
    glutDisplayFunc(display);
    glutReshapeFunc(reshape);
    glutMainLoop();
    return 0;
}
