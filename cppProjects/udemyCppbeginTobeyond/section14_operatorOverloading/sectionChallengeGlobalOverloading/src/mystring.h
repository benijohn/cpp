#pragma once

class Mystring {
    friend std::ostream &operator<<(std::ostream &out, const Mystring &rhs);
    friend std::istream &operator>>(std::istream &in, Mystring &rhs);

    // global overloading
    friend Mystring operator+(const Mystring &lhs, const Mystring &rhs);
    friend Mystring operator-(const Mystring &lhs);
    friend bool operator==(const Mystring &lhs, const Mystring &rhs);
    friend bool operator!=(const Mystring &lhs, const Mystring &rhs);
    friend bool operator>(const Mystring &lhs, const Mystring &rhs);
    friend bool operator<(const Mystring &lhs, const Mystring &rhs);
    friend bool operator>=(const Mystring &lhs, const Mystring &rhs);
    friend bool operator<=(const Mystring &lhs, const Mystring &rhs);
    friend Mystring operator*(const Mystring &lhs, int num);
    friend Mystring operator+=(const Mystring &lhs, const Mystring &rhs);
    friend Mystring operator*=(Mystring &lhs, int num);

    private:
    char *str;


    public:
    // Constructors
    Mystring ();
    Mystring (const char *init_str);
    Mystring (const Mystring &source);
    Mystring (Mystring &&source);
    ~Mystring ();

    // methods
    const char *get_str ();
    void display ();
    int get_length ();

    // overloaded operators
    Mystring &operator=(const Mystring &source);
    Mystring &operator=(Mystring &&source);
};