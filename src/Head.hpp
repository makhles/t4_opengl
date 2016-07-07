/*
 * @author: Makhles Reuter Lange
 * Date..: 2016-07-06 - initial implementation 
 */

#ifndef HEAD_HPP
#define HEAD_HPP

#include "BodyPart.hpp"

class Head : public BodyPart {

public:
    Head();
    ~Head() {}
    void display() override;
};

#endif  // HEAD_HPP