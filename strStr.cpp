#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <assert.h>
using namespace std;

char* strStr(char* str, char* target)
{
    if (target == NULL ||! *target )
        return str;
    char* p1 = str;   // point to the head of the sliding window
    char* p1Adv = str;
    char* p2 = target;

    while (*++p2)
        p1Adv++; // point to the tail of sliding window

    while (*p1Adv)
    {
        char* p1Begin = p1;
        p2 = target;

        while (*p1 && *p2 && *p1 == *p2)
        {
            p1++;
            p2++;
        }
        if (!*p2)
            return p1Begin;
        p1 = p1Begin + 1;
        p1Adv++;
    }
    return NULL;
}

int main()
{
    char * s = (char*)"abcd";
    char * target = (char*)"bc";
    cout << strStr(s, target) << endl;
    return 0;
}
