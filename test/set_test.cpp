#include<iostream>
#include<string>
#include<vector>
#include<unordered_set>
#include<set>
#include<algorithm>

using namespace std;

struct setComp
{
   //bool operator()(const pair<int, int> &a,const pair<int, int> &b) //wrong, set只能按key排序
   bool operator()(const int &a,const int &b)
       {
		return a < b;
       }
};

int main()
{
	set<int> m;
	//set<int> order;
	//set<int, greater<int> > order;
	//set<int, setComp > order;
	//set<int, setComp > order({3,2,1,5,0,10,12});
	//unordered_set<int, setComp > order({3,2,1,5,0,10,12});
	unordered_set<int> order;
	
// /*
	order.insert(567);
	order.insert(321);
	order.insert(23);
	order.insert(123);
	order.insert(12);
	order.insert(666);
// */
	for(auto it = order.begin(); it != order.end(); it++) {
		cout << *it << ' ';
	}
	cout << endl;

 /*
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

	if(order.find(666) == m.end()) {
		cerr << "not find" << endl;
	} else {
		cout << "find" << endl;
	}

// */
	return 0;
}
