#include "pch.h" 
#include <iostream>
using namespace std;

struct node {
	int data;
	node *left, *right, *next;
};
node * reverse(node * p, node * previous)
{
	node * list;
	if (p->right == NULL) {
		p->right = previous;
		return p;
	}
	else {
		list = reverse(p->right, p);
		p->right = previous;
		return list;
	}
}
void print_2(node *start) {
	node *p = start;
	while (p) {
		cout << p->data << "    ";
		p = p->right;
	}
}
int main()
{
	node *list, *a, *b, *c, *d;
	list = new node();
	a = new node();
	b = new node();
	c = new node();

	a->data = 1;
	b->data = 2;
	c->data = 4;

	a->left = NULL;
	b->left = a;
	c->left = b;
	a->right = b;
	b->right = c;
	c->right = NULL;



	reverse(a, b);
	print_2(a);
	

}
