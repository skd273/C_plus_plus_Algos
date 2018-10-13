
#include<iostream>
using namespace std;


struct node 
{


int data;
struct node *left,*right;
};


node* create(int data)
{
node *temp=new node;
temp->data=data;
temp->left=NULL;
temp->right=NULL;

return temp;


}

node* insert(node* rootptr,int data)
{

if(rootptr==NULL)
{
rootptr=create(data);

}
else if(data<(rootptr->data))
{

rootptr->left=insert(rootptr->left,data);
}

else
{
rootptr->right=insert(rootptr->right,data);
}
return rootptr;

}
bool search(node* head,int num)
{
if(head==NULL)
{

return false;
}
else if(head->data==num)
{
return true;
}
else if(num<head->data)
{

return search(head->left,num);
}
else
{
return search(head->right,num);
}

}

void inorder(node* head)
{
if(head==NULL)
{
return;
}
else
{


inorder(head->left);
cout<<head->data<<endl;
inorder(head->right);
}

}


void postorder(node* head)
{
if(head==NULL)
{
return;
}
else
{


postorder(head->left);
postorder(head->right);
cout<<head->data<<endl;

}

}


void preorder(node* head)
{
if(head==NULL)
{
return;
}
else
{

cout<<head->data<<endl;
preorder(head->left);
preorder(head->right);

}

}

int main()
{
int num;
struct node *head;
struct node *root=NULL;
head=root=insert(root,15);
root=insert(root,10);
root=insert(root,20);
root=insert(root,17);
root=insert(root,25);
root=insert(root,8);
root=insert(root,12);
cout<<"PREORDER"<<endl;
preorder(head);
cout<<"INORDER"<<endl;
inorder(head);
cout<<"POSTORDER"<<endl;
postorder(head);
cout<<"ENTER NO YOU WANT TO SEARCH"<<endl;
cin>>num;
if(search(head,num)==true)
{
cout<<"FOUND"<<endl;

}
else
{
cout<<"NOT FOUND"<<endl;

}
}
