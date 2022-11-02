#include "i_printable.h"

std::ostream &operator<< (std::ostream &os, const iPrintable &obj) {
    obj.print(os);
    return os;
}