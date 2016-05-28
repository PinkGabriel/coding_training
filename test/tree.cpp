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

//////Method 1. 模仿递归
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

//////Method 2. 手动遍历
// /*
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
// */

	return;
}
void InOrderIter()
{

//////Method 1. 模仿递归 标记是否首次入栈
// /*
	stack< pair<Node*,int> > s;
	Node *temp = NULL;
	int flag;
	s.push(make_pair(head,1));
	while(!s.empty()) {
		temp = s.top().first;
		flag = s.top().second;
		s.pop();
		if(flag) {
			if(temp->right)
				s.push( make_pair(temp->right,1) );
			s.push( make_pair(temp,0) );
			if(temp->left)
				s.push( make_pair(temp->left,1));
		}
		else
			cout << temp->val << endl;
	}

// */

//////Method 2. 手动遍历
 /*
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
// */

	return;
}
void PostOrderIter()
{

//////Method 1.1 模仿递归
 /*
	stack<Node *> s;
	Node *cur = NULL;
	Node *prev = NULL;
	s.push(head);
	while(!s.empty()) {
		cur = s.top();
		if( (cur->left == NULL && cur->right == NULL) ||
			(prev != NULL && (prev == cur->left || prev == cur->right))) {
			s.pop();
			cout << cur->val << endl;
			prev = cur;
		}else {
			if(cur->right) {
				s.push(cur->right);
			}
			if(cur->left) {
				s.push(cur->left);
			}
		}
	}
// */

//////Method 1.2 模仿递归 标记第几次入栈
// /*
	stack< pair<Node*,int> > s;
	Node *temp = NULL;
	int flag;
	s.push(make_pair(head,1));
	while(!s.empty()) {
		temp = s.top().first;
		flag = s.top().second;
		s.pop();
		if(flag) {
			s.push( make_pair(temp,0) );
			if(temp->right)
				s.push( make_pair(temp->right,1) );
			if(temp->left)
				s.push( make_pair(temp->left,1));
		}
		else
			cout << temp->val << endl;
	}

// */

	return;
}

int main()
{
	string str;
	TreeCreate();
	BFS_PrintTree();
//	PreOrderIter();
	InOrderIter();
	cout << endl;
	PostOrderIter();
	return 0;
}
