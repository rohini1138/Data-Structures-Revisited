#include<iostream>
using namespace std;

class Node
{
	public:
		Node *left;
		Node *right;
		int data;

		Node(int data)
		{
			this->data = data;
			left = NULL;
			right = NULL;
		}
};

class Tree
{
public:
void insert(Node *root,Node *node)
{
	if(root == NULL || node == NULL)
	{
		return;
	}
	else
	{
		if(node->data > root->data)
		{
			if(root->right == NULL)
			{
				root->right = node;
			}
			else
			{
				insert(root->right,node);
			}
		}
		if(node->data < root->data)
                {
		      
                        if(root->left == NULL)
                        {
                                root->left = node;
                        }
                        else
                        {
                                insert(root->left,node);
                        }
                }
	}
}

void inorder(Node *node)
{
	if(node==NULL)
	{
		return;
	}
	
	inorder(node->left);
	cout<<node->data<<" ";
	inorder(node->right);
}


void preorder(Node *node)
{
        if(node==NULL)
        {
                return;
        }
        cout<<node->data<<" ";
        preorder(node->left);
        preorder(node->right);
}


void postorder(Node *node)
{
       	if(node==NULL)
        {
               	return;
        }
        postorder(node->left);
        postorder(node->right);
	cout<<node->data<<" ";

}


};


int main()
{
Node *root = new Node(10);
Tree *t = new Tree();
t->insert(root,new Node(7));
t->insert(root,new Node(3));
t->insert(root,new Node(11));
cout<<endl;
cout<<"----------INORDER--------"<<endl;
t->inorder(root);
cout<<endl;
cout<<"----------PREORDER--------"<<endl;
t->preorder(root);
cout<<endl;
cout<<"----------POSTORDER--------"<<endl;
t->postorder(root);
cout<<endl;
return 0;
}

