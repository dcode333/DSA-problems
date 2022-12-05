#include <bits/stdc++.h>
using namespace std;

int main()
{
  string s = "PWWnKEW";
  vector<int> store(256, -1);
  int i = 0;
  int ch, counter = 0;
  int maxLen = INT_MIN;
  while (i != s.size())
  {
    ch = s[i];

    if (store[ch] == -1)
    {
      counter++;
      store[ch] = i;
    }
    else
    {
      i = store[ch];
      store[ch] = -1;
      counter = 0;
    }

    maxLen = max(maxLen, counter);
    i++;
  }

  cout << maxLen;

  return 0;
}
