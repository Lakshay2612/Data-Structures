#include <iostream>

using namespace std;
struct node
{
    int data;
    node *ptr;
};
node *head,*tail;
class OrderedList
{
    public:
    OrderedList()
    {
        head=NULL;
        tail=NULL;
    }
    ~OrderedList()
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
        return(head==NULL||tail==NULL);
    }
    void Insert()
    {
        node *temp=new node();
        cout<<"\nEnter data :";
        cin>>temp->data;
        temp->ptr=NULL;
        if(this->isEmpty())
        {
            head=tail=temp;

        }
        else if(temp->data>=head->data)
        {
            temp->ptr=head;
            head=temp;
        }
        else if(temp->data<=tail->data)
        {
            tail->ptr=temp;
            tail=temp;
        }
        else
        {
            node *temp1=head;
            while(temp1->ptr!=NULL)
            {
                if(temp1->ptr->data<=temp->data)
                {
                    temp->ptr=temp1->ptr;
                    temp1->ptr=temp;
                }

            }
        }
        cout<<"\nData inserted ";
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
    void deletenode()
    {
         if (this->isEmpty())
         {
            cout << "\nList is empty...\n";
            return;
         }
         int flag=0;
        struct node *temp = head;
        int n;
        cout<<"Enter data to be deleted :";
        cin>>n;
        if(head->data==n)
        {
            head=head->ptr;
            flag=1;
        }
        else if(tail->data==n)
        {
            node *temp1=new node();
              temp1=head;
              while (temp1->ptr!=tail)
              {
                  temp1 = temp1->ptr;
              }
              node *d=new node();
              d=tail;
              tail=temp1;
              tail->ptr=NULL;
              delete d;
              flag=1;
        }
        else if(head==tail&&head->data==n)
        {
            head=tail=NULL;
            flag=1;
        }
        else
        {
        while (temp->ptr != NULL)
        {


            if(temp->ptr->data==n)
            {
                temp->ptr=temp->ptr->ptr;
                flag=1;
            }
            temp = temp->ptr;
        }

        }
        if(flag==0)
            cout<<"Data can't be found";
        else
            cout<<"Data deleted";
    }

};
int main()
{
    OrderedList list;
    int ch;
    do
    {
        cout<<"\n==================ORDERED LINKED LIST=========================";
    cout<<"\n1. Insertion \n2.Deletion \n3.Display \n4.Exit\n\nEnter your choice : ";
    cin>>ch;
    if(ch==1)
        list.Insert();
    else if(ch==3)
            list.display();
    else if(ch==2)
        list.deletenode();

    else
        exit(0);
    }while(ch!=0);
    return 0;
}
