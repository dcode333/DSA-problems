#include <bits/stdc++.h>
using namespace std;

int postFixEvaluation(string exp)
{
    stack<int> s;
    int fst;
    int sec;

    for (int i = 0; i < exp.length(); i++)
    {
        if (exp[i] >= '0' && exp[i] <= '9')
            s.push(exp[i] - '0');
        else if (exp[i] == '+' || exp[i] == '-' || exp[i] == '/' || exp[i] == '*')
        {
            sec = s.top();
            s.pop();
            fst = s.top();
            s.pop();
            switch (exp[i])
            {
            case '+':
                s.push(fst + sec);
                break;
            case '-':
                s.push(fst - sec);
                break;
            case '/':
                s.push(fst / sec);
                break;
            case '*':
                s.push(fst * sec);
                break;
            case '^':
                s.push(pow(fst, sec));
                break;
            }
        }
    }
    return s.top();
}

int main()
{

    cout << postFixEvaluation("46+2/5*7+"); // 32

    return 0;
}
