#include <GL/glut.h>
#include <stdio.h>

#include <chrono>
#include <thread>
#include <cmath>

#include "lab2_2_drawing.hpp"

enum Object
{
    CUBE,
    OCTAHEDRON,
};
enum Display_mode
{
    EDGES,
    SINGLE_COLOR_WALLS,
    MULTI_COLOR_WALLS,
    TEXTURES
};
enum Rotation_trajectory
{
    NO_TRAJECTORY = 0, // only rotations around its own axes
    SMALLER_CIRCLE = 1,
    LARGER_CIRCLE = 2
};
// angle difference divisor
enum Animation_speed
{
    SLOW = 6,
    MEDIUM = 4,
    FAST = 2
};
enum Options
{
    RESET_ROTATION_ANGLE,
    START_ANIMATION,
    STOP_ANIMATION,
    EXIT
};

static Object object{CUBE};
static Display_mode display_mode{EDGES};
static Rotation_trajectory rotation_trajectory{NO_TRAJECTORY};
static Animation_speed animation_speed{MEDIUM};

static bool animation_on{true};
static bool reset_rotation{false};

static int window;

// angle of circle we're tracing
static double a{0};

// POV distance from middle of the circle
constexpr static double base_distance{5};

// rotation along own axis
static double rotation{0};

GLubyte texture[64][64][3];

void menu(int num)
{
    if (num == EXIT)
    {
        glutDestroyWindow(window);
        exit(0);
    }
    glutPostRedisplay();
}

template <typename T, T &option>
void default_menu(int num)
{
    option = static_cast<T>(num);
    glutPostRedisplay();
}

void options_menu(int num)
{
    if (num == START_ANIMATION)
    {
        animation_on = true;
    }
    else if (num == STOP_ANIMATION)
    {
        animation_on = false;
    }
    reset_rotation = num == RESET_ROTATION_ANGLE;
    glutPostRedisplay();
}

void createMenu(void)
{

    int object_menu_id = glutCreateMenu(default_menu<Object, object>);
    glutAddMenuEntry("Cube", CUBE);
    glutAddMenuEntry("Octahedron", OCTAHEDRON);

    int display_mode_menu_id = glutCreateMenu(default_menu<Display_mode, display_mode>);
    glutAddMenuEntry("Edges", EDGES);
    glutAddMenuEntry("Single color walls", SINGLE_COLOR_WALLS);
    glutAddMenuEntry("Multi color walls", MULTI_COLOR_WALLS);
    glutAddMenuEntry("Textures", TEXTURES);

    int rotation_trajectory_menu_id = glutCreateMenu(default_menu<Rotation_trajectory, rotation_trajectory>);
    glutAddMenuEntry("No trajectory", NO_TRAJECTORY);
    glutAddMenuEntry("Smaller circle", SMALLER_CIRCLE);
    glutAddMenuEntry("Larger circle", LARGER_CIRCLE);

    int animation_speed_menu_id = glutCreateMenu(default_menu<Animation_speed, animation_speed>);
    glutAddMenuEntry("Slow", SLOW);
    glutAddMenuEntry("Medium", MEDIUM);
    glutAddMenuEntry("Fast", FAST);

    int options_menu_id = glutCreateMenu(options_menu);
    glutAddMenuEntry("Reset rotation angle", RESET_ROTATION_ANGLE);
    glutAddMenuEntry("Start animation", START_ANIMATION);
    glutAddMenuEntry("Stop animation", STOP_ANIMATION);

    int menu_id = glutCreateMenu(menu);
    glutAddSubMenu("Object", object_menu_id);
    glutAddSubMenu("Display Mode", display_mode_menu_id);
    glutAddSubMenu("Rotation Trajectory", rotation_trajectory_menu_id);
    glutAddSubMenu("Animation Speed", animation_speed_menu_id);
    glutAddSubMenu("Options", options_menu_id);
    glutAddMenuEntry("Quit", EXIT);

    glutAttachMenu(GLUT_RIGHT_BUTTON);
}

