/*
 * @author: Makhles Reuter Lange
 * Date..: 2016-07-04 - initial implementation 
 */
#include <GL/glut.h>
#include <stdlib.h>
#include "WalkAndRun.hpp"

#define WINDOW_WIDTH 640
#define WINDOW_HEIGHT 480

// Function prototypes
void initGL();
void display();
void reshape(int w, int h);
void keyboard(unsigned char key, int x, int y);

// Global variables
WalkAndRun *war;

// ------------------------------------------------------------------------- //

int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_DEPTH | GLUT_RGBA);
    glutInitWindowSize(WINDOW_WIDTH, WINDOW_HEIGHT);
    glutInitWindowPosition((glutGet(GLUT_SCREEN_WIDTH) - WINDOW_WIDTH)/2,
                          (glutGet(GLUT_SCREEN_HEIGHT) - WINDOW_HEIGHT)/2);
    glutCreateWindow("OpenGL - t4");
    glutDisplayFunc(display);  // Register callback handler for window re-paint event
    glutReshapeFunc(reshape);  // Register callback handler for window re-size event
    glutKeyboardFunc(keyboard);
    initGL();
    glutMainLoop();
    return 0;
}

/**
 * @brief      Initialize OpenGL graphics.
 */
void initGL()
{
    glClearColor(0.0f, 0.0f, 0.0f, 1.0f);  // Set background color to opaque black
    glClearDepth(1.0f);       // Set background depth to farthest
    glEnable(GL_DEPTH_TEST);  // Enable depth testing for z-culling
    glDepthFunc(GL_LEQUAL);   // Set the type of depth-test
    glShadeModel(GL_SMOOTH);  // Enable smooth shading
    glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);  // Nice perspective corrections
    war = new WalkAndRun();
}

/**
 * @brief      Called when a re-paint event occurs.
 */
void display()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); // Clear color and depth buffers
    glMatrixMode(GL_MODELVIEW);     // To operate on model-view matrix

    glLoadIdentity();
    glColor3f(1.0f, 1.0f, 1.0f);
    gluLookAt(10.0f, 10.0f, 30.0f, 0.0f, 0.0f, 0.0f, 0.0f, 1.0f, 0.0f);

    // Update and draw scene
    war->display();

    glutSwapBuffers();
}

/**
 * @brief      Called whenever the window is resized.
 *
 * @param[in]  width     The new width of the window.
 * @param[in]  height    The new height of the window.
 */
void reshape(GLsizei width, GLsizei height)
{
    if (height == 0) height = 1;  // To prevent division by 0
    GLfloat aspect = (GLfloat)width / (GLfloat)height;
    glViewport (0, 0, width, height); 
    glMatrixMode (GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(60.0f, aspect, 0.1, 100.0f);
}

/**
 * @brief      Called whenever a key is pressed.
 *
 * @param[in]  key   ASCII character representing the key pressed.
 * @param[in]  x     Mouse pointer coordinate x when key was pressed.
 * @param[in]  y     Mouse pointer coordinate y when key was pressed.
 */
void keyboard(unsigned char key, int x, int y)
{
    const int POS = +1;
    const int NEG = -1;

    switch(key)
    {
        case 27 : exit(0); break;
        case 'x': war->rotate_x(POS); break;
        case 'X': war->rotate_x(NEG); break;
        case 'y': war->rotate_y(POS); break;
        case 'Y': war->rotate_y(NEG); break;
        case 'z': war->rotate_z(POS); break;
        case 'Z': war->rotate_z(NEG); break;
    }
    glutPostRedisplay();
}