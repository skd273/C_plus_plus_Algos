#include<iostream>
using namespace std;
#include<queue>
struct Node
{

char data;
struct Node *left;
struct Node *right;

};
void preorder(Node *n)
{
if(n==NULL)
{
return;
}
if(n->data=='-')
{
cout<<" ";
}
else
{
cout<<n->data;
}
preorder(n->left);
preorder(n->right);



}

void postorder(Node *n)
{

if(n==NULL)
{
return;
}
postorder(n->left);
postorder(n->right);
if(n->data=='-')
{
cout<<" ";
}
else
{
cout<<n->data;
}

}

void inorder(Node *n)
{

if(n==NULL)
{
return;
}
inorder(n->left);
if(n->data=='-')
{
cout<<" ";
}
else
{
cout<<n->data;
}
inorder(n->right);


}
Node* node (int val)
{
struct Node *temp=new Node;

temp->data=val;
temp->left=NULL;
temp->right=NULL;
return temp;
}
void levelorder(Node *root)
{

queue<Node*>q;
q.push(root);
while(!q.empty())
{



struct Node *current=q.front();
cout<<current->data;
if(current->left!=NULL)
{
q.push(current->left);

}


if(current->right!=NULL)
{
q.push(current->right);

}
q.pop();
//cout<<endl;

}



}
int main()
{

struct Node *root=node('A');
root->left=node('B');
root->right=node('C');
root->left->left=node('E');
root->left->right=node('F');
root->right->left=node('D');
cout<<"INDORDER"<<endl;
inorder(root);
cout<<endl;
cout<<endl;
cout<<"POSTORDER"<<endl;
postorder(root);
cout<<endl;
cout<<endl;
cout<<"PREORDER"<<endl;
preorder(root);

cout<<endl;
cout<<endl;
cout<<"LEVELORDER"<<endl;
levelorder(root);
return 0;
}

