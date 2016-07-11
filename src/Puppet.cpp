/*
 * @author: Makhles Reuter Lange
 * Date..: 2016-07-06 - initial implementation 
 */

#include <cstddef>
#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>
#include <iostream>
#include "Puppet.hpp"
#include "BodyPart.hpp"
#include "Hip.hpp"
#include "Torso.hpp"
#include "Neck.hpp"
#include "Head.hpp"
#include "UpperArm.hpp"
#include "LowerArm.hpp"
#include "UpperLeg.hpp"
#include "LowerLeg.hpp"
#include "Foot.hpp"

void print_modelview_matrix();

Puppet::Puppet()
{
    std::cout << "Creating Puppet" << std::endl;
    std::cout << "---------------" << std::endl;

    m_hip = new Hip(0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f);
    m_root = m_hip;
    m_torso = new Torso(0.0f, 0.0f, 0.0f, 0.0f, 5.0f, 0.0f);
    m_neck = new Neck(0.0f, 0.0f, 0.0f, 0.0f, 0.6f, 0.0f);
    m_head = new Head(0.0f, 0.0f, 0.0f, 0.0f, 1.0f, 0.0f);
    m_leftUpperArm = create_upper_arm(BodySide::LEFT);
    m_rightUpperArm = create_upper_arm(BodySide::RIGHT);
    m_leftLowerArm = create_lower_arm(BodySide::LEFT);
    m_rightLowerArm = create_lower_arm(BodySide::RIGHT);
    m_leftUpperLeg = create_upper_leg(BodySide::LEFT);
    m_rightUpperLeg = create_upper_leg(BodySide::RIGHT);
    m_leftLowerLeg = create_lower_leg(BodySide::LEFT);
    m_rightLowerLeg = create_lower_leg(BodySide::RIGHT);
    m_leftFoot = new Foot(0.0f, 0.0f, 0.0f, 0.0f, -6.0f, 0.0f);
    m_rightFoot = new Foot(0.0f, 0.0f, 0.0f, 0.0f, -6.0f, 0.0f);

    // Family tree
    m_hip->set_child(m_torso);
    m_torso->set_child(m_neck);
    m_neck->set_child(m_head);
    m_neck->set_sibling(m_leftUpperArm);
    m_leftUpperArm->set_child(m_leftLowerArm);
    m_leftUpperArm->set_sibling(m_rightUpperArm);
    m_rightUpperArm->set_child(m_rightLowerArm);
    m_torso->set_sibling(m_leftUpperLeg);
    m_leftUpperLeg->set_child(m_leftLowerLeg);
    m_leftLowerLeg->set_child(m_leftFoot);
    m_leftUpperLeg->set_sibling(m_rightUpperLeg);
    m_rightUpperLeg->set_child(m_rightLowerLeg);
    m_rightLowerLeg->set_child(m_rightFoot);

}

Puppet::~Puppet()
{
    std::cout << "Deleting puppet..." << std::endl;
    Puppet::delete_puppet(m_root);
}

void Puppet::delete_puppet(BodyPart *root)
{
    if (root == nullptr) return;
    if (root->child() != nullptr) traverse(root->child());
    if (root->sibling() != nullptr) traverse(root->sibling());
    delete root;
    root = nullptr;
}

BodyPart* Puppet::create_upper_leg(BodySide side)
{
    BodyPart *leg;
    if (side == BodySide::LEFT) {
        leg = new UpperLeg(-30.0f, 0.0f, -5.0f, -1.1f, -1.0f, 0.0f);
    } else if (side == BodySide::RIGHT) {
        leg = new UpperLeg(30.0f, 0.0f, 5.0f, 1.1f, -1.0f, 0.0f);
    } else {
        std::cout << "Could not create upper leg!" << std::endl;
        delete_puppet(m_root);
        exit(1);
    }
    leg->set_side(side);
    //leg->change_stance(Stance::WALKING);
    return leg;
}

BodyPart* Puppet::create_lower_leg(BodySide side)
{
    BodyPart *leg;
    if (side == BodySide::LEFT) {
        leg = new LowerLeg(0.0f, 0.0f, 0.0f, 0.0f, -4.0f, 0.0f);
    } else if (side == BodySide::RIGHT) {
        leg = new LowerLeg(0.0f, 0.0f, 0.0f, 0.0f, -4.0f, 0.0f);
    } else {
        std::cout << "Could not create lower leg!" << std::endl;
        delete_puppet(m_root);
        exit(1);
    }
    leg->set_side(side);
    //leg->change_stance(Stance::WALKING);
    return leg;
}

BodyPart* Puppet::create_upper_arm(BodySide side)
{
    BodyPart *arm;
    std::vector<float> angles;

    if (side == BodySide::LEFT) {
        arm = new UpperArm(-30.0f, 0.0f, -5.0f, -2.7f, 0.0f, 0.0f);
    } else if (side == BodySide::RIGHT) {
        arm = new UpperArm(30.0f, 0.0f, 5.0f, 2.7f, 0.0f, 0.0f);
    } else {
        std::cout << "Could not create upper arm!" << std::endl;
        delete_puppet(m_root);
        exit(1);
    }
    arm->set_side(side);
    //arm->change_stance(Stance::WALKING);
    return arm;
}

BodyPart* Puppet::create_lower_arm(BodySide side)
{
    BodyPart *arm;
    std::vector<float> angles;

    if (side == BodySide::LEFT) {
        arm = new LowerArm(0.0f, 0.0f, 5.0f, 0.0f, -3.0f, 0.0f);
    }
    else if (side == BodySide::RIGHT) {
        arm = new LowerArm(30.0f, 0.0f, -5.0f, 0.0f, -3.0f, 0.0f);
    }
    else {
        std::cout << "Could not create lower arm!" << std::endl;
        delete_puppet(m_root);
        exit(1);
    }
    arm->set_side(side);
    //arm->change_stance(Stance::WALKING);
    return arm;
}

/**
 * @brief      Tree traversal algorithm.
 *
 * @param      root  The root node.
 */
void Puppet::traverse(BodyPart *root)
{
    if (root == nullptr) return;
    glPushMatrix();  // Save parent's state
    root->display();
    if (root->child() != nullptr) traverse(root->child());
    glPopMatrix();  // Pop the parent's state
    if (root->sibling() != nullptr) traverse(root->sibling());
}

void print_modelview_matrix() {
    GLfloat m[16];
    glGetFloatv(GL_MODELVIEW_MATRIX, m);
    
    for (int i = 0; i < 16; i++)
    {
        std::cout << "   " << m[i];
        if ((i+1) % 4 == 0) std::cout << std::endl;
    }
    std::cout << " " << std::endl;
}

/**
 * @brief      Callback function to draw the puppet.
 */
void Puppet::display()
{
    Puppet::traverse(m_root);
}

void Puppet::animate(const unsigned stage, float factor)
{
    Puppet::animate(m_root, stage, factor);
}

void Puppet::animate(BodyPart *root, const unsigned stage, float factor)
{
    if (root == nullptr) return;
    root->animate(stage, factor);
    if (root->child() != nullptr) animate(root->child(), stage, factor);
    if (root->sibling() != nullptr) animate(root->sibling(), stage, factor);
}

void Puppet::change_stance(Stance stance)
{
    Puppet::change_stance(m_root, stance);
}

void Puppet::change_stance(BodyPart *root, Stance stance)
{
    if (root == nullptr) return;
    root->change_stance(stance);
    if (root->child() != nullptr) change_stance(root->child(), stance);
    if (root->sibling() != nullptr) change_stance(root->sibling(), stance);
}