void load_texture()
{
    int value;
    for (int row = 0; row < 64; row++)
    {
        for (int col = 0; col < 64; col++)
        {
            value = (((row & 0x8) == 0) ^ ((col & 0x8) == 0)) * 255;
            texture[row][col][0] = (GLubyte)value;
            texture[row][col][1] = (GLubyte)value;
            texture[row][col][2] = (GLubyte)value;
        }
    }
}

void translate_objects()
{
    auto r = static_cast<double>(rotation_trajectory);
    GLdouble z = sin(a) * r;
    GLdouble x = cos(a) * r;

    glTranslated(x, 0, z - base_distance);
}

void animate()
{
    rotation = reset_rotation ? 0 : rotation;
    a = reset_rotation ? 0 : a;
    reset_rotation = false;

    if (!animation_on)
    {
        return;
    }
    // angle divisor
    double div = static_cast<double>(animation_speed);

    // animation along own axis
    rotation += 2. / div;
    rotation = rotation > 360 ? rotation - 360 : rotation;

    // animation along circle
    if (rotation_trajectory != NO_TRAJECTORY)
    {
        a += 0.1 / div / static_cast<double>(rotation_trajectory);
    }
}

void my_reshape(int w, int h)
{
    glViewport(0, 0, w, h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(45.0, (GLfloat)w / (GLfloat)h, 0.1, 100.0);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
}

void draw_object()
{
    glLoadIdentity();
    glPushMatrix();

    translate_objects();
    glRotated(rotation, 0.5, 0.5, 0.5);

    if (object == CUBE)
    {
        switch (display_mode)
        {
        case EDGES:
            glColor3d(0.0, 1.0, 0.0);
            glutWireCube(1);
            break;
        case SINGLE_COLOR_WALLS:
            glColor3d(0.0, 1.0, 0.0);
            glutSolidCube(1);
            glColor3d(0.0, 0.0, 0.0);
            glutWireCube(1);
            break;
        case MULTI_COLOR_WALLS:
            multi_color_cube();
            glColor3d(0.0, 0.0, 0.0);
            glutWireCube(1);
            break;
        case TEXTURES:
            glColor3d(0.0, 0.0, 0.0);
            glutWireCube(1);
            textured_cube();
        }
    }
    else if (object == OCTAHEDRON)
    {
        auto scale = 1 / sqrt(2);
        glScaled(scale, scale, scale);

        switch (display_mode)
        {
        case EDGES:
            glColor3d(0.0, 1.0, 0.0);
            glutWireOctahedron();
            break;
        case SINGLE_COLOR_WALLS:
            glColor3d(0.0, 1.0, 0.0);
            glutSolidOctahedron();
            glColor3d(0.0, 0.0, 0.0);
            glutWireOctahedron();
            break;
        case MULTI_COLOR_WALLS:
            multi_color_octahedron();
            glColor3d(0.0, 0.0, 0.0);
            glutWireOctahedron();
            break;
        case TEXTURES:
            glColor3d(0.0, 0.0, 0.0);
            glutWireOctahedron();
            textured_octahedron();
        }
    }

    glPopMatrix();
}

void display(void)
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    draw_object();

    glutPostRedisplay();
    glFlush();
    glutSwapBuffers();
}
int main(int argc, char **argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
    glutInitWindowSize(800, 800);
    glutInitWindowPosition(100, 100);
    window = glutCreateWindow("Menus and Submenus - Programming Techniques");
    createMenu();
    glClearColor(0.0, 0.0, 0.0, 0.0);

    glutDisplayFunc(display);
    glutIdleFunc(animate);
    glutReshapeFunc(my_reshape);

    glEnable(GL_DEPTH_TEST);

    load_texture();
    glTexImage2D(GL_TEXTURE_2D, 0, 3, 64, 64, 0, GL_RGB,
                 GL_UNSIGNED_BYTE, texture);

    glutMainLoop();
    return 1;
}