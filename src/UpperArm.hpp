/*
 * @author: Makhles Reuter Lange
 * Date..: 2016-07-07 - initial implementation 
 */

#ifndef UPPER_ARM_HPP
#define UPPER_ARM_HPP

#include "BodyPart.hpp"

class UpperArm : public BodyPart {

private:
    const GLfloat m_colorBlue1[3] = {0.0f, 0.0f, 1.0f};
    const GLfloat m_colorBlue2[3] = {0.0f, 0.0f, 0.7f};
    const GLfloat m_colorBlue3[3] = {0.0f, 0.0f, 0.3f};

public:
    UpperArm(float rx, float ry, float rz, float dx, float dy, float dz);
    ~UpperArm() {}
    void display() override;
};

#endif  // UPPER_ARM_HPP