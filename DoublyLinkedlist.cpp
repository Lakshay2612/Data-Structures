#include <iostream>
#include<conio.h>
using namespace std;
template <typename t>
struct node
{
    t data;
    node<t> *next,*prev;

};
template <typename t>
class DoublyLinkedList
{
    public:
        struct node <t>*head,*tail;
      DoublyLinkedList()
    {
        head=NULL;
        tail=NULL;
    }
    ~DoublyLinkedList()
    {
         if (this->isEmpty())
            return;
    struct node<t>*next, *temp = head;
    while (temp != NULL)
        {
            next = temp->next;
            delete temp;
            temp = next;
        }
    }
      bool isEmpty()
    {
        return (head == NULL || tail == NULL);
    }
    void Insertbegin()
    {
        node<t> *temp=new node<t>();
        cout<<"Enter data :";
        cin>>temp->data;
        temp->next=NULL; temp->prev=NULL;
        if(this->isEmpty())
        {
            head=tail=temp;
            temp->next=NULL; temp->prev=NULL;

        }
        else
        {
            temp->next=head;
            head->prev=temp;
            head=temp;
        }
        cout<<"Element inserted";
    }
    void Insertend()
    {
        node<t> *temp=new node<t>();
        cout<<"Enter data :";
        cin>>temp->data;
        temp->next=NULL; temp->prev=NULL;
        if(this->isEmpty())
        {
            head=tail=temp;
            temp->next=NULL; temp->prev=NULL;

        }
        else
        {
            tail->next=temp;
            temp->prev=tail;
            tail=temp;
        }
        cout<<"Element inserted";
    }
    void display()
    {
         if (this->isEmpty())
         {
            cout << "\nList is empty...\n";
            return;
         }
        struct node<t> *temp = head;
        cout << "\nList: ";
        while (temp->next != NULL)
        {
            cout << temp->data << " -> ";
            temp = temp->next;
        }
        cout << temp->data << endl;
        return;
    }
    void Insertloc(int n)
    {
        if(n==1)
            Insertbegin();
        else
        {

            node<t> *temp=new node<t>();
            temp=head;
            for(int i=0;i<n-2&&temp!=NULL;i++)
                temp=temp->next;
            if(temp==NULL)
                {
                    cout<<"Invalid location :";
                    return;
                }
            else if(temp==tail)
            {
                Insertend();
            }
            else
            {
                node<t> *temp1=new node<t>();
                cout<<"Enter data :";
                cin>>temp1->data;
                temp1->prev=temp;
                temp1->next=temp->next;
                temp->next->prev=temp1;
                temp->next=temp1;
            }

        }
        cout<<"Element inserted";
    }
    void deletebegin()
    {
        node <t>*temp=new node<t>();
        if(this->isEmpty())
        {
            cout<<"List is already empty";
        }
        else if(head==tail)
        {
            node<t> *temp=new node<t>();

            temp=head;
            head=tail=NULL;
            delete temp;
        }
        else
        {
            temp=head;
            head->next->prev=NULL;
            head=temp->next;
            temp->next=NULL;
            temp->prev=NULL;
            delete temp;

        }
        cout<<"Element deleted";


    }
     void deleteend()
    {
         if(this->isEmpty())
        {
            cout<<"List is already empty";
        }
         else if(head==tail)
        {
            node <t>*temp=new node<t>();
            temp=head;
            head=tail=NULL;
            delete temp;
        }
         else
         {
              node <t>*temp=new node<t>();
              temp=tail;
              tail=tail->prev;
              tail->next=NULL;
              temp->prev=NULL;
              temp->prev=NULL;
              delete temp;
         }
         cout<<"Element deleted";

     }
     void deleteloc(int n)
    {
        if(n==1)
            deletebegin();
        else
        {

            node <t>*temp=new node<t>();
            temp=head;
            for(int i=0;i<n-2&&temp!=NULL;i++)
                temp=temp->next;
            if(temp==NULL)
                {
                    cout<<"Invalid location :";
                    return;
                }
            else if(temp->next==tail)
            {
                deleteend();
            }


            else
            {
                node<t> *temp1=new node<t>();
                temp1=temp->next;
                temp->next=temp1->next;
                temp1->next->prev=temp;
                temp1->prev=NULL;
              temp1->prev=NULL;
              delete temp1;
            }

        }
        cout<<"Element deleted";

    }
     void Search()
    {
         if (this->isEmpty())
         {
            cout << "\nList is empty...\n";
            return;
         }
         int flag=0;
        struct node <t>*temp = head;
        int n,c=1;
        cout<<"Enter data to be searched :";
        cin>>n;
        while (temp->next != NULL)
        {
           c++;
            temp = temp->next;
            if(temp->data==n)
            {
                cout<<"Data Found at location :"<<c;
                flag=1;
            }
        }
        if( temp->data ==n)
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
        struct node<t> *temp = head;
        int c=1;
        while (temp->next != NULL)
        {

            temp = temp->next;
            c++;
        }
        cout << "Length of list :"<<c;
        return;
    }
    void Reverse()
    {
        if (this->isEmpty())
         {
            cout << "\nList is empty...\n";
            return;
         }
         else
         {
             node<t> *temp=new node<t>();
             temp=tail;
             cout << "\nReversed List: ";
        while (temp->prev != NULL)
        {
            cout << temp->data << " -> ";
            temp = temp->prev;
        }
        cout << temp->data << endl;
        return;
         }
    }
};

int main()
{
    int info, ele, choice, loc, count;
  DoublyLinkedList<int> list;
  do
  {
    cout << "\n\tDoubly Linked List\n"
         << "===================================\n"
         << "  (1) Search an element               (2) Insert at Front\n"
         << "  (3) Insert at Back                  (4) Insert at Location\n"
         << "  (5) Delete from Front               (6) Delete from Back\n"
         << "  (7) Delete at Location              (8) Display the list\n"
         << "  (9) Count number of elements        (10) Reverse the list\n";

    cout << "Enter Choice: ";
    cin >> choice;
    switch (choice)
    {
    case 1:list.Search();
    break;

    case 2: list.Insertbegin();
    break;
    case 3:list.Insertend();
    break;
    case 4:int m;
        cout<<"Enter Location :";
        cin>>m;
        list.Insertloc(m);
    break;
    case 5:list.deletebegin();
    break;
    case 6:list.deleteend();
    break;

    case 8:list.display();
    break;
    case 7:int loc;
        cout<<"Enter location :";
        cin>>loc;
        list.deleteloc(loc);
    break;
    case 9:list.count();
    break;
    case 10:list.Reverse();
    break;
    default:cout<<"Please enter a valid choice";
    }
    } while (choice != 0);
    return 0;
}
