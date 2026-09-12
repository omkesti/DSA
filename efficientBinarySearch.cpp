#include <iostream>
using namespace std;

int main() {
	int arr[] = {10, 20, 30, 50, 70, 120, 450};
	int k = 0, n = sizeof(arr)/sizeof(int);
	int target = 70;

	for (int b = n/2; b >= 1; b/=2) {
		while (k+b < n && arr[k+b] <= target) k+=b;
	}

	if (arr[k] == target) {
		cout << "Found at " << k << endl;
	} else {
		cout << target << " not found" << endl;
	}

	return 0;
}
