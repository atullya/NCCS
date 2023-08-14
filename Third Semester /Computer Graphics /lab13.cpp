#include <GL/glut.h>
#include <cmath>

// Rectangle properties
float width = 200.0f;
float height = 50.0f;
float centerX = 100.0f;
float centerY = 100.0f;

// Rotation angle in degrees
float rotationAngle = 30.0f;

void drawRectangle(float r, float g, float b, float centerX, float centerY) {
    glColor3f(r, g, b);
    glBegin(GL_LINE_LOOP); // Change to GL_LINE_LOOP
    glVertex2f(centerX - width / 2, centerY - height / 2);
    glVertex2f(centerX + width / 2, centerY - height / 2);
    glVertex2f(centerX + width / 2, centerY + height / 2);
    glVertex2f(centerX - width / 2, centerY + height / 2);
    glEnd();
}

void display() {
    glClear(GL_COLOR_BUFFER_BIT);

    // Draw original rectangle outline in blue
    drawRectangle(0.0f, 0.0f, 1.0f, centerX, centerY);

    // Draw rotated rectangle in red
    glPushMatrix();
    glTranslatef(centerX, centerY, 0.0f);
    glRotatef(rotationAngle, 0.0f, 0.0f, 1.0f);
    glTranslatef(-centerX, -centerY, 0.0f);
    drawRectangle(1.0f, 0.0f, 0.0f, centerX, centerY);
    glPopMatrix();

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

