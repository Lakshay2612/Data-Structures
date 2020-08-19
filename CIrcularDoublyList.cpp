#include<iostream>
#include<iomanip>

using namespace std;

//Node class
struct Node
{
    //data members
    int data;
    Node* next;
    Node* prev;

};

//Circular Doubly Linked List Class
class CirDoublyLinkedList
{
private:

    Node *head,*temp;
public:
    //constructor
    CirDoublyLinkedList()
    {

        head =NULL;
    }
    //destructor
    ~CirDoublyLinkedList()
    {
        system("CLS");
        temp = head;
        Node *nextNodePtr;
        cout<<"Destroying The List\n";
        while(temp->next != head)
        {
            nextNodePtr = temp->next;
            delete temp;
            temp = nextNodePtr;
        }
        delete temp;
        cout<<"\nDone.\n";
    }

    //member functions
    void search();
    void insertAtBegin();
    void insertAtEnd();
    void insertAtLoc();
    void deleteAtBegin();
    void deleteAtEnd();
    void deleteAtLoc();
    void display();
    bool isEmpty();
    void count()
    {
        if (this->isEmpty())
         {
            cout << "\nList is empty...\n";
            return;
         }
        struct Node *temp1 =head;
        int c=2;
        while (temp1->next!=head->prev)
        {

            temp1 = temp1->next;
            c++;
        }
        cout << "Length of list :"<<c;
        return;
    }
};

//search function
void CirDoublyLinkedList :: search()
{

         if (this->isEmpty())
         {
            cout << "\nList is empty...\n";
            return;
         }
         int flag=0;
        struct Node *temp1 = head;
        int n,c=1;
        cout<<"Enter data to be searched :";
        cin>>n;
        while (temp1->next!=head->prev)
        {
           c++;
            temp1 = temp1->next;
            if(temp1->data==n)
            {
                cout<<"Data Found at location :"<<c;
                flag=1;
            }
        }
        if( head->prev->data ==n)
        {
            cout<<"Data Found at location :"<<c;
            flag=1;
        }
        if(flag==0)
            cout<<"Data can't be found";
}

//insert the Node at the beginning of the List
void CirDoublyLinkedList :: insertAtBegin()
{
    //taking input from the user
    temp = new Node();
    cout<<"Enter the Data of New Node : ";
    cin>>temp->data;
    //inserting the node
    if(head == NULL)
    {
        head = temp;
        head->next = head;
        head->prev = head;
         temp=0;
    }
    else
    {
        temp->next = head;
        temp->prev = head->prev;
        head->prev->next = temp;
        head = temp;
        temp=0;
    }

}

//insert the node at the end of the List
void CirDoublyLinkedList :: insertAtEnd()
{
    //taking input from the user
    temp = new Node();
    cout<<"Enter the Data of New Node : ";
    cin>>temp->data;
    //inserting the node
    if(head == NULL)
    {
        head = temp;
        head->next = head;
        head->prev = head;
        temp=0;
    }
    else
    {
        temp->next = head;
         head->prev->next = temp;
        temp->prev = head->prev;

        head->prev = temp;
         temp=0;
    }

}
//inserting a Node at the n-th position in List
void CirDoublyLinkedList :: insertAtLoc()
{
    //taking input from the user
    temp = new Node();
    cout<<"Enter the Data of New Node : ";
    cin>>temp->data;
    temp->next = NULL;
    //taking location input
    int loc;
    cout<<"Enter Location : ";
    cin>>loc;
    if(loc < 0 )
    {
        cout<<"Invalid Location\n";
    }
    else
    {
        if(loc == 1)
        {
            temp->next = head;
            temp->prev = head->prev;
            head->prev->next = temp;
            head = temp;
            temp = 0;
        }
        else
        {
            int counter = 1;
            Node* required = head;
            while(counter != (loc-1))
            {
                temp = temp->next;
                counter++;
            }
            temp->next = required->next;
            temp->prev = required;
            required->next->prev = temp;
            required->next = temp;
        }

    }
}

//delete at the beginning of list
void CirDoublyLinkedList :: deleteAtBegin()
{
    if(this->isEmpty())
         cout<<"The List is Empty\n";
    else

    {
        if(head->next==head)
        {
            temp = head;
             temp=0;
        }
        else
        {
            temp = head;
            head = head->next;
            head->prev = temp->prev;
            temp->prev->next = head;



            temp=0;

        }


    }


}

//delete a node at the end of the list
void CirDoublyLinkedList :: deleteAtEnd()
{
     if(this->isEmpty())
         cout<<"The List is Empty\n";
    else

    {
        if(head->next==head)
        {
            temp = head;
            temp=0;
        }
        else
        {
             temp = head->prev;
             temp->next->prev = temp->prev;
             temp->prev->next = temp->next;
             temp->next=NULL;
             temp->prev=NULL;
              temp=0;


        }

    }

}

//delete a node at the n-th location
void CirDoublyLinkedList :: deleteAtLoc()
{
    //taking location input
    int loc;
    cout<<"Enter Location : ";
    cin>>loc;
    if(loc < 0 )
    {
        cout<<"Invalid Location\n";
    }
    else
    {
        if(loc == 1)
        {
            temp = head;
            if(head->next==head)
            {
                delete temp;;
            }
            else
            {
                temp->next->prev = temp->prev;
                temp->prev->next = temp->next;
                head = head->next;
            }
            delete temp;
            temp = 0;
        }
        else
        {
            int counter = 1;
            temp = head;
            while(counter != loc)
            {
                temp = temp->next;
                counter++;
            }
            temp->prev->next = temp->next;
            temp->next->prev = temp->prev;
            if(temp->next == head)
            {
                head->prev = temp->prev;
            }
            delete temp;
            temp = 0;
        }

    }

}

//traverse function
void CirDoublyLinkedList :: display()
{
    if(head == NULL)
    {
        cout<<"List is Empty\n";
    }
    else
    {
        temp = head;
        do
        {
            cout<<temp->data<<"-> ";
            temp = temp->next;
        }
        while(temp != head);
        cout<<"\n";
        temp = 0;
    }
}

//isEmpty() function
bool CirDoublyLinkedList :: isEmpty()
{

        return ( head == NULL);

}



int main()
{
    CirDoublyLinkedList A;
    char flag = 'y';
    int choice;
    //menu
    do{
        // system("CLS");
        cout<<"\n----------------------CIRCULAR DOUBLY LINKED LIST-----------------------\n";

        cout<<"1. Search \n"
            <<"2. Insert a Node at the Beginning\n"
            <<"3. Insert a Node at the End\n"
            <<"4. Insert a Node at a Certain Location\n"
            <<"5. Delete a Node at the Beginning\n"
            <<"6. Delete a Node at the End\n"
            <<"7. Delete a Node at a Certain Location\n"
            <<"8. Count number of nodes\n"
            <<"9. Display the list\n"
            <<"9. Exit\n";
        //getting user input
        cout<<"Enter your choice: ";
        cin>>choice;
        //switch cases
        switch (choice)
        {
            case 1:
                A.search();
                break;
            case 2:
                A.insertAtBegin();
                break;
            case 3:
                A.insertAtEnd();
                break;
            case 4:
                A.insertAtLoc();
                break;
            case 5:
                A.deleteAtBegin();
                break;
            case 6:
                A.deleteAtEnd();
                break;
            case 7:
                A.deleteAtLoc();
                break;
            case 8:
                A.count();
                break;
            case 9:A.display();
            break;
            case 10:
                flag = 'n';
                break;
            default:
                break;
        }
    }
    while(flag == 'y');

    return 0;
}

