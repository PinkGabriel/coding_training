#include<iostream>
#include<vector>

using namespace std;

int main()
{
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
	return 0;
}
