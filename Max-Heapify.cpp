#include <iostream>

using namespace std;
int A[30],n;
int l,r,largest;
void max_heapify(int i)
{

    l=2*i;
    r=2*i+1;
    if(l<=n&&A[l]>A[i])
        largest=l;
    else
        largest=i;
    if(r<=n&&A[r]>A[largest])
        largest=r;

    if(largest!=i)
    {
        int temp=A[i];
        A[i]=A[largest];
        A[largest]=temp;
    }
    if(l>n||r>n)
        return;
    max_heapify(largest);
}
int main()
{
    cout<<"\nEnter number of elements in the priority queue : ";
    cin>>n;
    for(int i=0;i<n;i++)
        {
            cout<<"\nEnter element number "<<i+1<<" : ";
            cin>>A[i];
        }
    cout<<"\nEntered queue : ";
    for(int i=0;i<n;i++)
        {
            cout<<A[i]<<" ";
        }
    cout<<"\nEnter index for which you want to call Max Heapify : ";
    int ele;
    cin>>ele;
    cout<<"\nCalling Max Heapify function for Index Number "<<ele<<" and value "<<A[ele];
    max_heapify(ele);
    cout<<"\nQueue after calling Max Heapify : ";
    for(int i=0;i<n;i++)
        {
            cout<<A[i]<<" ";
        }




}
