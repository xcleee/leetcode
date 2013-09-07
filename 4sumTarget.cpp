#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <assert.h>
#include <vector>
#include <algorithm>
using namespace std;

vector<vector<int> > fourSum(vector<int>& num, int target)
{
    vector<vector<int> > result;
    int len = num.size();
    int sum;
    int left, right;

    sort(num.begin(), num.end());

    for(int i = 0; i < num.size(); i++)
    {
        for(int j = i + 1; j < len; j++)
        {
            left = j + 1;
            right = len - 1;
            while (left < right)
            {
                sum = num[i] + num[j] + num[left] + num[right];
                if (sum == target)
                {
                    result.push_back(vector<int>(4));
                    result.back()[0] = num[i];
                    result.back()[1] = num[j];
                    result.back()[2] = num[left];
                    result.back()[3] = num[right];
                    left++;
                    right--;
                }
                else if (sum < target)
                    left++;
                else
                    right--;
            }
        }
    }
    sort(result.begin(), result.end());
    result.resize(unique(result.begin(), result.end())-result.begin());
    return result;
}

int main()
{
    int test[] = {1, 0, -1, 0, -2, 2};

    vector<int> a(test, test + sizeof(test)/sizeof(test[0]));

    vector<vector<int> > result = fourSum(a, 0);

    for (int i = 0; i < result.size(); i++)
    {
        for (int j = 0; j < result[i].size(); j++)
            cout << result[i][j] << " ";
        cout << endl;
    }
    return 0;
}

