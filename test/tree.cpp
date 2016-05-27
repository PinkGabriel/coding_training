#include<iostream>
#include<fstream>
#include<string>
#include<queue>
#include<stack>
#include<stdlib.h>

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
	if(!infile) {
		cerr << "file open fail";
		exit(0);
	}
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
void InOrderRecur()
{
	return;
}
void PostOrderRecur()
{
	return;
}

void PreOrderIter()
{
 /*
	stack<Node *> s;
	Node *temp = NULL;
	s.push(head);
	while(!s.empty()) {
		temp = s.top();
		s.pop();
		cout << temp->val << endl;
		if(temp->right) {
			s.push(temp->right);
		}
		if(temp->left) {
			s.push(temp->left);
		}
	}
// */
	stack<Node *> s;
	Node *temp = NULL;
	s.push(head);
	while(!s.empty()){ //每层循环处理一个节点的左边一排左孩子和一个右孩子
		temp = s.top();
		while(temp) { //push一排左孩子（如果存在的话）
			cout << temp->val << endl;
			temp = temp->left;
			s.push(temp);
		}
		s.pop();
		if(!s.empty()) { //push一个右孩子
			temp = s.top();
			s.pop(); //pop这排中最后一个左孩子
			s.push(temp->right);
		}
	}
	return;
}
void InOrderIter()
{
	stack<Node *> s;
	Node *temp = NULL;
	s.push(head);
	while(!s.empty()){ //每层循环处理一个节点的左边一排左孩子和一个右孩子
		temp = s.top();
		while(temp) { //push一排左孩子（如果存在的话）
			temp = temp->left;
			s.push(temp);
		}
		s.pop();
		if(!s.empty()) { //push一个右孩子
			temp = s.top();
			cout << temp->val << endl;
			s.pop(); //pop这排中最后一个左孩子
			s.push(temp->right);
		}
	}
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
	PreOrderIter();
	InOrderIter();
	return 0;
}
