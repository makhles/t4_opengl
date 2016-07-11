/*
 * @author: Makhles Reuter Lange
 * Date..: 2016-07-08 - initial implementation 
 */

#ifndef NECK_HPP
#define NECK_HPP

#include "BodyPart.hpp"

class Neck : public BodyPart {

private:
    const float NECK_HEIGHT = 0.6f;
    const float NECK_RADIUS_BASE = 0.6f;
    const float NECK_RADIUS_TOP = 0.6f;
    const GLfloat m_color[3] = {1.0f, 0.86f, 0.7f};  // 255, 220, 178

public:
    Neck(float rx, float ry, float rz, float dx, float dy, float dz);
    ~Neck() {}
    void display() override;
    void animate(const unsigned stage, float factor) override;
};

#endif  // NECK_HPP