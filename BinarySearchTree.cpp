#include<iostream>
using namespace std;
struct node
{
    int data;
    node *right,*left;
};

class BST
{
    public :
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
};
int main()
{
    BST ob;
    int choice;
    do
  {
    cout << "\n\tBINARY SEARCH TREE\n"
         << "====================================================================================================\n"
         << "  (1) Insert a node                                      (2) Display Pre Order using recursion \n"
         << "  (3) Display In Order using recursion                   (4) Display Post Order using recursion \n";

    cout << "Enter Choice: ";
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

    default:cout<<"Please enter a valid choice";
    }
    } while (choice != 0);
    return 0;



}
