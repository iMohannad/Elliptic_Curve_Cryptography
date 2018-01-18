#include <cstdlib>
#include <iostream>
#include <cmath>

#include "EllipticCurve.hpp"

using namespace std;

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
// Point EllipticCurve::scalarMultiply(int k, Point P);

// Returns A + B
Point EllipticCurve::add(Point A, Point B){
    // get all x and y values of points A and B
    int x1 = A.getX();
    int y1 = A.getY();
    int x2 = B.getX();
    int y2 = B.getY();
    // get the slope of two points
    int slope = findSlope(x1, y1, x2, y2);
    // cout << "Slope > " << slope << endl;

    int x3 = (slope*slope - x1 - x2) % M;
    // cout << "x3 > " << x3 << endl;
    if (x3 < 0) {
        x3 = (x3 + M) % M;
    }

    int y3 = (slope*(x1 - x3) - y1) % M;
    // cout << "y3 > " << y3 << endl;
    if (y3 < 0) {
        y3 = (y3 + M) % M;
    }

    Point P(x3, y3);

    return P;

}



int EllipticCurve::findSlope(int x1, int y1, int x2, int y2) {
    int slope, ydiff, xdiff;
    // if the two points are equal, slope is for point doubling
    // else slope is for point addition operation.
    if ((x1 == x2) && (y1 == y2)) {
        slope = (((3*x1*x1) + this->a)/(2*y1)) % this->M;
    } else {
        ydiff = y2 - y1;
        xdiff = x2 - x1;
        slope = (ydiff / xdiff) % this->M;
    }
    return slope;
}