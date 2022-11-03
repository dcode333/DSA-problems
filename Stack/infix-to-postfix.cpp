#include <bits/stdc++.h>
using namespace std;

// if operand : print
// if '(' :     push
// if ')' : pop until ')' is found and pop ')' as well
// if operator: pop while (current scanning operator precedence <= operator at stack top precedence)  => push current

int precedence(char c)
{
    switch (c)
    {
    case '^':
        return 3;
    case '/':
    case '*':
        return 2;
    case '-':
    case '+':
        return 1;

    default:
        return -1;
    }
}

void infixToPostfix(string s)
{
    stack<char> stk;
    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] >= 'a' && s[i] <= 'z')
            cout << s[i] << " ";
        else if (s[i] == '(')
            stk.push(s[i]);
        else if (s[i] == ')')
        {
            while (!stk.empty() && stk.top() != '(')
            {
                cout << stk.top() << " ";
                stk.pop();
            }
            if (!stk.empty())
                stk.pop();
        }
        else
        {
            while (!stk.empty() && (precedence(stk.top()) >= precedence(s[i])))
            {
                cout << stk.top();
                stk.pop();
            }
            stk.push(s[i]);
        }
    }
    while (!stk.empty())
    {
        cout << stk.top();
        stk.pop();
    }
}

int main()
{

    infixToPostfix("(a-b/c)*(a/k-l)");

    return 0;
}
