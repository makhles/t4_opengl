/*
 * @author: Makhles Reuter Lange
 * Date..: 2016-07-07 - initial implementation 
 */

#ifndef LOWER_ARM_HPP
#define LOWER_ARM_HPP

#include "BodyPart.hpp"

class LowerArm : public BodyPart {

private:
    const GLint SLICES = 32;
    const GLint STACKS = 32;
    const float LOWER_ARM_HEIGHT = 4.0f;
    const float LOWER_ARM_RADIUS_BASE = 0.6f;
    const float LOWER_ARM_RADIUS_TOP = 0.4f;
    const GLfloat m_colorGreen1[3] = {0.0f, 0.3f, 0.0f};
    const GLfloat m_colorGreen2[3] = {0.0f, 0.7f, 0.0f};
    const GLfloat m_colorGreen3[3] = {0.0f, 1.0f, 0.0f};

public:
    LowerArm(float rx, float ry, float rz, float dx, float dy, float dz);
    ~LowerArm() {}
    void display() override;
};

#endif  // LOWER_ARM_HPP