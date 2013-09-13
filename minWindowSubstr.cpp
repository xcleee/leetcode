/*
 * leetcode Minimum Window Substring
 */
#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <assert.h>
using namespace std;

string minWindow(string S, string T)
{
    int need[256] = {0};
    for (int i = 0; i < T.size(); i++)
        need[T[i]]++;
    int found[256] = {0};

    int count = 0;
    int minLen = S.size() + 1;
    int minBegin = 0;

    for (int begin = 0, end = 0; end < S.size(); ++end)
    {
        char c = S[end];
        if (need[c] == 0)
            continue;
        if (++found[c] <= need[c])
            count++;

        if (count == T.size())
        {
            while (need[S[begin]] == 0 || found[S[begin]] > need[S[begin]])
            {
                if (found[S[begin]] > need[S[begin]])
                    found[S[begin]]--;
                begin++;
            }
            int len = end - begin + 1;
            if (len < minLen)
            {
                minLen = len;
                minBegin = begin;
            }
        }
    }
    return minLen > S.size() ? "" : S.substr(minBegin, minLen);
}

int main()
{
    string S = "ADOBECODEBANC";
    string T = "ABC";
    cout << minWindow(S, T) << endl;
    return 0;
}
