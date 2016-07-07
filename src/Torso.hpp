/*
 * @author: Makhles Reuter Lange
 * Date..: 2016-07-06 - initial implementation 
 */

#ifndef TORSO_HPP
#define TORSO_HPP

#include "BodyPart.hpp"

class Torso : public BodyPart {

public:
    Torso(float rx, float ry, float rz, float dx, float dy, float dz);
    ~Torso() {}
    void display() override;
};

#endif  // TORSO_HPP