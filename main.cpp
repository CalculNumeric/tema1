#include <iostream>

using namespace std;

double primaProblema();
bool aDouaProblema();

int main() {

    cout << "Problema 1: " ;
    cout << primaProblema() << endl;
    cout << "Problema 2: ";
    cout << aDouaProblema() << endl;

    return 0;
}

double primaProblema() {

    int m = 0;
    double u = 1.0;

    while (1 != (1 + u)) {
        u = u * 0.1;
        m ++;
    }

    return u;
}

bool aDouaProblema() {

    double u = primaProblema();

    double x = 1.0;
    double y = u / 10;
    double z = u / 10;
//  1 = neasociativa, 0 = asociativa
    return ((x + y) + z) != (x + (y + z));

}