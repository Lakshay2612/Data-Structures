#include<iostream>
using namespace std;
struct node
{
    int data;
    node *right,*left;
};
int flag=0;
class ArrayStack
{
    int Stack[30];
    int top;
    public:

        ArrayStack()
        {
            top=-1;
        }
        void push(int n)
        {
            if(top==29)
                cout<<"List is full";
            else
            {
                Stack[++top]=n;

            }
        }
        int pop()
        {
            if(top==-1)
            {

                return 0;
            }
            else
            {
                int a=Stack[top];
                top--;
                return a;
            }
        }
        bool isempty()
        {
            if(top==-1)
            return true;
            else
            return false;
        }
};
class BST
{
    public :
        int leafs=0,nonleafs=0,total_nodes=0;
        node *root;
    BST()
    {
        root=NULL;
    }
    void Insert()
    {
        int i;
        node *p=new node();
            node *p1=new node();
            cout<<"\nEnter value to be inserted : ";
            cin>>i;
        if(i!=0)
        {
            if(root==NULL)
            {
                root=new node();
                root->left=root->right=NULL;
                root->data=i;
                cout<<"Root value inserted\n";
            }
            else
            {

                p=root;
                node *q=new node();
                q->left=NULL;
                q->right=NULL;
                q->data=i;
                while(p!=0)
                {
                    if(i<p->data)
                    {
                        p1=p;
                        p=p->left;
                    }
                    else
                    {
                        p1=p;
                        p=p->right;
                    }
                }
                if(i<p1->data)
                {
                    p1->left=q;
                }
                else
                {
                    p1->right=q;
                }
            }
        }
        cout<<"\nElement inserted";
    }
    void rec_preorder(node *ele)
    {

        if(ele!=NULL)
        {
            cout<<ele->data<<",";
            rec_preorder(ele->left);
            rec_preorder(ele->right);

        }
    }
    void rec_inorder(node *ele)
    {

        if(ele!=NULL)
        {
            rec_inorder(ele->left);
            cout<<ele->data<<",";

            rec_inorder(ele->right);

        }
    }
    void rec_postorder(node *ele)
    {

        if(ele!=NULL)
        {

            rec_postorder(ele->left);
            rec_postorder(ele->right);
            cout<<ele->data<<",";
        }
    }
    void Iterative_PreOrder(node *temp)
    {
         node *temp1=new node();
        ArrayStack s1;
        if(temp!=0)
        {
            s1.push(temp->data);
            while(!s1.isempty())
            {
                temp1=temp;
                int t=s1.pop();
                cout<<t<<",";
                if(temp->right!=NULL)
                    {
                        s1.push(temp->right->data);

                        temp=temp->right;
                    }
                if(temp1->left!=NULL)
                    {
                        s1.push(temp1->left->data);
                        temp1=temp1->left;
                    }

            }
        }
    }
    void searchtree(node *temp,int ele)
    {

        while(temp!=NULL)
        {
            if(temp->data==ele)
            {
                flag=1;
                break;
            }
            else
            {
                if(ele>=temp->data)
                    temp=temp->right;
                else
                    temp=temp->left;

            }

        }
        if(flag==0)
                cout<<"\nNOT FOUND";
            else
                cout<<"\nNODE FOUND";
    }
    void counter(node *temp)
    {

        if(temp!=NULL)
        {

            if(temp->right==NULL&&temp->left==NULL)
                leafs++;
            if(temp->right!=NULL||temp->left!=NULL)
                nonleafs++;
            counter(temp->left);
            counter(temp->right);
        }
    }

};
int main()
{
    BST ob;
    int choice,n;
    do
  {
    cout << "\n\tBINARY SEARCH TREE\n"
         << "====================================================================================================\n"
         << "  (1) Insert a node                                                (2) Display Pre Order using recursion \n"
         << "  (3) Display In Order using recursion                             (4) Display Post Order using recursion \n"
         << "  (5) Display Pre Order using iteration                            (6) Search a node in the tree\n "
         << "  (7) Count total number of leaf nodes and non leaf nodes           ";

    cout << "\nEnter Choice: ";
    cin >> choice;
    switch (choice)
    {
    case 1:ob.Insert();
    break;

    case 2:cout<<"\nPRE ORDER : ";
         ob.rec_preorder(ob.root);
    break;
    case 3:cout<<"\nIN ORDER : ";
        ob.rec_inorder(ob.root);
    break;
    case 4:cout<<"\nPOST ORDER : ";
        ob.rec_postorder(ob.root);
    break;
    case 5:cout<<"\nPRE ORDER : ";
    ob.Iterative_PreOrder(ob.root);
    break;
    case 6:cout<<"\nEnter node to be searched : ";
            cin>>n;
        ob.searchtree(ob.root,n);
    break;
    case 7:ob.counter(ob.root);
            ob.total_nodes=ob.leafs+ob.nonleafs;
            cout<<"\nTotal number of leaf nodes : "<<ob.leafs;
            cout<<"\nTotal number of non-leaf nodes : "<<ob.nonleafs;
            cout<<"\nTotal number of nodes : "<<ob.total_nodes;
            break;

    default:cout<<"\nPlease enter a valid choice";
    }
    } while (choice != 0);
    return 0;



}
