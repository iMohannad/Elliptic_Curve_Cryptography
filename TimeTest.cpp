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
    Point P(87,206);

    // ------------ Variable Instantiations -------------//
    int k = 1122334455;
    int D[] = {1, 13, 15, 17, 19, 21, 23, 31, 33, 41, 43, 45, 53, 59, 61, 63};
    int size = sizeof(D)/sizeof(*D);
    std::cout << "Size => " << size << endl;
    int * k_RDP;
    int k_RDP_size;


    // ------------ RDP ------------- //
    RDPAlgorithm(k, D, size, k_RDP, k_RDP_size);
    for (int i =0; i<k_RDP_size; i++) {
        std::cout << k_RDP[i] << " ";
    }
    std::cout << endl;
    std::cout << "----------- RDP TEST --------------" << endl;
    Point R = ec.scalarMultiplyRDP(k_RDP, P, k_RDP_size, D, size);
    std::cout << k << "R = " << R << endl;

    // ---------- Normal --------------- //
    std::cout << "----------- DOUBLE AND ADD --------------" << endl;
    R = ec.scalarMultiply(k, P);
    std::cout << k << "R = " << R << endl;

    // ----------- NAF ------------------ //
    std::cout << "----------- NAF TEST --------------" << endl;
    NAF naf;
    int *x = naf.convertNAF(k);
    std::cout << "NAF of " << k << ": " << naf << endl;
    int *array;
    naf.getNAF(array);
    R = ec.scalarMultiplyNAF(array, P, naf.getSize());
    std::cout << k << "R = " << R << endl;

    return 0;

}