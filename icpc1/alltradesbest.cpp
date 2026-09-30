//#include <bits/stdc++.h>
#include <iostream>
#include <vector>
#include <string>
#include <queue>
using namespace std;

typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef string str;
typedef vector<str> vstr;

int get_profit(int n, int k, vi pattern, int l, int r);
vi get_range(vi vec, int l, int r);
int max(int x, int y);

int main() {
	int n, k,q;
	vi pattern;

	cin>>n>>k>>q;

	for (int i=0;i<n;i++) {
		int a;
		cin>>a;
		pattern.push_back(a);
	}

	for (int i=0;i<q;i++) {
		int l, r;
		cin>>l>>r;

		cout << get_profit(n, k, pattern, l, r)<<endl;
	}

	return 0;
}

int get_profit(int n, int k, vi pattern, int l, int r)
{
	if (l == r) return 0;

	vi interv = get_range(pattern, l, r);
	int profit = 0;

	std::vector<int> initial_vec(k, INT_MIN);
	priority_queue<int, vector<int>, greater<int>> trans(initial_vec.begin(), initial_vec.end());
	
	auto buy = pattern.begin();
	auto sell = buy + 1;
	
	int loc_large = INT_MIN;

	while (buy!=pattern.end())
	{
		if (*buy >= *sell) {
			buy++;
			sell++;
			continue;
		}
		else {
			loc_large = INT_MIN;
			while(*sell > *buy && sell != pattern.end()) {
				loc_large = max(loc_large, *sell);
				sell++;
			}

			int prof = loc_large-(*buy);
			trans.pop();	
			trans.push(prof);

			buy = sell-1;
		}
	}

	for (int i = 0;i<k;i++) {
		if (trans.top() != INT_MIN) profit+=trans.top();
		trans.pop();
	}

	return profit;
	
}

vi get_range(vi vec, int l, int r)
{
	vi temp;	
	if (l <= r) {
		for (int i=l-1; i<=r-1;i++) {
			temp.push_back(vec[i]);
		}
	}
	else
	{
		int i=l;

		while(i != r) {
			temp.push_back(vec[i]);

			if (i+1 == vec.size()) i=0;
			else i++;
		}
	}

	return temp;
}

int max(int x, int y) 
{
	if (x > y) return x;
	else return y;
}
