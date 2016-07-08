/*
 * @author: Makhles Reuter Lange
 * Date..: 2016-07-06 - initial implementation 
 */

#ifndef HEAD_HPP
#define HEAD_HPP

#include "BodyPart.hpp"

class Head : public BodyPart {

private:
    const GLint SLICES = 32;
    const GLint STACKS = 32;
    const float HEAD_RADIUS = 1.3f;
    const float HAT_BASE_RADIUS_BASE = 1.6;
    const float HAT_BASE_RADIUS_TOP = 1.6;
    const float HAT_BASE_HEIGHT = 0.6;
    const float HAT_TOP_RADIUS_BASE = 1.0;
    const float HAT_TOP_RADIUS_TOP = 1.0;
    const float HAT_TOP_HEIGHT = 0.7;
    const GLfloat m_colorBlue1[3] = {0.0f, 0.0f, 1.0f};
    const GLfloat m_colorBlue2[3] = {0.0f, 0.0f, 0.7f};
    const GLfloat m_colorBlue3[3] = {0.0f, 0.0f, 0.3f};

public:
    Head(float rx, float ry, float rz, float dx, float dy, float dz);
    ~Head() {}
    void display() override;
};

#endif  // HEAD_HPP