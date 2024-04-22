#include <GL/glut.h>
#include <cmath>

// Dimensiunile ferestrei
int width = 800;
int height = 600;

void init() {
    glClearColor(1.0, 1.0, 1.0, 1.0); // Setează culoarea de fundal la alb
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0, width, 0, height); // Setează sistemul de coordonate
}

void drawPentagon(float centerX, float centerY, float radius) {
    glBegin(GL_LINE_LOOP);
    for (int i = 0; i < 5; ++i) {
        float theta = 2.0f * M_PI * i / 5.0f;
        float x = radius * cos(theta);
        float y = radius * sin(theta);
        glVertex2f(centerX + x, centerY + y);
    }
    glEnd();
}

void display() {
    glClear(GL_COLOR_BUFFER_BIT);

    glColor3f(0.0, 0.0, 0.0); // Setează culoarea la negru

    float centerX = width / 2.0f;
    float centerY = height / 2.0f;
    float radius = 200.0f;

    drawPentagon(centerX, centerY, radius);

    glFlush(); // Procesează toate comenzile OpenGL cât mai repede posibil
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(width, height);
    glutCreateWindow("Pentagon Contour");
    init();
    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
}


/*#include <GL/glut.h>
#include <cmath>

// Dimensiunile ferestrei
int width = 800;
int height = 600;

void init() {
    glClearColor(1.0, 1.0, 1.0, 1.0); // Setează culoarea de fundal la alb
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0, width, 0, height); // Setează sistemul de coordonate
}

void drawSpiral() {
    glColor3f(0.0, 0.0, 1.0); // Setează culoarea la albastru
    glBegin(GL_LINE_STRIP);
    for (float theta = 0.0; theta <= 10.0 * M_PI; theta += 0.1) {
        float radius = theta * 10;
        float x = radius * cos(theta);
        float y = radius * sin(theta);
        glVertex2f(width / 2.0f + x, height / 2.0f + y);
    }
    glEnd();
}

void display() {
    glClear(GL_COLOR_BUFFER_BIT);

    drawSpiral();

    glFlush(); // Procesează toate comenzile OpenGL cât mai repede posibil
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(width, height);
    glutCreateWindow("Blue Spiral");
    init();
    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
}





/*#include <GL/glut.h>
#include <cmath>

// Dimensiunile ferestrei
int width = 800;
int height = 600;

void init() {
    glClearColor(1.0, 1.0, 1.0, 1.0); // Setează culoarea de fundal la alb
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0, width, 0, height); // Setează sistemul de coordonate
}

void drawSinusoid() {
    // Desenare sinusoidă roșie
    glColor3f(1.0, 0.0, 0.0); // Setează culoarea la roșu
    glBegin(GL_LINE_STRIP);
    for (int x = 0; x < width; ++x) {
        float y = height / 2.0f + 100.0f * sin(2.0f * M_PI * x / width);
        glVertex2f(x, y);
    }
    glEnd();

    // Desenare sinusoidă albastră
    glColor3f(0.0, 0.0, 1.0); // Setează culoarea la albastru
    glBegin(GL_LINE_STRIP);
    for (int x = 0; x < width; ++x) {
        float y = height / 2.0f + 100.0f * sin(2.0f * M_PI * x / width + M_PI); // Fază decalată pentru a avea o sinusoidă inversată
        glVertex2f(x, y);
    }
    glEnd();
}

void display() {
    glClear(GL_COLOR_BUFFER_BIT);

    drawSinusoid();

    glFlush(); // Procesează toate comenzile OpenGL cât mai repede posibil
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(width, height);
    glutCreateWindow("Sinusoid");
    init();
    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
}*/









