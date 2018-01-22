class NAF {
    public:
        NAF();
        NAF(int input[], int size);
        int * convertNAF(int k);
        int * getNAF();
        // ostream handler: Print NAF
        friend std::ostream& operator <<(std::ostream& os, const NAF& p);
    private:
        int * NAFNumber;
        int nbits; // Number of bits of the NAF number
};
