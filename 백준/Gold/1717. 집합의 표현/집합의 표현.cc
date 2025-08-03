#include <iostream>

using namespace std;

#define MAX 1000001

int set[MAX];

int parent(int a) {
	if (set[a] == a) return a;
	return set[a] = parent(set[a]);
}

void union_elem(int a, int b) {
	a = parent(set[a]);
	b = parent(set[b]);

	if (a < b) set[b] = a;
	else set[a] = b;
}

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N, M;
	cin >> N >> M;

	for (int i = 0; i <= N; i++) {
		set[i] = i;
	}

	for (int i = 0; i < M; i++) {
		int c, a, b;
		cin >> c >> a >> b;

		if (c == 0) {
			union_elem(a, b);
		}
		else {
			if (parent(a) == parent(b)) cout << "YES\n";
			else cout << "NO\n";
		}
	}

	return 0;
}
