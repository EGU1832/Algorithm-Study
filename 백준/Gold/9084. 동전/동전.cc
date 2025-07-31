#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

#define MAX 100001

int DP[MAX];

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int T;
	cin >> T;
	for (int t = 0; t < T; t++) {
		int N;
		cin >> N;

		vector<int> coin;
		for (int i = 0; i < N; i++) {
			int c;
			cin >> c;
			coin.push_back(c);
		}

		int M;
		cin >> M;
		for (int i = 0; i <= M; i++) {
			DP[i] = 0;
		}
	
		DP[0] = 1;
		for (auto c : coin) {
			for (int i = c; i <= M; i++) {
				DP[i] += DP[i - c];
			}
		}

		cout << DP[M] << "\n";
	}

	return 0;
}