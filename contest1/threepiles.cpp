#include <iostream>
#include <vector>
#include <string>
#include <cstdlib>

using namespace std;
typedef vector<int> vi;

int get_result(vi piles) {
	int a = piles[0], b = piles[1], c = piles[2];

	if (a == b) {
		return (a+c) - b;
	}
	else if (a > b) {
		return (a+c) - b;
	}
	else {	
		if (abs((a+c) - b) > b - a) return abs((a+c)-b);
		else return b-a;
	}
	
}

int main() {
	int n;
	vi piles;
	int data;

	cin >> n;

	for (int i =0;i<n;i++) {
		piles.clear();
		for (int j=0;j<3;j++) {
			cin >>data;
			piles.push_back(data);
		}

		cout << get_result(piles) << endl;
	}

	return 0;
}
