/*
 * @author: Makhles Reuter Lange
 * Date..: 2016-07-06 - initial implementation 
 */

#ifndef BODY_PART_HPP
#define BODY_PART_HPP

#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>

class BodyPart {

protected:
    BodyPart *m_child;
    BodyPart *m_sibling;
    GLuint m_displayList;

public:
    BodyPart(BodyPart *child, BodyPart *sibling)
        : m_child(child), m_sibling(sibling) {
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

    virtual void display() = 0;
};

#endif  // BODY_PART_HPP