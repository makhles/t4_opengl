/*
 * @author: Makhles Reuter Lange
 * Date..: 2016-07-07 - initial implementation 
 */

#ifndef UPPER_ARM_HPP
#define UPPER_ARM_HPP

#include "BodyPart.hpp"

class UpperArm : public BodyPart {

private:
    const int SLICES = 32;
    const int STACKS = 32;
    const float UPPER_ARM_HEIGHT = 3.0f;
    const float UPPER_ARM_RADIUS_BASE = 0.6f;
    const float UPPER_ARM_RADIUS_TOP = 0.6f;
    const GLfloat m_colorBlue1[3] = {0.0f, 0.0f, 1.0f};
    const GLfloat m_colorBlue2[3] = {0.0f, 0.0f, 0.7f};
    const GLfloat m_colorBlue3[3] = {0.0f, 0.0f, 0.3f};

public:
    UpperArm(float rx, float ry, float rz, float dx, float dy, float dz);
    ~UpperArm() {}
    void display() override;
};

#endif  // UPPER_ARM_HPP