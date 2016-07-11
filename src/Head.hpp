/*
 * @author: Makhles Reuter Lange
 * Date..: 2016-07-06 - initial implementation 
 */

#ifndef HEAD_HPP
#define HEAD_HPP

#include "BodyPart.hpp"

class Head : public BodyPart {

private:
    const float HEAD_RADIUS = 1.3f;
    const float HAT_BASE_RADIUS_BASE = 1.6;
    const float HAT_BASE_RADIUS_TOP = 1.6;
    const float HAT_BASE_HEIGHT = 0.6;
    const float HAT_TOP_RADIUS_BASE = 1.0;
    const float HAT_TOP_RADIUS_TOP = 1.0;
    const float HAT_TOP_HEIGHT = 0.7;
    const GLfloat m_color1[3] = {1.00f, 0.86f, 0.70f};  // 255, 220, 178
    const GLfloat m_color2[3] = {0.34f, 0.25f, 0.18f};  // 87, 65, 47
    const GLfloat m_color3[3] = {0.47f, 0.37f, 0.30f};  // 121, 96, 76

public:
    Head(float rx, float ry, float rz, float dx, float dy, float dz);
    ~Head() {}
    void display() override;
};

#endif  // HEAD_HPP