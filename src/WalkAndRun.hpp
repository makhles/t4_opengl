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
    const float DEFAULT_ROTATION = 5.0f;
    Puppet *m_puppet;
    float m_rx, m_ry, m_rz;  // Scene rotation angles

public:
    WalkAndRun();
    ~WalkAndRun();
    void display();

    void rotate_x(int orientation) {
        m_rx += orientation * DEFAULT_ROTATION;
    }
    void rotate_y(int orientation) {
        m_ry += orientation * DEFAULT_ROTATION;
    }
    void rotate_z(int orientation) {
        m_rz += orientation * DEFAULT_ROTATION;
    }
};

#endif  // WALKANDRUN_HPP