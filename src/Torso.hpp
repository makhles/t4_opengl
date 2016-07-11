/*
 * @author: Makhles Reuter Lange
 * Date..: 2016-07-06 - initial implementation 
 */

#ifndef TORSO_HPP
#define TORSO_HPP

#include "BodyPart.hpp"

class Torso : public BodyPart {

private:
    const float TORSO_HEIGHT = 5.0f;
    const float TORSO_RADIUS_BASE = 2.5f;
    const float TORSO_RADIUS_TOP = 2.0f;
    const GLfloat m_color1[3] = {0.165f, 0.435f, 0.216f};  // 42, 111, 55 (green)
    const GLfloat m_color2[3] = {0.132f, 0.348f, 0.173f};  // 42, 111, 55 (darker green)

public:
    Torso(float rx, float ry, float rz, float dx, float dy, float dz);
    ~Torso() {}
    void display() override;
    void animate(const unsigned stage, float factor) override;
};

#endif  // TORSO_HPP