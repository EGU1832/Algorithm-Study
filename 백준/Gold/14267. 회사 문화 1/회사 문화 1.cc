#include <iostream>
#include <vector>

using namespace std;

#define MAX 100001

bool visited[MAX];
int dmap[MAX];
vector<vector<int>> adj(MAX);

void dfs(int c, int d) {
	dmap[c] = d;
	visited[c] = true;

	for (int n : adj[c]) {
		if (!visited[n]) {
			dfs(n, d + dmap[n]);
		}
	}
}

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, m;
	cin >> n >> m;
	for (int v = 1; v <= n; ++v) {
		int u;
		cin >> u;
		if (u == -1) continue;
		adj[u].push_back(v);
	}

	for (int i = 0; i < m; ++i) {
		int j, w;
		cin >> j >> w;
		dmap[j] += w;
	}

	dfs(1, dmap[1]);

	for (int i = 1; i <= n; ++i) {
		cout << dmap[i]	<< " ";
	}

	return 0;
}