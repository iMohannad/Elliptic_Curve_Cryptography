#include <cmath>

int getWMax(int k, int Wn, int * D, int size) {
    w = Wn + 2; // Upper bound of w
    int * Dw_complement;
    for (int i=Wn+2; i > 0; i--) {
        // Get Dw_complement

    }
}

// pw(k) = k % (2**w)
int pw(int k, int w) {
    return k % (int) pow(2, w);
}

void get_Dw(int * Dw, int * D, int w, int size) {
    Dw = new int[size];
    for (int i = 0; i<size; i++){
        Dw[i] = pw(D[i], w);
    }
    // Sort Dw
}