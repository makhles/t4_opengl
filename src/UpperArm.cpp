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
        glColor3fv(m_color);
        GLUquadricObj *quadratic = gluNewQuadric();
        glTranslatef(0.0f, -0.5f, 0.0f);
        gluSphere(quadratic, 0.6, SLICES, STACKS);
        glRotatef(90.0f, 1.0f, 0.0f, 0.0f);
        gluCylinder(quadratic, UPPER_ARM_RADIUS_BASE, UPPER_ARM_RADIUS_TOP, UPPER_ARM_HEIGHT, SLICES, STACKS);
        gluDisk(quadratic, 0.0f, UPPER_ARM_RADIUS_BASE, SLICES, STACKS);
        glPushMatrix();
            glTranslatef(0.0f, 0.0f, UPPER_ARM_HEIGHT);
            gluDisk(quadratic, 0.0f, UPPER_ARM_RADIUS_TOP, SLICES, STACKS);
        glPopMatrix();
        glRotatef(-90.0f, 1.0f, 0.0f, 0.0f);
    glEndList();
}

void UpperArm::display()
{
    //std::cout << "> UpperArm::display()" << std::endl;
    glRotatef(m_rx, 1.0, 0.0, 0.0);
    glRotatef(m_rz, 0.0, 0.0, 1.0);
    glRotatef(m_ry, 0.0, 1.0, 0.0);
    glTranslatef(m_dx, m_dy, m_dz);
    glCallList(m_displayList);
}

void UpperArm::animate(const unsigned stage, float factor)
{
    //BodyPart::animate(stage);

    float last_angle = 0.0f;
    if (stage == 0) {
        last_angle = m_walk_angles.at(m_walk_angles.size() - 1);
    } else {
        last_angle = m_walk_angles.at(stage - 1);
    }
     
    float stage_period = m_walk_angles.at(stage) - last_angle;
    m_rx = last_angle + factor * stage_period;
}