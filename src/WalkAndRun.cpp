/*
 * @author: Makhles Reuter Lange
 * Date..: 2016-07-05 - initial implementation 
 */

#include <iostream>
#include <GL/glut.h>
#include "WalkAndRun.hpp"
#include "Puppet.hpp"

WalkAndRun::WalkAndRun(float eyex, float eyey, float eyez) :
    m_eyex(eyex), m_eyey(eyey), m_eyez(eyez)
{
    std::cout << "WalkAndRun::WalkAndRun()" << std::endl;
    m_puppet = new Puppet();
}

WalkAndRun::~WalkAndRun() {
    delete m_puppet;
}

void WalkAndRun::display() {
    std::cout << "WalkAndRun::display()" << std::endl;
    gluLookAt(m_eyex, m_eyey, m_eyez, 0.0f, 0.0f, 0.0f, 0.0f, 1.0f, 0.0f);
    glRotatef(m_rx, 1.0f, 0.0f, 0.0f);
    glRotatef(m_ry, 0.0f, 1.0f, 0.0f);
    glRotatef(m_rz, 0.0f, 0.0f, 1.0f);
    m_puppet->display();
}
