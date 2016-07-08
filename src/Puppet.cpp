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


Puppet::Puppet()
{
    std::cout << "Creating torso..." << std::endl;

    m_hip = new Hip(0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f);
    m_torso = new Torso(0.0f, 0.0f, 0.0f, 0.0f, 5.0f, 0.0f);
    m_neck = new Neck(0.0f, 0.0f, 0.0f, 0.0f, 0.6f, 0.0f);
    m_head = new Head(0.0f, 0.0f, 0.0f, 0.0f, 1.0f, 0.0f);
    m_leftUpperArm = new UpperArm(0.0f, 0.0f, -5.0f, -2.7f, 0.0f, 0.0f);
    m_rightUpperArm = new UpperArm(0.0f, 0.0f, 5.0f, 2.7f, 0.0f, 0.0f);
    m_leftLowerArm = new LowerArm(0.0f, 0.0f, 5.0f, 0.0f, -3.0f, 0.0f);
    m_rightLowerArm = new LowerArm(0.0f, 0.0f, -5.0f, 0.0f, -3.0f, 0.0f);
    m_leftUpperLeg = new UpperLeg(0.0f, 0.0f, -5.0f, -1.1f, -1.0f, 0.0f);
    m_rightUpperLeg = new UpperLeg(0.0f, 0.0f, 5.0f, 1.1f, -1.0f, 0.0f);

    // Family tree
    m_hip->set_child(m_torso);
    m_torso->set_child(m_neck);
    m_neck->set_child(m_head);
    m_neck->set_sibling(m_leftUpperArm);
    m_leftUpperArm->set_child(m_leftLowerArm);
    m_leftUpperArm->set_sibling(m_rightUpperArm);
    m_rightUpperArm->set_child(m_rightLowerArm);
    m_torso->set_sibling(m_leftUpperLeg);
    m_leftUpperLeg->set_sibling(m_rightUpperLeg);

    m_root = m_hip;
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
    std::cout << "Displaying body part..." << std::endl;
    root->display();

    // Visit child
    if (root->child() != nullptr)
    {
        std::cout << "Visiting child: " << root->child() << std::endl;
        traverse(root->child());
    }

    // Pop the parent's state
    glPopMatrix();

    // Visit sibling
    if (root->sibling() != nullptr)
    {
        std::cout << "Visiting sibling: " << root->sibling() << std::endl;
        traverse(root->sibling());
    }
}

/**
 * @brief      Callback function to draw the puppet.
 */
void Puppet::display()
{
    Puppet::traverse(m_root);
}