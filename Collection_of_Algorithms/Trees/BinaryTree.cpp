struct node
{
        char data;
	node *left;
	node *right;
	node(char data)
  	{
  		this->data=data;
  		left=right=NULL;
  	}

};
queue<node *> q;
void insert(node *root,node *temp)
{
	if(root == NULL)
	{
		root = temp;
		root->left = NULL;
		root->right = NULL;
	}
}
void levelOrder(struct node* temp)
{
		if(q.empty())
		{
			return ;
		}

		cout<<q.front()->data<<" ";

		if(q.front()->left != NULL)
		{
			q.push(temp->left);
		}
		if(q.front()->right != NULL)
		{
			q.push(temp->right);
		}
		q.pop();
		levelOrder(q.front());

}
void inorder(struct node* temp)
{
    if (!temp)
    {
        return;
    }
    inorder(temp->left);
    cout << temp->data << " ";
    inorder(temp->right);
}

void preorder(struct node* temp)
{
	if(temp == NULL)
	{
		return;
	}
	cout<<temp->data<<" ";
	preorder(temp->left);
	preorder(temp->right);
}
void postorder(struct node *temp)
{
	if(!temp)
		return;
	postorder(temp->left);
	postorder(temp->right);
	cout<<temp->data<<" ";
}
int main()
{

    struct node *root = new node('A');
    root->left = new node('B');
    root->right = new node('C');
    root->left->left  = new node('D');
    root->left->right = new node('E');

	cout<<"levelOrder traversal"<<endl;
	q.push(root);
	levelOrder(root);
        cout<<endl<<"Inorder traversal"<<endl;
	inorder(root);
	cout<<endl<<"Preorder traversal"<<endl;
	preorder(root);
	cout<<endl;
	                                                                                                                                                                	return 0;
}
