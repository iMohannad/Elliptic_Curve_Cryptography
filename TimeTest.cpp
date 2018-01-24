#include <iostream>
#include <cmath>
#include "EllipticCurve.hpp"
#include "NAF.hpp"

#include "randomRecordingAlg.cpp"

using namespace std;
using namespace RDP;

int main() {

    int M = 523, a = 120, b = 47;
    EllipticCurve ec(a, b, M);
    std::cout << "Elliptic Curve Equation: " << ec << endl;
    Point P(87,317);

    // ------------ RDP ------------- //
    int k = 31415;
    int D[] = {1, 3, 23, 27};
    int size = sizeof(D)/sizeof(*D);
    int * k_RDP;
    int k_RDP_size;
    RDPAlgorithm(k, D, size, k_RDP, k_RDP_size);
    Point R = ec.scalarMultiplyRDP(k_RDP, P, k_RDP_size, D, size);
    std::cout << k << "R = " << R << endl;

    // ---------- Normal --------------- //
    R = ec.scalarMultiply(k, P);
    std::cout << k << "R = " << R << endl;

    // ----------- NAF ------------------ //
    NAF naf;
    int *x = naf.convertNAF(k);
    std::cout << "NAF of " << k << ": " << naf << endl;
    int *array;
    naf.getNAF(array);
    R = ec.scalarMultiplyNAF(array, P, naf.getSize());
    std::cout << k << "R = " << R << endl;

    return 0;

}