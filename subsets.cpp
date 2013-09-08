/*
 * leetcode OJ Subsets
 */
#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <assert.h>
#include <vector>
#include <algorithm>
using namespace std;

void sub(vector<vector<int> >& result, vector<int>& n, int p, vector<int>& path)
{
    result.push_back(path);

    for (int i = p; i < n.size(); i++)
    {
        path.push_back(n[i]);
        sub(result, n, i+1, path);
        path.pop_back();
    }
}

vector<vector<int> > subsets(vector<int>& n)
{
    vector<vector<int> > result;
    vector<int> path;
    sort(n.begin(), n.end());
    sub(result, n, 0, path);
    return result;
}

int main()
{
    int test[] = {1, 2, 3};

    vector<int> n(test, test+sizeof(test)/sizeof(int));

    vector<vector<int> > result = subsets(n);

    for (int i = 0; i < result.size(); i++)
    {
        for (int j = 0; j < result[i].size(); j++)
            cout << " " << result[i][j];
        cout << endl;
    }

    return 0;
}

