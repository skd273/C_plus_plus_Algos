#include<iostream>
#include<queue>
using namespace std;
struct node
{
	char data;
	node *left,*right;
};
void display( struct node *root)
{
	if(root==NULL)
		return;
	queue<node *>queue;
	queue.push(root);

	while(!queue.empty())
	{
		struct node *temp=queue.front();
		cout<<temp->data;
		queue.pop();

		if(temp->left!=NULL)
		{
			queue.push(temp->left);
		}

		if(temp->right!=NULL)
		{
			queue.push(temp->right);
		}
	}
}
 struct node* newNode(char data)
{
	struct node *node=new node;
	node->data=data;
	node->left=NULL;
	node->right=NULL;
	return node;
}
int main()
{
	struct node *root=newNode('A');
	root->left=newNode('B');
	root->right=newNode('C');
	root->left->left=newNode('E');
	root->left->right=newNode('F');
	root->right->left=newNode('D');

	cout<<"Level Order traversal using Queue is : \n";
	display(root);
	return 0;
}
