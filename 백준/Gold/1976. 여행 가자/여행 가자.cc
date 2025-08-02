#include <iostream>
#include <vector>

using namespace std;

#define CMAX 201
#define VMAX 1001

int set[CMAX];

int find_parent(int a) {
	if (set[a] == a) return a;
	return set[a] = find_parent(set[a]);
}

void union_elem(int a, int b) {
	a = find_parent(a);
	b = find_parent(b);
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

	for (int i = 1; i <= N; i++) {
		set[i] = i;
	}

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			int path;
			cin >> path;
			if (path) union_elem(i, j);
		}
	}

	int city[VMAX];
	for (int i = 0; i < M; i++) {
		cin >> city[i];
	}

	int s = find_parent(city[0]);
	for (int i = 1; i < M; i++) {
		if (find_parent(s) != find_parent(city[i])) {
			cout << "NO\n";
			return 0;
		}
	}
	cout << "YES\n";

	return 0;
}
