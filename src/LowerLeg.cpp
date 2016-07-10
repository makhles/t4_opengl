/*
 * @author: Makhles Reuter Lange
 * Date..: 2016-07-07 - initial implementation 
 */
#include <iostream>
#include "LowerLeg.hpp"

LowerLeg::LowerLeg(float rx, float ry, float rz, float dx, float dy, float dz) :
    BodyPart(rx, ry, rz, dx, dy, dz)
{
    m_displayList = glGenLists(1);
    glNewList(m_displayList, GL_COMPILE);
        glColor3fv(m_color1);
        GLUquadricObj *quadratic = gluNewQuadric();
        glRotatef(90.0f, 1.0f, 0.0f, 0.0f);
        gluCylinder(quadratic, LOWER_LEG_RADIUS_BASE, LOWER_LEG_RADIUS_TOP, LOWER_LEG_HEIGHT, SLICES, STACKS);
        glPushMatrix();
            glColor3fv(m_color2);
            glTranslatef(0.0f, 0.0f, LOWER_LEG_HEIGHT);
            gluDisk(quadratic, 0.0f, LOWER_LEG_RADIUS_TOP, SLICES, STACKS);
        glPopMatrix();
        glRotatef(-90.0f, 1.0f, 0.0f, 0.0f);
    glEndList();
}

void LowerLeg::display()
{
    std::cout << "> LowerLeg::display()" << std::endl;
    glRotatef(m_rx, 1.0, 0.0, 0.0);
    glRotatef(m_rz, 0.0, 0.0, 1.0);
    glRotatef(m_ry, 0.0, 1.0, 0.0);
    glTranslatef(m_dx, m_dy, m_dz);
    glCallList(m_displayList);
}