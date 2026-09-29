#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>

using namespace std;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef string str;

int get_result(unordered_map<str, int> groups) {
	int taxi_cnt = 0;
	int ones = groups["1"], twos = groups["2"], threes = groups["3"];

	// All the 4's added to a single taxi.
	taxi_cnt += groups["4"];

	// Some greedy method for 2's and 1's to decide with whom to group with...
	// stack all 1's together...
	if (ones > 1 && twos == 0 && threes == 0) {	
		(ones >= 4) ? taxi_cnt += (ones/4) : taxi_cnt += 1;
		(ones >= 4) ? ones = ones%4 : ones = 0;
	}

	// stack all two's together
	if (twos > 1) {
		taxi_cnt += (twos/2);
		twos = twos%2;
	}

	// stack all 1's into 2's
	if (ones >= 2*twos) {
		taxi_cnt += twos;
		ones -= 2*twos;
		twos = 0;
	} else {
		if (ones&2 != 0) {
			taxi_cnt += (ones/2) + 1;
			twos -= (ones/2) + 1;
			ones = 0;
		} else {
			taxi_cnt += ones/2;
			twos -= (ones/2);
			ones = 0;
		}
	}

	// stack all 1's into 3's
	if (ones >= threes) {
		taxi_cnt += threes;
		ones -= threes;
		threes = 0;
	} else {
		taxi_cnt += ones;
		threes -= ones;
		ones = 0;
	}

	// if any ones left
	if (ones > 1) {	
		(ones >= 4) ? taxi_cnt += (ones/4) : taxi_cnt += 1;
		(ones >= 4) ? ones = ones%4 : ones = 0;
	}

	taxi_cnt += (ones + twos + threes);
	return taxi_cnt;
}
int main() {
	int n;
	unordered_map<str, int> groups;

	groups["1"] = 0;
	groups["2"] = 0;
	groups["3"] = 0;
	groups["4"] = 0;

	cin >> n;
	for (int i = 0;i<n;i++) {
		int num;
		cin >> num;
		
		if (num==1) groups["1"]++;
		else if (num==2) groups["2"]++;
		else if (num==3) groups["3"]++;
		else if (num==4) groups["4"]++;
	}

	cout << get_result(groups);

	return 0;
}
