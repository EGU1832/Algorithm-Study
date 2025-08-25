#include <iostream>

using namespace std;

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N, M;
	cin >> N >> M;

	for (int i = 1; i <= N * M; ++i) {
		if (i % M == 0) cout << i << "\n";
		else cout << i << " ";
	}

	return 0;
}