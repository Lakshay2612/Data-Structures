#include <iostream>

using namespace std;
template <typename t>
struct node
{
    int data;
    node *ptr;
};
template <typename t>
class EnqueCostly
{
     public:
         int flag=0;
        struct node<t> *top,*tail;
    EnqueCostly()
    {
        top=NULL;
        tail=NULL;
    }
    ~EnqueCostly()
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

    }
    t pop()
    {
         node<t> *temp=new node<t>();
        if(this->isEmpty())
        {
            cout<<"\nQueue is already empty";this->flag=1;
        }
        else
        {
            temp=top;
            top=temp->ptr;
            temp->ptr=NULL;
            return temp->data;
            delete temp;

        }


    }
    void enque(EnqueCostly& s1,EnqueCostly& s2)
    {
        while(!s1.isEmpty())
        {
            t a=s1.pop();
            s2.push(a);
        }
        t n;
        cout<<"\nEnter the element to be inserted :";
        cin>>n;
        s1.push(n);
        while(!s2.isEmpty())
        {
            t a=s2.pop();
            s1.push(a);
        }
    }
    void dequeue(EnqueCostly& s1)
    {
        t a=s1.pop();
        if (s1.flag==0)
        cout<<"\nElement deleted :"<<a;
    }
    void show()
    {
        if (this->isEmpty())
         {
            cout << "\nQueue is empty...\n";
            return;
         }
        node<t> *temp=new node<t>();
        temp=top;
        cout << "\nQueue: ";
        while (temp->ptr != NULL)
        {
            cout << temp->data << "->";
            temp = temp->ptr;
        }
        cout << temp->data << endl;
        return;
    }
    void display(EnqueCostly& s1)
    {
        s1.show();
    }
};
int main()
{
    EnqueCostly<int> ob1,ob2,ob;
    int choice;
      do
    {
    cout << "\n\tQueue using stack (Enqueue costly)\n"
         << "\t===================================\n"
         << "  (1) Insert/Enqueue\t(2) Delete/Dequeue    \t(3) Display\t(4) Exit\n";


    cout << "Enter Choice: ";
    cin >> choice;
    switch (choice)
    {
    case 1: ob.enque(ob1,ob2);
            break;
    case 2: ob.dequeue(ob1);
            break;
    case 3: ob.display(ob1);
            break;

    case 4: exit(0);
            break;

    default:cout<<"Please enter a valid choice";
    }
    } while (choice != 0);
    return 0;
}
