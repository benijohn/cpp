#include <cstring>
#include <iostream>
#include "mystring.h"

// No args constructor

MyString::MyString () 
    : str {nullptr} {
    str = new char [1];
    *str = '\0';
}

MyString::MyString (const char *s) 
    : str {nullptr} {
    if (s == nullptr) {
        str = new char [1];
        *str = '\0';
    }
    else {
        str = new char[std::strlen(s)+1];
        std::strcpy(str, s);
    }
}
// copy constructor
MyString::MyString (const MyString &source) 
    : str {nullptr} {
    str = new char[std::strlen(source.str)+1];
    std::strcpy(str, source.str);
    std::cout << "Copy constructor used" << std::endl;
}

// move constructor
MyString::MyString (MyString &&source)
    : str(source.str) {
        source.str = nullptr;
        std::cout << "Move constructor used" << std::endl;
}

MyString::~MyString () {
    if (str == nullptr) {
        std::cout << "Destructor called for MyString: nullptr" << std::endl;
    }
    else {
        std::cout << "Destructor called for MyString: " << str << std::endl;
    }
    delete [] str;
}


// Copy Assignment

MyString &MyString::operator=(const MyString &rhs) {
    std::cout << "Copy Assignment: " << std::endl;
    if (this == &rhs) {
        return *this;
    }
    delete [] str;   // in this case, str == this->str == (*this).str
    str = new char [std::strlen(rhs.str) + 1]; // now allocating new memory for the string being copied
    std::strcpy(str, rhs.str); // go ahead and copy the string
    return *this;
}

// Move Assignement
MyString &MyString::operator=(MyString &&rhs) {
    std::cout << "Move Assignment: " << std::endl;
    if (this == &rhs) {
        return *this;
    }
    delete [] str; // 
    str = rhs.str;
    rhs.str = nullptr;
    return *this;
}

// cannot have both Member functions and Global functions defined
// /// concatenate the strings
// MyString MyString::operator+(const MyString &rhs) const {
//     char *buff = new char [std::strlen(str) + std::strlen(rhs.str) + 1];
//     std::strcpy(buff, str);
//     std::strcat(buff, rhs.str);
//     MyString temp {buff};
//     delete [] buff;
//     return temp;
// }

// // lowercase the string
// MyString MyString::operator-() const {
//     char *buff = new char [std::strlen(str) +1];
//     std::strcpy(buff, str);
//     for (size_t i {0}; i < std::strlen(buff); i++) {
//         buff[i] = std::tolower(buff[i]);
//     }
//     MyString temp {buff};
//     delete [] buff;                 /// de allocate the buffer to prevent memory leaks
//     return temp;
// };

// // check equality of strings
// bool MyString::operator==(const MyString &rhs) const {
//     return (std::strcmp(str, rhs.str) == 0);
// }

void MyString::display () const {
    std::cout << str << " : " << get_length() << std::endl;
}

int MyString::get_length () const {
    return std::strlen(str);
}

const char *MyString::get_str() const {
    return str;
}


// Equality
bool operator==(const MyString &lhs, const MyString &rhs) {
    return (std::strcmp(lhs.str, rhs.str) == 0);
}

// LowerCase
MyString operator-(const MyString &obj) {
    char *buff = new char [std::strlen(obj.str) + 1];
    std::strcpy(buff, obj.str);
    for (size_t i {0}; i < std::strlen(obj.str); i++) {
        buff[i] = std::tolower(buff[i]);
    }
    MyString temp {buff};
    delete [] buff;
    return temp;
}

// Concatenate
MyString operator+(const MyString &lhs, const MyString &rhs) {
    char *buff = new char [std::strlen(lhs.str) + std::strlen(rhs.str) + 1];
    std::strcpy(buff, lhs.str);
    std::strcat(buff, rhs.str);
    MyString temp {buff};
    delete [] buff;
    return temp;
}