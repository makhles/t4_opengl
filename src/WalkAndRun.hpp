/*
 * @author: Makhles Reuter Lange
 * Date..: 2016-07-05 - initial implementation 
 */

#ifndef WALKANDRUN_HPP
#define WALKANDRUN_HPP

// Forward declarations
class Puppet;


class WalkAndRun {

private:
    Puppet *m_puppet;

public:
    WalkAndRun();
    ~WalkAndRun();
    void display();
};

#endif  // WALKANDRUN_HPP