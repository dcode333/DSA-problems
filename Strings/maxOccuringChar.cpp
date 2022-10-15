#include <bits/stdc++.h>
using namespace std;
/// highest occuring in an array login big o of n
int main()
{
    string str = "aoaomaodd";
    int charCount[26] = {0};
    char HighestOccuring;
    int maxChar = INT_MIN;

    // O(n) approach

    for (int i = 0; i < str.length(); i++)
        charCount[str[i] - 'a']++;

    for (int i = 0; i < 26; i++)
    {
        if (charCount[i] > maxChar)
            HighestOccuring = 'a' + i;
        maxChar = max(maxChar, charCount[i]);
    }

    cout << HighestOccuring << " : " << maxChar;

    // nlogn approach
    // sort(str.begin(), str.end());
    // int maxChar = 0;
    // int maxOccuringCount = INT_MIN;
    // char maxOccuruingChar;

    // for (int i = 0; i < str.length(); i++)
    // {
    //     if (str[i] == str[i + 1])
    //     {
    //         maxChar++;
    //         maxOccuringCount = max(maxChar, maxOccuringCount);
    //     }
    //     else
    //     {
    //         if (maxChar == maxOccuringCount)
    //             maxOccuruingChar = str[i];
    //         maxChar = 0;
    //     }
    // }

    // cout << maxOccuringCount + 1 << maxOccuruingChar;

    return 0;
}