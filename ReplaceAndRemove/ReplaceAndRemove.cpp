// ReplaceAndRemove.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <string>

using namespace std;

void ReplaceAndRemoveSimple(string& orig, int size)
{
    string s(orig.size(), '-');
    int j = 0;
    for (int i = 0; i < size; i++)
    {
        if (orig[i] == 'b') continue;
        else if (orig[i] == 'a')
        {
            s[j++] = 'd';
            s[j++] = 'd';
        }
        else s[j++] = orig[i];
    }
    orig = s;
}

void ReplaceAndRemoveSleek(string& orig, int size)
{
    // Perform sanity check
    if (orig.size() == 0 || orig.size() < size) return;

    //delete 'b' characters 
    int rT = 0; int wT = 0;

    while (rT < size)
    {
        if (orig[rT] != 'b')
        {
            orig[wT] = orig[rT];
            wT++;
        }
        rT++;
    }
    //update size as it might have shrinked
    size = wT;

    // replace 'a' with 'd''d'
    wT = orig.size() - 1;
    size--;
    while (size >= 0)
    {
        if (orig[size] == 'a')
        {
            orig[wT--] = orig[wT--] = 'd';
        }
        else orig[wT--] = orig[size];

        size--;
    }

    // shift the chars to the beginning of the array
    int i = 0;

    wT++;
    while (wT < orig.size())
    {
        orig[i++] = orig[wT++];
        orig[wT - 1] = '-';
    }
}


int main()
{
    string s = "dbba";

    ReplaceAndRemoveSleek(s, 4);


    return 0;
}

