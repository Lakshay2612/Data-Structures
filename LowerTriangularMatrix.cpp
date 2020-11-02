#include<iostream>
using namespace std;
class LowerTriangular
{
    public :
      int *d,n;
      LowerTriangular(int size =10)
      {
          n=size;
          if(size!=0)
            d=new int [n*n+1/2];
          else
            d=0;
      }
      ~LowerTriangular()
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
                    cout<<"0"<<"\t";
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
            else
                return 0;
      }


};
int main()
{
    int m1,i,j,ele;
    cout<<"\nEnter the size of matrix : ";
    cin>>m1;
    LowerTriangular d(m1);
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
    cout<<"\nThe LowerTriangular matrix is : ";
    d.show();
    cout<<"\nEnter index for retrieval : ";
    cin>>i>>j;
    int res=d.retrieve(i,j);
    cout<<"\nRetrieved value is : "<<res;
    return 0;
}
