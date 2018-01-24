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
    Point scalarMultiplyRDP(int * k, Point P, int size, int * D, int sizeD);
    // Scalar multiplication where the input is NAF representation
    Point scalarMultiplyNAF(int * k, Point P, int size);
    // Returns A + B
    Point add(Point A, Point B);
    ~EllipticCurve();
    // ostream handler: print this ellitpic curve equation
    friend std::ostream& operator <<(std::ostream& os, const EllipticCurve& ec);

private:
    bool time;
    int a, b; // points for elliptic curve equation
    int M; // module
    // Calculate the slope of two points
    int * findSlope(int x1, int y1, int x2, int y2);
};