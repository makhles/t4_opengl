/*
 * @author: Makhles Reuter Lange
 * Date..: 2016-07-06 - initial implementation 
 */

#ifndef PUPPET_HPP
#define PUPPET_HPP

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

private:
    void traverse(BodyPart *root);
    void delete_puppet(BodyPart *root);

public:
    Puppet();
    ~Puppet();
    void display();

};

#endif  // PUPPET_HPP