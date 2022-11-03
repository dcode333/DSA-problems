#include <bits/stdc++.h>
using namespace std;

/* isValid
Declare an empty stack.
Push an opening parenthesis on top of the stack.
In case of a closing bracket, check if the stack is empty.
If not, pop in a closing parenthesis if the top of the stack contains the corresponding opening parenthesis.
If the parentheses are valid,​ then the stack will be empty once the input string finishes.
*/
bool balancedParantheses(string s)
{
    stack<char> stk;
    int i = 0;

    if (s.size() % 2 != 0)
        return false;

    for (; i < s.size() / 2; i++)
        if (s[i] == '(' || s[i] == '{' || s[i] == '[')
            stk.push(s[i]);

    for (; i < s.size(); i++)
    {
        if (stk.top() == '(' && s[i] != ')')
            return false;
        if (stk.top() == '[' && s[i] != ']')
            return false;
        if (stk.top() == '{' && s[i] != '}')
            return false;
        stk.pop();
    }
    return true;
}
bool isValid(string s)
{
    stack<char> stk;

    if (s.size() % 2 != 0)
        return false;

    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] == '[' || s[i] == '{' || s[i] == '(')
            stk.push(s[i]);
        else
        {
            if (stk.empty())
                return false;

            else if ((s[i] == ']' && stk.top() == '[') || (s[i] == ')' && stk.top() == '(') || (s[i] == '}' && stk.top() == '{'))
                stk.pop();
            else
                return false;
        }
    }

    if (stk.empty())
        return true;

    return false;
}

int main()
{

    cout << balancedParantheses("{([])}");
    return 0;
}