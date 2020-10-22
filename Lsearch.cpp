#include<iostream>
using namespace std;
int arr[20],n;
int Lsearch(int ele)
{
    for(int i=0;i<n;i++)
    {
        if(arr[i]==ele)
            return i;
    }
    return -1;
}
int main()
{
    int ele;
    cout<<"\nEnter number of elements in the array : ";
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cout<<"\nEnter element number "<<i+1<<" : ";
        cin>>arr[i];

    }
    cout<<"\nEntered array is : ";
    for(int i=0;i<n;i++)
    {
        cout<<" "<<arr[i];
    }
    cout<<"\nEnter element to be searched : ";
    cin>>ele;
    int a=Lsearch(ele);
    if(a==-1)
        cout<<"\nElement not found ";
    else
        cout<<"\nElement found at index number : "<<a;
    return 0;
}
