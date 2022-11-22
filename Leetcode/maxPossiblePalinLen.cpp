#include <bits/stdc++.h>
using namespace std;

int main()
{
    // Failed testCase
    vector<string> words = {"jo", "jj", "ro", "jr", "mm", "gr", "dd", "qq", "bb", "gr", "oj", "gr", "rj", "oj", "rj", "or", "gr", "or", "gj", "jr", "aa", "rg", "jr", "oo", "rg", "jg", "ro", "gj", "rg", "cc", "jo", "or", "og", "pp", "jo", "uu", "tt", "or", "jo", "hh", "vv", "gj", "ro", "jo", "ro", "jg", "gj", "jg", "ii", "ww", "gj", "yy", "jr", "go", "qq", "gr", "jr", "pp", "xx", "qq", "mm", "oj", "dd", "or", "go", "jr", "gr", "rg", "gj", "rj", "jr", "mm", "jj", "qq", "rj", "jg", "rg", "jr", "go", "rj", "pp", "rj", "og", "oj", "oo", "uu", "go", "gg", "nn", "gj", "ee", "oj", "ww", "ro", "vv", "zz", "jo", "aa", "ff", "rg", "oj", "go", "uu", "ss", "aa", "ro", "vv", "bb", "gr", "jo", "og", "ss", "oo", "or", "og", "vv", "jr", "oj", "gg", "kk", "oj", "qq", "rj", "jg", "or", "og", "jg", "ro", "ll", "jo", "ro", "vv", "mm", "jg", "jo", "gr", "rg", "og", "jo", "gj", "qq", "rg", "jg", "tt", "og", "rj", "rr", "tt", "rg", "jo", "jr", "jo", "jr", "or", "jr", "nn", "rr", "gg", "og", "rg", "rj", "xx", "jo", "jo", "bb", "zz", "gr", "or", "xx", "rg", "ss", "or", "jr", "aa", "or", "jg", "rg", "go", "oj", "gj", "vv", "oj", "og", "rg", "ro", "rj", "jo", "go", "pp", "aa", "go", "jo", "gr", "go", "aa", "rj", "aa", "xx", "gj", "ss", "gj", "gj", "yy", "jg", "go", "jj", "yy", "cc", "ii", "dd", "jo", "go", "jj", "tt", "nn", "jr", "oj", "gj", "jo", "go", "go", "gj", "gr", "gg", "oj", "ro", "or", "nn", "mm", "og", "og", "ww", "mm", "go", "ff", "hh", "gr", "pp", "jg", "jr", "rr", "go", "ww", "jr", "nn", "rj", "cc", "gg", "dd", "jr", "vv", "oo", "oj", "gr", "jg", "go", "ff", "og", "nn", "hh", "gr", "ro", "ww", "ff", "pp", "or", "cc", "jr", "ww", "oo", "rg", "ss", "oo", "ss", "gj", "gg", "ll", "gr", "aa", "pp", "rj", "jg", "vv", "oj", "zz", "og", "ro", "dd", "og", "or", "jg", "oj", "yy", "gr", "cc", "oj", "or", "pp", "jo", "ll", "bb", "rr", "rg", "rj", "gj", "gr", "ff", "ro", "ee", "ll", "ss", "rg", "vv", "nn", "aa", "ww", "aa", "or", "zz", "jr", "og", "oj", "or", "gj", "rj", "gr", "rj", "ss", "jj", "yy", "zz", "jj", "go", "ll", "og", "yy", "oj", "rg", "xx", "jo", "jo", "or", "jg", "jj", "nn", "go", "jr", "rj", "ss", "og", "oj", "ww", "ll", "og", "cc", "or", "gr", "jg", "zz", "rr", "rg", "go", "gr", "jr", "uu", "tt", "rj", "oj", "go", "jo", "jg", "og", "cc", "vv", "ll", "rg"};

    pair<string, int> myPair = {"0", 0};
    vector<pair<string, int>> storeDiffLetters(300, myPair);
    vector<pair<string, int>> storeSameLetters(300, myPair);
    vector<pair<string, int>> maxMiddle(300, myPair);
    string maxPalin = "";
    int index, maxMiddleIndex = INT_MIN;
    string middleSame;

    for (int i = 0; i < words.size(); i++)
    {
        if (words[i][0] == words[i][1])
        {
            index = words[i][0] + words[i][1];
            maxMiddle[index].second++;
            maxMiddle[index].first = words[i];
        }
    }

    for (int i = 0; i < maxMiddle.size(); i++)
    {
        if (maxMiddle[i].second > maxMiddleIndex && maxMiddle[i].second % 2 != 0)
        {
            maxMiddleIndex = maxMiddle[i].second;
            middleSame = maxMiddle[i].first;
        }
    }

    for (int i = 0; i < words.size(); i++)
    {
        index = words[i][0] + words[i][1];
        if (words[i][0] == words[i][1])
        {
            if (words[i] == middleSame)
                maxPalin += words[i];
            else if (storeSameLetters[index].first == "0")
            {
                storeSameLetters[index].first = words[i];
                storeSameLetters[index].second++;
            }
            else if (storeSameLetters[index].first != "0")
            {
                storeSameLetters[index].first += words[i];
                storeSameLetters[index].second++;
                if (storeSameLetters[index].second == 2)
                {
                    maxPalin += storeSameLetters[index].first;
                    storeSameLetters[index].first = "0";
                    storeSameLetters[index].second = 0;
                }
            }
        }

        else if (storeDiffLetters[index].first == "0") // case 1: when there is no string at storeDiffLetters current index
        {
            storeDiffLetters[index].first = words[i];
            storeDiffLetters[index].second++;
        }
        else if (storeDiffLetters[index].first == words[i]) // case 2: when storeDiffLetters[index] string = words[i] string
            storeDiffLetters[index].second++;
        else if (storeDiffLetters[index].first[0] == words[i][1] && storeDiffLetters[index].first[1] == words[i][0])
        {

            maxPalin += (storeDiffLetters[index].first + words[i]);
            storeDiffLetters[index].second--;
            if (storeDiffLetters[index].second == 0)
                storeDiffLetters[index].first = "0";
        }
    }

    // cout << maxPalin << " : " << maxPalin.size();
    cout << maxPalin.length();

    return 0;
    
}
