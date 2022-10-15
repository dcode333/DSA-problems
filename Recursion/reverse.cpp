// Online C++ compiler to run C++ program online
#include <iostream>
#include <bits/stdc++.h>
using namespace std;

void strRev(string s)
{

  if (s.length() == 0)
    return;

  strRev(s.substr(1));
  cout << s[0];
}

int main()
{

  strRev("binod");

  return 0;
}