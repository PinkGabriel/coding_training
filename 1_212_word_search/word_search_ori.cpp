#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
	bool exist(vector<vector<char>>& board, string word) {
		m = board.size();
		n = board[0].size();
		for(int i = 0; i < m; i++) {
			for(int j = 0; j < n; j++) {
				if(find(board,word.c_str(),i,j)) {
					return true;
				}
			}
		}
		return false;
	}
private:
	int m, n;
	bool find(vector<vector<char>>& board, const char* w, int x, int y) {
		if(x < 0 || x >= m || y < 0 || y >= n || board[x][y] == '\0' || *w != board[x][y]) {
			return false;
		}
		if(*(w + 1) == '\0') {
			return true;
		}
		char temp = board[x][y];
		board[x][y] = '\0';
		if(find(board, w + 1, x -1, y) || find(board, w + 1, x + 1, y) ||
			find(board, w + 1, x, y - 1) || find(board, w + 1, x, y + 1)) {
			return true;
		}
		board[x][y] = temp;
		return false;
	}
};

int main()
{
	string input;
	vector<vector<char> > board = {{'a','b','c'},{'e','b','a'},{'e','c','b'},{'a','e','c'}};
	//g++ -std=c++11 1_word_search_ori.cpp
	int m = board.size();
	int n = board[0].size();
	for(int i = 0; i < m; i++) {
		for(int j = 0; j < n; j++) {
			cout << board[i][j] << ' ';
		}
		cout << endl;
	}
	Solution s;
	cout << "input a word:" << endl;
	while(cin >> input) {
		cout << input << endl;
		if(s.exist(board, input)) {
			cout << "true" << endl;
		}else {
			cout << "false" << endl;
		}
	}
	return 0;
}
