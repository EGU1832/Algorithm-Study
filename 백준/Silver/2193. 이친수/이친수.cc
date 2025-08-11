#include <iostream>

using namespace std;

#define MAX 91

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	long long int DP[MAX];
	DP[1] = 1;
	DP[2] = 1;

	int N;
	cin >> N;

	for (int i = 3; i <= N; i++) {
		DP[i] = DP[i - 1] + DP[i - 2];
	}

	cout << DP[N] << "\n";

	return 0;
}