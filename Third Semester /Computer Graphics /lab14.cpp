#include <GL/glut.h>
#include <cmath>

// Rectangle properties
float width = 200.0f;
float height = 50.0f;
float centerX = 100.0f;
float centerY = 100.0f;

// Rotation angle in degrees
float rotationAngle = 30.0f;

// Function to rotate a point (x, y) about the origin (0, 0)
void rotatePoint(float& x, float& y, float centerX, float centerY, float angle) {
    float radianAngle = angle * (3.14159265358979323846f / 180.0f);
    float s = sin(radianAngle);
    float c = cos(radianAngle);

    // Translate the point to the origin
    x -= centerX;
    y -= centerY;

    // Rotate the point
    float newX = x * c - y * s;
    float newY = x * s + y * c;

    // Translate the point back
    x = newX + centerX;
    y = newY + centerY;
}

void drawRectangle(float r, float g, float b, float centerX, float centerY) {
    glColor3f(r, g, b);
    glBegin(GL_LINE_LOOP);
    float halfWidth = width / 2;
    float halfHeight = height / 2;

    // Calculate and store the rotated vertices
    float x1 = centerX - halfWidth;
    float y1 = centerY - halfHeight;
    float x2 = centerX + halfWidth;
    float y2 = centerY - halfHeight;
    float x3 = centerX + halfWidth;
    float y3 = centerY + halfHeight;
    float x4 = centerX - halfWidth;
    float y4 = centerY + halfHeight;
    rotatePoint(x1, y1, centerX, centerY, rotationAngle);
    rotatePoint(x2, y2, centerX, centerY, rotationAngle);
    rotatePoint(x3, y3, centerX, centerY, rotationAngle);
    rotatePoint(x4, y4, centerX, centerY, rotationAngle);

    // Draw the rotated rectangle
    glVertex2f(x1, y1);
    glVertex2f(x2, y2);
    glVertex2f(x3, y3);
    glVertex2f(x4, y4);
    glEnd();
}

void display() {
    glClear(GL_COLOR_BUFFER_BIT);

    // Draw rotated rectangle in red
    drawRectangle(1.0f, 0.0f, 0.0f, centerX, centerY);

    // Draw original rectangle outline in blue
    glColor3f(0.0f, 0.0f, 1.0f);
    glBegin(GL_LINE_LOOP);
    float halfWidth = width / 2;
    float halfHeight = height / 2;
    glVertex2f(centerX - halfWidth, centerY - halfHeight);
    glVertex2f(centerX + halfWidth, centerY - halfHeight);
    glVertex2f(centerX + halfWidth, centerY + halfHeight);
    glVertex2f(centerX - halfWidth, centerY + halfHeight);
    glEnd();

    glutSwapBuffers();
}

void reshape(int w, int h) {
    glViewport(0, 0, (GLsizei)w, (GLsizei)h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0.0, (GLdouble)w, 0.0, (GLdouble)h);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowSize(800, 600);
    glutCreateWindow("OpenGL Rectangle Rotation");
    glutDisplayFunc(display);
    glutReshapeFunc(reshape);

    glClearColor(1.0f, 1.0f, 1.0f, 1.0f); // Set background color to white

    glutMainLoop();
    return 0;
}
