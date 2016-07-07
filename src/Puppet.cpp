/*
 * @author: Makhles Reuter Lange
 * Date..: 2016-07-06 - initial implementation 
 */

#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>
#include <iostream>
#include "Puppet.hpp"
#include "BodyPart.hpp"
#include "Torso.hpp"
#include "Head.hpp"
#include "UpperArm.hpp"
#include "LowerArm.hpp"


Puppet::Puppet()
{
    std::cout << "Creating torso..." << std::endl;

    BodyPart *head, *leftUpperArm, *rightUpperArm;
    BodyPart *leftLowerArm, *rightLowerArm;

    m_root = new Torso(0.0f, 0.0f, 0.0f, 0.0f, 5.0f, 0.0f);
    head = new Head(0.0f, 0.0f, 0.0f, 0.0f, 1.3f, 0.0f);
    leftUpperArm = new UpperArm(0.0f, 0.0f, -10.0f, -2.5f, 0.0f, 0.0f);
    rightUpperArm = new UpperArm(0.0f, 0.0f, 10.0f, 2.5f, 0.0f, 0.0f);
    leftLowerArm = new LowerArm(0.0f, 0.0f, -10.0f, 0.0f, -3.0f, 0.0f);
    rightLowerArm = new LowerArm(0.0f, 0.0f, -50.0f, 0.0f, -3.0f, 0.0f);

    m_root->set_child(head);
    head->set_sibling(leftUpperArm);
    leftUpperArm->set_child(leftLowerArm);
    leftUpperArm->set_sibling(rightUpperArm);
    rightUpperArm->set_child(rightLowerArm);
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
    root->display();

    // Visit child
    if (root->child() != nullptr) traverse(root->child());

    // Pop the parent's state
    glPopMatrix();

    // Visit sibling
    if (root->sibling() != nullptr) traverse(root->sibling());
}

/**
 * @brief      Callback function to draw the puppet.
 */
void Puppet::display()
{
    Puppet::traverse(m_root);
}