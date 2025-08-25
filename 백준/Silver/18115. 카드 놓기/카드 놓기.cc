#include <iostream>
#include <vector>

using namespace std;

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N;
	cin >> N;

	vector<int> A(N + 1);
	for (int i = 0; i < N; ++i) {
		cin >> A[i];
	}

	int s = 1, f = 1, i = 2;
	vector<int> ans(N + 1);
	ans[s] = f;
	for (int j = N - 2; j >= 0; --j) {
		if (A[j] == 1) {
			ans[i] = s; s = i;
		}
		else if (A[j] == 2) {
			if (s == f) { ans[s] = i; f = i; }
			else { ans[i] = ans[s]; ans[s] = i; }
		}
		else if (A[j] == 3) {
			ans[f] = i; f = i;
		}
		i++;
	}

	i = s;
	int n = 0;
	while (n < N) {
		cout << i << " ";
		i = ans[i];
		n++;
	}

	return 0;
}