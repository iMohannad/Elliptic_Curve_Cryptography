#include <cstdlib>
#include <iostream>
#include <cmath>

#include "ec.hpp"
#include "point.hpp"

using namespace std;

ec::ec()
{
    ec(1, 1, 17);
}

ec::ec(int a, int b, int M){
    this->a = a;
    this->b = b;
    this->M = M;
}

ec::~ec()
{
}

// Scalar multiplication returns a point X = kP
Point scalarMultiply(int k, Point P);

// Returns A + B
Point add(Point A, Point B){
    Point P;
    // get all x and y values of points A and B
    int x1 = A.getX();
    int y1 = A.getY();
    int x2 = B.getX();
    int y2 = B.getY();
    // get the slope of two points
    int slope = findSlope(x1, y1, x2, y2);

    int x3 = slope^2 - x1 - x2;
    int y3 = slope*(x1 - x3) - y1;

}



int findSlope(int x1, int y1, int x2, int y2) {
    int slope, ydiff, xdiff;
    // if the two points are equal, slope is for point doubling
    // else slope is for point addition operation.
    if ((x1 == x2) && (y1 == y2)) {
        slope = ((3*x1*x1) + a)/(2*y1) % M;
    } else {
        ydiff = y2 - y1;
        xdiff = x2 - x1;
        slope = (ydiff / xdiff) % M;
    }
}