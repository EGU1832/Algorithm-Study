#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

#define MAX 100001

int set[MAX];

bool sort_w(pair<pair<int, int>, int> a, pair<pair<int, int>, int> b) {
	return a.second < b.second;
}

int parent(int a) {
	if (set[a] == a) return a;
	else return set[a] = parent(set[a]);
}

void union_e(int a, int b) {
	a = parent(a);
	b = parent(b);

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

	vector<pair<pair<int, int>, int>> adj;

	for (int i = 0; i < M; ++i) {
		int u, v, w;
		cin >> u >> v >> w;
		adj.push_back({{u, v}, w});
	}
	sort(adj.begin(), adj.end(), sort_w);

	for (int i = 1; i <= N; ++i) {
		set[i] = i;
	}

	vector<int> W;
	int ans = 0;
	for (auto p : adj) {
		int u = p.first.first;
		int v = p.first.second;
		int w = p.second;

		if (parent(u) != parent(v)) {
			union_e(u, v);
			ans += w;
			W.push_back(w);
		}
	}
	cout << ans - W.back() << "\n";

	return 0;
}