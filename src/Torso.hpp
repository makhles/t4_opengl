/*
 * @author: Makhles Reuter Lange
 * Date..: 2016-07-06 - initial implementation 
 */

#ifndef TORSO_HPP
#define TORSO_HPP

#include "BodyPart.hpp"

class Torso : public BodyPart {

private:
    float m_x, m_y, m_z;

public:
    Torso();
    ~Torso() {}
    void display() override;
};

#endif  // TORSO_HPP