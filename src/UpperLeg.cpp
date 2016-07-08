/*
 * @author: Makhles Reuter Lange
 * Date..: 2016-07-07 - initial implementation 
 */
#include <iostream>
#include "UpperLeg.hpp"

UpperLeg::UpperLeg(float rx, float ry, float rz, float dx, float dy, float dz) :
    BodyPart(rx, ry, rz, dx, dy, dz)
{
    m_displayList = glGenLists(1);
    glNewList(m_displayList, GL_COMPILE);
        glColor3fv(m_colorBlue1);
        GLUquadricObj *quadratic = gluNewQuadric();
        glRotatef(90.0f, 1.0f, 0.0f, 0.0f);
        gluCylinder(quadratic, UPPER_LEG_RADIUS_BASE, UPPER_LEG_RADIUS_TOP, UPPER_LEG_HEIGHT, SLICES, STACKS);
        glRotatef(-90.0f, 1.0f, 0.0f, 0.0f);
    glEndList();
}

void UpperLeg::display()
{
    std::cout << "> UpperLeg::display()" << std::endl;
    glTranslatef(m_dx, m_dy, m_dz);
    glRotatef(m_rx, 1.0, 0.0, 0.0);
    glRotatef(m_rz, 0.0, 0.0, 1.0);
    glRotatef(m_ry, 0.0, 1.0, 0.0);
    glCallList(m_displayList);
}