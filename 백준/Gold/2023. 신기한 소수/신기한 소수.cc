#include <iostream>
#include <vector>
#include <string>

using namespace std;

int N;
vector<int> result;

bool isPrime(int n) {
	if (n < 2) return false;
	for (int i = 2; i * i <= n; ++i) {
		if (n % i == 0) return false;
	}
	return true;
}

void dfs(int num, int depth) {
	if (depth == N) {
		result.push_back(num);
		return;
	}

	for (int digit = 1; digit <= 9; ++digit) {
		int next = num * 10 + digit;
		if (isPrime(next)) {
			dfs(next, depth + 1);
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> N;

	for (int start : {2, 3, 5, 7}) {
		dfs(start, 1);
	}

	for (int num : result) {
		cout << num << '\n';
	}

	return 0;
}