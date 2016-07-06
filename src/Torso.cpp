/*
 * @author: Makhles Reuter Lange
 * Date..: 2016-07-06 - initial implementation 
 */
#include <iostream>
#include "Torso.hpp"

Torso::Torso() : BodyPart(nullptr, nullptr), m_x(0), m_y(0), m_z(0)
{
    m_displayList = glGenLists(1);
    glNewList(m_displayList, GL_COMPILE);
        GLUquadricObj *quadratic = gluNewQuadric();
        glRotatef(90.0f, 1.0f, 0.0f, 0.0f);
        gluCylinder(quadratic,2.5f, 2.0f, 5.0f, 32, 32);
        gluDisk(quadratic,0.0f, 2.5f, 32, 32);

        glPushMatrix();
            glTranslatef(0.0, 0.0, 5.0f);
            gluDisk(quadratic, 0.0f, 2.0f, 32, 32);
        glPopMatrix();

        glRotatef(-90.0f, 1.0f, 0.0f, 0.0f);
    glEndList();
}

void Torso::display()
{
    std::cout << "> Torso::display()" << std::endl;
    glRotatef(m_x, 1.0, 0.0, 0.0);
    glRotatef(m_z, 0.0, 0.0, 1.0);
    glRotatef(m_y, 0.0, 1.0, 0.0);
    glTranslatef(0.0f, 5.0f, 0.0f);
    glColor3f(1.0f, 0.0f, 1.0f);
    glCallList(m_displayList);
}