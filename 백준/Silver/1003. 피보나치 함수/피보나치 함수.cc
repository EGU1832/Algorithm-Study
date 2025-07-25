#include <iostream>
#include <vector>

using namespace std;

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int T;
	cin >> T;

	for (int i = 0; i < T; i++) {
		int N;
		cin >> N;

		vector<pair<int, int>> DP;
		DP.push_back(make_pair(1, 0));
		DP.push_back(make_pair(0, 1));
		for (int j = 2; j <= N; j++) {
			DP.push_back(make_pair(DP[j-1].first + DP[j-2].first,
						DP[j-1].second + DP[j-2].second));
		}

		cout << DP[N].first << " " << DP[N].second << "\n";
	}

	return 0;
}
