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


Puppet::Puppet()
{
    std::cout << "Creating torso..." << std::endl;
    m_root = new Torso();
    // TODO: Add body parts here
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