/*
 * leetcode Search a 2D Matrix
 */
#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <assert.h>
#include <vector>
using namespace std;

bool searchMatrix(vector<vector<int> > &matrix, int target)
{
    int cols = matrix[0].size();
    int rows = matrix.size();
    int total = cols * rows;

    int l = 0;
    int r = total - 1;
    while (l <= r)
    {
        int m = r + (l - r) / 2;
        int mVal = matrix[m / cols][m % cols];

        if (mVal == target)
            return true;
        else if (mVal < target)
            l = m + 1;
        else
            r = m - 1;
    }
    return false;
}

int main()
{
    int a[][4] = {
        {1, 3,  5,  7},
        {10, 11, 16, 20},
        {23, 30, 34, 50}
    };
    vector<vector<int> > m;

    for (int i = 0; i < sizeof(a) / sizeof(a[0]); i++)
    {
        vector<int> v(a[i], a[i]+sizeof(a[i])/sizeof(int));
        m.push_back(v);
    }

    for (int i = 0; i < m.size(); i++)
    {
        for (int j = 0; j < m[i].size(); j++)
            cout << m[i][j] << " ";
        cout << endl;
    }

    int cols = m[0].size();
    int rows = m.size();
    int s = cols * rows;
    cout << s << endl;
    for (int i = 0; i < s; i++)
    {
        int target = m[i / cols][i % cols];
        if (searchMatrix(m,target))
            cout << target << " is found" << endl;
        else
            cout << target << " is not found" << endl;

    }
    return 0;
}
