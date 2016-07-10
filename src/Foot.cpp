/*
 * @author: Makhles Reuter Lange
 * Date..: 2016-07-07 - initial implementation 
 */
#include <iostream>
#include "Foot.hpp"

Foot::Foot(float rx, float ry, float rz, float dx, float dy, float dz) :
    BodyPart(rx, ry, rz, dx, dy, dz)
{
    m_displayList = glGenLists(1);
    glNewList(m_displayList, GL_COMPILE);
        glColor3fv(m_color);
        GLUquadricObj *quadratic = gluNewQuadric();
        gluSphere(quadratic, FOOT_RADIUS_BASE, SLICES, STACKS);
        gluCylinder(quadratic, FOOT_RADIUS_BASE, FOOT_RADIUS_TOP, FOOT_HEIGHT, SLICES, STACKS);
        glPushMatrix();
            glTranslatef(0.0f, 0.0f, FOOT_HEIGHT);
            gluSphere(quadratic, FOOT_RADIUS_TOP, SLICES, STACKS);
        glPopMatrix();
    glEndList();
}

void Foot::display()
{
    std::cout << "> Foot::display()" << std::endl;
    glRotatef(m_rx, 1.0, 0.0, 0.0);
    glRotatef(m_rz, 0.0, 0.0, 1.0);
    glRotatef(m_ry, 0.0, 1.0, 0.0);
    glTranslatef(m_dx, m_dy, m_dz);
    glCallList(m_displayList);
}