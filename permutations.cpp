/*
 * leetcode OJ Permutations, Permutations II
 */

#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <assert.h>
#include <algorithm>
#include <vector>

using namespace std;

// k is the number currently chosen to swap with the element after it
void perm(vector<int> &num, vector<vector<int> >& result, int k, int end)
{
    if (k < end - 1)
    {
        for (int i = k; i < end; i++)
        {
            //num[i],(num[1], ..., num[k], ..., num[end-1])
            swap(num[k], num[i]);
            perm(num, result, k+1, end);
            swap(num[k], num[i]);
        }
    }
    else
        result.push_back(num);
}

bool canSwap(vector<int>& num, int k, int m)
{
    for (int i = k; i < m; i++)
        if (num[i] == num[m])
            return false;
    return true;
}

void permWithRepeatElement(vector<int>& num, vector<vector<int> >& result, int k, int end)
{
    if (k < end - 1)
    {
        for (int i = k; i < end; i++)
        {
            if (canSwap(num, k, i))
            {
                //num[i],(num[1], ..., num[k], ..., num[end-1])
                swap(num[k], num[i]);
                permWithRepeatElement(num, result, k+1, end);
                swap(num[k], num[i]);
            }
        }
    }
    else
        result.push_back(num);
}

vector<vector<int> > permUnique(vector<int>& num)
{
    vector<bool> used(num.size(), false);
    vector<vector<int> > result;

    sort(num.begin(), num.end());

    permWithRepeatElement(num, result, 0, num.size());

    return result;
}

void printResult(vector<vector<int> >& result)
{
    for (int i = 0; i < result.size(); i++)
    {
        for (int j = 0; j < result[i].size(); j++)
            cout << result[i][j] << " ";
        cout << endl;
    }
}

int main()
{
    //test case 1 normal array
    cout << "test case 1" << endl;
    vector<int> num;
    num.push_back(1);
    num.push_back(2);
    num.push_back(3);
    vector<vector<int> > result;
    perm(num, result, 0, num.size());
    printResult(result);

    vector<vector<int> >().swap(result);
    vector<int>().swap(num);

    //test case 2 empty array
    cout << "test case 2" << endl;
    perm(num, result, 0, num.size());
    printResult(result);

    vector<vector<int> >().swap(result);
    vector<int>().swap(num);

    //test case 3 single element array
    cout << "test case 3" << endl;
    num.push_back(1);
    perm(num, result, 0, num.size());
    printResult(result);

    vector<vector<int> >().swap(result);
    vector<int>().swap(num);

    cout << "test case 4" << endl;
    int test4[] = {1,2,2,3,3,3};
    for (int i = 0; i < sizeof(test4)/sizeof(test4[0]); i++)
        num.push_back(test4[i]);

    result = permUnique(num);

    printResult(result);

    return 0;
}
