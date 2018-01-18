#include <stdlib.h>

namespace Cryptography {


    /* Find the inverse of a number x mod n such that
     * x*i mod n = 1 where i is the inverse of x mod n.
     */
    int inverseMod(int x, int n) {
        int t; // a temp value
        for (int i = 0; i < n; i++) {
            t = x*i % n;
            if (t == 1) {
                return i;
            }
        }
    }

    int modulo (int m, int n) {
        return m >= 0 ? m % n : (n - abs( m%n )) % n;
    }

}