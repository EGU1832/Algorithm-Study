#include <iostream>
#include <algorithm>

using namespace std;

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int T;

	cin >> T;
	for(int t = 0; t < T; ++t) {
		int K;
		int k[501][501];
		int min_k[502][502];

		cin >> K;
		for(int j = 1; j <= K; ++j) {
			cin >> k[j][j];

			int k_i_to_j = k[j][j];
			for(int i = j - 1; i > 0; --i) {
				k_i_to_j += k[i][i];
				k[i][j] = k_i_to_j;
			}
		}

		for(int j = 1; j <= K; ++j) {
			for(int i = j - 1; i > 0; --i) {
				min_k[i][j] = min_k[i][i] + min_k[i + 1][j] + k[i][j];
				for(int m = i + 1; m < j; ++m) {
					min_k[i][j] = min(min_k[i][j], \
							min_k[i][m] + min_k[m + 1][j] + k[i][j]);
				}
			}
		}
		cout << min_k[1][K] << "\n";
	}
	
	return 0;
}