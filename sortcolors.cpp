/*
 * leetcode Sort Colors
 */
#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <assert.h>
using namespace std;

//counting sort
void sortColors(int A[], int n)
{
    char count[3] = {0};
    for (int i = 0; i < n; i++)
        count[A[i]]++;
    int k = 0;
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < count[i]; j++)
            A[k++] = i;
}

// one pass sort
void sortColors2(int A[], int n)
{
    int i = 0;     // i point to 0 element
    int j = n - 1; // j point to 1 element
    int k = n - 1; // k point to 2 element
    while (i <= j)
    {
        if (A[i] == 2)
        {
            swap(A[i], A[k]);
            k--;
            if (k < j)
                j = k;//keep j is before k
        }
        else if (A[i] == 1)
        {
            swap(A[i], A[j]);
            j--;
        }
        else
            i++;
    }
}

int main()
{
    int A[] = {1, 2, 1, 2, 0, 1, 1, 0, 2, 0};
    sortColors2(A, sizeof(A)/sizeof(int));
    for (int i = 0; i < sizeof(A)/ sizeof(int); i++)
        cout << A[i] << " ";
    cout << endl;
    return 0;
}

