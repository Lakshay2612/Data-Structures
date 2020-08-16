#include <iostream>

using namespace std;
struct node
{
    int data;
    node *ptr;
};

struct node *tail;
class CircularSinglyList
{
    public:
    CircularSinglyList()
    {
        tail=NULL;
    }
    ~CircularSinglyList()
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
    void Insertbegin()
    {
        node *temp=new node();
        cout<<"\nEnter data :";
        cin>>temp->data;
        temp->ptr=NULL;
        if(this->isEmpty())
        {
            tail=temp;
            tail->ptr=tail;
        }
        else
        {
            temp->ptr=tail->ptr;
            tail->ptr=temp;

        }
    }
    void Insertend()
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
    }
    void display()
    {
        if(this->isEmpty())
            cout<<"\nList is empty......";
        else
        {
            node *temp=new node;
            temp=tail->ptr;

            while(temp->ptr!=tail)
            {
                cout<<temp->data<<"->";
                temp=temp->ptr;


            }
            cout<<tail->data;
        }

    }
    void deletebegin()
    {
        if(this->isEmpty())
        {
            cout<<"List is empty..";

        }
        else
        {
            node *temp=new node();
            temp=tail->ptr;
            tail->ptr=temp->ptr;
            delete temp;
        }
    }
     void deleteend()
    {
        if(this->isEmpty())
        {
            cout<<"List is empty..";

        }
        else
        {
            node *temp=new node();
            temp=tail->ptr;
            while(temp->ptr!=tail)
            {
                temp=temp->ptr;

            }
            temp->ptr=tail->ptr;

            delete temp;
            tail=temp;
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
        struct node *temp = tail->ptr;
        int n,c=1;
        cout<<"Enter data to be searched :";
        cin>>n;
        while (temp->ptr!=tail)
        {
           c++;
            temp = temp->ptr;
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
        struct node *temp =tail->ptr;
        int c=2;
        while (temp->ptr!=tail)
        {

            temp = temp->ptr;
            c++;
        }
        cout << "Length of list :"<<c;
        return;
    }
};
int main()
{
     int info, ele, choice, loc, count;
  CircularSinglyList list;
  do
  {
    cout << "\n\tDoubly Linked List\n"
         << "===================================\n"
         << "  (1) Search an element               (2) Insert at Front\n"
         << "  (3) Insert at Back                  \n"
         << "  (4) Delete from Front               (5) Delete from Back\n"
         << "  (6) Display the list\n"
         << "  (7) Count number of elements    "    ;

    cout << "\nEnter Choice: ";
    cin >> choice;
    switch (choice)
    {
   case 1:list.Search();
   break;

    case 2: list.Insertbegin();
    break;
    case 3:list.Insertend();
    break;
     case 6:list.display();
    break;

    case 4:list.deletebegin();
    break;
    case 5:list.deleteend();
    break;


    case 7:list.count();
    break;

    default:cout<<"Please enter a valid choice";
    }
    } while (choice != 0);
    return 0;
}
