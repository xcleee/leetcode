/*
 * leetcode Trapping Rain Water
 */
#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <assert.h>
using namespace std;

int trap(int A[], int n)
{
    int mid = 0;
    int water = 0;
    int h = 0; // record the highest before
    for (int i = 0; i < n; i++)
        if (A[i] > A[mid])
            mid = i;// find the max number which is the summit

    for (int i = 0; i < mid; i++)
        if (h > A[i])
            water += h - A[i];
        else
            h = A[i];

    h = 0;
    for (int i = n-1; i > mid; i--)
        if (h > A[i])
            water += h - A[i];
        else
            h = A[i];
    return water;
}

int main()
{
    int A[] = {0,1,0,2,1,0,1,3,2,1,2,1};
    cout << trap(A,sizeof(A)/sizeof(int)) << endl;
    return 0;
}

