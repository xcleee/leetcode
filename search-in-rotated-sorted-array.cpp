/*
 * leetcode Search in Rotated Sorted Array
 */
#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <assert.h>
using namespace std;

int search(int A[], int n, int target)
{
    int left = 0, right = n - 1;
    while (left <= right)
    {
        int mid = left + (right - left) / 2;
        if (A[mid] == target)
            return mid;
        // left side is sorted
        if (A[mid] > A[left])
        {
            //judge which side the target is in
            if (target < A[mid] && target >= A[left])
                right = mid - 1;
            else
                left = mid + 1;
        }
        //right side is sorted
        else if (A[mid] < A[left])
        {
            //judge which side the target is in
            if (target > A[mid] && target <= A[right])
                left = mid + 1;
            else
                right = mid - 1;
        }
        else
            left++;
    }
    return -1;
}

int main()
{
    int A[] = {1, 1, 1, 1, 1 ,3, 1, 1};
    int n = sizeof(A) / sizeof(int);
    cout << search(A, n, 3) << endl;
    //for (int i = 0; i < n; i++)
    //    assert(search(A, n, A[i]) == i);

    return 0;
}

