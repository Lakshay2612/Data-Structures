#include <iostream>

using namespace std;

struct node
{
    int data;
    node *next,*prev;

};
struct node *tail;
class DoublyCircularList
{
     public:
      DoublyCircularList()
    {

        tail=NULL;
    }
    ~DoublyCircularList()
    {
         if (this->isEmpty())
            return;
    struct node *next, *temp = tail->next;
    while (temp != NULL)
        {
            next = temp->next;
            delete temp;
            temp = next;
        }
    }
      bool isEmpty()
    {
        return ( tail == NULL);
    }

 void Insertbegin()
    {
        node *temp=new node();
        cout<<"Enter data :";
        cin>>temp->data;
        temp->next=NULL; temp->prev=NULL;
        if(this->isEmpty())
        {
            tail=temp;
            temp->next=temp; temp->prev=temp;

        }
        else
        {
            temp->next=tail->next;
            temp->prev=tail;
            tail->next=temp;
            tail->next->prev=temp;
            tail=temp;
        }
        cout<<"Element inserted";
    }
 void deletebegin()
 {
     if(this->isEmpty())
     {
         cout<<"\nAlready empty";

     }
     else if(tail->next==tail)
     {
         delete tail;
     }
     else if(tail->next==tail->prev)
     {
         node *temp=new node();
         temp=tail;
         tail->prev->next=tail->next;
         tail->next->prev=tail->prev;
         tail=tail->prev;
         temp->next=NULL;
         temp->prev=NULL;
         delete temp;

     }
     else
     {
          node *temp=new node();
          temp=tail;tail->prev->next=tail->next;
          tail->next->prev=tail->prev;
          tail=tail->prev;
          temp->next=NULL;
          temp->prev=NULL;
          delete temp;
     }

 }
  void display()
    {
        if(this->isEmpty())
            cout<<"\nList is empty......";
        else
        {
            node *temp=new node;
            temp=tail->next;

            while(temp->next!=tail)
            {
                cout<<temp->data<<"->";
                temp=temp->next;


            }
            cout<<tail->data;
        }
    }
    void Search()
    {
         if (this->isEmpty())
         {
            cout << "\nList is empty...\n";
            return;
         }
         int flag=0;
        struct node *temp = tail->next;
        int n,c=1;
        cout<<"Enter data to be searched :";
        cin>>n;
        while (temp->next!=tail)
        {
           c++;
            temp = temp->next;
            if(temp->data==n)
            {
                cout<<"Data Found at location :"<<c;
                flag=1;
            }
        }
        if( tail->data ==n)
        {
            cout<<"Data Found at location :"<<c;
            flag=1;
        }
        if(flag==0)
            cout<<"Data can't be found";
    }
    void count()
    {
        if (this->isEmpty())
         {
            cout << "\nList is empty...\n";
            return;
         }
        struct node *temp =tail->next;
        int c=2;
        while (temp->next!=tail)
        {

            temp = temp->next;
            c++;
        }
        cout << "Length of list :"<<c;
        return;
    }

};
int main()
{
      int info, ele, choice, loc, count;
  DoublyCircularList list;
  do
  {
    cout << "\n\tDoubly Linked List\n"
         << "===================================\n"
         << "  (1) Search an element\n "
         <<"   (2) Insert\n"
         << "  (3)Delete\n"
         <<"   (4)Display\n"
         <<"   (5)Count";


    cout << "Enter Choice: ";
    cin >> choice;
    switch (choice)
    {
    case 1:list.Search();
    break;

    case 2: list.Insertbegin();
    break;

    case 3:list.deletebegin();
    break;


    case 4:list.display();
    break;

    case 5:list.count();
    break;

    default:cout<<"Please enter a valid choice";
    }
    } while (choice != 0);
    return 0;
}
