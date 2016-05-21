#include<iostream>
#include<fstream>
#include<string>
#include<queue>

using namespace std;

typedef struct bstnode{
	int val;
	struct bstnode *parent;
	struct bstnode *left;
	struct bstnode *right;
} Node;

Node *head = NULL;

bool InsertNode(int value)
{
	Node *temp = head;
	Node *ptemp = NULL;
	while (temp != NULL) {
		ptemp = temp;
		if (temp->val > value) {
			temp = temp->left;
		} else {
			temp = temp->right;
		}
	}
	Node *newnode = new(nothrow) Node;
	if (newnode == NULL) {
		return false;
	}
	newnode->val = value;
	newnode->parent = ptemp;
	newnode->left = NULL;
	newnode->right = NULL;
	if (head == NULL) {
		head = newnode;
		return true;
	}
	if (ptemp->val > value) {
		ptemp->left = newnode;
	} else {
		ptemp->right = newnode;
	}
	return true;
}

void TreeCreate()
{
	int temp;
	ifstream infile("input.txt");
	//cout << "enter the new node's val, EOF to end: ";
	while (infile >> temp) {
		if (InsertNode(temp))
			cout << "insert success, continue enter or EOF to end" << endl;
		else
			cerr << "insert error" <<endl;
	}
	return;
}

void BFS_PrintTree()
{
	Node *temp;
	queue<Node *> q;
	q.push(head);
	Node *sentinel = new Node;
	sentinel->val = -1;
	sentinel->parent = NULL;
	sentinel->left = NULL;
	sentinel->right = NULL;
	q.push(sentinel);
	cout << "BFS:" << endl;
	while (!q.empty()) {
		temp = q.front();
		if (temp->val == -1) {
			cout << '\n';
			q.pop();
			if (q.empty()) {
				return;
			}
			q.push(sentinel);
			continue;
		}
		if (temp == head)
			cout << temp->val << "   ";
		else
			cout << temp->val << '(' << temp->parent->val << ')' << "   ";
		if (temp->left) {
			q.push(temp->left);
		}
		if (temp->right) {
			q.push(temp->right);
		}
		q.pop();
	}
	return;
}

void PreOrderRecur()
{
	return;
}
void MidOrderRecur()
{
	return;
}
void PostOrderRecur()
{
	return;
}

void PreOrderIter()
{
	return;
}
void MidOrderIter()
{
	return;
}
void PostOrderIter()
{
	return;
}

int main()
{
	string str;
	TreeCreate();
	BFS_PrintTree();
	return 0;
}
