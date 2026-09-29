#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
using namespace std;

int get_result(unordered_map<string, int> store) {
	int taxi_cnt = 0;

	taxi_cnt += store["4"];
	
	// check weather 2's stack is more efficient than 2-1's stack
	

	if (store["1"] >= 2*store["2"]) {
		store["1"] -= 2*store["2"];
	} else {
		store["1"] = 0;
	}

	if (store["1"] >= store["3"]) {
		store["1"] -= store["3"];
	} else {
		store["1"] = 0;
	}

	taxi_cnt += (store["2"] + store["1"] + store["3"]);
	return taxi_cnt;
}

int main() {
	int n;
	unordered_map<string, int> store;
	store["1"] = 0;
	store["2"] = 0;
	store["3"] = 0;
	store["4"] = 0;

	cin >> n;

	for (int i = 0; i < n; i++) {
		int num;
		cin >> num;

		if (num == 1) store["1"]++;
		else if (num == 2) store["2"]++;
		else if (num == 3) store["3"]++;
		else if (num == 4) store["4"]++;

	}

	int res = get_result(store);

	cout << res;
	return 0;
}
