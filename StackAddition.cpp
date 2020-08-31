#include <iostream>
#include<conio.h>
using namespace std;

struct node
{
    int data;
    node *ptr;

};

class StackAddition
{
    public:
        struct node   *top,*tail;
    StackAddition()
    {
        top=NULL;
        tail=NULL;
    }
    ~StackAddition()
    {
         if (this->isEmpty())
            return;
    struct node   *ptr, *temp = top;
    while (temp != NULL)
        {
            ptr = temp->ptr;
            delete temp;
            temp = ptr;
        }
    top = tail = NULL;
    }
      bool isEmpty()
    {
        return (top == NULL || tail == NULL);
    }
    void push(int n)
    {

        node   *temp=new node  ();
        temp->data=n;
        temp->ptr=NULL;
        if(this->isEmpty())
        {
            top=tail=temp;
            temp->ptr=NULL;

        }
        else
        {
            temp->ptr=top;
            top=temp;

        }

    }

    void display()
    {
         if (this->isEmpty())
         {
            cout << "\nList is empty...\n";
            return;
         }
        node   *temp=new node  ();
        temp=top;
        cout << "\nAddition is: ";
        while (temp->ptr != NULL)
        {
            cout << temp->data ;
            temp = temp->ptr;
        }
        cout << temp->data << endl;
        return;
    }

};

int main()
{
        StackAddition s1,s2,s3;
        char n1[60],n2[60];
        cout<<"\nNOTE: Number of digits of both the numbers must be same";
        cout<<"\nEnter first number : ";
        cin>>n1;
       int a;

        for(int i=0;n1[i]!='\0';i++)
        {
            a=n1[i]-48;


            s1.push(a);
        }

        cout<<"\nEnter second number : ";
        cin>>n2;
       int b;

        for(int i=0;n1[i]!='\0';i++)
        {
            b=n2[i]-48;


            s2.push(b);
        }

        cout<<"\Adding";
        node   *temp1=new node  ();
        node   *temp2=new node  ();
        temp1=s1.top;
        temp2=s2.top;
        int add=0,c=0;
        while(temp1!=NULL&&temp2!=NULL)
        {
            int x=temp1->data;
            int y=temp2->data;
            add=x+y+c;
            if(add>=10)
            {
                c=1;
                int m=add%10;
                s3.push(m);
            }
            else
            {
                s3.push(add);
                c=0;
            }
            temp1=temp1->ptr;
            temp2=temp2->ptr;

        }
        s3.push(c);
        s3.display();

}
