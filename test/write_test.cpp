#include<iostream>
#include<vector>
#include<cstdlib>
#include<fstream>
using namespace std;

int main()
{
	int random = 100;
	int r;
	ofstream outfile("outputfile",ios_base::app);
	vector<int> v(8);
	v[0] = 1;

	srand(time(NULL));
	r = rand() % random;
	cout << v[0] << '\n' << r << '\n';
	if (!outfile)
		cerr << "error\n";
	else
		outfile << "Hello World!" << endl;
	return 0;
}
