#include <iostream>
#include <cmath>
#include <string>
#include <iomanip>

using namespace std;

double calc_cost (double base_cost, double tax_rate = 0.06, double shipping = 3.50);

void greeting (string name, string prefix = "Mr", string suffix = "");

double calc_cost (double base_cost, double tax_rate, double shipping) {
    return base_cost += base_cost*tax_rate + shipping;
}

void greeting(string name, string prefix, string suffix) {
    cout << "Hello " << prefix + " " + name + " " + suffix << endl; 
}

int main () {
    double cost {};

    cost = calc_cost(100.0, 0.08, 4.25);

    cout << fixed << setprecision(2);
    cout << "Cost is: " << cost << endl;

    cost = calc_cost(100.0, 0.08);
    cout << "Cost is: " << cost << endl;

    cost = calc_cost(100, 3.5);

    greeting("M.Jones", "Dr.", "M.D.");
    greeting("Frank Miller", "Dr.");
    greeting("William Smith");
    



    return 0;
}

