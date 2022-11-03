#ifndef _MYSTRING_H_
#define _MYSTRING_H_

class MyString {
    private:
    char *str;

    public:
    MyString();                             // no args constructor
    MyString(const char *s);                // constructor
    MyString(const MyString &source);       // copy constructor
    MyString(MyString &&source);            // move constructor
    ~MyString();                            // destructor

    // operator overloading
    MyString &operator=(const MyString &rhs);  // overloading the = operator ... copy assignment .... rhs = right hand side
    MyString &operator=(MyString &&rhs);       // overloading the = operator .... move assignment


    // methods 
    void display() const;               // display self
    int get_length() const;             // return length of string (- null terminator)
    const char *get_str() const;        // returns the string
};



#endif 