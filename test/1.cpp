#include<iostream>
#include<string>

using namespace std;

int main()
{
	string input;
	string output;
	cin >> input;
	for (int i = 0; i < input.length(); i++) {
		if (input[i] == ',') {
			cout << output << endl;;
			output = "";
		} else
			output += input[i];
	}
	cout << output << endl;;
	return 0;
}
