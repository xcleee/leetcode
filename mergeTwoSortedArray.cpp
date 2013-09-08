#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <assert.h>
#include <vector>
using namespace std;

// this function merge two sorted array, one of them is longer and the space used
// is given, return the new sorted array's length after merging
int merge(vector<int>& longArray, vector<int>& shortArray, int longUsed)
{
    int longTail = longUsed - 1;
    int shortTail = shortArray.size() - 1;

    while (longTail >=0 && shortTail >= 0)
    {
        if (longArray[longTail] > shortArray[shortTail])
        {
            longArray[longTail + shortTail + 1] = longArray[longTail];
            longTail--;
        }
        else
        {
            longArray[longTail + shortTail + 1] = shortArray[shortTail];
            shortTail--;
        }
    }

    while (shortTail >= 0)
    {
        longArray[shortTail] = shortArray[shortTail];
        shortTail--;
    }
}
int main()
{
    int l[] = {1, 3, 6, 10, 11, 12, 14};
    int s[] = {2, 9, 17};
    vector<int> longArray(l, l + sizeof(l)/sizeof(l[0]));
    vector<int> shortArray(s, s + sizeof(s)/sizeof(s[0]));
    longArray.resize((sizeof(l) + sizeof(s)) / sizeof(int));
    int newLen =  merge(longArray, shortArray, sizeof(l)/ sizeof(l[0]));
    for (int i = 0; i < longArray.size(); i++)
        cout << longArray[i] << " ";
    cout << endl;
    return 0;
}

