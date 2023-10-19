#pragma once

#include <GL/glut.h>

void multi_color_cube()
{
    glBegin(GL_QUADS);

    glColor3f(1.0, 0.0, 0.0);
    glVertex3f(-0.5, -0.5, 0.5);
    glVertex3f(0.5, -0.5, 0.5);
    glVertex3f(0.5, 0.5, 0.5);
    glVertex3f(-0.5, 0.5, 0.5);

    glColor3f(0.0, 1.0, 0.0);
    glVertex3f(-0.5, -0.5, -0.5);
    glVertex3f(0.5, -0.5, -0.5);
    glVertex3f(0.5, 0.5, -0.5);
    glVertex3f(-0.5, 0.5, -0.5);

    glColor3f(0.0, 0.0, 1.0);
    glVertex3f(-0.5, -0.5, -0.5);
    glVertex3f(-0.5, 0.5, -0.5);
    glVertex3f(-0.5, 0.5, 0.5);
    glVertex3f(-0.5, -0.5, 0.5);

    glColor3f(1.0, 1.0, 0.0);
    glVertex3f(0.5, -0.5, -0.5);
    glVertex3f(0.5, 0.5, -0.5);
    glVertex3f(0.5, 0.5, 0.5);
    glVertex3f(0.5, -0.5, 0.5);

    glColor3f(1.0, 0.0, 1.0);
    glVertex3f(-0.5, 0.5, -0.5);
    glVertex3f(0.5, 0.5, -0.5);
    glVertex3f(0.5, 0.5, 0.5);
    glVertex3f(-0.5, 0.5, 0.5);

    glColor3f(0.0, 1.0, 1.0);
    glVertex3f(-0.5, -0.5, -0.5);
    glVertex3f(0.5, -0.5, -0.5);
    glVertex3f(0.5, -0.5, 0.5);
    glVertex3f(-0.5, -0.5, 0.5);

    glEnd();
}

void multi_color_octahedron()
{
    glBegin(GL_TRIANGLES);

    glColor3f(1, 0.0f, 0.0f);
    glVertex3f(1, 0.0f, 0.0f);
    glVertex3f(0.0f, 1, 0.0f);
    glVertex3f(0.0f, 0.0f, 1);

    glColor3f(0.0f, 1, 0.0f);
    glVertex3f(-1, 0.0f, 0.0f);
    glVertex3f(0.0f, 1, 0.0f);
    glVertex3f(0.0f, 0.0f, 1);

    glColor3f(0.0f, 0.0f, 1);
    glVertex3f(1, 0.0f, 0.0f);
    glVertex3f(0.0f, 1, 0.0f);
    glVertex3f(0.0f, 0.0f, -1);

    glColor3f(1, 1, 0.0f);
    glVertex3f(-1, 0.0f, 0.0f);
    glVertex3f(0.0f, 1, 0.0f);
    glVertex3f(0.0f, 0.0f, -1);

    // bottom
    glColor3f(0.0f, 1, 1);
    glVertex3f(1, 0.0f, 0.0f);
    glVertex3f(0.0f, -1, 0.0f);
    glVertex3f(0.0f, 0.0f, 1);

    glColor3f(1, 0.0f, 1);
    glVertex3f(-1, 0.0f, 0.0f);
    glVertex3f(0.0f, -1, 0.0f);
    glVertex3f(0.0f, 0.0f, 1);

    glColor3f(1, 1, 1);
    glVertex3f(1, 0.0f, 0.0f);
    glVertex3f(0.0f, -1, 0.0f);
    glVertex3f(0.0f, 0.0f, -1);

    glColor3f(1, 0.5f, 0.0f);
    glVertex3f(-1, 0.0f, 0.0f);
    glVertex3f(0.0f, -1, 0.0f);
    glVertex3f(0.0f, 0.0f, -1);

    glEnd();
}

