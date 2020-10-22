#include<iostream>
using namespace std;
int arr[20],n;
int bsearch(int l,int r,int x)
{
    if (r >= l) {
        int mid = l + (r - l) / 2;

        // If the element is present at the middle
        // itself
        if (arr[mid] == x)
            return mid;

        // If element is smaller than mid, then
        // it can only be present in left subarray
        if (arr[mid] > x)
            return bsearch( l, mid - 1, x);

        // Else the element can only be present
        // in right subarray
        return bsearch( mid + 1, r, x);
    }

    // We reach here when element is not
    // present in array
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
    int a=bsearch(0,n-1,ele);
    if(a==-1)
        cout<<"\nElement not found ";
    else
        cout<<"\nElement found at index number : "<<a;
    return 0;
}
