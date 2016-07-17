#include<iostream>
#include<vector>

using namespace std;

int cnt = 0;

void recur(int row, vector<int> colcheck, vector<string> &board)
{
	if (row == 6) {
		int sumcheck = 0;
		for (int a:colcheck) {
			cout << a << endl;
			sumcheck += a;
		}
		if (sumcheck == 0)
			cnt++;
		return;
	}
	int start[3] = {-1, -1, -1};
	for (int ii = 0, jj = 0; ii < 6; ii++)
		if (board[row][ii] == 'o')
			start[jj++] = ii;
	int end[3] = {5, 5, 5};
	for (int ii = 0; ii < 3; ii++)
		if (start[ii] != -1)
			end[ii] = start[ii];
	//cout << start[0] << start[1] << start[2] << endl;
	//cout << end[0] << end[1] << end[2] << endl;
	for (int i = (start[0] == -1 ? 0 : start[0]); i <= end[0]; i++) {
		if (colcheck[i] == 0)
			continue;
		else
			colcheck[i]--;
		for (int j = (start[1] == -1 ? i : start[1]); j <= end[1]; j++) {
			if (colcheck[j] == 0)
				continue;
			else
				colcheck[j]--;
			for (int k = (start[2] == -1 ? j : start[2]); k <= end[2]; k++) {
				if (colcheck[k] == 0)
					continue;
				else
					colcheck[k]--;
				cout << row << i << ' ' << j << ' ' << k << endl;
				recur(row + 1, colcheck, board);
			}
		}
	}
	return;
}

int main()
{
	vector<string> board(6);
	for (int i = 0; i < 6; i++)
		cin >> board[i];
	vector<int> colcheck(6, 3);
	recur(0, colcheck, board);
	cout << cnt << endl;
	return 0;
}



