/*
 * leetcode OJ Median of Two Sorted Array 
 */
#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <assert.h>
using namespace std;

int findKthSmallest(int a[], int m, int b[], int n, int k)
{
    if (m > n) //keep the first array be the short one
        findKthSmallest(b, n, a, m, k);
    if (m == 0)
        return b[k-1];
    if (k == 1) // return the first smallest element, which just return the minimum one
        return a[0] < b[0] ? a[0] : b[0];

    int pa = k/2 < m ? k/2 : m; // halved the k each time
    int pb = k - pa;

    if (a[pa - 1] < b[pb - 1]) // drop a[0] ~ a[pa-1], narrow down k to k-pa
        return findKthSmallest(a+pa, m-pa, b, n, k-pa);
    else if (a[pa - 1] > b[pb - 1])// drop b[0] ~ b[pb-1], narrow down k to k-pb
        return findKthSmallest(a, m, b+pb, n-pb, k-pb);
    else// equal case, return either of them
        return a[pa - 1];
}

double medianOfTwoSortedArrays(int a[], int m, int b[], int n)
{
    if ((m+n) % 2 != 0)
        return findKthSmallest(a, m, b, n, (m+n)/2+1);
    else
        return (findKthSmallest(a, m, b, n, (m+n)/2)
            + findKthSmallest(a, m, b, n, (m+n)/2 + 1))/2.0;
}

int main()
{
    // test case 1: m+n even, ans is 7.5
    int a[] = {2, 5, 6, 9, 11};
    int b[] = {3, 4, 7, 8, 13, 14, 17};

    int m = sizeof(a) / sizeof(a[0]);
    int n = sizeof(b) / sizeof (b[0]);

    cout << medianOfTwoSortedArrays(a, m, b, n) << endl;

    // test case 2: m+n odd, ans is 8
    int c[] = {2, 5, 6, 9, 11, 12};
    int d[] = {3, 4, 7, 8, 13, 14, 17};

    m = sizeof(c) / sizeof(c[0]);
    n = sizeof(d) / sizeof (d[0]);

    cout << medianOfTwoSortedArrays(c, m, d, n) << endl;

    return 0;
}
