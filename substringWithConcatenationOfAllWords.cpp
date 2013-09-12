/*
 * leetcode Substring with Concatenation of All Words
 */
#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <vector>
#include <map>
using namespace std;

vector<int> findSubstring(string S, vector<string> &L)
{
    map<string, int> rightWords, curWords;
    vector<int> result;
    for (int i = 0; i < L.size(); i++)
        ++rightWords[L[i]];

    int WordLen = L[0].length();
    int ListLen = L.size();
    int StrLen = S.length();
    for (int i = 0; i <= StrLen - WordLen * ListLen; i++)
    {
        curWords.clear();
        int j;
        for (j = 0; j < ListLen; j++)
        {
            string w = S.substr(i + j * WordLen, WordLen);
            if (rightWords.find(w) == rightWords.end())
                break;
            ++curWords[w];
            if (curWords[w] > rightWords[w])
                break;
        }
        if (j == ListLen)
            result.push_back(i);
    }
    return result;
}

int main()
{
    string S = "barfoothefoobarman";
    vector<string> L;
    L.push_back("bar");
    L.push_back("foo");
    vector<int> result = findSubstring(S, L);
    for (int i = 0; i < result.size(); i++)
        cout << result[i] << " ";
    cout << endl;

    return 0;
}

