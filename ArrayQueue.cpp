#include <iostream>
#include<conio.h>
using namespace std;
class ArrayQueue
{
    int que[30],Front,Rear;
    public:
        ArrayQueue()
        {
            Front=-1;
            Rear=-1;
        }
        void enque(int n)
        {
            int flag=0;
            if(Rear==-1)
            {
                Front=Rear=0;
                que[Front]=n;
            }
            else if(Rear<30)
            {
                Rear++;
                que[Rear]=n;
            }
            else
            {
                cout<<"\nQueue is already full";
                flag=1;
            }
            if(flag==0)
            {
                cout<<"\nElement inserted ";
            }
        }
        void dequeue()
        {
            if(Rear==-1)
                cout<<"\nQueue is already empty";
            else if(Front>-1&&Front<Rear)
            {
                cout<<que[Front]<<" Deleted";
                Front++;
            }
            else if(Front==Rear)
            {
                cout<<"\nDeleting the last element : "<<que[Front];
                cout<<"\nQueue is empty now";
                Front=Rear=-1;
            }

        }
        void display()
        {
            if(Rear==-1)
            {
                cout<<"\nQueue is empty";
            }
            else
            {
            cout<<"\nQueue :";
            for(int i=Front;i<Rear;i++)
            {
                cout<<que[i]<<"->";
            }
            cout<<que[Rear];
            }
        }
        void Clear()
        {
            if(Rear==-1)
                cout<<"\nQueue is already empty";
            else
            {
                cout<<"\nClearing Queue";
                Rear=-1;
                Front=-1;
            }
        }

};
int main()
{
    int ele,choice;
  ArrayQueue list;
  do
  {
    cout << "\n\tQueue operations using Array\n"
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

