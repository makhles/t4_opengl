/*
 * @author: Makhles Reuter Lange
 * Date..: 2016-07-05 - initial implementation 
 */

#include <GL/glut.h>
#include "WalkAndRun.hpp"
#include "Puppet.hpp"

WalkAndRun::WalkAndRun() {
    m_puppet = new Puppet();
}

WalkAndRun::~WalkAndRun() {
    delete m_puppet;
}

void WalkAndRun::display() {
    glRotatef(m_rx, 1.0f, 0.0f, 0.0f);
    glRotatef(m_ry, 0.0f, 1.0f, 0.0f);
    glRotatef(m_rz, 0.0f, 0.0f, 1.0f);
    m_puppet->display();
}
