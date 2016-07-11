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

#define LEFT_SIDE 0
#define RIGHT_SIDE 1

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
    m_leftUpperArm = create_upper_arm(LEFT_SIDE);
    m_rightUpperArm = create_upper_arm(RIGHT_SIDE);
    m_leftLowerArm = create_lower_arm(LEFT_SIDE);
    m_rightLowerArm = create_lower_arm(RIGHT_SIDE);
    m_leftUpperLeg = create_upper_leg(LEFT_SIDE);
    m_rightUpperLeg = create_upper_leg(RIGHT_SIDE);
    m_leftLowerLeg = create_lower_leg(LEFT_SIDE);
    m_rightLowerLeg = create_lower_leg(RIGHT_SIDE);
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

BodyPart* Puppet::create_upper_leg(unsigned side)
{
    BodyPart *leg;
    std::vector<float> angles;

    if (side == LEFT_SIDE) {
        leg = new UpperLeg(-30.0f, 0.0f, -5.0f, -1.1f, -1.0f, 0.0f);
        angles.push_back(-30.0f);
        angles.push_back(-20.0f);
        angles.push_back(-10.0f);
        angles.push_back(+0.0f);
        angles.push_back(+10.0f);
        angles.push_back(+20.0f);
        angles.push_back(+30.0f);
        angles.push_back(+20.0f);
        angles.push_back(+10.0f);
        angles.push_back(+0.0f);
        angles.push_back(-10.0f);
        angles.push_back(-20.0f);
    }
    // Right upper leg moves forward first
    else if (side == RIGHT_SIDE) {
        leg = new UpperLeg(30.0f, 0.0f, 5.0f, 1.1f, -1.0f, 0.0f);
        angles.push_back(+30.0f);
        angles.push_back(+20.0f);
        angles.push_back(+10.0f);
        angles.push_back(+0.0f);
        angles.push_back(-10.0f);
        angles.push_back(-20.0f);
        angles.push_back(-30.0f);
        angles.push_back(-20.0f);
        angles.push_back(-10.0f);
        angles.push_back(+0.0f);
        angles.push_back(+10.0f);
        angles.push_back(+20.0f);
    }
    else {
        std::cout << "Could not create upper leg!" << std::endl;
        delete_puppet(m_root);
        exit(1);
    }
    leg->set_walk_angles(angles);

    return leg;
}

BodyPart* Puppet::create_lower_leg(unsigned side)
{
    BodyPart *leg;
    std::vector<float> angles;

    if (side == LEFT_SIDE) {
        leg = new LowerLeg(0.0f, 0.0f, 0.0f, 0.0f, -4.0f, 0.0f);
        angles.push_back(+0.0f);
        angles.push_back(+6.0f);
        angles.push_back(+4.0f);
        angles.push_back(+0.0f);
        angles.push_back(+0.0f);
        angles.push_back(+0.0f);
        angles.push_back(+0.0f);
        angles.push_back(+10.0f);
        angles.push_back(+50.0f);
        angles.push_back(+65.0f);
        angles.push_back(+30.0f);
        angles.push_back(+5.0f);
    }
    else if (side == RIGHT_SIDE) {
        leg = new LowerLeg(0.0f, 0.0f, 0.0f, 0.0f, -4.0f, 0.0f);
        angles.push_back(+0.0f);
        angles.push_back(+10.0f);
        angles.push_back(+50.0f);
        angles.push_back(+65.0f);
        angles.push_back(+30.0f);
        angles.push_back(+5.0f);
        angles.push_back(+0.0f);
        angles.push_back(+6.0f);
        angles.push_back(+4.0f);
        angles.push_back(+0.0f);
        angles.push_back(+0.0f);
        angles.push_back(+0.0f);
    }
    else {
        std::cout << "Could not create upper leg!" << std::endl;
        delete_puppet(m_root);
        exit(1);
    }
    leg->set_walk_angles(angles);

    return leg;
}

BodyPart* Puppet::create_upper_arm(unsigned side)
{
    BodyPart *arm;
    std::vector<float> angles;

    if (side == LEFT_SIDE) {
        arm = new UpperArm(-30.0f, 0.0f, -5.0f, -2.7f, 0.0f, 0.0f);
        angles.push_back(+30.0f);
        angles.push_back(+20.0f);
        angles.push_back(+10.0f);
        angles.push_back(+0.0f);
        angles.push_back(-10.0f);
        angles.push_back(-20.0f);
        angles.push_back(-30.0f);
        angles.push_back(-20.0f);
        angles.push_back(-10.0f);
        angles.push_back(+0.0f);
        angles.push_back(+10.0f);
        angles.push_back(+20.0f);
    }
    else if (side == RIGHT_SIDE) {
        arm = new UpperArm(30.0f, 0.0f, 5.0f, 2.7f, 0.0f, 0.0f);
        angles.push_back(-30.0f);
        angles.push_back(-20.0f);
        angles.push_back(-10.0f);
        angles.push_back(+0.0f);
        angles.push_back(+10.0f);
        angles.push_back(+20.0f);
        angles.push_back(+30.0f);
        angles.push_back(+20.0f);
        angles.push_back(+10.0f);
        angles.push_back(+0.0f);
        angles.push_back(-10.0f);
        angles.push_back(-20.0f);
    }
    else {
        std::cout << "Could not create upper arm!" << std::endl;
        delete_puppet(m_root);
        exit(1);
    }
    arm->set_walk_angles(angles);

    return arm;
}

BodyPart* Puppet::create_lower_arm(unsigned side)
{
    BodyPart *arm;
    std::vector<float> angles;

    if (side == LEFT_SIDE) {
        arm = new LowerArm(0.0f, 0.0f, 5.0f, 0.0f, -3.0f, 0.0f);
        angles.push_back(+0.0f);
        angles.push_back(-5.0f);
        angles.push_back(-10.0f);
        angles.push_back(-15.0f);
        angles.push_back(-20.0f);
        angles.push_back(-25.0f);
        angles.push_back(-30.0f);
        angles.push_back(-25.0f);
        angles.push_back(-20.0f);
        angles.push_back(-15.0f);
        angles.push_back(-10.0f);
        angles.push_back(-5.0f);
    }
    else if (side == RIGHT_SIDE) {
        arm = new LowerArm(30.0f, 0.0f, -5.0f, 0.0f, -3.0f, 0.0f);
        angles.push_back(-30.0f);
        angles.push_back(-25.0f);
        angles.push_back(-20.0f);
        angles.push_back(-15.0f);
        angles.push_back(-10.0f);
        angles.push_back(-5.0f);
        angles.push_back(+0.0f);
        angles.push_back(-5.0f);
        angles.push_back(-10.0f);
        angles.push_back(-15.0f);
        angles.push_back(-20.0f);
        angles.push_back(-25.0f);
    }
    else {
        std::cout << "Could not create upper arm!" << std::endl;
        delete_puppet(m_root);
        exit(1);
    }
    arm->set_walk_angles(angles);

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

    // Save parent's state
    glPushMatrix();

    // Draw body part
    root->display();

    // Visit child
    if (root->child() != nullptr)
    {
        //std::cout << "Visiting child: ";
        traverse(root->child());
    }

    // Pop the parent's state
    glPopMatrix();

    // Visit sibling
    if (root->sibling() != nullptr)
    {
        //std::cout << "Visiting sibling: ";
        traverse(root->sibling());
    }
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