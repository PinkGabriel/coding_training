#include<iostream>

using namespace std;

int maxdeep = 0;
void deep_test(int n)
{
	if (n == maxdeep)
		return;
	deep_test(n + 1);
}

int main()
{
	cout << "input depth to test:   " << endl;
	cin >> maxdeep;
	deep_test(1);
	cout << maxdeep << " is OK";
	return 0;
}
