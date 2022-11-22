#include <bits/stdc++.h>
using namespace std;

int main()
{
    string s = "abbbbvccCbvDd";
    pair<char, int> myPair = {'0', 0};
    vector<pair<char, int>> findMaxOdd(150, myPair);
    vector<int> store(150, 0);
    string maxPalindrome = "";
    char maxOdd;
    int maxOddCounter = INT_MIN;
    int index;

    for (int i = 0; i < s.size(); i++)
    {
        index = s[i];
        findMaxOdd[index].second++;
        findMaxOdd[index].first = s[i];
    }

    for (int i = 0; i < findMaxOdd.size(); i++)
    {

        if (findMaxOdd[i].second > maxOddCounter && findMaxOdd[i].second % 2 != 0)
        {
            maxOddCounter = findMaxOdd[i].second;
            maxOdd = findMaxOdd[i].first;
        }
    }



    for (int i = 0; i < s.size(); i++)
    {
        index = s[i];

        if (s[i] == maxOdd)
            maxPalindrome += s[i];
        else if (store[index] == 0)
            store[index]++;
        else if (store[index] == 1)
        {
            maxPalindrome += s[i];
            maxPalindrome += s[i];
            store[index] = 0;
        }
    }
    cout << maxPalindrome;

    return 0;
}