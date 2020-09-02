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
class LinkedQueue
{
    public:
        struct node<t> *Front,*Rear;
    LinkedQueue()
    {
        Front=NULL;
        Rear=NULL;
    }
    ~LinkedQueue()
    {
         if (this->isEmpty())
            return;
    struct node<t> *ptr, *temp = Front;
    while (temp != NULL)
        {
            ptr = temp->ptr;
            delete temp;
            temp = ptr;
        }
    Front = Rear = NULL;
    }
      bool isEmpty()
    {
        return (Front == NULL || Rear == NULL);
    }
    void enque(t n)
    {
         node<t> *temp=new node<t>();
        temp->data=n;
        if(this->isEmpty())
        {
            Front=Rear=temp;
            temp->ptr=NULL;

        }
        else
        {
            Rear->ptr=temp;
            temp->ptr=NULL;
            Rear=temp;

        }
        cout<<"\nElement inserted";

    }
     void display()
    {
         if (this->isEmpty())
         {
            cout << "\nQueue is empty...\n";
            return;
         }
        node<t> *temp=new node<t>();
        temp=Front;
        cout << "\nQueue: ";
        while (temp->ptr != NULL)
        {
            cout << temp->data << " -> ";
            temp = temp->ptr;
        }
        cout << temp->data << endl;
        return;
    }
     void dequeue()
    {
       node<t> *temp=new node<t>();
        if(this->isEmpty())
        {
            cout<<"\nQueue is already empty";
        }
        else
        {
            temp=Front;
            Front=temp->ptr;
            temp->ptr=NULL;
            cout<<"\nDeleting :"<<temp->data;
            delete temp;

        }
        cout<<"\nElement deleted";

    }
     void Clear()
    {
         if (this->isEmpty())
            cout<<"\nQueue is already empty ";
    struct node<t> *ptr, *temp = Front;
    while (temp != NULL)
        {
            ptr = temp->ptr;
            delete temp;
            temp = ptr;
        }
        Front=NULL;
        Rear=NULL;
    cout<<"\nQueue has been cleared ";

    }
};



int main()
{
    int ele,choice;
  LinkedQueue<int> list;
  do
  {
    cout << "\n\tQueue operations using Linked list\n"
         << "\t===================================\n"
         << "  (1) Insert/Enqueue\t(2) Delete/Dequeue       \t(3) Display\t(4) Clear\t(5) Exit\n";


    cout << "Enter Choice: ";
    cin >> choice;
    switch (choice)
    {
    case 1: cout<<"\nEnter the value to be inserted in the Queue : ";
            cin>>ele;
            list.enque(ele);
            break;
    case 2: list.dequeue();
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

