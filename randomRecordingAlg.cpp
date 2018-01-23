#include <cmath>
#include <list>
#include <iostream>
#include <algorithm>

namespace RDP
{
    // pw(k) = k % (2**w)
    int pw(int k, int w) {
        return k % (int) pow(2, w);
    }

    void get_Dw(int *& Dw, int * D, int w, int size, int &size_Dw) {
        Dw = new int[size];
        std::list<int> Dw_list;
        for (int i = 0; i<size; i++){
            Dw_list.push_back(pw(D[i], w));
        }
        // Sort Dw
        Dw_list.sort();
        Dw_list.unique();
        int index = 0;
        size_Dw = Dw_list.size();
        for (std::list<int>::iterator it=Dw_list.begin(); it!=Dw_list.end(); ++it) {
            Dw[index++] = *it;
        }
    }

    void get_Dw_complement(int *& Dw_complement, int * D, int w, int size, int &size_Dw_Comp) {
        int * Dw;
        int size_Dw;
        get_Dw(Dw, D, w, size, size_Dw);
        std::list<int> Dw_complement_list (Dw, Dw+size_Dw);
        int temp;
        int constant = (int) pow(2, w);
        for (int i = 0; i < size; i++) {
            temp = constant - Dw[i];
            Dw_complement_list.push_back(temp);
        }
        Dw_complement_list.sort();
        Dw_complement_list.unique();

        size_Dw_Comp = Dw_complement_list.size();
        Dw_complement = new int[size_Dw_Comp];
        int index = 0;
        std::list<int>::iterator it=Dw_complement_list.begin();
        for (int i = 0; i < size_Dw_Comp; i++) {
            Dw_complement[i] = *it;
            it++;
        }

    }

    int get_Wn(int * D, int size) {
        int max = D[0];
        // Get the max element in D
        for (int i = 1; i<size; i++){
            if (D[i] > max) max = D[i];
        }
        return (int) floor(log2(max));
    }

    int getWMax(int k, int Wn, int * D, int size) {
        int w = Wn + 2; // Upper bound of w
        int * Dw_complement;
        int size_Dw_Comp;
        bool cond1 = true;
        for (int i=Wn+2; i > 0; i--) {
            // Search if di < k
            for (int j = 0; j < size; j++) {
                if (D[j] >= k) {
                    cond1 = false;
                    break;
                }
            }
            // Pick a smaller w
            if (!cond1) {
                cond1 = true;
                continue;
            }
            get_Dw_complement(Dw_complement, D, i, size, size_Dw_Comp);
            // for (int j =0; j<size_Dw_Comp; j++) {
            //     std::cout << Dw_complement[j] << " ";
            // }
            // std::cout << std::endl;

            int pw_k = pw(k, i);
            int * p = std::find(Dw_complement, Dw_complement+size_Dw_Comp, pw_k);
            // std::cout << "Pw(k) = " << pw_k << ", P > " << *p << std::endl;
            if(p != Dw_complement+size_Dw_Comp) {
                return i;
            }
        }
        std::cout << "No w found to match the condition" << std::endl;
    }
}