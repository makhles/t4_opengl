/*
 * @author: Makhles Reuter Lange
 * Date..: 2016-07-05 - initial implementation 
 */

#include "WalkAndRun.hpp"
#include "Puppet.hpp"

WalkAndRun::WalkAndRun() {
    m_puppet = new Puppet();
}

WalkAndRun::~WalkAndRun() {
    delete m_puppet;
}

void WalkAndRun::display() {
    m_puppet->display();
}
