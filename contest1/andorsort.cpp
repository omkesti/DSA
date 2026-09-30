#include <iostream>
#include <string>
#include <vector>

using namespace std;
typedef string str;

vector<int> numberize(str s, str::iterator it)
{
	vector<int> store;
	int target = it - s.begin();
	for (int i = 0;i<=target;i++) {
		if (s[i] == '1') store.push_back(1);
		else store.push_back(0);
	}
	return store;
}

int OR_operation(str s, str::iterator target) {
	int val = 0;
	int diff = target-s.begin();
	vector<int> store = numberize(s, target);

	for (int i = 0; i <= diff ; i++) {
		val = val | (store[i]);
	}

	return val;
}

int AND_operation(str s, str::iterator target) {
	int val = 1;
	int diff = target-s.begin();
	vector<int> store = numberize(s, target);

	for (int i = 0; i <= diff ; i++) {
		val = val & (store[i]);
	}

	return val;
}

int get_result(str s) {
	auto first = s.begin();
	auto second = first + 1;
	int op_count = 0;
	bool flag = (*first == '1') ? true: false;
	cout << *first << endl;

	while (second != s.end())
	{
		cout << "f:" << *first << endl;
		cout << "s:" << * second << endl;
		if (*first <= *second) {
			first++;
			second++;
			continue;
		}
		else
		{
			if (flag) {
				*second = OR_operation(s, second);
				cout << "here" << endl;
				op_count++;
			}
			else {
				cout << "else" << endl;
				*first = AND_operation(s, first);
				op_count++;
			}



		}
		first = second;
		second++;
	}
	return op_count;
}

int main()
{
	int n;
	str s;

	cin>>n;

	for (int i = 0;i<n;i++) {
		int sz;
		cin>>sz;
		cin>>s;
		cout << get_result(s)<<endl;
	}

	return 0;
}
