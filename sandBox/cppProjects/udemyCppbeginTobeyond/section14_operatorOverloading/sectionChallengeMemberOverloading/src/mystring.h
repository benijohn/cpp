#pragma once

class Mystring {
    friend std::ostream &operator<<(std::ostream &out, const Mystring &rhs);
    friend std::istream &operator>>(std::istream &in, Mystring &rhs);

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

    Mystring operator+(const Mystring &rhs) const;
    Mystring operator-() const;
    bool operator==(const Mystring &rhs) const;
    bool operator!=(const Mystring &rhs) const;
    bool operator>(const Mystring &rhs) const;
    bool operator<(const Mystring &rhs) const;
    bool operator>=(const Mystring &rhs) const;
    bool operator<=(const Mystring &rhs) const;
    Mystring operator*(int num) const;
    Mystring operator+=(const Mystring &rhs);
    Mystring operator*=(int num);
    Mystring &operator++();
    Mystring operator++(int);
};