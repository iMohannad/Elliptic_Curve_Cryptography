#include <iostream>
#include <cmath>
#include "EllipticCurve.hpp"
#include "NAF.hpp"

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

    NAF naf;
    int *x = naf.convertNAF(7);
    cout << "NAF representation of 7 is " << naf << endl;
    int *array;
    naf.getNAF(array);
    cout << "Size of NAF " << naf.getSize() << endl;
    for (int i=0; i < 4; i++) {
        cout << array[i] << " ";
    }
    cout << endl;
    delete array;
    delete x;
    return 0;
}