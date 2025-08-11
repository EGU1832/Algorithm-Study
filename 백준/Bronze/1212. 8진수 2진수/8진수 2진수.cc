#include <iostream>
#include <cstring>
#include <vector>

using namespace std;

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	string s;
	cin >> s;

	vector<int> byte;
	for (auto c : s) {
		byte.push_back(c - '0');
	}

	if (byte.size() == 1 && byte.front() == 0) {
		cout << "0\n";
		return 0;
	}

	vector<int> bit;
	for (auto b : byte) {
		vector<int> t;
		for (int i = 0; i < 3; i++) {
			if ((b % 2) == 0) t.insert(t.begin(), 0);
			else t.insert(t.begin(), 1);
			
			if (b == 1) { break; }
			b /= 2;
		}

		while (t.size() < 3) {
			t.insert(t.begin(), 0);
		}

		for (auto bb : t) {
			bit.push_back(bb);
		}
	}

	bool flag = false;
	for (auto b : bit) {
		if (b == 1) flag = true;
		if (flag) cout << b;
	}
	cout << "\n";

	return 0;
}
