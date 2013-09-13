/*
 * leetcode Divide Two Integers
 */
#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <assert.h>
using namespace std;

int dv(int dividend, int divisor)
{
    long long a = abs(dividend);
    long long b = abs(divisor);

    if (b == 0 || a < b || a == 0)
        return 0;
    if (divisor == 1)
        return dividend;

    long long ret = 0;
    while (a >= b)
    {
        long long c = b;
        for (int i = 0; a >= c; i++, c <<= 1)
        {
            a -= c;
            ret += 1 << i;
        }
    }
    return (dividend ^ divisor) >> 31 ? -ret:ret;
}

int main()
{
    cout << dv(-16, 1) << endl;
    cout << dv(16, 1) << endl;
    assert(dv(-16,1) == -16);
    assert(dv(16,1) == 16);
    assert(dv(-16,0) == 0);
    assert(dv(0,16) == 0);
    return 0;
}

