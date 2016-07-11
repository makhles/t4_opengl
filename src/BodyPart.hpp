/*
 * @author: Makhles Reuter Lange
 * Date..: 2016-07-06 - initial implementation 
 */

#ifndef BODY_PART_HPP
#define BODY_PART_HPP

#define _USE_MATH_DEFINES  // For value of PI
#include <math.h>  // For value of PI
#include <cstddef>
#include <iostream>
#include <vector>
#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>

class BodyPart {

protected:
    const GLint SLICES = 32;
    const GLint STACKS = 32;
    const float m_period = 2.0f;
    const float m_angleMax = 15.0;  // Degrees

    BodyPart *m_child;
    BodyPart *m_sibling;

    float m_rx, m_ry, m_rz;  // Rotation angles
    float m_dx, m_dy, m_dz;  // Displacements

    float m_time;
    float m_angle;

    std::vector<float> m_walk_angles;

    GLuint m_displayList;

public:
    BodyPart(float rx, float ry, float rz, float dx, float dy, float dz) :
        m_child(nullptr), m_sibling(nullptr),
        m_rx(rx), m_ry(ry), m_rz(rz),
        m_dx(dx), m_dy(dy), m_dz(dz),
        m_time(0.0f), m_angle(0.0f)
    {
    }

    virtual ~BodyPart() {
    }

    BodyPart * child() const {
        return m_child;
    }
    
    BodyPart * sibling() const {
        return m_sibling;
    }

    void set_child(BodyPart *a_child) {
        m_child = a_child;
    }

    void set_sibling(BodyPart *a_sibling) {
        m_sibling = a_sibling;
    }

    void set_walk_angles(std::vector<float> angles) {
        m_walk_angles = angles;
    }

    virtual void display() = 0;

    virtual void animate(const unsigned stage, float factor)
    {
    }
};

#endif  // BODY_PART_HPP