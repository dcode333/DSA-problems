#include <bits/stdc++.h>
using namespace std;

//                     (Algorithm)
// (push Call stack)
// => store first char of string (i.e in fst)
// => call again for rest of the string
//  (pop call stack)
//  compare the fst with substr[0]
//            if(equal) return substr
//            else return fst+substr

string remDups(string s)
{
    if (s.length() == 0)
        return s;

    char fst = s[0];
    string sub = remDups(s.substr(1));

    if (fst == sub[0])
        return sub;

    return fst + sub;
}

int main()
{
    int a[6] = {10, 4, 4, 10, 4, 6};

    cout << remDups("aabbddss");

    return 0;
}