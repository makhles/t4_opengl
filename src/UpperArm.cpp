/*
 * @author: Makhles Reuter Lange
 * Date..: 2016-07-07 - initial implementation 
 */
#include <iostream>
#include "UpperArm.hpp"

UpperArm::UpperArm(float rx, float ry, float rz, float dx, float dy, float dz) :
    BodyPart(rx, ry, rz, dx, dy, dz)
{
    m_displayList = glGenLists(1);
    glNewList(m_displayList, GL_COMPILE);
        glColor3fv(m_colorBlue1);
        GLUquadricObj *quadratic = gluNewQuadric();
        glRotatef(90.0f, 1.0f, 0.0f, 0.0f);
        gluCylinder(quadratic,0.6f,0.6f,3.0f,32,32);
        glColor3fv(m_colorBlue2);
        gluDisk(quadratic,0.0f,0.6f,32,32);
        glPushMatrix();
            glColor3fv(m_colorBlue3);
            glTranslatef(0.0,0.0,3.0f);
            gluDisk(quadratic,0.0f,0.6f,32,32);
        glPopMatrix();
        glRotatef(-90.0f, 1.0f, 0.0f, 0.0f);
    glEndList();
}

void UpperArm::display()
{
    std::cout << "> UpperArm::display()" << std::endl;
    glRotatef(m_rx, 1.0, 0.0, 0.0);
    glRotatef(m_rz, 0.0, 0.0, 1.0);
    glRotatef(m_ry, 0.0, 1.0, 0.0);
    glTranslatef(m_dx, m_dy, m_dz);
    glCallList(m_displayList);
}