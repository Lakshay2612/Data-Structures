#include<iostream>
using namespace std;
struct node
{
    int data;
    node *right,*left;
};
int flag=0;
class ArrayQueue
{
    node* que[30];
    int Front,Rear;
    public:
        ArrayQueue()
        {
            Front=-1;
            Rear=-1;
        }
        void enque(node* n)
        {

            if(Rear==-1)
            {
                Front=Rear=0;
                que[Front]=n;
            }
            else if(Rear<30)
            {
                Rear++;
                que[Rear]=n;
            }

        }
        node* dequeue()
        {
            if(Rear==-1)
                cout<<"\nQueue is already empty";
            else if(Front>-1&&Front<Rear)
            {
                Front++;
                node *a=(que[Front]);
                return a;

            }
            else if(Front==Rear)
            {

                Front=Rear=-1;
                node *a=(que[Front]);
                return a;
            }

        }
        bool isEmpty()
        {
            if(Rear==-1)
            return true;
            else
                return false;
        }
};
class ArrayStack
{
    node* Stack[30];
    int top;
    public:

        ArrayStack()
        {
            top=-1;
        }
        void push(node* n)
        {
            if(top==29)
                cout<<"List is full";
            else
            {
                Stack[++top]=n;

            }
        }
        node* pop()
        {
            if(top==-1)
            {

                return 0;
            }
            else
            {
                node* a=Stack[top];
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

        ArrayStack s1;
        if(temp!=0)
        {
            s1.push(temp);
            while(!s1.isempty())
            {
               temp=s1.pop();
               cout<<temp->data<<",";
               if(temp->right!=NULL)
                s1.push(temp->right);
               if(temp->left!=NULL)
                s1.push(temp->left);
            }
        }
    }
    void Iterative_InOrder(node *temp)
    {
        ArrayStack s1;
        while(temp!=0)
        {
            while(temp!=0)
            {
                if(temp->right!=NULL)
                s1.push(temp->right);
                s1.push(temp);
                temp=temp->left;
            }
            temp=s1.pop();
            while(!s1.isempty()&&temp->right==NULL)
            {
                cout<<temp->data<<",";
                temp=s1.pop();
            }
             cout<<temp->data<<",";
             if(!s1.isempty())
                temp=s1.pop();
             else
                temp=NULL;


        }
    }
    void Iterative_PostOrder(node *temp)
    {
        ArrayStack s1;
        node *q=temp;
        while(temp!=0)
        {
            for(;temp->left!=NULL;temp=temp->left)
                s1.push(temp);
            while(temp!=0&&(temp->right==NULL||temp->right==q))
            {
                cout<<temp->data<<",";
                q=temp;
                if(s1.isempty())
                    return;
                    temp=s1.pop();

            }
            s1.push(temp);
            temp=temp->right;
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
    void bfs(node* temp)
    {
        ArrayQueue q1;
        if(temp!=NULL)
        {
            q1.enque(temp);
            while(!q1.isEmpty())
            {
                temp=q1.dequeue();
                cout<<temp->data<<"hi";
                if(temp->left!=NULL)
                    q1.enque(temp->left);
                if(temp->right!=NULL)
                    q1.enque(temp->right);
            }
        }
    }

};
int main()
{
    BST ob;
    int choice,n;
    do
  {
    cout << "\n\t\t\t\t\tBINARY SEARCH TREE\n"
         << "====================================================================================================\n"
         << "  (1) Insert a node                                                (2) Display Pre Order using recursion \n"
         << "  (3) Display In Order using recursion                             (4) Display Post Order using recursion \n"
         << "  (5) Display Pre Order using iteration                            (6) Display In Order using iteration\n"
         << "  (7) Display Post Order using iteration                           (8) Count total number of leaf nodes and non leaf nodes\n"
         << "  (9) Search a node in the tree                                    (10) Display level by level BFS traversal  ";

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
    case 6:cout<<"\nIN ORDER : ";
    ob.Iterative_InOrder(ob.root);
    break;
    case 7:cout<<"\nPOST ORDER : ";
    ob.Iterative_PostOrder(ob.root);
    break;
    case 9:cout<<"\nEnter node to be searched : ";
            cin>>n;
        ob.searchtree(ob.root,n);
    break;
    case 8:ob.counter(ob.root);
            ob.total_nodes=ob.leafs+ob.nonleafs;
            cout<<"\nTotal number of leaf nodes : "<<ob.leafs;
            cout<<"\nTotal number of non-leaf nodes : "<<ob.nonleafs;
            cout<<"\nTotal number of nodes : "<<ob.total_nodes;
            break;
    case 10:ob.bfs(ob.root);
    cout<<"\nBFS : ";
    break;

    default:cout<<"\nPlease enter a valid choice";
    }
    } while (choice != 0);
    return 0;



}
