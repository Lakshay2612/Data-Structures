#include<iostream>
using namespace std;
int arr[20],n;
void sel_sort()
{
    int i,j,pos,temp;
    for(i=0;i<n-1;i++)
    {
        pos=i;
        for(j=i+1;j<n;j++)
        {
            if(arr[j]<arr[pos])
                pos=j;
        }
        temp=arr[pos];
        arr[pos]=arr[i];
        arr[i]=temp;
    }
    cout<<"\nSorted array : ";
    for(int i=0;i<n;i++)
    {
        cout<<" "<<arr[i];
    }
}
void bub_sort()
{
    int i,j;
    for(i=0;i<n-1;i++)
        {
            for(j=0;j<n-1;j++)
            {
                if(arr[j]>arr[j+1])
                    {
                    int temp=arr[j];
                    arr[j]=arr[j+1];
                    arr[j+1]=temp;
                    }
            }
        }
    cout<<"\nSorted array : ";
    for(int i=0;i<n;i++)
    {
        cout<<" "<<arr[i];
    }
}
void ins_sort()
{
    int i, key, j;
    for (i = 1; i < n; i++)
    {
        key = arr[i];
        j = i - 1;

        /* Move elements of arr[0..i-1], that are
        greater than key, to one position ahead
        of their current position */
        while (j >= 0 && arr[j] > key)
        {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
    cout<<"\nSorted array : ";
    for(int i=0;i<n;i++)
    {
        cout<<" "<<arr[i];
    }
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
    cout<<"\nEnter \n1 For Selection sort \n2 For Bubble sort \n3 For Insertion sort ";
    int ch;
    cin>>ch;
    if(ch==1)
    {
        cout<<"\nPerforming Selection sort ";
        sel_sort();
    }
    else if(ch==2)
    {
        cout<<"\nPerforming Bubble sort ";
        bub_sort();
    }
    else if(ch==3)
    {
        cout<<"\nPerforming Insertion sort ";
        ins_sort();
    }
    else
    {
        cout<<"\nWrong choice ";
    }
    return 0;
}

