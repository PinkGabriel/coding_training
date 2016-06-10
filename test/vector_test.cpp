#include<iostream>
#include<vector>

using namespace std;

int main()
{
	vector<int> erase_test = {1,1,2,3,5,6,9};
	erase_test.erase(erase_test.begin(),erase_test.begin() + 1);
	for(auto i:erase_test) {
		cout << i << ' ';
	}
	cout << endl;
	//vector<char> board = {'a','b','c','e','b','a','e','c','b','a','e','c'};
	vector<vector<char> > board = {{'a','b','c'},{'e','b','a'},{'e','c','b'},{'a','e','c'}};
	//g++ -std=c++11 1_word_search_ori.cpp
	//vector<vector<int> > vecInt(m, vector<int>(n)); 
	int m = board.size();
	int n = board[0].size();
	cout << m << endl;
	cout << n << endl;
	for(int i = 0; i < m; i++) {
		for(int j = 0; j < n; j++) {
			cout << board[i][j] << ' ';
			//cout << board[i] << endl;
		}
		cout << endl;
	}
	
	cout << endl << endl << endl;
	vector<int> v1 = {1,2,3};
	vector<int> v2 = {4,5,6};
	auto iter = v1.begin();
	for(; iter != v1.end(); iter++) {
		if(*iter == 2)
			break;
	}
	v1.insert(v1.erase(iter),v2.begin(),v2.end());
	iter = v1.begin();
	cout << "iter point to: " << *iter << endl;
	for(auto i:v1) {
		cout << i << ' ';
	}
	cout << endl << endl << endl;

	vector<int> v3 = {1,2,3};
	vector<int> v4 = {4,5,6};
	int wao = 4;
	v3 = v4;
	v4 = {wao, 2};
	for(auto i:v3) {
		cout << i << ' ';
	}
	cout << endl << endl << endl;
	for(auto i:v4) {
		cout << i << ' ';
	}
	cout << endl << endl << endl;

	return 0;
}
