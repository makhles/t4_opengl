/*
 * @author: Makhles Reuter Lange
 * Date..: 2016-07-06 - initial implementation 
 */

#ifndef TORSO_HPP
#define TORSO_HPP

#include "BodyPart.hpp"

class Torso : public BodyPart {

private:
    const int SLICES = 32;
    const int STACKS = 32;
    const float TORSO_HEIGHT = 5.0f;
    const float TORSO_RADIUS_BASE = 2.5f;
    const float TORSO_RADIUS_TOP = 2.0f;
    const GLfloat m_color1[3] = {0.7f, 0.0f, 0.7f};  // Dark Magenta
    const GLfloat m_color2[3] = {1.0f, 0.0f, 1.0f};  // Magenta

public:
    Torso(float rx, float ry, float rz, float dx, float dy, float dz);
    ~Torso() {}
    void display() override;
};

#endif  // TORSO_HPP