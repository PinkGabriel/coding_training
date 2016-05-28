#include<iostream>
#include<cstdlib>
#include<queue>

using namespace std;

typedef struct bstnode{
	int val;
	struct bstnode *left;
	struct bstnode *right;
} Node;

Node *BuildTree(int *pre, int *mid, int len)
{
	Node *root = new Node;
	root->val = pre[0];
	root->left = root->right = NULL;
	if(len == 1) {
		if(pre[0] != mid[0]) {
			cerr << "input invalid" << endl;
			exit(0);
		}
		return root;
	}

	int i;
	for(i = 0; i < len; i++) {
		if(mid[i] == pre[0]) {
			break;
		}
	}

	if(i == len) {
		cerr << "input invalid" << endl;
		exit(0);
	}

	if(i > 0) {
		root->left = BuildTree(pre + 1, mid, i);
	}
	if(i < (len - 1)) {
		root->right = BuildTree(pre + i + 1, mid + i + 1, len - i -1);
	}

	return root;
}

void BFS_print(Node *root)
{
	queue<Node *> q;
	Node *temp;
	q.push(root);
	while(!q.empty()) {
		temp = q.front();
		cout << temp->val << endl;
		if(temp->left) {
			q.push(temp->left);
		}
		if(temp->right) {
			q.push(temp->right);
		}
		q.pop();
	}
	return;
}

int main()
{
//	int PreOrder[6] = {1,2,4,7,3,5,6,8};
//	int MidOrder[6] = {4,7,2,1,5,3,8,6};
	int PreOrder[6] = {1,2,4,3,6,8};
	int MidOrder[6] = {4,2,3,1,8,6};

//error
//	int PreOrder[6] = {1,2,4,3,6,8};
//	int MidOrder[6] = {4,2,1,3,7,6};
	Node *root = BuildTree(PreOrder,MidOrder,6);
	BFS_print(root);
	return 0;
}
