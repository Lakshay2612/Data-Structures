#include<iostream>
using namespace std;
 int l,r,smallest;
class Min_Heap
{

   public:
        int Arr[30],n;
       void Heap_decrease_Key(int Arr[ ], int i, int val)
            {
                if(val > Arr[ i ])
                    {
                        cout<<"New value is greater than current value, can’t be inserted" <<endl;
                        return;
                    }
                Arr[ i ] = val;
                while( i > 1 and Arr[ i/2 ] > Arr[ i ])
                    {
                        int temp=Arr[i];
                        Arr[i]=Arr[i/2];
                        Arr[i/2]=temp;
                        i = i/2;
                    }
            }

      void Min_Heap_Insert(int Arr[ ], int val)
      {
                n = n + 1;
                Arr[ n ] = 1000000000000000000;  //assuming all the numbers smaller than 100000000000 are to be inserted in queue.
                Heap_decrease_Key (Arr, n, val);
      }

      int heap_minimum(int Arr[ ])
     {
        return Arr[ 1 ];  //as the minimum element is the root element in the min heap.
     }
     int heap_extract_minimum (int Arr[ ])
    {
        if(n == 0)
        {
            cout<< "Can’t remove element as queue is empty";
            return -1;
        }
        int min = Arr[1];
        Arr[1] = Arr[n];
        n=n-1;
        min_heapify(1);
        return min;
    }
    void min_heapify(int i)
    {


        l=2*i;
        r=2*i+1;
        if(l<=n&&Arr[l]<Arr[i])
            smallest=l;
        else
            smallest=i;
        if(r<=n&&Arr[r]<Arr[smallest])
            smallest=r;


        if(smallest!=i)
        {
            int temp=Arr[i];
            Arr[i]=Arr[smallest];
            Arr[smallest]=temp;
             min_heapify(smallest);
        }
    }
    void Build_min_heap()
    {
        for(int i=n/2;i>=1;i--)
            min_heapify(i);
    }
};

int main()
{
    Min_Heap m;
    int ch,in,val1,val2,ma1,ma2;
    cout<<"\nEnter number of elements in the Queue : ";
    cin>>m.n;
    for(int i=1;i<=m.n;i++)
        {
            cout<<"\nEnter element number "<<i<<" : ";
            cin>>m.Arr[i];
        }
    cout<<"\nEntered elements : ";
    for(int i=1;i<=m.n;i++)
    cout<<m.Arr[i]<<" ";
    do
    {
        cout<<"\n-----------------PRIORITY QUEUE USING MIN HEAP------------------------";
        cout<<"\nEnter your choice ";
        cout<<"\n1 for converting the queue into a min heap priority queue "
            <<"\n2 for Heap Decrease Key "
            <<"\n3 for Min Heap Insert "
            <<"\n4 for Heap Minimum "
            <<"\n5 for Heap Extract Minimum "
            <<"\n6 for Exit";
        cin>>ch;
        switch(ch)
        {
            case 1:m.Build_min_heap();
                    break;
            case 2: cout<<"\nEnter index : ";
                    cin>>in;
                    cout<<"\nEnter value : ";
                    cin>>val1;
                    m.Heap_decrease_Key(m.Arr,in,val1);
                    break;
            case 3: cout<<"\nEnter value : ";
                    cin>>val2;
                    m.Min_Heap_Insert(m.Arr,val2);
                    break;
            case 4:  ma1=m.heap_minimum(m.Arr);
                    cout<<"\nHeap minimum is : "<<ma1;
                    break;
            case 5:  ma2=m.heap_extract_minimum(m.Arr);
                    cout<<"\nHeap minimum is : "<<ma2;
                    break;
            case 6: exit(0);
                    break;
            default:cout<<"\nWrong choice";




        }
        cout<<"\nQueue now : ";
        for(int i=1;i<=m.n;i++)
        cout<<m.Arr[i]<<" ";

    }while(ch!=6);
    return 0;

}
