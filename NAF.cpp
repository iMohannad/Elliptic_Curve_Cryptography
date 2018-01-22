
class NAF {
    public:
        int * convertNAF(int k);
        int * getNAF();
        // ostream handler: Print NAF
        friend std::ostream& operator <<(std::ostream& os, const NAF& p);
    private:
        int * NAFNumber;
        int nbits = 0; // Number of bits of the NAF number
};


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
        count +=1;
    }

    // Copy the array backword to the NAFNumber Array;
    NAFNumber = new int[count];

    count--; // Reduce count by 1 because of the last iteration
    nbits = count; // size the size of the NAF number
    for (int i=0; i<nbits; i++) {
        NAFNumber[i] = dArray[count--];
    }

    // delete the point of the array
    delete [] dArray;
    dArray = nullptr; // Clear to prevent using invalid memory reference
}

// Return a copy of the NAF number
int * NAF::getNAF() {
    if (nbits == 0)
        return nullptr;
    // A variable to store the copy data
    int copyNAF[nbits];
    for (int i = 0; i < nbits;i++) {
        copyNAF[i] = NAFNumber[i];
    }
    return copyNAF;
}

std::ostream& operator <<(std::ostream& os, const NAF& k){
    for (int i=0; i<k.nbits; i++){
        os << k.NAFNumber[i] << " ";
    }
    return os;
}
