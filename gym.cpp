#include <iostream>
using namespace std;

int main() {
	int n;

	cin >> n;

	for (int i=0;i<n;i++) {
		int c, h, o;
		cin>>c>>h>>o;

		if (h == 2*c - 4) cout << "Saturated" << endl;
		else if (h < 2*c - 4) cout << "Unsaturated" << endl;
	}
	return 0;
}
