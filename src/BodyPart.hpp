/*
 * @author: Makhles Reuter Lange
 * Date..: 2016-07-06 - initial implementation 
 */

#ifndef BODY_PART_HPP
#define BODY_PART_HPP

#include <cstddef>
#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>

class BodyPart {

protected:
    // const GLint SLICES = 32;
    // const GLint STACKS = 32;

    // const float NECK_HEIGHT = 0.6f;
    // const float NECK_RADIUS_BASE = 0.6f;
    // const float NECK_RADIUS_TOP = 0.6f;

    // const float HIP_HEIGHT = 1.0f;
    // const float HIP_RADIUS_BASE = 2.1f;
    // const float HIP_RADIUS_TOP = 2.1f;

    // const float LOWER_LEG_HEIGHT = 6.0f;
    // const float LOWER_LEG_RADIUS_BASE = 1.0f;
    // const float LOWER_LEG_RADIUS_TOP = 0.8f;

    BodyPart *m_child;
    BodyPart *m_sibling;
    float m_rx, m_ry, m_rz;  // Rotation angles
    float m_dx, m_dy, m_dz;  // Displacements
    GLuint m_displayList;

public:
    BodyPart(float rx, float ry, float rz,
            float dx, float dy, float dz) :
        m_child(nullptr), m_sibling(nullptr),
        m_rx(rx), m_ry(ry), m_rz(rz),
        m_dx(dx), m_dy(dy), m_dz(dz)
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

    void set_rotation(float rx, float ry, float rz) {
        m_rx = rx;   m_ry = ry;   m_rz = rz;
    }

    void set_displacement(float dx, float dy, float dz) {
        m_dx = dx;   m_dy = dy;   m_dz = dz;
    }

    virtual void display() = 0;
};

#endif  // BODY_PART_HPP