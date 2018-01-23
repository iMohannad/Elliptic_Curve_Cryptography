#include <cmath>
#include <list>

int getWMax(int k, int Wn, int * D, int size) {
    int w = Wn + 2; // Upper bound of w
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
    std::list<int> Dw_list;
    for (int i = 0; i<size; i++){
        Dw_list.pop_back(pw(D[i], w));
    }
    // Sort Dw
    Dw_list.sort();
    int index = 0;
    
    for (std::list<int>::iterator it=Dw_list.begin(); it!=Dw_list.end(); ++it) {
        Dw[index++] = *it;
    }
}

void get_Dw_complement(int * Dw_complement, int * D, int w, int size) {
    int * Dw;
    get_Dw(Dw, D, w, size);
    std::list<int> Dw_complement_list (Dw, Dw+size);
    int temp;
    int constant = (int) pow(2, w);
    for (int i = 0; i < size; i++) {
        temp = constant - Dw[i];
        Dw_complement_list.push_back(temp);
    }
    Dw_complement_list.sort();
    Dw_complement_list.unique();
    int size_Dw_Complement = Dw_complement_list.size();
    Dw_complement = new int[size_Dw_Complement];
    int index = 0;
    for (std::list<int>::iterator it=Dw_complement_list.begin(); it!=Dw_complement_list.end(); ++it) {
        Dw_complement[index++] = *it;
    }

}

int get_Wn(int * D, int size) {
    int max = D[0];
    // Get the max element in D
    for (int i = 1; i<size; i++){
        if (D[i] > max) max = D[i];
    }
    return (int) floor(std::log2(max));
}