#include <iostream>
#include<conio.h>
using namespace std;
class CircularQueueArray
{
    int a[30],first,last;
    public:
        CircularQueueArray()
        {
            first=-1;
            last=-1;
        }
        bool isfull()
        {
            return(first==0&&last==29||first==last+1);
        }


        bool isempty()
        {
            return(first==-1);
        }
        void enque(int ele)
        {

              if(isempty())
                {
                    cout<<"\nInserting first element";
                    first=0;
                    last=0;
                    a[last]=ele;

                }
                else if(isfull())
                {
                    cout<<"\nQueue is already full";
                    return;
                }
                else if(last==29)
                {
                    last=0;
                    cout<<"\nInserting element at the last place";
                }
                else
                {
                    last++;
                    a[last]=ele;
                    cout<<"\nElement inserted";
                }

        }
        void dequeue()
        {
            int r;
            if(first==-1)
                cout<<"\nUnderflow";
            else
            {
                 r=a[first];
                if(first==last)
                    first=last=-1;
                else if(first==29)
                    first=0;
                else first++;
                cout<<"\nElement deleted :"<<r;

            }

        }
        void display()
        {
            if(last==-1)
            {
                cout<<"\nQueue is empty";
            }
            else
            {
            cout<<"\nQueue :";
            for(int i=first;i<last;i++)
            {
                cout<<a[i]<<"->";
            }
            cout<<a[last];
            }
        }
        void Clear()
        {
            if(last==-1)
                cout<<"\nQueue is already empty";
            else
            {
                cout<<"\nClearing Queue";
                last=-1;
                first=-1;
            }
        }

};
int main()
{
      int n,choice;
  CircularQueueArray ob;
  do
  {
    cout << "\n\tCircular Queue operations using Array\n"
         << "\t===================================\n"
         << "  (1) Insert/Enqueue\t(2) Delete/Dequeue   \t(3) Display\t(4) Clear\t(5) Exit\n";


    cout << "Enter Choice: ";
    cin >> choice;
    switch (choice)
    {
    case 1: cout<<"\nEnter the value to be inserted in the Queue : ";
            cin>>n;
            ob.enque(n);
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
