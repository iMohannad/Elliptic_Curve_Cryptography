#include <iostream>
#include "randomRecordingAlg.cpp"
//#include <randomRecordingAlg.cpp>

using namespace std;
using namespace RDP;

int main() {
    int k = 31415;
    int D[] = {1, 3, 23, 27};
    int size = sizeof(D)/sizeof(*D);
    // int * Dw;
    // int Wn = get_Wn(D, size);
    // cout << "Wn > " << Wn << endl;
    // int size_Dw;
    // int WMAX = getWMax(k, Wn, D, size);
    // cout << "Wmax = " << WMAX << endl;
    // get_Dw(Dw, D, 3, size, size_Dw);
    // for (int i =0; i<size_Dw; i++) {
    //     cout << Dw[i] << " ";
    // }
    // cout << endl;
    // int * Dw_complement;
    // size_Dw = 0;
    // get_Dw_complement(Dw_complement, D, 3, size, size_Dw);

    // std::cout << size_Dw << std::endl;
    // for (int i =0; i<size_Dw; i++) {
    //     cout << Dw_complement[i] << " ";
    // }

    // cout << endl;

    int * result;
    int resultSize;
    RDPAlgorithm(k, D, size, result, resultSize);

    for (int i =0; i<resultSize; i++) {
        cout << result[i] << " ";
    }
    cout << endl;

    return 0;
}