#include <iostream>
#include <cmath>
#include "EllipticCurve.hpp"

using namespace std;


int main() {
    int M = 17, a = 2, b = 2;
    EllipticCurve ec(a, b, M);
    cout << "Elliptic Curve Equation: " << ec << endl;
    Point P(5,14);
    Point Q(5,1);
    Point R = ec.add(P, Q);
    cout << "Point =  " << R << endl;

    for (int i=1; i < 20; i++) {
        R = ec.scalarMultiply(i, Q);
        cout << i << "P = " << R << endl;
    }
    return 0;
}