#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N, k;
	cin >> N >> k;

	int f = 1, l = k, m;
	int res = 0;

	while (1) {
		if (f > l) break;
		m = (f + l) / 2;

		int cnt = 0;
		for (int i = 1; i <= N; i++) {
			cnt += min(N, m / i);
		}

		if (cnt >= k) {
			res = m;
			l = m - 1;
		}
		else {
			f = m + 1;
		}
	}

	cout << res << '\n';

	return 0;
}