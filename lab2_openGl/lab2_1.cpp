#include <GL/glut.h>

using namespace std;

void init()
{
}

void points()
{
    glPointSize(5);
    glColor3f(1, 0, 0);
    glBegin(GL_POINTS);
    glVertex2f(-0.8, 0.9);
    glVertex2f(-0.75, 0.85);
    glVertex2f(-0.65, 0.85);
    glVertex2f(-0.6, 0.9);
    glVertex2f(-0.55, 0.95);
    glEnd();
}

void lines()
{
    glColor3f(0, 1, 0);
    glBegin(GL_LINES);
    glVertex2f(-0.95, 0.6);
    glVertex2f(-0.75, 0.7);

    glVertex2f(-0.80, 0.65);
    glVertex2f(-0.65, 0.6);

    glVertex2f(-0.90, 0.57);
    glVertex2f(-0.73, 0.52);

    glVertex2f(-0.93, 0.54);
    glVertex2f(-0.73, 0.58);

    glEnd();
}
void line_strip()
{
    glColor3f(0, 0, 1);
    glBegin(GL_LINE_STRIP);
    glVertex2f(-0.1, 0.7);
    glVertex2f(0.1, 0.65);
    glVertex2f(0.07, 0.68);
    glVertex2f(-0.05, 0.665);
    glVertex2f(-0.07, 0.66);
    glEnd();
}

void line_loop()
{
    glColor3f(0.5, 0.5, 0);
    glBegin(GL_LINE_LOOP);
    glVertex2f(0.5, 0.65);
    glVertex2f(0.53, 0.6);
    glVertex2f(0.61, 0.6);
    glVertex2f(0.57, 0.63);
    glVertex2f(0.55, 0.615);
    glVertex2f(0.54, 0.66);
    glEnd();
}

void triangles()
{
    glColor3f(0.5, 0, 0.5);
    glBegin(GL_TRIANGLES);
    glVertex2f(-0.9, -0.2);
    glVertex2f(-0.9, -0.0);
    glVertex2f(-0.65, -0.2);
    glEnd();

    glBegin(GL_TRIANGLES);
    glVertex2f(-0.8, 0.1);
    glVertex2f(-0.3, 0.1);
    glVertex2f(-0.55, -0.15);
    glEnd();
}

void triangle_strip()
{
    glColor3f(0, 0.5, 0.5);
    glBegin(GL_TRIANGLE_STRIP);
    glVertex2f(-0.1, 0.2);
    glVertex2f(-0.1, 0.0);
    glVertex2f(0.0, 0.2);
    glColor3f(0.5, 0.5, 0.5);
    glVertex2f(0.07, 0.0);
    glVertex2f(0.15, 0.2);
    glVertex2f(0.2, -0.1);
    glEnd();
}
void triangle_fan()
{
    glColor3f(0.7, 0.2, 0);
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(0.6, 0.0);
    glVertex2f(0.6, 0.2);
    glVertex2f(0.7, 0.15);
    glVertex2f(0.74, 0.03);
    glVertex2f(0.72, -0.05);
    glEnd();
}

void quads()
{
    glColor3f(0.7, 0.2, 0.2);
    glBegin(GL_QUADS);
    glVertex2f(-0.9, -0.8);
    glVertex2f(-0.85, -0.75);
    glVertex2f(-0.7, -0.73);
    glVertex2f(-0.72, -0.82);
    glEnd();

    glBegin(GL_QUADS);
    glVertex2f(-0.6, -0.9);
    glVertex2f(-0.62, -0.7);
    glVertex2f(-0.5, -0.65);
    glVertex2f(-0.55, -0.9);
    glEnd();
}

void quad_strip()
{
    glColor3f(0.2, 0.7, 0.2);
    glBegin(GL_QUAD_STRIP);
    glVertex2f(-0.2, -0.9);
    glVertex2f(-0.22, -0.8);
    glVertex2f(-0.1, -0.9);
    glVertex2f(-0.1, -0.78);
    glVertex2f(0.0, -0.88);
    glVertex2f(-0.05, -0.75);
    glVertex2f(0.05, -0.88);
    glVertex2f(0.02, -0.7);
    glEnd();
}

void polygon()
{
    glColor3f(0.2, 0.7, 0.7);
    glBegin(GL_POLYGON);
    glVertex2f(0.5, -0.7);
    glVertex2f(0.7, -0.68);
    glVertex2f(0.65, -0.75);
    glVertex2f(0.45, -0.81);
    glVertex2f(0.42, -0.75);
    glEnd();
}

void primitives()
{
    points();
    lines();
    line_strip();
    line_loop();
    triangles();
    triangle_strip();
    triangle_fan();
    quads();
    quad_strip();
    polygon();
}

void mydisplay()
{
    glClear(GL_COLOR_BUFFER_BIT); // czyszczenie bufora obrazu
    primitives();
    glFlush(); // wyświetlenie bufora obrazu
}

int main(int argc, char **argv)
{
    glutInit(&argc, argv);
    glutInitWindowSize(1024, 800);
    glutCreateWindow("Okno OpenGL"); // tworzenie okna aplikacji
    glutDisplayFunc(mydisplay);      // definiowanie funkcji callback do wyświetlania zawartości okna
    init();
    glutMainLoop(); // główna pętla aplikacji
}