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
    const float DEFAULT_DISPLACEMENT = 1.0f;
    Puppet *m_puppet;
    float m_rx, m_ry, m_rz;        // Scene rotation angles
    float m_eyex, m_eyey, m_eyez;  // Desired viewpoint

public:
    WalkAndRun(float eyex, float eyey, float eyez);
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
    void move_eye_x(int displacement) {
        m_eyex += displacement * DEFAULT_DISPLACEMENT;
    }
    void move_eye_y(int displacement) {
        m_eyey += displacement * DEFAULT_DISPLACEMENT;
    }
    void move_eye_z(int displacement) {
        m_eyez += displacement * DEFAULT_DISPLACEMENT;
    }
};

#endif  // WALKANDRUN_HPP