#include <iostream>
#include<conio.h>
using namespace std;
template <typename t>
struct node
{
    t data;
    node<t> *ptr;

};
template <typename t>
class LinkedStack
{
    public:
        struct node<t> *top,*tail;
    LinkedStack()
    {
        top=NULL;
        tail=NULL;
    }
    ~LinkedStack()
    {
         if (this->isEmpty())
            return;
    struct node<t> *ptr, *temp = top;
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
    void push(t n)
    {
        node<t> *temp=new node<t>();
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
        cout<<"\nElement pushed";
    }
    void pop()
    {
         node<t> *temp=new node<t>();
        if(this->isEmpty())
        {
            cout<<"List is already empty";
        }
        else
        {
            temp=top;
            top=temp->ptr;
            temp->ptr=NULL;
            cout<<"\nPopping : "<<temp->data;
            delete temp;

        }


    }
    void display()
    {
         if (this->isEmpty())
         {
            cout << "\nList is empty...\n";
            return;
         }
        node<t> *temp=new node<t>();
        temp=top;
        cout << "\nStack: ";
        while (temp->ptr != NULL)
        {
            cout <<"\n "<< temp->data << "\n ^ ";
            temp = temp->ptr;
        }
        cout <<"\n "<< temp->data << endl;
        return;
    }
    void Clear()
    {
         if (this->isEmpty())
            cout<<"\nStack is already empty ";
    struct node<t> *ptr, *temp = top;
    while (temp != NULL)
        {
            ptr = temp->ptr;
            delete temp;
            temp = ptr;
        }
    top = tail = NULL;
    cout<<"\nStack has been cleared ";

    }
};


int main()
{
    int ele,choice;
  LinkedStack<int> list;
  do
  {
    cout << "\n\tStack operations using Linked list\n"
         << "\t===================================\n"
         << "  (1) Push\t(2) Pop       \t(3) Display\t(4) Clear\t(5) Exit\n";


    cout << "Enter Choice: ";
    cin >> choice;
    switch (choice)
    {
    case 1: cout<<"Enter the value to be pushed : ";
            cin>>ele;
            list.push(ele);
            break;
    case 2: list.pop();
            break;
    case 3: list.display();
            break;
    case 4: list.Clear();
            break;
    case 5: exit(0);
            break;

    default:cout<<"Please enter a valid choice";
    }
    } while (choice != 0);
    return 0;
}

