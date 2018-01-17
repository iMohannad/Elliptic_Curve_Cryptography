#include <cstdlib>
#include <iostream>
#include <cmath>

#include "ec.hpp"

using namespace std;

ec::ec()
{
    ec(1, 1), 17;
}

ec::ec(int a, int b, int M){
    this->a = a;
    this->b = b;
    this->M = M;
}

ec::~ec()
{
}