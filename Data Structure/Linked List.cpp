#include "pch.h"
#include <iostream>
using namespace std;

struct node {
	int data;
	node *right,*left;
};
void insert(node *p, node *q, int x)
{
	node *r = new node();
	r->data = x;
	r->right = q;
	r->left = p;
	p->right = r;
	q->left = r;
}
void print(node *list)
{
	node *p = list;
	while (p != NULL)
	{
		cout << p->data;
		p = p->right;
	}
}
int main()
{
	node *a, *b, *c;
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
	print(a);
	cout << endl;
	insert(b,c, 3);
	print(a);

}
