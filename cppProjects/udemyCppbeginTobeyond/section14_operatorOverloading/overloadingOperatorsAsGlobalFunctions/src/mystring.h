#ifndef _MYSTRING_H_
#define _MYSTRING_H_

class MyString {
    friend bool operator==(const MyString &lhs, const MyString &rhs);
    friend MyString operator-(const MyString &obj); // obj takes the place of " this " in the global setting since we don't have a " this " in the global sense
    friend MyString operator+(const MyString &lhs, const MyString &rhs);

private:
    char *str;

public:
    MyString();                             // no args constructor
    MyString(const char *s);                // constructor
    MyString(const MyString &source);       // copy constructor
    MyString(MyString &&source);            // move constructor
    ~MyString();                            // destructor

    MyString &operator=(const MyString &rhs);  // overloading the = operator ... copy assignment .... rhs = right hand side
    MyString &operator=(MyString &&rhs);       // overloading the = operator .... move assignment

    // MyString operator+(const MyString &rhs) const;  // concatenate the strings
    // MyString operator-() const;                 // lower case the string
    // bool operator==(const MyString &rhs) const;


    // methods 
    void display() const;               // display self
    int get_length() const;             // return length of string (- null terminator)
    const char *get_str() const;        // returns the string
};



#endif 