#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N, L, R, X;
vector<int> comb;

void gen_comb(int c, int n) {
	if (n == N) {
		comb.push_back(c);
		return;
	}
	gen_comb(c << 1 | 0, n + 1);
	gen_comb(c << 1 | 1, n + 1);

	return;
}

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> L >> R >> X;
	
	int A[N];
	for (int i = 0; i < N; i++) {
		cin >> A[i];
	}

	// sum(A): [L, R], abs(minA - maxA) >= X
	gen_comb(0, 0);

	int total = 0;
	for(auto c : comb) {
		vector<int> P;
		for (int i = 0; i < N; i++) {
			if (c & (1 << i)) P.push_back(A[i]);
		}
		sort(P.begin(), P.end());

		int sum_A = 0;
		for (auto p : P) {
			sum_A += p;
		}
		
		if (sum_A >= L && sum_A <= R && P.back() - P.front() >= X) total++;
	}
	cout << total << "\n";

	return 0;
}
