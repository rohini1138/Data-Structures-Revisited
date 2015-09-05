#include <iostream>
#include <stdlib.h>
using namespace std;

class NODE
{
public:
	int data;
	NODE *right;
	NODE *left;
};

	NODE *first;
	NODE *top;
	NODE *new1;

class manager
{
public:


	void push()
	{
	
		if(first==NULL)
		{
			cout<<"first node";
			first = new NODE();
			first->left=NULL;
			first->right=NULL;
			cout<<endl<<"Enter the data"<<endl;
			cin>>first->data;
			top=first;
		}
		else
		{
			new1 = new NODE();
			cout<<"new1 node";
			new1->right=NULL;
			new1->left=top;
			cout<<endl<<"Enter the data"<<endl;
			cin>>new1->data;
			top->right = new1;
			top=new1;
		}
	}

	void display()
	{
		cout<<endl<<"THE STACK ELEMENTS ARE : "<<endl;
		NODE *ptr;
		ptr = top;
		while(ptr->left != NULL)
		{
			cout<<ptr->data<<endl;
			ptr = ptr->left;
		}
		cout<<ptr->data<<endl; 
	}
	
	/*void displayreverse()
	{
		NODE *ptr;
		ptr = current;
		while(ptr->left != NULL)
		{
			cout<<ptr->data<<" ";
			ptr = ptr->left;
		}
		cout<<ptr->data<<" "; 
	}*/
	
	void count()
	{
		NODE *ptr;
		ptr = top;
		int count = 0;
		while(ptr->left != NULL)
		{
			count++;
			ptr = ptr->left;
		}
		count++;
		cout<<endl<<"TOTAL NODES = "<<count;
	}
	
	/*void deletenode()
	{
		cout<<endl<<"Enter the node to delete"<<endl;
		int delitem;
		cin>>delitem;
		NODE *ptr = first;
		
		while(ptr->right!=NULL)
		{
			if(first->data == delitem)
			{
				first = first->right;
				break;
			}
			if(current->data == delitem)
			{	
				current = current->left;
				current->right=NULL;
				break;
			}
			if(ptr->data == delitem)
			{
				
				cout<<endl<<"ptr = "<<ptr->data;
				(ptr->left)->right=ptr->right;
				(ptr->right)->left=ptr->left;
				break;
			}
			cout<<ptr->data<<" ";
			
			ptr = ptr->right;
			
		}*/
		
		void pop()
		{
			cout<<endl<<top->data<<" popped succuessfully"<<endl;
			top = top->left;
			top->right = NULL;
		}
		
	

};

int main()
{
	manager m;
	int menuchoice;
	int exitchoice;
	
	do
	{
		cout<<"-----LINKED LIST-------"<<endl;
		cout<<"1)PUSH ELEMENT"<<endl;
		cout<<"2)POP ELEMENTS"<<endl;
		cout<<"3)DISPLAY"<<endl;
		cout<<"4)COUNT NODES"<<endl;
		cout<<"5)EXIT"<<endl;
		cout<<"ENTER CHOICE : ";
		cin>>menuchoice;
		
		switch(menuchoice)
		{
			case 1:
				m.push();
				break;
			case 2:
				m.pop();
				break;
			case 3:
				m.display();
				break;
			case 4:
				m.count();
				break;
			case 5:
				exit(0);
				break;
		}
		
		cout<<endl<<"DO YOU WANNA CONTINUE 1) YES 2) NO "<<endl;
		cin>>exitchoice;
	}while(exitchoice==1);
	return 0;
}
