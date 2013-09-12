/*
 * leetcode Valid Palindrome
 */
#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <assert.h>
using namespace std;

bool isDigitAndAlpha(char c)
{
    return (isdigit(c) || isalpha(c));
}
bool isPalindrome(string s)
{
    int start = 0;
    int end = s.length() - 1;
    int err = abs('A'-'a');
    while (start < end)
    {
        char c1 = s[start];
        char c2 = s[end];
        if (isDigitAndAlpha(c1) && isDigitAndAlpha(c2))
        {
            if (c1 == c2 || abs(c1 - c2) == err)
            {
                start++;
                end--;
            }
            else
                return false;
        }

        if (!isDigitAndAlpha(c1))
            start++;
        if (!isDigitAndAlpha(c2))
            end--;
    }
    return true;
}

int main()
{
    string s = "1a1";
    if (isPalindrome(s))
        cout << "Yes\n";
    else
        cout << "No\n";
    return 0;
}

