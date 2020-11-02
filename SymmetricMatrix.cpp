#include<iostream>
using namespace std;
class SymmetricMatrix
{
    public :
      int *d,n;
      SymmetricMatrix(int size =10)
      {
          n=size;
          if(size!=0)
            d=new int [n*n+1/2];
          else
            d=0;
      }
      ~SymmetricMatrix()
      {
          delete d;
      }
      void store(int x,int i,int j)
      {
          if(i>n||j>n||i<1||j<1)
            {
                cout<<"\nIndex out of bound ";
                exit(0);
            }
          else
          {
              int p=(i*(i-1)/2)+j;
              d[p]=x;
          }

      }
      void show()
      {
          for(int i=1;i<=n;i++)
          {
              cout<<"\n";
              for(int j=1;j<=n;j++)
              {
                  if(i<j)
                    {
                        int a=i;
                        int b=j;
                        int temp=a;
                        a=b;
                        b=temp;
                        cout<<d[(a*(a-1)/2)+b]<<"\t";
                    }
                  else
                    cout<<d[(i*(i-1)/2)+j]<<"\t";
              }

          }
      }
      int retrieve(int i,int j)
      {
          if(i>n||j>n||i<1||j<1)
            {
                cout<<"\nIndex out of bound ";
                exit(0);
            }
            else if(i>=j)
            {
                return d[(i*(i-1)/2)+j];
            }
            else if(i<j)
            {
                        int a=i;
                        int b=j;
                        int temp=a;
                        a=b;
                        b=temp;
                         return d[(a*(a-1)/2)+b];

            }
            else
                return 0;
      }


};
int main()
{
    int m1,i,j,ele;
    cout<<"\nEnter the size of matrix : ";
    cin>>m1;
    SymmetricMatrix d(m1);
    for(i=1;i<=m1;i++)
    {
        for(j=1;j<=m1;j++)
        {
           if(i>=j)
           {
               cout<<"\nEnter element on index ("<<i<<","<<j<<") : ";
               cin>>ele;
               d.store(ele,i,j);
           }
        }

    }
    cout<<"\nThe SymmetricMatrix  is : ";
    d.show();
    cout<<"\nEnter index for retrieval : ";
    cin>>i>>j;
    int res=d.retrieve(i,j);
    cout<<"\nRetrieved value is : "<<res;
    return 0;
}
