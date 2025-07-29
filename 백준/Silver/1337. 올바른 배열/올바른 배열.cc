#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

#define MAX 1000000000

bool num(int a, vector<int> arr) {
	for (auto b : arr) {
		if (b == a) return true;
	}
	return false;
}

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N;
	cin >> N;

	vector<int> arr;
	for (int i = 0; i < N; i++) {
		int temp;
		cin >> temp;
		arr.push_back(temp);

	}
	sort(arr.begin(), arr.end());

	int min_add = 5;
	for (auto n : arr) {
		int add_u = 0;
		for (int i = n; i < n + 5; i++) {
			if (i > MAX) { add_u = 5; break; }
			if (!num(i, arr)) add_u++;
		}

		int add_d = 0;
		for (int i = n; i > n - 5; i--) {
			if (i < 0) { add_d = 5; break; }
			if (!num(i, arr)) add_d++;
		}

		//cout << add_u << ", " << add_d << "\n";
		if (add_u < min_add) min_add = add_u;
		if (add_d < min_add) min_add = add_d;
	}
	cout << min_add << "\n";

	return 0;
}
