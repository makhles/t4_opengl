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
    //std::cout << "> LowerArm::display()" << std::endl;
    glTranslatef(m_dx, m_dy, m_dz);
    glRotatef(m_rx, 1.0f, 0.0f, 0.0f);
    glRotatef(m_ry, 0.0f, 1.0f, 0.0f);
    glRotatef(m_rz, 0.0f, 0.0f, 1.0f);
    glCallList(m_displayList);
}

void LowerArm::animate(const unsigned stage, float factor)
{
    //BodyPart::animate(stage);

    float last_angle = 0.0f;
    if (stage == 0) {
        last_angle = m_angles.at(m_angles.size() - 1);
    } else {
        last_angle = m_angles.at(stage - 1);
    }
     
    float stage_period = m_angles.at(stage) - last_angle;
    m_rx = last_angle + factor * stage_period;
}

void LowerArm::change_stance(Stance stance) {
    if (m_stance != Stance::WALKING && stance == Stance::WALKING) {
        m_stance = Stance::WALKING;
        m_angles.clear();
        if (m_side == BodySide::LEFT) {
            m_angles.push_back(+0.0f);
            m_angles.push_back(-5.0f);
            m_angles.push_back(-10.0f);
            m_angles.push_back(-15.0f);
            m_angles.push_back(-20.0f);
            m_angles.push_back(-25.0f);
            m_angles.push_back(-30.0f);
            m_angles.push_back(-25.0f);
            m_angles.push_back(-20.0f);
            m_angles.push_back(-15.0f);
            m_angles.push_back(-10.0f);
            m_angles.push_back(-5.0f);
        } else if (m_side == BodySide::RIGHT) {
            m_angles.push_back(-30.0f);
            m_angles.push_back(-25.0f);
            m_angles.push_back(-20.0f);
            m_angles.push_back(-15.0f);
            m_angles.push_back(-10.0f);
            m_angles.push_back(-5.0f);
            m_angles.push_back(+0.0f);
            m_angles.push_back(-5.0f);
            m_angles.push_back(-10.0f);
            m_angles.push_back(-15.0f);
            m_angles.push_back(-20.0f);
            m_angles.push_back(-25.0f);
        }
    } else if (m_stance != Stance::RUNNING && stance == Stance::RUNNING) {
        m_stance = Stance::RUNNING;
        m_angles.clear();
        if (m_side == BodySide::LEFT) {
            m_angles.push_back(-90.0f);
            m_angles.push_back(-90.0f);
            m_angles.push_back(-90.0f);
            m_angles.push_back(-90.0f);
            m_angles.push_back(-90.0f);
            m_angles.push_back(-90.0f);
            m_angles.push_back(-90.0f);
            m_angles.push_back(-90.0f);
            m_angles.push_back(-90.0f);
            m_angles.push_back(-90.0f);
            m_angles.push_back(-90.0f);
            m_angles.push_back(-90.0f);
        } else if (m_side == BodySide::RIGHT) {
            m_angles.push_back(-90.0f);
            m_angles.push_back(-90.0f);
            m_angles.push_back(-90.0f);
            m_angles.push_back(-90.0f);
            m_angles.push_back(-90.0f);
            m_angles.push_back(-90.0f);
            m_angles.push_back(-90.0f);
            m_angles.push_back(-90.0f);
            m_angles.push_back(-90.0f);
            m_angles.push_back(-90.0f);
            m_angles.push_back(-90.0f);
            m_angles.push_back(-90.0f);
        }
    } else if (m_stance != Stance::STANDING && stance == Stance::STANDING) {
        m_stance = Stance::STANDING;
        for (unsigned i = 0; i < m_angles.size(); i++) {
            m_angles.at(i) = 0.0f;
        }
    }
}