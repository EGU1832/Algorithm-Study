#include <iostream>

using namespace std;

#define MAX 1048577

bool T[MAX];

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N, Q;
	cin >> N >> Q;

	for (int i = 0; i < Q; ++i) {
		int n;
		cin >> n;
		
		int m = n;
		int min = 0;
		while (m > 0) {
			if (T[m]) min = m;
			m /= 2;
		}

		if (min == 0) {
			T[n] = true;
			cout << "0\n";
		}
		else {
			cout << min << "\n";
		}
	}

	return 0;
}