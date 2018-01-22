#include <iostream>
#include <cstdlib>
#include "NAF.hpp"

using namespace std;


NAF::NAF() {
    NAFNumber = NULL;
    nbits = 0;
}

NAF::NAF(int input[], int size) : NAFNumber(input), nbits(size)
{
}

int * NAF::convertNAF(int k) {
    int * dArray = new int[500];
    int count = 0; //count the number of bits in the NAF number
    int ki;
    while (k >= 1) {
        if (k % 2 == 1) {
            ki = 2 - (k % 4);
            k -= ki;
        }
        else {
            ki = 0;
        }
        k = k/2;
        dArray[count] = ki;
        cout << "count = " << count << ", ki = " << ki << endl;
        count +=1;
    }

    // Initalize a space for NAFNumber equal to the size of the NAF generated
    NAFNumber = new int[count];

    // Set the size of the NAF number
    nbits = count;
    for (int i=0; i<nbits; i++) {
        NAFNumber[i] = dArray[i];
    }

    // delete the point of the array
    delete [] dArray;
    dArray = NULL; // Clear to prevent using invalid memory reference
    return NAFNumber;
}

// Return a copy of the NAF number
void NAF::getNAF(int *&copyNAF) {
    if (nbits == 0)
        return;
    // A variable to store the copy data
    int * copyData = new int[nbits];
    for (int i = 0; i < nbits;i++) {
        copyData[i] = NAFNumber[i];
        cout << "copyData[" << i << "] = " << copyData[i] << endl;
        cout << "NAFNumber[" << i << "] = " << NAFNumber[i] << endl;
    }
    cout << "NAF ARRAY OF SIZE " << sizeof(copyNAF) << endl;
    copyNAF = copyData;
}

int NAF::getSize() {
    return nbits;
}

std::ostream& operator <<(std::ostream& os, const NAF& k){
    for (int i=0; i<k.nbits; i++){
        os << k.NAFNumber[k.nbits-i-1] << " ";
    }
    return os;
}
