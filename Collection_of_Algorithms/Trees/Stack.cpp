#include<iostream>
using namespace std;
#include<stack>
struct Node
{

char data;
struct Node *left;
struct Node *right;

};

void inorder(Node *n)
{

struct Node *current=n;
stack<Node*>s;
while(!s.empty() || current!=NULL)
{


while(current!=NULL)
{

s.push(current);
current=current->left;
}

if(!s.empty())
{
current=s.top();
cout<<current->data<<endl;
current=current->right;
s.pop();
}


}


}

Node* node (char val)
{
struct Node *temp=new Node;

temp->data=val;
temp->left=NULL;
temp->right=NULL;
return temp;
}



int main()
{

struct Node *root=node('A');
root->left=node('B');
root->right=node('C');
root->left->left=node('D');
root->left->right=node('E');
root->left->right->left=node('F');
cout<<"INDORDER"<<endl;
inorder(root);
return 0;
}

