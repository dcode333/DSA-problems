#include <bits/stdc++.h>
using namespace std;

int preFixEvaluation(string exp)
{
    stack<int> s;
    int fst;
    int sec;

    for (int i = exp.length() - 1; i >= 0; i--)
    {
        if (exp[i] >= '0' && exp[i] <= '9')
            s.push(exp[i] - '0');
        else if (exp[i] == '+' || exp[i] == '-' || exp[i] == '/' || exp[i] == '*' || exp[i] == '^')
        {
            fst = s.top();
            s.pop();
            sec = s.top();
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

    cout << preFixEvaluation("-+7*45+20"); // 25

    return 0;
}
