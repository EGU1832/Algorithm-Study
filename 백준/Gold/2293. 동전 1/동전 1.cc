#include <iostream>

using namespace std;

#define MAX 100001

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N, K;
	cin >> N >> K;
	
	int DP[MAX] = { 0 };
	for (int i = 0; i < N; i++) {
		int c;
		cin >> c;
		
		DP[c]++;
		for (int j = c + 1; j <= K; ++j) {
			DP[j] += DP[j - c];
		}
	}

	cout << DP[K] << "\n";

	return 0;
}