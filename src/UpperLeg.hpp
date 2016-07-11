/*
 * @author: Makhles Reuter Lange
 * Date..: 2016-07-07 - initial implementation 
 */

#ifndef UPPER_LEG_HPP
#define UPPER_LEG_HPP

#include "BodyPart.hpp"

class UpperLeg : public BodyPart {

private:
    const float UPPER_LEG_HEIGHT = 4.0f;
    const float UPPER_LEG_RADIUS_BASE = 1.0f;
    const float UPPER_LEG_RADIUS_TOP = 1.0f;
    const GLfloat m_colorBlue1[3] = {0.0f, 0.0f, 1.0f};
    const GLfloat m_colorBlue2[3] = {0.0f, 0.0f, 0.7f};
    const GLfloat m_colorBlue3[3] = {0.0f, 0.0f, 0.3f};

public:
    UpperLeg(float rx, float ry, float rz, float dx, float dy, float dz);
    ~UpperLeg() {}
    void display() override;
    void animate(const unsigned stage, float factor) override;
    void change_stance(Stance stance) override;
};

#endif  // UPPER_LEG_HPP