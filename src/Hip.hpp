/*
 * @author: Makhles Reuter Lange
 * Date..: 2016-07-08 - initial implementation 
 */

#ifndef HIP_HPP
#define HIP_HPP

#include "BodyPart.hpp"

class Hip : public BodyPart {

private:
    const int SLICES = 32;
    const int STACKS = 32;
    const float HIP_HEIGHT = 1.0f;
    const float HIP_RADIUS_BASE = 2.1f;
    const float HIP_RADIUS_TOP = 2.1f;
    const GLfloat m_color1[3] = {0.0f, 0.7f, 0.7f};  // Dark Cyan
    const GLfloat m_color2[3] = {0.0f, 1.0f, 1.0f};  // Cyan

public:
    Hip(float rx, float ry, float rz, float dx, float dy, float dz);
    ~Hip() {}
    void display() override;
};

#endif  // HIP_HPP