#include <cmath>
#include <list>
#include <iostream>
#include <string>
#include <algorithm>
#include "BigInteger.hpp"

namespace RDP
{

    void printArray(BigInteger * arr, int size) {
        for (int i =0; i<size; i++) {
                std::cout << arr[i] << " ";
        }
        std::cout << std::endl;
    }


    /* Find if a value exists in an array */
    int findValue(BigInteger * arr, int size, BigInteger item) {
        // int found = 0;
        for (int i =0; i < size; i++) {
            if (arr[i] == item) return 1;
        }
        return 0;
    }

    // Calcuclate pw(k) = k % (2**w)
    BigInteger pw(BigInteger k, int w) {
        return BI_Residue(k, (int) pow(2, w));
    }

    /* Get Dw = pw(d) for each d in D
     * Parameters:
     *      Dw      = an empty array that is filled by the results of pw(d)
     *      w       = is needed to calculcate pw(d)
     *      D       = Array of digit set D
     *      size    = size of D digit set
     *      size_DW = a reference to size of Dw array
     */
    void get_Dw(BigInteger *& Dw, BigInteger * D, int w, int size, int &size_Dw) {
        Dw = new BigInteger[size];
        std::list<BigInteger> Dw_list;
        for (int i = 0; i<size; i++){
            Dw_list.push_back(pw(D[i], w));
        }
        // Sort Dw
        Dw_list.sort();
        // Remove duplicates
        Dw_list.unique();
        int index = 0; // used to fill the array Dw
        size_Dw = Dw_list.size();
        for (std::list<BigInteger>::iterator it=Dw_list.begin(); it!=Dw_list.end(); ++it) {
            Dw[index++] = *it;
        }
    }

    void get_D_k (BigInteger * D, int size, BigInteger *& D_less_k, BigInteger k, int &size_D_less_k) {
        std::list<BigInteger> D_k_list;
        for (int i = 0; i < size; i++) {
            if (D[i] < k) {
                D_k_list.push_back(D[i]);
            }
            else {
                break;
            }
        }
        D_k_list.sort();
        D_k_list.unique();
        size_D_less_k = D_k_list.size();
        D_less_k = new BigInteger[size_D_less_k];
        int index = 0;
        for (std::list<BigInteger>::iterator it=D_k_list.begin(); it!=D_k_list.end(); ++it) {
            D_less_k[index++] = *it;
        }
    }

    void get_Dw_complement(BigInteger *& Dw_complement, BigInteger * D, int w, int size, int &size_Dw_Comp) {
        BigInteger * Dw;
        int size_Dw;
        get_Dw(Dw, D, w, size, size_Dw);
        std::list<BigInteger> Dw_complement_list (Dw, Dw+size_Dw);
        BigInteger temp;
        BigInteger constant = (int) pow(2, w);
        for (int i = 0; i < size_Dw; i++) {
            temp = constant - Dw[i];
            Dw_complement_list.push_back(temp);
        }
        Dw_complement_list.sort();
        Dw_complement_list.unique();

        size_Dw_Comp = Dw_complement_list.size();
        Dw_complement = new BigInteger[size_Dw_Comp];
        int index = 0;
        std::list<BigInteger>::iterator it=Dw_complement_list.begin();
        for (int i = 0; i < size_Dw_Comp; i++) {
            Dw_complement[i] = *it;
            it++;
        }
        delete [] Dw;
    }

    // Computes \floor(log_2(max(D)))
    int get_Wn(BigInteger * D, int size) {
        BigInteger max(D[0]);
        // Get the max element in D
        for (int i = 1; i<size; i++){
            if (D[i] > max) max = D[i];
        }

        int targetlevel = 0;
        while (max/2 != 0) {
            ++targetlevel;
            max = max/2;
        }
        return targetlevel;
    }

    int getWMax(BigInteger k, int Wn, BigInteger * D, int size) {
        int w = Wn + 2; // Upper bound of w
        BigInteger constant;
        for (int i=Wn+2; i > 0; i--) {
            // Search if di < k
            constant = (int) pow(2, i);
            for (int j = 0; j < size; j++) {
                if (pw(D[j], i) == pw(k, i)) {
                    return i;
                }
                if (pw(k, i) == (constant - pw(D[j], i)))
                    return i;
            }
        }
    }

    BigInteger digitD(BigInteger k, BigInteger * D, int size) {
        int findK = findValue(D, size, k);
        std::list<int> tempResult;
        if (k%2 == 0) {
            return 0;
        }
        if (k == 1) {
            return k;
        }

        BigInteger * D_less_k; //array that contains D value less than k
        int size_D_less_k;
        // Get all the values of D less than k
        get_D_k(D, size, D_less_k, k, size_D_less_k);

        int Wn = get_Wn(D, size);
        int WMAX = getWMax(k, Wn, D_less_k, size_D_less_k);



        BigInteger * Dw;
        int size_Dw;
        get_Dw(Dw, D_less_k, WMAX, size_D_less_k, size_Dw);
        BigInteger * Dw_complement;
        int size_Dw_comp;
        get_Dw_complement(Dw_complement, D_less_k, WMAX, size_D_less_k, size_Dw_comp);

        BigInteger pw_k = pw(k, WMAX);
        /* If pwmax(k) in Dwmax:
        *      if (pw(k) == pw(d)) return d
        */
        int found = findValue(Dw, size_Dw, pw_k);
        if (found) {
            for (int j = 0; j < size_D_less_k; j++) {
                if (pw(k, WMAX) == pw(D_less_k[j], WMAX)) {
                    delete [] Dw;
                    delete [] Dw_complement;
                    return D_less_k[j];
                }
            }
        }

        BigInteger pw_comp = (int) pow(2, WMAX) - pw(k, WMAX);
        found = findValue(Dw_complement, size_Dw_comp, pw_comp);
        if (found) {
            for (int j = 0; j < size_D_less_k; j++) {
                if (((int) pow(2, WMAX) - pw(D_less_k[j], WMAX)) == pw(k, WMAX)) {
                    D_less_k[j].sign = -1;
                    delete [] Dw;
                    delete [] Dw_complement;
                    return D_less_k[j];
                }
            }
        }
    }


    void RDPAlgorithm(BigInteger k, BigInteger * D, int size, BigInteger *& result, int &resultSize) {
        std::list<BigInteger> resultList;
        BigInteger ki;
        while (k != 0) {
            ki = digitD(k, D, size);
            k = (k - ki) / 2;
            resultList.push_back(ki);
        }
        std::list<BigInteger>::iterator it = resultList.begin();
        resultSize = resultList.size();
        result = new BigInteger[resultSize];
        for (int i = 0; i < resultSize; i++) {
            result[i] = *it;
            it++;
        }
    }
}