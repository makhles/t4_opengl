/*
 * @author: Makhles Reuter Lange
 * Date..: 2016-07-08 - initial implementation 
 */
#include <iostream>
#include "Neck.hpp"

Neck::Neck(float rx, float ry, float rz, float dx, float dy, float dz) :
    BodyPart(rx, ry, rz, dx, dy, dz)
{
    m_displayList = glGenLists(1);
    glNewList(m_displayList, GL_COMPILE);
        glColor3fv(m_color);
        GLUquadricObj *quadratic = gluNewQuadric();
        glRotatef(90.0f, 1.0f, 0.0f, 0.0f);
        gluCylinder(quadratic, NECK_RADIUS_BASE, NECK_RADIUS_TOP, NECK_HEIGHT, SLICES, STACKS);
        glRotatef(-90.0f, 1.0f, 0.0f, 0.0f);
    glEndList();
}

void Neck::display()
{
    std::cout << "> Neck::display()" << std::endl;
    glRotatef(m_rx, 1.0, 0.0, 0.0);
    glRotatef(m_rz, 0.0, 0.0, 1.0);
    glRotatef(m_ry, 0.0, 1.0, 0.0);
    glTranslatef(m_dx, m_dy, m_dz);
    glCallList(m_displayList);
}