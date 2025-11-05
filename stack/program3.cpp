#include <iostream>
#include <stack>
using namespace std;

bool paranthesisBalance(string s)
{
    stack<char> sp;
    int size = s.length();

    for (int i = 0; i < size; i++)
    {
        char c = s[i];
        if (c == '[' || c == '{' || c == '(')
        {
            sp.push(c);
        }
        else
        {
            if (sp.empty())
            {
                return false;
            }
            char topp = sp.top();
            sp.pop();
            if (c == ']' && topp != '[')
                return false;
            if (c == '}' && topp != '{')
                return false;
            if (c == ')' && topp != '(')
                return false;
        }
    }

    return sp.empty();
}

int charToDigit(char c)
{
    return c - '0';
}

float calc(float n1, float n2, string op)
{

    if (op == "+")
    {
        return n1 + n2;
    }
    if (op == "-")
    {
        return n1 - n2;
    }
    if (op == "*")
    {
        return n1 * n2;
    }
    if (op == "/")
    {
        return n1 / n2;
    }
    return -1;
}

float postfixEval(string s[],int size)
{
    stack<float> sp;

    for (int i = 0; i < size; i++)
    {
        string st = s[i];
        if (st == "+" || st == "-" || st == "*" || st == "/")
        {
            float top1 = sp.top();
            sp.pop();
            float top2 = sp.top();
            sp.pop();
            float ans = calc(top2, top1, st);
            sp.push(ans);
        }
        else
        {
            sp.push(stof(st));
        }
    }
    return sp.top();
}

float prefixEval(string s[],int size){
    stack<float> sp;

    for(int i=size-1;i>=0;i--){
        string c = s[i];
        if(c == "+" || c == "-" || c == "*" || c == "/"){
            float top1 = sp.top();
            sp.pop();
            float top2 = sp.top();
            sp.pop();

            float ans = calc(top1,top2,c);
            sp.push(ans);
        }
        else{
            sp.push(stof(c));
        }
    }
    return sp.top();
}

string infixToPostfix(string s[],int size){
    string postfix = "";
    stack<string> sp;

    for(int i=0;i<size;i++){
        string c = s[i];
        
        if(c == "+" || c == "-"){
            while(!sp.empty()){
                string topp = sp.top();
                if(topp == "+" || topp == "-" || topp == "*" || topp == "/"){
                    postfix += topp;
                    sp.pop();
                }
                else{
                    break;
                }
            }
            sp.push(c);
        }
        else if(c == "*" || c == "/"){
            while(!sp.empty()){
                string topp = sp.top();
                if(topp == "*" || topp == "/"){
                    postfix += topp;
                    sp.pop();
                }
                else{
                    break;
                }
            }
            sp.push(c);
        }
        else{
            postfix += c;
        }
    }

    while(!sp.empty()){
        postfix += sp.top();
        sp.pop();
    }
    return postfix;
}

string infixToPrefix(string s[],int size){
    
}

// infix, postfix, prefix
// evaluate postfix and prefix expression

int main()
{
    string s = "[()()]";
    cout << paranthesisBalance(s) << endl;

    string exp[] = {"2", "11.1", "4","*","+"};
    int expSize = sizeof(exp) / sizeof(exp[0]);

    cout << postfixEval(exp,expSize) << endl;

    string exp2[] = {"+","2","*","3","4"};
    int exp2Size = sizeof(exp) / sizeof(exp[0]);


    cout<<prefixEval(exp2,exp2Size)<<endl;

    string exp3[] = {"2", "+", "3", "*", "4", "-", "1", "/", "5", "+", "6", "*", "2"};
    cout<<infixToPostfix(exp3,13)<<endl;
    return 0;
}


