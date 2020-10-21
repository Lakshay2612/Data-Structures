#include<iostream>
using namespace std;
 int l,r,largest;
class Max_Heap
{

   public:
        int Arr[30],n;
       void Heap_Increase_Key(int Arr[ ], int i, int val)
            {
                if(val < Arr[ i ])
                    {
                        cout<<"New value is less than current value, can’t be inserted" <<endl;
                        return;
                    }
                Arr[ i ] = val;
                while( i > 1 and Arr[ i/2 ] < Arr[ i ])
                    {
                        int temp=Arr[i];
                        Arr[i]=Arr[i/2];
                        Arr[i/2]=temp;
                        i = i/2;
                    }
            }

      void Max_Heap_Insert(int Arr[ ], int val)
      {
                n = n + 1;
                Arr[ n ] = -1000000000;  //assuming all the numbers greater than -1000000000000 are to be inserted in queue.
                Heap_Increase_Key (Arr, n, val);
      }

      int heap_maximum(int Arr[ ])
     {
        return Arr[ 1 ];  //as the maximum element is the root element in the max heap.
     }
     int heap_extract_maximum (int Arr[ ])
    {
        if(n == 0)
        {
            cout<< "Can’t remove element as queue is empty";
            return -1;
        }
        int max = Arr[1];
        Arr[1] = Arr[n];
        n=n-1;
        max_heapify(1);
        return max;
    }
    void max_heapify(int i)
    {


        l=2*i;
        r=2*i+1;
        if(l<=n&&Arr[l]>Arr[i])
            largest=l;
        else
            largest=i;
        if(r<=n&&Arr[r]>Arr[largest])
            largest=r;


        if(largest!=i)
        {
            int temp=Arr[i];
            Arr[i]=Arr[largest];
            Arr[largest]=temp;
             max_heapify(largest);
        }
    }
    void build_max_heap()
    {
        for(int i=n/2;i>=1;i--)
            max_heapify(i);
    }
};

int main()
{
    Max_Heap m;
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
        cout<<"\n-----------------PRIORITY QUEUE USING MAX HEAP------------------------";
        cout<<"\nEnter your choice ";
        cout<<"\n1 for converting the queue into a max heap priority queue "
            <<"\n2 for Heap Increase Key "
            <<"\n3 for Max Heap Insert "
            <<"\n4 for Heap Maximum "
            <<"\n5 for Heap Extract Maximum "
            <<"\n6 for Exit";
        cin>>ch;
        switch(ch)
        {
            case 1:m.build_max_heap();
                    break;
            case 2: cout<<"\nEnter index : ";
                    cin>>in;
                    cout<<"\nEnter value : ";
                    cin>>val1;
                    m.Heap_Increase_Key(m.Arr,in,val1);
                    break;
            case 3: cout<<"\nEnter value : ";
                    cin>>val2;
                    m.Max_Heap_Insert(m.Arr,val2);
                    break;
            case 4:  ma1=m.heap_maximum(m.Arr);
                    cout<<"\nHeap maximum is : "<<ma1;
                    break;
            case 5:  ma2=m.heap_extract_maximum(m.Arr);
                    cout<<"\nHeap maximum is : "<<ma2;
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
