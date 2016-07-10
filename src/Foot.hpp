/*
 * @author: Makhles Reuter Lange
 * Date..: 2016-07-10 - initial implementation 
 */

#ifndef FOOT_HPP
#define FOOT_HPP

#include "BodyPart.hpp"

class Foot : public BodyPart {

private:
    const GLint SLICES = 32;
    const GLint STACKS = 32;
    const float FOOT_HEIGHT = 2.5f;
    const float FOOT_RADIUS_BASE = 1.0f;
    const float FOOT_RADIUS_TOP = 0.6f;
    const GLfloat m_color[3] = {1.00f, 0.86f, 0.70f};  // 255, 220, 178

public:
    Foot(float rx, float ry, float rz, float dx, float dy, float dz);
    ~Foot() {}
    void display() override;
};

#endif  // FOOT_HPP