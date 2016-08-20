// AllValidIPs.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <map>
#include <set>
#include <vector>
#include <sstream>
#include <string>

using namespace std;

bool isValid(vector<string> IPstrings)
{
    if (IPstrings.size() != 4) return false;

    for (string s : IPstrings)
        if (atoi(s.c_str()) >= 256)
            return false;

    return true;
}

void FindValidIPs(string mangledIp, set<string>& validIPs)
{
    // this question is about spreading 3 '.' in a string with the following rules
    // - a '.' cannot be next to another '.'
    // - each seperated substring should be less then 256
    // - each seperated string should be at least a digit

    size_t length = mangledIp.size();

    for (int firstDot = 1; firstDot <= 3; firstDot++)
    {
        vector<string> IPStrings;
        IPStrings.push_back(mangledIp.substr(0, firstDot));

        for (int lastDot = 1; lastDot <= 3; lastDot++)
        {
            if (length - firstDot - lastDot < 2) continue;

            IPStrings.push_back(mangledIp.substr(length - lastDot, lastDot));

            for (int middleDot = 1; middleDot <= 3; middleDot++)
            {
                if (length - lastDot - firstDot - middleDot <= 0) continue;

                IPStrings.push_back(mangledIp.substr(firstDot, middleDot));

                IPStrings.push_back(mangledIp.substr(firstDot + middleDot, length - lastDot - firstDot - middleDot));
                
                if (isValid(IPStrings))
                {
                    stringstream ss;

                    ss << IPStrings[0] << "." << IPStrings[2] << "." << IPStrings[3] << "." << IPStrings[1];

                    validIPs.insert(ss.str());

                    ss.str("");
                }

                IPStrings.pop_back();
                IPStrings.pop_back();
            }
            IPStrings.pop_back();
        }
        IPStrings.pop_back();
    }


}

int main()
{
    map<string, set<string>> testCases;
    testCases["19216811"] = {
        "192.168.1.1",
        "192.16.81.1",
        "192.16.8.11",
        "192.1.68.11",
        "19.216.8.11",
        "19.216.81.1",
        "19.21.68.11",
        "19.2.168.11",
        "1.92.168.11",
    };

    for each(auto var in testCases)
    {
        set<string> validIPs;
        FindValidIPs(var.first, validIPs);

        for each(auto ip in var.second)
        {
            if (validIPs.find(ip) == validIPs.end()) throw;
        }
    }

    return 0;
}

