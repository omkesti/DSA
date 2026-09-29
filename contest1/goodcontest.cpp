#include <iostream>
#include <string>
#include <vector>
#include <set>

using namespace std;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;

int main() {
	int n, sz;
	set<int> s;
	cin>> n;

	for (int i = 0; i < n; i++) {
		s.clear();
		cin >> sz;
		for (int j = 0;j<3;j++) {
			int data;
			cin >> data;
			s.insert(data);
		}
		
		cout << sz - (*(next(s.begin(), 0)));
		cout << endl;
	}
	
	return 0;
}

