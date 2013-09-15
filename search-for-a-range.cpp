/*
 * leetcode Search for a Range
 */
#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <assert.h>
#include <vector>
using namespace std;

vector<int> searchRange(int A[], int n, int target)
{
    vector<int> ret(2);
    int l = 0;
    int r = n - 1;
    int m;
    while (l <= r)
    {
        int m = r + (l - r) / 2;
        if (A[m] < target)
            l = m + 1;
        else if (A[m] > target)
            r = m - 1;
        else
        {
            // search the left side of m
            int b = m;
            while (b >= 0 && A[b] == target)
                b--;
            ret[0] = b + 1;
            // search the right side of m
            b = m;
            while (b < n && A[b] == target)
                b++;
            ret[1] = b - 1;
            return ret;
        }
    }

    ret[0] = ret[1] = -1;
    return ret;
}

int main()
{
    int A[] = {1, 2, 3, 4, 4, 4, 5, 6, 7, 8};
    int n = sizeof(A) /sizeof(int);
    vector<int> range = searchRange(A, n, 9);
    cout << "[" << range[0] << "," << range[1] << "]" << endl;
    return 0;
}

