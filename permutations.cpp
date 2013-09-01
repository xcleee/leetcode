/*
 * leet code 46,47
 */

#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <assert.h>
#include <vector>

using namespace std;

void perm(vector<int> &num, vector<vector<int> >& result, int start, int end)
{
    if (start < end - 1)
    {
        perm(num, result, start+1, end);// num[0],(num[1],...,num[end-1])
        for (int i = start+1; i < end; i++)//num[i],(num[1], ..., num[i], ..., num[end-1])
        {
            swap(num[start], num[i]);
            perm(num, result, start+1, end);
            swap(num[start], num[i]);
        }
    }
    else
        result.push_back(num);
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

    return 0;
}
