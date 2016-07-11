/*
 * @author: Makhles Reuter Lange
 * Date..: 2016-07-06 - initial implementation 
 */
#include <iostream>
#include "Torso.hpp"

Torso::Torso(float rx, float ry, float rz, float dx, float dy, float dz) :
    BodyPart(rx, ry, rz, dx, dy, dz)
{
    m_displayList = glGenLists(1);
    glNewList(m_displayList, GL_COMPILE);
        GLUquadricObj *quadratic = gluNewQuadric();
        glColor3fv(m_color1);
        glRotatef(90.0f, 1.0f, 0.0f, 0.0f);
        gluCylinder(quadratic, TORSO_RADIUS_BASE, TORSO_RADIUS_TOP, TORSO_HEIGHT, SLICES, STACKS);
        glColor3fv(m_color2);
        gluDisk(quadratic, 0.0f, TORSO_RADIUS_BASE, SLICES, STACKS);

        glPushMatrix();
            glTranslatef(0.0, 0.0, TORSO_HEIGHT);
            gluDisk(quadratic, 0.0f, TORSO_RADIUS_TOP, SLICES, STACKS);
        glPopMatrix();

        glRotatef(-90.0f, 1.0f, 0.0f, 0.0f);
    glEndList();
}

void Torso::display()
{
    //std::cout << "> Torso::display()" << std::endl;
    glRotatef(m_rx, 1.0, 0.0, 0.0);
    glRotatef(m_rz, 0.0, 0.0, 1.0);
    glRotatef(m_ry, 0.0, 1.0, 0.0);
    glTranslatef(m_dx, m_dy, m_dz);
    glCallList(m_displayList);
}

void Torso::animate(const unsigned stage, float factor)
{

}