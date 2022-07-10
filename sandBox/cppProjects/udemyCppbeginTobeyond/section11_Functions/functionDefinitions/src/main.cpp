#include <iostream>
#include <cmath>

using namespace std;

double calc_area_of_circle(double radius) {
    return M_PI*pow(radius,2);
}

double calc_volume_of_cylinder(double radius, double height) {
    return M_PI*pow(radius,2)*height;
}

void area_of_circle() {
    double radius {};

    cout << "\nPlease enter the radius of the circle: " << endl;
    cin >> radius;

    cout << "The area of a circle with radius " << radius << " is " << calc_area_of_circle(radius) << endl;
}

void volume_of_cylinder() {
    double radius {};
    double height {};

    cout << "Please enter the radius of the cylinder: ";
    cin >> radius;

    cout << "Please enter the height of the cylinder: ";
    cin >> height;

    cout << "The volume of the cylinder is: " << calc_volume_of_cylinder(radius, height) << " units cubed." << endl;
}

int main () {

    area_of_circle();
    volume_of_cylinder();

    return 0;
}