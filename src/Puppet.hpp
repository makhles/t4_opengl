/*
 * @author: Makhles Reuter Lange
 * Date..: 2016-07-06 - initial implementation 
 */

#ifndef PUPPET_HPP
#define PUPPET_HPP

#include "Definitions.hpp"

// Forward declarations
class BodyPart;


class Puppet {

private:
    BodyPart * m_root;
    BodyPart * m_hip;
    BodyPart * m_torso;
    BodyPart * m_neck;
    BodyPart * m_head;
    BodyPart * m_leftUpperArm;
    BodyPart * m_rightUpperArm;
    BodyPart * m_leftLowerArm;
    BodyPart * m_rightLowerArm;
    BodyPart * m_leftUpperLeg;
    BodyPart * m_rightUpperLeg;
    BodyPart * m_leftLowerLeg;
    BodyPart * m_rightLowerLeg;
    BodyPart * m_leftFoot;
    BodyPart * m_rightFoot;

private:
    void traverse(BodyPart *root);
    void delete_puppet(BodyPart *root);

    BodyPart* create_upper_leg(BodySide side);
    BodyPart* create_lower_leg(BodySide side);
    BodyPart* create_upper_arm(BodySide side);
    BodyPart* create_lower_arm(BodySide side);

public:
    Puppet();
    ~Puppet();
    void display();
    void animate(const unsigned stage, float factor);
    void animate(BodyPart *root, const unsigned stage, float factor);
    void change_stance(Stance stance);
    void change_stance(BodyPart *root, Stance stance);
};

#endif  // PUPPET_HPP