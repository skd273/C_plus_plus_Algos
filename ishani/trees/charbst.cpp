
#include<iostream>
using namespace std;


struct node 
{


char data;
struct node *left,*right;
};


node* create(char data)
{
node *temp=new node;
temp->data=data;
temp->left=NULL;
temp->right=NULL;

return temp;


}

node* insert(node* rootptr,char data)
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
bool search(node* head,char num)
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
char num;
struct node *head;
struct node *root=NULL;
head=root=insert(root,'A');
root=insert(root,'B');
root=insert(root,'C');
root=insert(root,'D');
root=insert(root,'E');
root=insert(root,'F');
root=insert(root,'G');
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
