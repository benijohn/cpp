#pragma once
#include <iostream>


class iPrintable {
    friend std::ostream &operator<< (std::ostream &os, const iPrintable &obj);

    public:
    virtual void print (std::ostream &os) const = 0;
    virtual ~iPrintable () = default;
};