void textured_cube()
{
    glEnable(GL_TEXTURE_2D);
    glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
    glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
    glColor3d(1.0, 1.0, 1.0);
    glBegin(GL_QUADS);

    glTexCoord2f(0.0f, 0.0f);
    glVertex3f(-0.5f, -0.5f, 0.5f);
    glTexCoord2f(1.0f, 0.0f);
    glVertex3f(0.5f, -0.5f, 0.5f);
    glTexCoord2f(1.0f, 1.0f);
    glVertex3f(0.5f, 0.5f, 0.5f);
    glTexCoord2f(0.0f, 1.0f);
    glVertex3f(-0.5f, 0.5f, 0.5f);

    glTexCoord2f(1.0f, 0.0f);
    glVertex3f(-0.5f, -0.5f, -0.5f);
    glTexCoord2f(1.0f, 1.0f);
    glVertex3f(-0.5f, 0.5f, -0.5f);
    glTexCoord2f(0.0f, 1.0f);
    glVertex3f(0.5f, 0.5f, -0.5f);
    glTexCoord2f(0.0f, 0.0f);
    glVertex3f(0.5f, -0.5f, -0.5f);

    glTexCoord2f(0.0f, 1.0f);
    glVertex3f(-0.5f, 0.5f, -0.5f);
    glTexCoord2f(0.0f, 0.0f);
    glVertex3f(-0.5f, 0.5f, 0.5f);
    glTexCoord2f(1.0f, 0.0f);
    glVertex3f(0.5f, 0.5f, 0.5f);
    glTexCoord2f(1.0f, 1.0f);
    glVertex3f(0.5f, 0.5f, -0.5f);

    glTexCoord2f(1.0f, 1.0f);
    glVertex3f(-0.5f, -0.5f, -0.5f);
    glTexCoord2f(0.0f, 1.0f);
    glVertex3f(0.5f, -0.5f, -0.5f);
    glTexCoord2f(0.0f, 0.0f);
    glVertex3f(0.5f, -0.5f, 0.5f);
    glTexCoord2f(1.0f, 0.0f);
    glVertex3f(-0.5f, -0.5f, 0.5f);

    glTexCoord2f(1.0f, 0.0f);
    glVertex3f(0.5f, -0.5f, -0.5f);
    glTexCoord2f(1.0f, 1.0f);
    glVertex3f(0.5f, 0.5f, -0.5f);
    glTexCoord2f(0.0f, 1.0f);
    glVertex3f(0.5f, 0.5f, 0.5f);
    glTexCoord2f(0.0f, 0.0f);
    glVertex3f(0.5f, -0.5f, 0.5f);

    glTexCoord2f(0.0f, 0.0f);
    glVertex3f(-0.5f, -0.5f, -0.5f);
    glTexCoord2f(1.0f, 0.0f);
    glVertex3f(-0.5f, -0.5f, 0.5f);
    glTexCoord2f(1.0f, 1.0f);
    glVertex3f(-0.5f, 0.5f, 0.5f);
    glTexCoord2f(0.0f, 1.0f);
    glVertex3f(-0.5f, 0.5f, -0.5f);
    glEnd();

    glDisable(GL_TEXTURE_2D);
}

void textured_octahedron()
{
    glEnable(GL_TEXTURE_2D);
    glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
    glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
    glColor3d(1.0, 1.0, 1.0);
    glBegin(GL_TRIANGLES);

    glTexCoord2f(0.0f, 0.0f);
    glVertex3f(1, 0.0f, 0.0f);
    glTexCoord2f(1.0f, 1.0f);
    glVertex3f(0.0f, 1, 0.0f);
    glTexCoord2f(1.0f, 0.0f);
    glVertex3f(0.0f, 0.0f, 1);

    glTexCoord2f(0.0f, 0.0f);
    glVertex3f(-1, 0.0f, 0.0f);
    glTexCoord2f(1.0f, 1.0f);
    glVertex3f(0.0f, 1, 0.0f);
    glTexCoord2f(1.0f, 0.0f);
    glVertex3f(0.0f, 0.0f, 1);

    glTexCoord2f(0.0f, 0.0f);
    glVertex3f(1, 0.0f, 0.0f);
    glTexCoord2f(1.0f, 1.0f);
    glVertex3f(0.0f, 1, 0.0f);
    glTexCoord2f(0.0f, 1.0f);
    glVertex3f(0.0f, 0.0f, -1);

    glTexCoord2f(0.0f, 0.0f);
    glVertex3f(-1, 0.0f, 0.0f);
    glTexCoord2f(1.0f, 1.0f);
    glVertex3f(0.0f, 1, 0.0f);
    glTexCoord2f(0.0f, 1.0f);
    glVertex3f(0.0f, 0.0f, -1);

    // bottom
    glTexCoord2f(0.0f, 0.0f);
    glVertex3f(1, 0.0f, 0.0f);
    glTexCoord2f(1.0f, 1.0f);
    glVertex3f(0.0f, -1, 0.0f);
    glTexCoord2f(1.0f, 0.0f);
    glVertex3f(0.0f, 0.0f, 1);

    glTexCoord2f(0.0f, 0.0f);
    glVertex3f(-1, 0.0f, 0.0f);
    glTexCoord2f(1.0f, 1.0f);
    glVertex3f(0.0f, -1, 0.0f);
    glTexCoord2f(1.0f, 0.0f);
    glVertex3f(0.0f, 0.0f, 1);

    glTexCoord2f(0.0f, 0.0f);
    glVertex3f(1, 0.0f, 0.0f);
    glTexCoord2f(1.0f, 1.0f);
    glVertex3f(0.0f, -1, 0.0f);
    glTexCoord2f(1.0f, 0.0f);
    glVertex3f(0.0f, 0.0f, -1);

    glTexCoord2f(0.0f, 0.0f);
    glVertex3f(-1, 0.0f, 0.0f);
    glTexCoord2f(1.0f, 1.0f);
    glVertex3f(0.0f, -1, 0.0f);
    glTexCoord2f(1.0f, 0.0f);
    glVertex3f(0.0f, 0.0f, -1);

    glEnd();
    glDisable(GL_TEXTURE_2D);
}