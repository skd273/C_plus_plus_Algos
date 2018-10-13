#include<stdlib.h>
#include<iostream>
using namespace std;

struct node
{
string val;
struct node *left,*right;
};

void inorder(node *root)
{
inorder(root->left);
if(root->val=="-")
{
cout<<" ";

}
else
{
cout<<root->val;
}
inorder(root->right);

}

void preorder(node *root)
{

if(root->val=="-")
{
cout<<" ";
}
else
{
cout<<root->val;
}
preorder(root->left);
preorder(root->right);

}




void postorder(node *root)
{

postorder(root->left);
postorder(root->right);

if(root->val=="-")
{
cout<<" ";
}
else
{
cout<<root->val;
}

}



node* newNode(string val)
{

struct node *temp=new node;
temp->val=val;
temp->left=NULL;
temp->right=NULL;
return temp;
}
int main(int argv,char *arg[])
{

struct node *root=newNode(arg[1]);
root->left=newNode(arg[2]);
root->right=newNode(arg[3]);
root->left->left=newNode(arg[4]);
root->left->right=newNode(arg[5]);
root->right->left=newNode(arg[6]);
root->right->right=newNode(arg[7]);
inorder(root);
preorder(root);
postorder(root);
}
