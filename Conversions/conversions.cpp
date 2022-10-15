#include <bits/stdc++.h>
using namespace std;

//--------------------------------
int binToDeci(int n)
{
    int count = (log10(n) + 1);
    int deci = 0;

    for (int i = 0; i < count; i++)
    {
        deci += (n % 10) * (pow(2, i));
        n = n / 10;
    }
    return deci;
}

//--------------------------------
void deciToBin(int n)
{
    string bin = n == 0 ? "0" : "";

    while (n > 0)
    {
        bin += to_string(n % 2);
        n /= 2;
    }

    for (int i = bin.length(); i >= 0; i--)
        cout << bin[i];
}

//--------------------------------
void deciToOctal(int n)
{
    string oct = n == 0 ? "0" : "";

    while (n > 0)
    {
        cout << "oct: " << oct << endl;
        oct += to_string(n % 8);
        n /= 8;
    }

    for (int i = oct.length(); i >= 0; i--)
        cout << oct[i];
}

//--------------------------------
int hexaToDeci(string n)
{
    int deci = 0;
    for (int i = 0; i < n.length(); i++)
    {
        if (n[i] >= '0' && n[i] <= '9')
            deci += (n[i] - '0') * pow(16, (n.length() - 1) - i); // here eg: '4'-'0' = 4
        else if (n[i] >= 'A' && n[i] <= 'F')
            deci += ((n[i] - 'A') + 10) * pow(16, (n.length() - 1) - i); // here ascii subtraction eg: 'F'- 'A' gives us: 5 + 10 = 15
    }

    return deci;
}

//--------------------------------

void deciToHexa(int n)
{
    string hexa = n == 0 ? "0" : "";
    char a;
    while (n > 0)
    {
        if (n % 16 <= 9)
            hexa += to_string(n % 16);
        else
        {
            a = 'A' + (n % 16) - 10; // converting 10 to 'A'
            hexa += a;
        }
        n /= 16;
    }

    for (int i = hexa.length(); i >= 0; i--)
        cout << hexa[i];
}

//--------------------------------
int main()
{

    return 0;
}