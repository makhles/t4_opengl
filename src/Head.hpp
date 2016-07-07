/*
 * @author: Makhles Reuter Lange
 * Date..: 2016-07-06 - initial implementation 
 */

#ifndef HEAD_HPP
#define HEAD_HPP

#include "BodyPart.hpp"

class Head : public BodyPart {

private:
    const GLfloat m_colorBlue1[3] = {0.0f, 0.0f, 1.0f};
    const GLfloat m_colorBlue2[3] = {0.0f, 0.0f, 0.7f};
    const GLfloat m_colorBlue3[3] = {0.0f, 0.0f, 0.3f};

public:
    Head(float rx, float ry, float rz, float dx, float dy, float dz);
    ~Head() {}
    void display() override;
};

#endif  // HEAD_HPP