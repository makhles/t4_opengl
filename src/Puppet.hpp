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
    BodyPart *m_root;

private:
    void traverse(BodyPart *root);
    void delete_puppet(BodyPart *root);

public:
    Puppet();
    ~Puppet();
    void display();

};

#endif  // PUPPET_HPP