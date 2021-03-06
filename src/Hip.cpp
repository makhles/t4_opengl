/*
 * @author: Makhles Reuter Lange
 * Date..: 2016-07-08 - initial implementation 
 */
#include <iostream>
#include "Hip.hpp"

Hip::Hip(float rx, float ry, float rz, float dx, float dy, float dz) :
    BodyPart(rx, ry, rz, dx, dy, dz)
{
    m_displayList = glGenLists(1);
    glNewList(m_displayList, GL_COMPILE);
        GLUquadricObj *quadratic = gluNewQuadric();
        glPushMatrix();
            glColor3fv(m_color1);
            glTranslatef(0.0f, -HIP_HEIGHT / 2.0f, HIP_RADIUS_BASE);
            gluDisk(quadratic, 0.0f, 0.2f, SLICES, STACKS);  // Belt buckle
        glPopMatrix();
        glColor3fv(m_color2);
        glRotatef(90.0f, 1.0f, 0.0f, 0.0f);
        gluCylinder(quadratic, HIP_RADIUS_BASE, HIP_RADIUS_TOP, HIP_HEIGHT, SLICES, STACKS);
        glPushMatrix();
            glColor3fv(m_color3);
            glTranslatef(0.0f, 0.0f, HIP_HEIGHT);
            gluDisk(quadratic, 0.0f, HIP_RADIUS_TOP, SLICES, STACKS);
        glPopMatrix();
        glRotatef(-90.0f, 1.0f, 0.0f, 0.0f);
    glEndList();
}

void Hip::display()
{
    //std::cout << "> Hip::display()" << std::endl;
    glRotatef(m_rx, 1.0, 0.0, 0.0);
    glRotatef(m_rz, 0.0, 0.0, 1.0);
    glRotatef(m_ry, 0.0, 1.0, 0.0);
    glTranslatef(m_dx, m_dy, m_dz);
    glCallList(m_displayList);
}

void Hip::animate(const unsigned stage, float factor)
{

}