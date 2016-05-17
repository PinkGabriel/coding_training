#include<iostream>
#include<string>
#include<queue>

using namespace std;

typedef struct bstnode{
	int val;
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
	cout << "enter the new node's val, EOF to end: ";
	while (cin >> temp) {
		if (InsertNode(temp))
			cout << "insert success, continue enter or EOF to end" << endl;
		else
			cerr << "insert error" <<endl;
	}
	return;
}

void PrintTree()
{
	Node *temp;
	queue<Node *> q;
	q.push(head);
	while (!q.empty()) {
		temp = q.front();
		cout << temp->val << endl;
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

int main()
{
	string str;
	TreeCreate();
	PrintTree();
	return 0;
}
