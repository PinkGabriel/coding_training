#include<iostream>
#include<string>
#include<vector>
#include<map>
#include<algorithm>

using namespace std;

struct mapComp
{
   //bool operator()(const pair<int, int> &a,const pair<int, int> &b) //wrong, map只能按key排序
   bool operator()(const int &a,const int &b)
       {
		return a > b;
       }
};

int main()
{
	map<int, int> m;
	//map<int, int> order;
	//map<int, int, greater<int> > order;
	map<int, int, mapComp > order;
	
	order.insert({223,12});
	order.insert({23,12});
	order.insert({13,12});
	order.insert({123,12});
	order.insert({666,12});
	order.insert({3,12});
	order.insert({345,12});
	order.insert({168,12});
	for(auto it = order.begin(); it != order.end(); it++) {
		cout << it->first << ' ';
	}
	cout << endl;

	m[1]++;
	cout << "if not exist: " << m[1] << "." <<endl;
	m[1]++;
	cout << "if not exist: " << m[1] << "." <<endl;

	if(m.find(1) == m.end()) {
		cerr << "not find" << endl;
	} else {
		cout << "find" << endl;
	}

	if(m.find(0) == m.end()) {
		cerr << "not find" << endl;
	} else {
		cout << "find" << endl;
	}

	if(m.find(0) == m.end()) {
		cerr << "not find" << endl;
	} else {
		cout << "find" << endl;
	}

	int i = m[0];

	if(m.find(0) == m.end()) {
		cerr << "not find" << endl;
	} else {
		cout << "find" << endl;
		cout << m[0] << endl;
	}

	return 0;
}
