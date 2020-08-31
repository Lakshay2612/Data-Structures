#include<iostream>
#include<conio.h>
using namespace std;
class Stack
{
    int array[40];
    int top;
public:
    Stack()
    {
        top=-1;
    }
    void push(int i)
    {
        if(top==19)
        {
            cout<<"Stack Full\n";
        }
        else
        {
        array[++top]=i;
        }
    }
    int pop()
    {
        int n;
        if(top==-1)
        {
            cout<<"Stack Empty\n";

        }
        else
        {

            n=array[top--];
        }
    return n;
    }

};
int main()
{

    int i=0,x,a,b;
    double c;
    char exp[20];
    Stack s1;
    cout <<"Enter a valid postfix expression\n";
    cin>>exp;
    while(exp[i]!='\0')
    {
        if (exp[i]>='0'&& exp[i]<='9')
        {
            x=exp[i]-48;
            s1.push(x);
        }
        else if(exp[i]=='+'||exp[i]=='-'||exp[i]=='/'||exp[i]=='*')
        {
            a=s1.pop();
            b=s1.pop();
            switch(exp[i])
            {
            case '+':
                c=a+b;
                s1.push(c);
                break;
            case'-':
                c=b-a;

                s1.push(c);
                break;
            case'*':
                c=b*a;

                s1.push(c);
                break;
            case'/':
                c=b/a;

                s1.push(c);
                break;

                }
        }
        i++;
    }
    cout<<"Answer= "<<s1.pop()<<endl;
    return 0;
}
