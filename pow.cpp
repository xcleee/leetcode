/*
 * leetcode pow(x,n)
 */
#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <assert.h>
using namespace std;

double pow(double x, int n)
{
    double ret;
    if (n == 0)
        return 1;

    int m = abs(n);

    double v = pow(x, m / 2);

    if (m & 1)
        ret = v * v * x;
    else
        ret = v * v;

    return n>0? ret : 1/ret;
}

int main()
{
    cout << pow (2, -2) << endl;
    return 0;
}

