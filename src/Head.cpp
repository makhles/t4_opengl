/*
 * @author: Makhles Reuter Lange
 * Date..: 2016-07-06 - initial implementation 
 */
#include <iostream>
#include "Head.hpp"


Head::Head(float rx, float ry, float rz, float dx, float dy, float dz) :
    BodyPart(rx, ry, rz, dx, dy, dz)
{
    m_displayList = glGenLists(1);
    glNewList(m_displayList, GL_COMPILE);
    glPushMatrix();
        glColor3fv(m_colorBlue1);
        glScalef(0.9f, 1.0f, 1.0f);
        GLUquadricObj *quadratic = gluNewQuadric();
        gluSphere(quadratic, HEAD_RADIUS, SLICES, STACKS);

        GLUquadricObj *quadratic1 = gluNewQuadric();
        glColor3fv(m_colorBlue2);
        glTranslatef(0.0f, 0.9f, 0.0f);
        glRotatef(90.0f, 1.0f, 0.0f, 0.0f);
        gluCylinder(quadratic1, HAT_BASE_RADIUS_BASE, HAT_BASE_RADIUS_TOP, HAT_BASE_HEIGHT, SLICES, STACKS);
        gluDisk(quadratic1, 0.0f, HAT_BASE_RADIUS_BASE, SLICES, STACKS);

        glColor3fv(m_colorBlue3);
        glRotatef(-90.0f, 1.0f, 0.0f, 0.0f);
        glTranslatef(0.0f, 0.6f, 0.0f);
        glRotatef(90.0f, 1.0f, 0.0f, 0.0f);
        gluCylinder(quadratic1,1.0f,1.0f,0.7f,32,32);
        gluDisk(quadratic1,0.0f,1.0f,32,32);
    glPopMatrix();
    glEndList();
}

void Head::display()
{
    std::cout << "> Head::display()" << std::endl;
    glRotatef(m_rx, 1.0, 0.0, 0.0);
    glRotatef(m_rz, 0.0, 0.0, 1.0);
    glRotatef(m_ry, 0.0, 1.0, 0.0);
    glTranslatef(m_dx, m_dy, m_dz);
    //glColor3f(1.0f, 1.0f, 0.0f);
    glCallList(m_displayList);
}