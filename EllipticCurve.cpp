#include <cstdlib>
#include <iostream>
#include <cmath>

#include "EllipticCurve.hpp"
#include "NumberTheory.cpp"

using namespace std;
using namespace Cryptography;

EllipticCurve::EllipticCurve()
{
    EllipticCurve(1, 1, 17);
}

EllipticCurve::EllipticCurve(int a, int b, int M) : a(a), b(b), M(M) {
    // this->a = a;
    // this->b = b;
    // this->M = M;
}

EllipticCurve::~EllipticCurve()
{
}

// Scalar multiplication returns a point X = kP
Point EllipticCurve::scalarMultiply(int k, Point P){
    Point Q; // Initalize a point to (0,0)
    Point R = P;
    // cout << "Q =  " << Q << endl;
    // cout << "R =  " << R << endl;
    while (k != 0) {
        if (k & 1) {
            // cout << "R + Q = " << R << " + " << Q  << " = ";
            Q = add(Q, R);
            // cout << Q << endl;
        }
        R = add(R, R);
        k = k >> 1; // shift k one bit to the right
    }
    return Q;

}

// Returns A + B
Point EllipticCurve::add(Point A, Point B){
    // get all x and y values of points A and B
    int x1 = A.getX();
    int y1 = A.getY();
    int x2 = B.getX();
    int y2 = B.getY();

    // Check if point A or point B = 0;
    if (x1 == 0 && y1 == 0) {
        return B;
    }
    if (x2 == 0 && y2 == 0) {
        return A;
    }

    // get the slope of two points, it returns a point to the slope.
    int *slopeValue = findSlope(x1, y1, x2, y2);
    // Check if the pointer is null
    if (slopeValue == NULL) {
        Point P(-M, -M);
        return P;
    }
    int slope = *slopeValue;

    int x3 = modulo(slope*slope - x1 - x2, M);
    int y3 = modulo(slope*(x1 - x3) - y1, M);

    Point P(x3, y3);

    return P;

}



int * EllipticCurve::findSlope(int x1, int y1, int x2, int y2) {
    int *slope; // initialize a pointer to slope
    int numerator, denominator;
    // if the two points are equal, slope is for point doubling
    // else slope is for point addition operation.
    if ((x1 == x2) && (y1 == y2)) {
        numerator = modulo((3*x1*x1) + this->a, M);
        denominator = modulo(2*y1, M);
    } else {
        numerator = modulo(y2-y1, M);
        denominator = modulo(x2-x1, M);
    }
    if (denominator == 0) {
        return NULL;
    }
    int inv = inverseMod(denominator, this->M);
    *slope = inv*numerator % this->M;
    return slope;
}

// ostream handler: print this elliptic curve equation
std::ostream& operator <<(std::ostream& os, const EllipticCurve& ec)
{
    return (os << "y^2 = x^3 + " << ec.a << "x + " << ec.b <<
                " Mod " << ec.M);
}