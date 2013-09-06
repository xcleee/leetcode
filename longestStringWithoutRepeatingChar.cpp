#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <assert.h>
#include <string>
using namespace std;

string longestUnrepeatedString(const string& s)
{
    int i = 0;// point to the begin of string
    int j = 0;// point to the last not encountered character

    bool map[256] = {false};
    int n = s.length();

    int maxlen = 0;
    int maxi = 0;
    while (j < n)
    {
        if (!map[s[j]])
            map[s[j++]] = true;
        else
        {
            if (maxlen < j-i)
            {
                    maxlen = j-i;
                    maxi = i;
            }
            //maxlen = max(maxlen, j-i);
            // the following code is supposed to locate the first
            // repeated char int the [i, j] range and then update
            // the new range's begin, i
            while (s[i] != s[j])
                map[s[i++]] = false;
            i++;
            j++;
        }
    }
    // update at last in case of j jump out of the loop
    // without update maxlen and maxi
    if (maxlen < j-i)
    {
        maxlen = j-i;
        maxi = i;
    }
    return s.substr(maxi, maxlen);
}

int main()
{
    string s = "abcabebb";
    cout << s << endl;
    cout << longestUnrepeatedString(s)<< endl;
    return 0;
}

