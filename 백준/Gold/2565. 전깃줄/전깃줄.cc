#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

#define MAX 101

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N;
	cin >> N;

	vector<pair<int, int>> wire(N);
	for (int i = 0; i < N; i++) {
		cin >> wire[i].first >> wire[i].second;
	}
	sort(wire.begin(), wire.end());

	int DP[MAX];
	fill(DP, DP + MAX, 1);
	
	int M = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < i; j++) {
			if (wire[j].second < wire[i].second) {
				DP[i] = max(DP[i], DP[j] + 1);
			}
		}
		M = max(M, DP[i]);
	}
	cout << N - M << "\n";

	return 0;
}
