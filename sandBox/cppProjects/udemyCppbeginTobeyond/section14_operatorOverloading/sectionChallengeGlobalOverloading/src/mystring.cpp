#include <iostream>
#include "mystring.h"

// No args constructor
Mystring::Mystring ()
    : str {nullptr} {
        str = new char [1];
        *str = '\0';
}

Mystring::Mystring (const char *init_str)
    : str {nullptr} {
        if (init_str == nullptr) {
            str = new char [1];
            *str = '\0';
        }
        else {
            str = new char [std::strlen(init_str) + 1];
            std::strcpy(str, init_str);
        }
};

// copy constructor
Mystring::Mystring (const Mystring &source)
    : str {nullptr} {
        str = new char [std::strlen(source.str) + 1];
        std::strcpy(str, source.str);
        std::cout << "copy constructor" << std::endl;
};

// move constructor
Mystring::Mystring (Mystring &&source)
    : str {source.str} {
        source.str = nullptr;
        std::cout << "move constructor" << std::endl;
};

// insertion operator
std::ostream &operator<<(std::ostream &out, const Mystring &rhs) {
    out << rhs.str;
    return out;
}

// extraction operator
std::istream &operator>>(std::istream &in, Mystring &rhs) {
    char *buff = new char [std::strlen(rhs.str) + 1];
    in >> buff;
    rhs = Mystring {buff};
    delete [] buff;
    return in;
}

// copy assignment
Mystring &Mystring::operator=(const Mystring &source) {
    if (this == &source) {
        return *this;
    }
    delete [] str;
    str = new char [std::strlen(source.str) + 1];
    std::strcpy(str, source.str);
    return *this;
}

// move assignment
Mystring &Mystring::operator=(Mystring &&source) {
    if (this == &source) {
        return *this;
    }
    delete [] str;
    str = source.str;
    source.str = nullptr;
    return *this;
}

Mystring::~Mystring () {
    if (str == nullptr) {
        std::cout << "destructor called for nullptr" << std::endl;
    }
    else {
        std::cout << "destructor called for " << str << std::endl;
    }
    delete [] str;
};

// methods
const char *Mystring::get_str () {
    return str;
};

void Mystring::display () {
    std::cout << str << std::endl;
};

int Mystring::get_length () {
    return (std::strlen(str));
};

// overloaded operators

// concatenate
Mystring operator+(const Mystring &lhs, const Mystring &rhs) {
    char *buff = new char [std::strlen(lhs.str) + std::strlen(rhs.str) + 1];
    std::strcpy(buff, lhs.str);
    std::strcat(buff, rhs.str);
    Mystring temp {buff};
    delete [] buff;
    return temp;
};

// to_lower
Mystring operator-(const Mystring &lhs) {
    char *buff = new char [std::strlen(lhs.str) + 1];
    std::strcpy(buff, lhs.str);
    for (size_t i {0}; i < std::strlen(lhs.str); i++) {
        buff[i] = std::tolower(buff[i]);
    }
    Mystring temp {buff};
    delete [] buff;
    return temp;
};

// equality operator
bool operator==(const Mystring &lhs, const Mystring &rhs) {
    return (std::strcmp(lhs.str, rhs.str) == 0);
};

// inequality operator... oposite of equality
bool operator!=(const Mystring &lhs, const Mystring &rhs) {
    return (std::strcmp(lhs.str, rhs.str));
};

// greater than operator .... lexically compare characters
bool operator>(const Mystring &lhs, const Mystring &rhs) {
    size_t size_lhs {std::strlen(lhs.str)};
    size_t size_rhs {std::strlen(rhs.str)};
    size_t size {};
    size = (size_lhs < size_rhs? size_lhs: size_rhs); 
    for (size_t i {0}; i < size; i++) {
        if (lhs.str[i] > rhs.str[i]) {
            return true;
        }
        else if (lhs.str[i] < rhs.str[i]) {
            return false;
        }   
    }
    if (size_lhs > size_rhs) {
        return true;
    }
    else {
        return false;
    }    
};

bool operator>=(const Mystring &lhs, const Mystring &rhs) {
    return ((lhs>rhs) || (lhs==rhs));
}

bool operator<=(const Mystring &lhs, const Mystring &rhs) {
    return ((lhs<rhs) || (lhs==rhs));
}
   

// less than operator ... lexically compare characters
bool operator<(const Mystring &lhs, const Mystring &rhs) {
    size_t size_lhs {std::strlen(lhs.str)};
    size_t size_rhs {std::strlen(rhs.str)};
    size_t size {};
    size = (size_lhs < size_rhs? size_lhs: size_rhs); 
    for (size_t i {0}; i < size; i++) {
        if (lhs.str[i] < rhs.str[i]) {
            return true;
        }
        else if (lhs.str[i] > rhs.str[i]) {
            return false;
        }   
    }
    if (size_lhs >= size_rhs) {
        return false;
    }
    else {
        return true;
    } 
};

// multiply operator ... returns Mystring object that is copied num times. 
Mystring operator*(const Mystring &lhs, int num) {
    char *buff = new char [std::strlen(lhs.str)*num + 1];
    std::strcpy(buff, lhs.str);
    for (size_t i {0}; i < (num-1); i++) {
        std::strcat(buff, lhs.str);
    }
    Mystring temp {buff};
    delete [] buff;
    return temp;
};

// plus equal reassign to original string
Mystring operator+=(const Mystring &lhs, const Mystring &rhs) {
    std::strcat(lhs.str, rhs.str);
    return lhs;
};

// times equal repeat string num times and assign back to self
Mystring operator*=(Mystring &lhs, int num) {
    lhs = lhs*num;
    return lhs;
}
