#include "point.hpp"

class EllipticCurve
{
public:
    EllipticCurve();
    EllipticCurve(int a, int b, int M);
    // Find all points in the elliptic curve defined
    void calculatePoints();
    // Scalar multiplication returns a point X = kP
    Point scalarMultiply(int k, Point P);
    // Returns A + B
    Point add(Point A, Point B);
    ~EllipticCurve();

private:
    int a, b; // points for elliptic curve equation
    int M; // module
    // Calculate the slope of two points
    int * findSlope(int x1, int y1, int x2, int y2);
};