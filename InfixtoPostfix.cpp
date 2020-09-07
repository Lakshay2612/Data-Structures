#include<iostream>

using namespace std;
class stack
{
    char a[20];
    int top;
public:
    stack()
    {
        top=-1;
    }
    void push(char item)
    {
        if(top==19)
        {
            cout<<"Stack Full\n";
        }
        else
        {
        a[++top]=item;
        }
    }
    int AtTop()
    {
        char q;
        q=a[top];
        if(top==-1)
        {
            cout<<"Stack Empty\n";

        }
        return q;

    }
    void pop()
    {
        if(top==-1)
        {
            cout<<"Stack Empty\n";

        }
        else
        {
           top--;
        }
    }
    int empty()
    {

        if(top==-1)
        {
           return 0;
        }

    }
bool isOperator(char c)
{
    if(c=='+'||c=='-'||c=='*'||c=='/'||c=='^')
    {
      return true;
    }
    else
    {
        return false;
    }
}
bool isOperand(char b)
{
    if(b>='0'&&b<='9')
        return true;
    else if(b>='a'&&b<='z'||b>='A'&&b<='Z')
        return true;
    else
        return false;
}
int precedence(char op)
{
    if(op=='+'||op=='-')
        return 1;
    else if(op=='*'||op=='/')
        return 2;
    else if(op=='^')
        return 3;
    else
        return 0;
}
bool equate(char op1,char op2)
{
    int p1=precedence(op1);
    int p2=precedence(op2);
    if(p1==p2)
    {
        if(op1=='^')
            return false;
        else
            return true;
    }
    return (p1>p2? true :false);
}
string convert(string infix)
{
    stack s;
    string postfix="";
    char ch1;
    s.push('(');
    infix +=')';
    for(int i=0;i<infix.length();i++)
    {
        ch1=infix[i];
        if(ch1==' ')
            continue;
        else if(ch1=='(')
            s.push(ch1);
        else if(isOperand(ch1))
            postfix+=ch1;
        else if(isOperator(ch1))
        {
            int k=s.empty();
            char top1=s.AtTop();
            while(equate(top1,ch1))
            {
                postfix+=top1;
                s.pop();
                top1=s.AtTop();
            }
        s.push(ch1);
        }
        else if(ch1==')')
        {
            int k=s.empty();char top1=s.AtTop();
            while(top1!='(')
            {
                postfix+=top1;
                s.pop();
                top1=s.AtTop();
            }
            s.pop();

        }

    }
    return postfix;
}
};
int main()
{
    stack s;
    string a2,p;
    int ch;
    do
    {
        cout<<"\nEnter infix Expression\n";
        cin>>a2;
        p=s.convert(a2);
        cout<<"\nInfix :"<<a2;
        cout<<"\nPostfix :"<<p;
        cout<<"\nDo you want to continue\nEnter 0 to Exit";
        cin>>ch;

        }while(ch!=0);
    return 0;
}
