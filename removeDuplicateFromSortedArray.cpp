#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <assert.h>
using namespace std;

int removeDuplicates(int a[], int n)
{
    assert(n > 0);
    int i = 0;//i point to first meet unique element
    for (int j = 0; j < n; j++)
        if (a[i] != a[j])
            a[++i] = a[j];

    return i+1;
}

int main()
{
    int a[] = {1, 2, 2, 3, 4, 4, 4, 7};
    int len = removeDuplicates(a, sizeof(a)/sizeof(int));
    for (int i = 0; i < len; i++)
        cout << a[i] << " ";
    cout << endl;
    return 0;
}

