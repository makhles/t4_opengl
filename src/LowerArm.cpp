/*
 * @author: Makhles Reuter Lange
 * Date..: 2016-07-07 - initial implementation 
 */
#include <iostream>
#include "LowerArm.hpp"

LowerArm::LowerArm(float rx, float ry, float rz, float dx, float dy, float dz) :
    BodyPart(rx, ry, rz, dx, dy, dz)
{
    m_displayList = glGenLists(1);
    glNewList(m_displayList, GL_COMPILE);
        glColor3fv(m_color1);
        GLUquadricObj *quadratic = gluNewQuadric();
        glRotatef(90.0f, 1.0f, 0.0f, 0.0f);
        gluCylinder(quadratic, LOWER_ARM_RADIUS_BASE, LOWER_ARM_RADIUS_TOP, LOWER_ARM_HEIGHT, SLICES, STACKS);
        glColor3fv(m_color2);
        gluDisk(quadratic, 0.0f, LOWER_ARM_RADIUS_BASE, SLICES, STACKS);
        glPushMatrix();
            glColor3fv(m_color3);
            glTranslatef(0.0, 0.0, LOWER_ARM_HEIGHT);
            gluDisk(quadratic, 0.0f, LOWER_ARM_RADIUS_TOP, SLICES, STACKS);
        glPopMatrix();
        glRotatef(-90.0f, 1.0f, 0.0f, 0.0f);
    glEndList();
}

void LowerArm::display()
{
    std::cout << "> LowerArm::display()" << std::endl;
    glTranslatef(m_dx, m_dy, m_dz);
    glRotatef(m_rx, 1.0f, 0.0f, 0.0f);
    glRotatef(m_ry, 0.0f, 1.0f, 0.0f);
    glRotatef(m_rz, 0.0f, 0.0f, 1.0f);
    glCallList(m_displayList);
}