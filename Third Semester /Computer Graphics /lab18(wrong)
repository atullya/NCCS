#include <GL/glut.h>
#include <cmath>

float x, y;
float width, height;
int win_width = 800;
int win_height = 600;

void drawRectangle(float x, float y, float width, float height) {
    glColor3f(0.0f, 0.0f, 1.0f);
    glLineWidth(2.0);
    glBegin(GL_LINE_LOOP);
    glVertex2f(x, y);
    glVertex2f(x + width, y);
    glVertex2f(x + width, y + height);
    glVertex2f(x, y + height);
    glEnd();
}

void rotatePoint(float angle, float& x, float& y, float centerX, float centerY) {
    float s = sin(angle * M_PI / 180.0);
    float c = cos(angle * M_PI / 180.0);

    // Translate point back to origin
    x -= centerX;
    y -= centerY;

    // Rotate point
    float newX = x * c - y * s;
    float newY = x * s + y * c;

    // Translate point back
    x = newX + centerX;
    y = newY + centerY;
}

void display() {
    glClear(GL_COLOR_BUFFER_BIT);

    // Draw the original rectangle
    drawRectangle(x, y, width, height);

    // Calculate the center of rotation
    float centerX = 150.0f;
    float centerY = 125.0f;

    // Rotate the vertices of the rectangle
    float x1 = x;
    float y1 = y;
    float x2 = x + width;
    float y2 = y;
    float x3 = x + width;
    float y3 = y + height;
    float x4 = x;
    float y4 = y + height;

    rotatePoint(30.0, x1, y1, centerX, centerY);
    rotatePoint(30.0, x2, y2, centerX, centerY);
    rotatePoint(30.0, x3, y3, centerX, centerY);
    rotatePoint(30.0, x4, y4, centerX, centerY);

    // Draw the rotated rectangle
    glBegin(GL_LINE_LOOP);
    glVertex2f(x1, y1);
    glVertex2f(x2, y2);
    glVertex2f(x3, y3);
    glVertex2f(x4, y4);
    glEnd();

    glFlush();
}

void reshape(int w, int h) {
    glViewport(0, 0, w, h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(-100, win_width, -100, win_height);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
}

int main(int argc, char *argv[]) {
    x = 100;
    y = 100;
    width = 200;
    height = 50;

    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(win_width, win_height);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("Rotate Rectangle About Fixed Point Without Using OpenGL Transformations");

    glClearColor(1.0, 1.0, 1.0, 1.0);
    glutDisplayFunc(display);
    glutReshapeFunc(reshape);

    glutMainLoop();

    return 0;
}
