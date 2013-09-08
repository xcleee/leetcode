#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <assert.h>
#include <vector>
using namespace std;

void dfs(int p, int curSum, int target, vector<int>& n, vector<int> path, vector<vector<int> >& result)
{
    if (curSum > target)
        return;
    if (curSum == target)
    {
        result.push_back(path);
        return;
    }

    for (int i = p; i < n.size(); i++)
    {
        curSum += n[i];
        path.push_back(n[i]);

        dfs(i, curSum, target, n, path, result);

        curSum -= n[i];
        path.pop_back();
    }
}

vector<vector<int> > combinationSum(vector<int>& n, int target)
{
    vector<vector<int> > result;
    vector<int> path;
    sort(n.begin(), n.end());
    dfs(0, 0, target, n, path, result);
    return result;
}

int main()
{
    int test[] = {1, 2, 3, 6, 7};
    vector<int> n(test, test+sizeof(test)/sizeof(int));

    vector<vector<int> > result = combinationSum(n, 7);

    for (int i = 0; i < result.size(); i++)
    {
        for (int j = 0; j < result[i].size(); j++)
            cout << " " << result[i][j];
        cout << endl;
    }
    return 0;
}

