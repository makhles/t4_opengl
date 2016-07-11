/*
 * @author: Makhles Reuter Lange
 * Date..: 2016-07-08 - initial implementation 
 */

#ifndef LOWER_LEG_HPP
#define LOWER_LEG_HPP

#include "BodyPart.hpp"

class LowerLeg : public BodyPart {

private:
    const float LOWER_LEG_HEIGHT = 6.0f;
    const float LOWER_LEG_RADIUS_BASE = 1.0f;
    const float LOWER_LEG_RADIUS_TOP = 0.8f;
    const GLfloat m_color1[3] = {1.00f, 0.86f, 0.70f};  // 255, 220, 178
    const GLfloat m_color2[3] = {0.0f, 0.7f, 0.0f};  // Dark Green
    const GLfloat m_color3[3] = {0.0f, 1.0f, 0.0f};  // Green

public:
    LowerLeg(float rx, float ry, float rz, float dx, float dy, float dz);
    ~LowerLeg() {}
    void display() override;
    void animate(const unsigned stage, float factor) override;
};

#endif  // LOWER_LEG_HPP