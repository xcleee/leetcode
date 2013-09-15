/*
 * leetcode sqrt(x)
 */
#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <assert.h>
using namespace std;

// any number's sqrt root is less then half of itself plus one (root <= x/2+1)
// so use binary search to locate the root
int sqrt(int x)
{
    long long left = 0;
    long long right = x;
    long long xx = x;

    while (left <= right)
    {
        long long m = (left + right) / 2; //use long long to avoid multiplication overflow
        if (m * m <= xx && (m + 1) * (m + 1) > xx)
            return (int)m;

        if (m * m < xx)
            left = m + 1;
        else
            right = m - 1;
    }
}

int main()
{
    for (int i = 0; i < 26; i++)
        cout << i << " => " << sqrt(i) << endl;
    return 0;
}

