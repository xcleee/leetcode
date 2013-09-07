/*
 * leet code 11
 */
#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <assert.h>
#include <vector>
#include <algorithm>
using namespace std;

vector<vector<int> > threeSum0(vector<int> n)
{
    sort(n.begin(), n.end());
    vector<vector<int> > result;

    int length = n.size();

    for (int i = 0; i < length; i++)
    {
        // skip the same element
        if (i > 0 && n[i] == n[i-1])
            continue;

        int start = i + 1; // var start point to the leftmost of the var i
        int end = length - 1; // var end point to the end of the array

        while (start < end)
        {
            //skip the same element
            if (start - i > 1 && n[start] == n[start - 1])
            {
                start++;
                continue;
            }
            if (end + 1 < length && n[end] == n[end + 1])
            {
                end--;
                continue;
            }

            int sum = n[i] + n[start] + n[end];

            if (sum == 0)
            {
                vector<int> r;
                r.push_back(n[i]);
                r.push_back(n[start]);
                r.push_back(n[end]);
                result.push_back(r);
                start++;
            }
            else if (sum > 0)
                end--;
            else
                start++;
        }
    }
    return result;
}

int main()
{
    int test[] = {-4,-2,-2,-2,0,1,2,2,2,3,3,4,4,6,6};
    vector<int> n(test, test+ sizeof(test)/sizeof(test[0]));

    vector<vector<int> > result = threeSum0(n);

    for (int i = 0; i < result.size(); i++)
    {
        for (int j = 0; j < result[i].size(); j++)
            cout << result[i][j] << " ";
        cout << endl;
    }
    return 0;
}
