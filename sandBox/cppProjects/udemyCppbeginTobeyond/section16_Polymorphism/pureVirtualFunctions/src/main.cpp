#include <iostream>
#include <vector>

using namespace std;

class Shape {
    private:
    /// attributes
    public:
    virtual void draw () = 0;
    virtual void rotate () = 0;

    virtual ~Shape () {
        cout << "destructing a shape" << endl;
    };

};

class OpenShape: public Shape {
    public:
    virtual ~OpenShape () {
        cout << "destructing an open shape" << endl;
    };

};

class ClosedShape: public Shape {
    public:
    virtual ~ClosedShape () {
        cout << "destructing a closed shape" << endl;
    };

};

class Line: public OpenShape {
    public:
    virtual void draw () override {
        cout << "drawing a line" << endl;
    }

    virtual void rotate () override {
        cout << "rotating a line" << endl;
    }

    virtual ~Line () {
        cout << "destructing a line" << endl;
    };
};

class Circle: public ClosedShape {
    public:
    virtual void draw () override {
        cout << "drawing a circle" << endl;
    }

    virtual void rotate () override {
        cout << "rotating a circle" << endl;
    }

    virtual ~Circle () {
        cout << "destrucing a circle" << endl;
    };
};

class Square: public ClosedShape {
    public:
    virtual void draw () override {
        cout << "drawing a square" << endl;
    }

    virtual void rotate () override {
        cout << "rotating a square" << endl;
    }

    virtual ~Square () {
        cout << "destructing a square" << endl;
    };

};

int main () {
    //Shape s;
    // Shape *ptr = new Shape;
    Line l {};
    Circle c {};
    Square s {};

    Shape *lptr = new Line {};
    Shape *cptr = new Circle {};
    Shape *sptr = new Square {};

    // Shape *ptr;
    // ptr = l;

    lptr->draw();
    lptr->rotate();

    cptr->draw();
    cptr->rotate();

    sptr->draw();
    sptr->rotate();

    vector<Shape *> shapes;

    shapes.push_back(sptr);
    shapes.push_back(cptr);
    shapes.push_back(lptr);

    for (auto shape: shapes) {
        shape->draw();
        shape->rotate();
    }
    
    delete lptr;
    delete cptr;
    delete sptr;
}