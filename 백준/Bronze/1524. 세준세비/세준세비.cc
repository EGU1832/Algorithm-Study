#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int T;
	cin >> T;

	for (int t = 0; t < T; t++) {
		int N, M;
		cin >> N >> M;

		vector<int> S;
		vector<int> B;
		int temp;
		for (int i = 0; i < N; i++) {
			cin >> temp;
			S.push_back(temp);
		}
		for (int i = 0; i < M; i++) {
			cin >> temp;
			B.push_back(temp);
		}
		sort(S.begin(), S.end());
		sort(B.begin(), B.end());
		
		while ((S.size() + B.size()) >= 1 && !S.empty() && !B.empty()) {
			if (S.front() >= B.front()) {
				B.erase(B.begin());
			}
			else { S.erase(S.begin()); }
		}

		if (!S.empty()) cout << "S\n";
		else if (!B.empty()) cout << "B\n";
		else cout << "C\n";
	}

	return 0;
}