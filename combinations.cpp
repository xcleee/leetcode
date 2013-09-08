/*
 * leetcode OJ Combinations
 */
#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <assert.h>
#include <vector>
using namespace std;

void com(int n, int k, int curlen, int pos, vector<vector<int> >& result, vector<int>& rcd)
{
    if (curlen == k)
    {
        result.push_back(rcd);
        return;
    }

    for (int i = pos; i < n; i++)
    {
        rcd[curlen] = i + 1;
        com(n, k, curlen+1, i+1, result, rcd);
    }
}

vector<vector<int> > combination(int n, int k)
{
    vector<vector<int> > result;
    vector<int> rcd(k);
    com(n, k, 0, 0, result, rcd);
    return result;
}

int main()
{
    vector<vector<int> > result = combination(2, 2);
    for (int i = 0; i < result.size(); i++)
    {
        for (int j = 0; j < result[i].size(); j++)
            cout << result[i][j] << " ";
        cout << endl;
    }
    return 0;
}
