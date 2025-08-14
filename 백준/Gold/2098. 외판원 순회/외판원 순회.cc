#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>

using namespace std;

#define INF 1e9

int N;
int dp[16][1<<16];

int dfs (int node, int visited_bit, const vector<vector<int>> &cost_graph) {
	if (visited_bit == (1 << N) - 1) {
		if (cost_graph[node][0] == 0)	// Cannot Move
			return INF;
		return cost_graph[node][0];
	}

	if (dp[node][visited_bit] != -1)
		return dp[node][visited_bit];

	dp[node][visited_bit] = INF;

	for (int i = 0; i < N; i++) {
		if (cost_graph[node][i] == 0) {	// No Path || [i, i]
			continue;
		}
		if ((visited_bit & (1 << i)) == (1 << i)) {	// Already Visited
			continue;
		}
		dp[node][visited_bit] = min(dp[node][visited_bit],
								cost_graph[node][i] + dfs(i, visited_bit | 1 << i, cost_graph));
	}

	return dp[node][visited_bit];

}

int travelling(int N, const vector<vector<int>> &cost_graph) {
    // TODO: Implement the travelling function

	memset(dp, -1, sizeof(dp));
    return dfs(0, 1, cost_graph);
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N;

    vector<vector<int>> cost_graph(N, vector<int>(N));
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> cost_graph[i][j];
        }
    }

    int ans = travelling(N, cost_graph);
    cout << ans << '\n';

    return 0;
}
