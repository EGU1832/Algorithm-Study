#include <iostream>
#include <algorithm>

using namespace std;

#define MAX 100001

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N, M;
	cin >> N >> M;
	
	int use[MAX];
	int max_use = 0, sum_use = 0;
	for (int i = 0; i < N; i++) {
		cin >> use[i];
		max_use = max(max_use, use[i]);
		sum_use += use[i];
	}

	int min = max_use;
	int max = sum_use;
	int i = (min + max) / 2;
	while (min != max) {
		int m = 1;
		int curr_m = i;
		for (int j = 0; j < N; j++) {
			if (curr_m - use[j] < 0) {
				m++; curr_m = i;
			}
			curr_m -= use[j];
		}

		if (m <= M) {
			max = i;
		}
		else {
			min = i + 1;
		}
		i = (min + max) / 2;
	}

	cout << i << "\n";

	return 0;
}