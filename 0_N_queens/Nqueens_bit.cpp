#include<iostream>
#include<vector>
#include<iomanip>
#include<cstdlib>
#include<sys/time.h>

using namespace std;

int count = 0;
int n = 0;
int upperlim = 0;

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

/***************************************
 * 
 * row ld rd中的1表示已被占用的列，两条对角线占用的列
 * 每一层调用解决一行，并递归解决下一行。跟普通N皇后一样的。
 * 只能统计总数，不能输出各层结果
 *
 ***************************************/

void nqueens_bit(int row, int ld, int rd)  
{
	int pos, p;
	if ( row != upperlim ) {  
		pos = upperlim & (~(row | ld | rd ));	//pos即当前行的棋盘。1表示当前可放置的位置
		while ( pos ) {  
			p = pos & (~pos + 1);		//pos & (~pos + 1)即pos最右边的1
			pos = pos - p;			//从右向左占据一个位置
			nqueens_bit(row | p, (ld | p) << 1, (rd | p) >> 1);  
		}  
	}else {
		++count;  
	}
}  

void nqueens_bit_print(int row, int ld, int rd, int cur, vector<int> &chessboard)  
{
	int pos, p, i;
	//if ( row != upperlim ) {  
	if ( cur != n ) {  
		pos = upperlim & (~(row | ld | rd ));	//pos即当前行的棋盘。1表示当前可放置的位置
		while ( pos ) {
			p = pos & (~pos + 1);		//pos & (~pos + 1)即pos最右边的1
			pos = pos - p;			//从右向左占据一个位置

			 /*统计number中1的个数,循环次数为1的个数
			while (number) {
				counter++;  
				number &= number - 1 ;  
			} 
			// */

			// /*不够优雅
			for(i = 0; i < n; i ++) {
				if(p & (1 << i)) {
					break;
				}
			}
			// */

			chessboard[cur] = i;
			nqueens_bit_print(row | p, (ld | p) << 1, (rd | p) >> 1, cur + 1, chessboard);  
		}  
	}else {
		++count;  
		print(chessboard);
	}
}

int main()
{
	struct timeval start;
	struct timeval end;
	unsigned long time;

	cout << "input the number of queens: " << endl;
	cin >> n;
	vector<int> chessboard(n);
	upperlim = (1 << n) - 1; //n个1

	gettimeofday(&start,NULL);
	nqueens_bit(0, 0, 0);
	//nqueens_bit_print(0, 0, 0, 0, chessboard);
	gettimeofday(&end,NULL);

	time = 1000000 * (end.tv_sec-start.tv_sec)+ end.tv_usec-start.tv_usec;
	cout << "total " << count << " results" << endl;
	cout<<"runtime: "<< time << " ums" << endl;
	return 0;
}
