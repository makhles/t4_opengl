/*
 * @author: Makhles Reuter Lange
 * Date..: 2016-07-05 - initial implementation 
 */

#include <iostream>
#include <GL/glut.h>
#include "WalkAndRun.hpp"

WalkAndRun::WalkAndRun(float eyex, float eyey, float eyez) :
    m_eyex(eyex), m_eyey(eyey), m_eyez(eyez), m_current_time(0.0f)
{
    std::cout << "WalkAndRun::WalkAndRun()" << std::endl;
    m_puppet = new Puppet();
    WalkAndRun::fill_stages();
}

WalkAndRun::~WalkAndRun() {
    delete m_puppet;
}

void WalkAndRun::fill_stages()
{
    for (unsigned i = 0; i < M_NUMBER_OF_STAGES; i++) {
        m_stages.push_back((i + 1) * M_STAGE_PERIOD);
    }
}

void WalkAndRun::display() {
    //std::cout << "WalkAndRun::display()" << std::endl;
    gluLookAt(m_eyex, m_eyey, m_eyez, 0.0f, 0.0f, 0.0f, 0.0f, 1.0f, 0.0f);
    glRotatef(m_rx, 1.0f, 0.0f, 0.0f);
    glRotatef(m_ry, 0.0f, 1.0f, 0.0f);
    glRotatef(m_rz, 0.0f, 0.0f, 1.0f);
    m_puppet->display();
}

void WalkAndRun::animate(const double dt)
{
    unsigned stage = 0;
    float factor = 0.0f;

    m_current_time += dt;

    if (m_current_time > M_PERIOD && m_current_time < 1.5 * M_PERIOD) {
        m_current_time -= M_PERIOD;
    } else if (m_current_time >= 1.5 * M_PERIOD) {
        m_current_time = 0.0f;
    }

    for (unsigned i = 0; i < M_NUMBER_OF_STAGES; i++)
    {
        if (m_current_time > m_stages.at(i)) {
            stage++;
        } else {
            if (i == 0) {
                factor = m_current_time / M_STAGE_PERIOD;
            } else {
                factor = (m_current_time - m_stages.at(i-1)) / M_STAGE_PERIOD;
            }
            break;
        }
    }
    //std::cout << "Current time: " << m_current_time << std::endl;
    m_puppet->animate(stage, factor);
}