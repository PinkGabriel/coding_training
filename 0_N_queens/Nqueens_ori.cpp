#include<iostream>
#include<vector>
#include<iomanip>
#include<cstdlib>
#include<sys/time.h>

using namespace std;

int count = 0;
int n = 0;

void print(vector<int> &chessboard)
{
	cout << "this is the " << count << "th result:" << endl;
	for (int j = 0; j < n; j++) {
		for(int i = 0; i < n; i++) {
			cout << (i == chessboard[j] ? 1 : 0);
			cout << setw(2); //设置下一个输出的宽度
		}
		cout << '\n';
	}
	cout << '\n';
	return;
}

bool valid(int CurRow, int i, vector<int> &chessboard)
{
	for(int j = 0; j < CurRow; j++) {
		if(i == chessboard[j] || abs(i - chessboard[j]) == abs(CurRow - j)) {
			return false;
		}
	}
	return true;
}

void nqueens(int CurRow, vector<int> &chessboard)
{
	if(CurRow == n) {
		count++;
		print(chessboard);
		return;
	}
	for(int i = 0; i < n; i++) {
		chessboard[CurRow] = i;
		if(valid(CurRow, i, chessboard)) {
			nqueens(CurRow + 1, chessboard);
		}
	}
	return;
}

int main()
{
	struct timeval start;
	struct timeval end;
	unsigned long time;

	cout << "input the number of queens: " << endl;
	cin >> n;
	vector<int> chessboard(n);

	gettimeofday(&start,NULL);
	nqueens(0, chessboard);
	gettimeofday(&end,NULL);

	time = 1000000 * (end.tv_sec-start.tv_sec)+ end.tv_usec-start.tv_usec;
	cout << "total " << count << " results" << endl;
	cout<<"runtime: "<< time << " ums" << endl;
	return 0;
}
