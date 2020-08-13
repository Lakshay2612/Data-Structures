#include<iostream.h>
#include<conio.h>
#include<process.h>
class linkedlist
{
struct Node
{
int data;
Node *link;
};
Node *head,*temp;
public:
linkedlist()
{
head=NULL;
}
void create();
void insertbegin();
void insertend();
void display();
};
void linkedlist::create()
{
int w;
cout<<"\nenter the value to be stored in Data\n";
cin>>w;
Node *ptr=new Node();
ptr->data=w;
ptr->link=NULL;
head=ptr;
}
void linkedlist::insertbegin()
{
int e;
cout<<"enter the value for Data\n";
cin>>e;
Node *ptr=new Node();
ptr->data=e;
ptr->link=head;
head=ptr;
}
void linkedlist::insertend()
{
int d;
cout<<"enter the value for Data\n";
cin>>d;
Node *ptr=new Node();
ptr->data=d;
ptr->link=NULL;
if(head==NULL)
{
head=ptr;
}
else
{
Node *temp=head;
while(temp->link!=NULL)
{
temp=temp->link;
}
cout<<"\nthe values of first item\n";
cout<<temp->data;
}
}
void linkedlist::display()
{
if(head==NULL)
{
cout<<"empty\n";
}
else
{
temp=head;
while(temp!=NULL)
{
cout<<"\nDATA DISPLAYED\n";
cout<<temp->data<<"\t";
temp=temp->link;
}
}
}
void main()
{
clrscr();
int ch;
char n;
linkedlist l1;
do
{
cout<<"\nenter y to continue || n to exit\n";
cin>>n;
cout<<"\nenter your choice: \n1. to create \n2. to insert in the beginning \n3. to insert in the end\n4. to display\n5. to exit\n";
cin>>ch;
switch(ch)
{
case 1:
l1.create();
break;
case 2:
l1.insertbegin();
break;
case 3:
l1.insertend();
break;
case 4:
l1.display();
break;
case 5:
exit(0);
break;
}
} while(n=='y');
getch();
}