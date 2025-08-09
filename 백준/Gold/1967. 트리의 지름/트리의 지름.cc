#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <cstring>

using namespace std;

#define MAX 10001

vector<vector<pair<int, int>>> adj(MAX);

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n;
	cin >> n;

	for (int i = 0; i < n - 1; i++) {
		int u, v, w;
		cin >> u >> v >> w;

		adj[u].push_back({v, w});
		adj[v].push_back({u, w});
	}

	int max_dist = 0;
	for (int s = 1; s <= n; s++) {
		queue<pair<int, int>> q;
		bool visited[MAX];
		memset(visited, false, sizeof(visited));

		q.push({s, 0});
		visited[s] = true;
		while(!q.empty()) {
			int curr = q.front().first;
			int curr_d = q.front().second;
			q.pop();
			
			max_dist = max(max_dist, curr_d);
			for (auto neighbor : adj[curr]) {
				int next = neighbor.first;
				int dist = neighbor.second;

				if (!visited[next]) {
					q.push({next, curr_d + dist});
					visited[next] = true;
				}
			}
		}
	}
	cout << max_dist << "\n";

	return 0;
}