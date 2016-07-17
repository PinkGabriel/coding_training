#include<iostream>
#include<vector>

using namespace std;

int main()
{
	int n, cnt = 0;
	cin >> n;
	vector<int> dots(n + 1, 1);
	vector<int> arr(n + 1, 0);
	for (int i = 1; i <= n; i++)
		cin >> arr[i];
	for (int i = 1; i <= n; i++) {
		if (dots[i]) {
			int start = i, temp = i;
			while (arr[temp] != start) {
				temp = arr[temp];
				dots[temp] = 0;
			}
			dots[temp] = 0;
			cnt++;
		}
	}
	cout << cnt << endl;
	return cnt;
}
