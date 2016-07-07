/*
 * @author: Makhles Reuter Lange
 * Date..: 2016-07-06 - initial implementation 
 */

#ifndef TORSO_HPP
#define TORSO_HPP

#include "BodyPart.hpp"

class Torso : public BodyPart {

private:
    float m_rx, m_ry, m_rz;  // Rotation angles
    float m_dx, m_dy, m_dz;  // Displacements

public:
    Torso();
    ~Torso() {}

    void set_rotation(float rx, float ry, float rz) {
        m_rx = rx;   m_ry = ry;   m_rz = rz;
    }

    void set_displacement(float dx, float dy, float dz) {
        m_dx = dx;   m_dy = dy;   m_dz = dz;
    }

    void display() override;
};

#endif  // TORSO_HPP