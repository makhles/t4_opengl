/*
 * @author: Makhles Reuter Lange
 * Date..: 2016-07-07 - initial implementation 
 */

#ifndef UPPER_ARM_HPP
#define UPPER_ARM_HPP

#include "BodyPart.hpp"

class UpperArm : public BodyPart {

private:
    const float UPPER_ARM_HEIGHT = 3.0f;
    const float UPPER_ARM_RADIUS_BASE = 0.6f;
    const float UPPER_ARM_RADIUS_TOP = 0.6f;
    const GLfloat m_color1[3] = {0.165f, 0.435f, 0.216f};  // 42, 111, 55 (green)
    const GLfloat m_color2[3] = {0.132f, 0.348f, 0.173f};  // 42, 111, 55 (darker green)

public:
    UpperArm(float rx, float ry, float rz, float dx, float dy, float dz);
    ~UpperArm() {}
    void display() override;
    void animate(const unsigned stage, float factor) override;
    void change_stance(Stance stance) override;
};

#endif  // UPPER_ARM_HPP