#include <iostream>

using namespace std;
struct node
{
    int data;
    node *ptr;
};
struct node *tail;
class CircularLinkedQueue
{
    public:
    CircularLinkedQueue()
    {
        tail=NULL;
    }
    ~CircularLinkedQueue()
    {
         if (this->isEmpty())
            return;
    struct node *ptr, *temp = tail->ptr;
    while (temp->ptr!=tail)
        {
            ptr = temp->ptr;
            delete temp;
            temp = ptr;
        }
    tail = NULL;
    }
      bool isEmpty()
    {
        return ( tail == NULL);
    }
     void enque()
    {
         node *temp=new node();
        cout<<"\nEnter data :";
        cin>>temp->data;
        temp->ptr=NULL;
        if(this->isEmpty())
        {
            tail=temp;
            temp->ptr=tail;
        }
        else
        {
            temp->ptr=tail->ptr;
            tail->ptr=temp;
            tail=temp;
        }
        cout<<"\nElement inserted";
    }
     void display()
    {
        if(this->isEmpty())
            cout<<"\nQueue is empty......";
        else
        {
            node *temp=new node;
            temp=tail->ptr;
            do
                {
                    cout<<temp->data<<"-> ";
                    temp=temp->ptr;
                }while(temp!=tail->ptr);


        }

    }
     void dequeue()
    {
        if(this->isEmpty())
        {
            cout<<"Queue is empty..";

        }
        else
        {
            node *temp=new node();
            temp=tail->ptr;
            tail->ptr=temp->ptr;
            cout<<"\n"<<temp->data<<" deleted";
            delete temp;
        }
    }
    void Clear()
    {
        if (this->isEmpty())
        {
            cout<<"\nQueue is already empty ";
            return;
        }
    struct node *ptr, *temp = tail->ptr;
    while (temp->ptr!=tail)
        {
            ptr = temp->ptr;
            delete temp;
            temp = ptr;
        }
    tail = NULL;
    cout<<"\nQueue has been cleared ";
    }
};
int main()
{
         int choice;
  CircularLinkedQueue ob;
  do
  {
    cout << "\n\tCircular Queue operations using Linked List\n"
         << "\t===================================\n"
         << "  (1) Insert/Enqueue\t(2) Delete/Dequeue    \t(3) Display\t(4) Clear\t(5) Exit\n";


    cout << "Enter Choice: ";
    cin >> choice;
    switch (choice)
    {
    case 1: ob.enque();
            break;
    case 2: ob.dequeue();
            break;
    case 3: ob.display();
            break;
    case 4: ob.Clear();
            break;
    case 5: exit(0);
            break;

    default:cout<<"Please enter a valid choice";
    }
    } while (choice != 0);
    return 0;
}
