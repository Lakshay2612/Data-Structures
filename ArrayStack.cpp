#include <iostream>
#include<conio.h>
using namespace std;
template <typename t>
class ArrayStack
{
    t Stack[30];
    int top;
    public:
        ArrayStack()
        {
            top=-1;
        }
        void push(t n)
        {
            if(top==29)
                cout<<"\nStack is already full";
            else
            {
                Stack[++top]=n;
                cout<<"\nElement pushed";
            }
        }
        void pop()
        {
            if(top==-1)
                cout<<"\nStack is already empty";
            else
            {
                cout<<"\nPopping "<<Stack[top];
                top--;
            }
        }
        void Clear()
        {
            if(top==-1)
                cout<<"\nStack is already empty";
            else
            {
                cout<<"\nClearing stack";
                top=-1;
            }
        }
        void Display()
        {
            if(top==-1)
                cout<<"\nStack is empty";
            else
            {
                cout<<"\nStack is =";
                for(int i=0;i<=top;i++)
                {
                    cout << Stack[i]<<"->";

                }

            }
        }

};
int main()
{
    int ele,choice;
  ArrayStack<int> list;
  do
  {
    cout << "\n\tStack operations using Linked list\n"
         << "\t===================================\n"
         << "  (1) Push\t(2) Pop\t      (3) Display\t(4) Clear\t(5) Exit\n";


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
    case 3: list.Display();
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

