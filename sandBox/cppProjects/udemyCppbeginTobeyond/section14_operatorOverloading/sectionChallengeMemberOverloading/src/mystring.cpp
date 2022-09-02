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
Mystring Mystring::operator+(const Mystring &rhs) const {
    char *buff = new char [std::strlen(str) + std::strlen(rhs.str) + 1];
    std::strcpy(buff, str);
    std::strcat(buff, rhs.str);
    Mystring temp {buff};
    delete [] buff;
    return temp;
};

// to_lower
Mystring Mystring::operator-() const {
    char *buff = new char [std::strlen(str) + 1];
    std::strcpy(buff, str);
    for (size_t i {0}; i < std::strlen(str); i++) {
        buff[i] = std::tolower(buff[i]);
    }
    Mystring temp {buff};
    delete [] buff;
    return temp;
};

// equality operator
bool Mystring::operator==(const Mystring &rhs) const {
    return (std::strcmp(str, rhs.str) == 0);
};

// inequality operator... oposite of equality
bool Mystring::operator!=(const Mystring &rhs) const {
    return (std::strcmp(str, rhs.str));
};

// greater than operator .... lexically compare characters
bool Mystring::operator>(const Mystring &rhs) const {
    size_t size_lhs {std::strlen(str)};
    size_t size_rhs {std::strlen(rhs.str)};
    size_t size {};
    size = (size_lhs < size_rhs? size_lhs: size_rhs); 
    for (size_t i {0}; i < size; i++) {
        if (str[i] > rhs.str[i]) {
            return true;
        }
        else if (str[i] < rhs.str[i]) {
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

bool Mystring::operator>=(const Mystring &rhs) const {
    return ((*this>rhs) || (*this==rhs));
}

bool Mystring::operator<=(const Mystring &rhs) const {
    return ((*this<rhs) || (*this==rhs));
}
   

// less than operator ... lexically compare characters
bool Mystring::operator<(const Mystring &rhs) const {
    size_t size_lhs {std::strlen(str)};
    size_t size_rhs {std::strlen(rhs.str)};
    size_t size {};
    size = (size_lhs < size_rhs? size_lhs: size_rhs); 
    for (size_t i {0}; i < size; i++) {
        if (str[i] < rhs.str[i]) {
            return true;
        }
        else if (str[i] > rhs.str[i]) {
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
Mystring Mystring::operator*(int num) const {
    char *buff = new char [std::strlen(str)*num + 1];
    std::strcpy(buff, str);
    for (size_t i {0}; i < (num-1); i++) {
        std::strcat(buff, str);
    }
    Mystring temp {buff};
    delete [] buff;
    return temp;
};

// plus equal reassign to original string
Mystring Mystring::operator+=(const Mystring &rhs) {
    std::strcat(str, rhs.str);
    return *this;
};

// times equal repeat string num times and assign back to self
Mystring Mystring::operator*=(int num) {
    *this = *this*num;
    return *this;
}

Mystring &Mystring::operator++() {
    for (size_t i {0}; i < std::strlen(str); i++) {
        str[i] = std::toupper(str[i]);
    }
    return *this;
}

Mystring Mystring::operator++(int) {
    Mystring temp {*this};
    operator++();
    return temp;
}
