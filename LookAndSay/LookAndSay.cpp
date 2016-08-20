// LookAndSay.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <string>
#include <vector>

using namespace std;

inline void throwIfNotSame(int value)
{
    if (value != 0) throw;
}

string LookAndSay(int number)
{
    string result = "";
    
    if (number > 0)
    {
        string lastResult = "";

        for (int i = 1; i <= number; i++)
        {
            if (lastResult.size() == 0)
                result.push_back('1');
            else
            {
                // get the first char and set the count to 1
                char lastChar = lastResult[0];
                int count = 1;
                for (int j = 1; j < lastResult.size(); j++)
                {
                    if (lastChar == lastResult[j])
                        count++;
                    else
                    {
                        // now we are on a different char than the previous one
                        // push the count and then the char
                        result.push_back('0' + count);
                        result.push_back(lastChar);

                        // update the last char and count
                        lastChar = lastResult[j];
                        count = 1;
                    }
                }
                // when the iteration finishes the last set of similar chars are still 
                // need to be pushed to the string
                result.push_back('0' + count);
                result.push_back(lastChar);
            }
            // set the current result as previous
            lastResult = result;
            result = "";
        }

        // set the return value
        result = lastResult;
    }

    return result;
}





int main()
{
    vector<string> tests = {
        "",
        "1",
        "11",
        "21",
        "1211",
        "111221",
        "312211",
        "13112221",
        "1113213211"
    };

    for (int i = 0; i < tests.size(); i++)
    {
        throwIfNotSame(LookAndSay(i).compare(tests[i]));
    }

    return 0;
}

