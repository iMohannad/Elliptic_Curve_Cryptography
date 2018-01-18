#include <iostream>
#include <cmath>
#include "EllipticCurve.hpp"

using namespace std;


int main() {
    EllipticCurve ec(2, 2, 17);
    Point P(5,16);
    Point Q(5,1);
    Point R = ec.add(P, Q);
    cout << "Point =  " << R << endl;
    return 0;
}