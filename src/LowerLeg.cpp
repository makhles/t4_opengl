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
    //std::cout << "> LowerLeg::display()" << std::endl;
    glTranslatef(m_dx, m_dy, m_dz);
    glRotatef(m_rx, 1.0, 0.0, 0.0);
    glRotatef(m_rz, 0.0, 0.0, 1.0);
    glRotatef(m_ry, 0.0, 1.0, 0.0);
    glCallList(m_displayList);
}

void LowerLeg::animate(const unsigned stage, float factor)
{
    //BodyPart::animate(stage);

    float last_angle;
    if (stage == 0) {
        last_angle = m_angles.at(m_angles.size() - 1);
    } else {
        last_angle = m_angles.at(stage - 1);
    }
    float stage_period = m_angles.at(stage) - last_angle;
    m_rx = last_angle + factor * stage_period;
}

void LowerLeg::change_stance(Stance stance) {
    if (m_stance != Stance::WALKING && stance == Stance::WALKING) {
        m_stance = Stance::WALKING;
        m_angles.clear();
        if (m_side == BodySide::LEFT) {
            m_angles.push_back(+0.0f);
            m_angles.push_back(+6.0f);
            m_angles.push_back(+4.0f);
            m_angles.push_back(+0.0f);
            m_angles.push_back(+0.0f);
            m_angles.push_back(+0.0f);
            m_angles.push_back(+0.0f);
            m_angles.push_back(+10.0f);
            m_angles.push_back(+50.0f);
            m_angles.push_back(+65.0f);
            m_angles.push_back(+30.0f);
            m_angles.push_back(+5.0f);
        } else if (m_side == BodySide::RIGHT) {
            m_angles.push_back(+0.0f);
            m_angles.push_back(+10.0f);
            m_angles.push_back(+50.0f);
            m_angles.push_back(+65.0f);
            m_angles.push_back(+30.0f);
            m_angles.push_back(+5.0f);
            m_angles.push_back(+0.0f);
            m_angles.push_back(+6.0f);
            m_angles.push_back(+4.0f);
            m_angles.push_back(+0.0f);
            m_angles.push_back(+0.0f);
            m_angles.push_back(+0.0f);
        }
    } else if (m_stance != Stance::RUNNING && stance == Stance::RUNNING) {
        m_stance = Stance::RUNNING;
        m_angles.clear();
        if (m_side == BodySide::LEFT) {
            m_angles.push_back(+45.0f);
            m_angles.push_back(+15.0f);
            m_angles.push_back(+5.0f);
            m_angles.push_back(+10.0f);
            m_angles.push_back(+5.0f);
            m_angles.push_back(+0.0f);
            m_angles.push_back(+0.0f);
            m_angles.push_back(+30.0f);
            m_angles.push_back(+60.0f);
            m_angles.push_back(+110.0f);
            m_angles.push_back(+90.0f);
            m_angles.push_back(+60.0f);
        } else if (m_side == BodySide::RIGHT) {
            m_angles.push_back(+0.0f);
            m_angles.push_back(+30.0f);
            m_angles.push_back(+60.0f);
            m_angles.push_back(+110.0f);
            m_angles.push_back(+90.0f);
            m_angles.push_back(+60.0f);
            m_angles.push_back(+45.0f);
            m_angles.push_back(+15.0f);
            m_angles.push_back(+5.0f);
            m_angles.push_back(+10.0f);
            m_angles.push_back(+5.0f);
            m_angles.push_back(+0.0f);
        }
    } else if (m_stance != Stance::STANDING && stance == Stance::STANDING) {
        m_stance = Stance::STANDING;
        for (unsigned i = 0; i < m_angles.size(); i++) {
            m_angles.at(i) = 0.0f;
        }
    }
}