/*
	Ishan Bhatt, 14 March 2017
	Binary Search Tree
	insert, all traverse functions, copy and compare trees	
*/
#include<iostream>
using namespace std;

class node{
	private:
		int data;
		node* left;
		node* right;
	public:
		node(){
			data =NULL;
			left = right = NULL;
		}
		node(int a){
			data =a;
			left = right = NULL;
		}
		void insert(node*);
		void travLVR();
		void travVLR();
		void travLRV();
	friend void copy(node*, node*);
	friend void compare(node*, node*);
};

void node::insert(node* new1){
		if(this->data == NULL){
			this->data = new1->data;
			return;
		}
		
		if((new1->data) > (this->data)){
			if(this->right == NULL)
				this->right = (new node(new1->data));
			else
				this->right->insert(new1);
		}
		else{
			if(this->left == NULL)
				this->left = (new node(new1->data));
			else
				this->left->insert(new1);
		}
}
void node::travVLR(){
	cout<<this->data<<endl;
	if(this->left != NULL)
		this->left->travVLR();
	if(this->right != NULL)
		this->right->travVLR();
}
void node::travLVR(){
	if(this->left != NULL)
		this->left->travLVR();
	cout<<this->data<<endl;
	if(this->right != NULL)
		this->right->travLVR();
}
void node::travLRV(){
	if(this->left != NULL)
		this->left->travLRV();
	if(this->right != NULL)
		this->right->travLRV();
	cout<<this->data<<endl;	
}
void copy(node* source, node* target){
	target->insert(source);
	if(source->left != NULL)
		copy(source->left, target);
	if(source->right != NULL)
		copy(source->right,target);
}
void compare(node* a, node* b){
	if(a->data != b->data)
		throw 1;
	if((a->left == NULL && b->left != NULL) ||(a->left != NULL && b->left == NULL))
		throw 1;
	else if(a->left != NULL && b->left != NULL)
		compare(a->left, b->left);

	if((a->right == NULL && b->right != NULL) ||(a->right != NULL && b->right == NULL))
		throw 1;
	else if(a->right != NULL && b->right != NULL)
		compare(a->right, b->right);
}



int main(){
	node* first;
	first = new node[1];	
	node* c;
	c = new node[1];
	first->insert(new node(2));
	first->insert(new node(11));
	first->insert(new node(9));
	first->insert(new node(45));
	first->insert(new node(90));
	first->insert(new node(110));
	copy(first, c);
	first->travVLR();
	cout<<endl;
	c->travVLR();
	node* d;
	d = new node[1];
	d->insert(new node(5));
	d->insert(new node(4));
	d->insert(new node(6));
	d->insert(new node(11));
	
	try{
		compare(first, c);
		cout<<"Trees are same.\n";
	}catch(int a){
		cout<<"Trees are not same.\n";		
	}
	try{
		compare(first, d);
		cout<<"Trees are same.\n";
	}catch(int a){
		cout<<"Trees are not same.\n";		
	}
	
	return 0;
}


















