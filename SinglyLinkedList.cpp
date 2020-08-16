#include <iostream>
#include<conio.h>
using namespace std;
struct node
{
    int data;
    node *ptr;

};
struct node *head,*tail;
class SinglyLinkedList
{
    public:
    SinglyLinkedList()
    {
        head=NULL;
        tail=NULL;
    }
    ~SinglyLinkedList()
    {
         if (this->isEmpty())
            return;
    struct node *ptr, *temp = head;
    while (temp != NULL)
        {
            ptr = temp->ptr;
            delete temp;
            temp = ptr;
        }
    head = tail = NULL;
    }
      bool isEmpty()
    {
        return (head == NULL || tail == NULL);
    }
    void Insertbegin()
    {
        node *temp=new node();
        cout<<"Enter data :";
        cin>>temp->data;
        temp->ptr=NULL;
        if(this->isEmpty())
        {
            head=tail=temp;
            temp->ptr=NULL;

        }
        else
        {
            temp->ptr=head;
            head=temp;

        }
        cout<<"Element inserted";
    }
    void Insertend()
    {
         node *temp=new node();
        cout<<"Enter data :";
        cin>>temp->data;
        if(this->isEmpty())
        {
            head=tail=temp;
            temp->ptr=NULL;

        }
        else
        {
            tail->ptr=temp;
            temp->ptr=NULL;
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
        struct node *temp = head;
        cout << "\nList: ";
        while (temp->ptr != NULL)
        {
            cout << temp->data << " -> ";
            temp = temp->ptr;
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

            node *temp=new node();
            temp=head;
            for(int i=0;i<n-2&&temp!=NULL;i++)
                temp=temp->ptr;
            if(temp==NULL)
                {
                    cout<<"Invalid location :";
                    return;
                }
            if(temp==tail)
            {
                Insertend();
            }
            node *temp1=new node();
            cout<<"Enter data :";
            cin>>temp1->data;
            temp1->ptr=temp->ptr;
            temp->ptr=temp1;
            if(temp==tail)
            {
                tail=temp1;
            }

        }
        cout<<"Element inserted";
    }
    void deletebegin()
    {
        node *temp=new node();
        if(this->isEmpty())
        {
            cout<<"List is already empty";
        }
        else
        {
            temp=head;
            head=temp->ptr;
            temp->ptr=NULL;
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
         else
         {
              node *temp=new node();
              temp=head;
              while (temp->ptr!=tail)
              {
                  temp = temp->ptr;
              }
              node *d=new node();
              d=tail;
              tail=temp;
              tail->ptr=NULL;
              delete d;
         }
         cout<<"Element deleted";



    }
    void deleteloc(int n)
    {
        if(n==1)
            deletebegin();
        else
        {

            node *temp=new node();
            temp=head;
            for(int i=0;i<n-2&&temp!=NULL;i++)
                temp=temp->ptr;
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
            node *temp1=new node();

            temp1=temp->ptr;
            temp->ptr=temp1->ptr;
            temp1->ptr=NULL;
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
        struct node *temp = head;
        int n,c=1;
        cout<<"Enter data to be searched :";
        cin>>n;
        while (temp->ptr != NULL)
        {
           c++;
            temp = temp->ptr;
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
        struct node *temp = head;
        int c=1;
        while (temp->ptr != NULL)
        {

            temp = temp->ptr;
            c++;
        }
        cout << "Length of list :"<<c;
        return;
    }
      void Reverse()
    {
        // Initialize current, previous and
        // next pointers
        node* current = head;
        node *prev = NULL, *next = NULL;

        while (current != NULL) {
            // Store next
            next = current->ptr;

            // Reverse current node's pointer
            current->ptr = prev;

            // Move pointers one position ahead.
            prev = current;
            current = next;
        }
        head = prev;
    }

};

int main()
{
    int info, ele, choice, loc, count;
  SinglyLinkedList list;
  do
  {
    cout << "\n\tSingly Linked List\n"
         << "===================================\n"
         << "  (1) Search an element              (2) Insert at Front\n"
         << "  (3) Insert at Back                 (4) Insert at Location\n"
         << "  (5) Delete from Front              (6) Delete from Back\n"
         << "  (7) Delete at Location             (8) Display the list\n"
         << "  (9) Count number of elements       (10) Reverse the list\n";

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
