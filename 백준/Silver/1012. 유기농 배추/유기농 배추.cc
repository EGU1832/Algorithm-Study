#include <iostream>

using namespace std;

#define MAX 51

int map[MAX][MAX];
bool visited[MAX][MAX];
int di[] = { 0, 0, -1, 1 };
int dj[] = { -1, 1, 0, 0 };
int M, N, K;

void dfs(int i, int j) {
	if (visited[i][j]) {
		return;
	}
	visited[i][j] = true;
	
	for (int d = 0; d < 4; d++) {
		int ni = i + di[d];
		int nj = j + dj[d];

		if (ni < 0 || nj < 0 || ni >= N || nj >= M) { continue; }
		if (visited[ni][nj]) { continue; }
		if (map[ni][nj] == 0) { continue; }

		dfs(ni, nj);
	}

	return;
}

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int T;
	cin >> T;

	for (int t = 0; t < T; t++) {
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				map[i][j] = 0;
				visited[i][j] = false;
			}
		}

		cin >> M >> N >> K;

		for (int i = 0; i < K; i++) {
			int X, Y;
			cin >> X >> Y;
			map[Y][X] = 1;
		}

		int min_worm = 0;
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				if (!visited[i][j] && map[i][j] == 1) {
					dfs(i, j);
					min_worm++;
				}
			}
		}

		cout << min_worm << "\n";
	}

	return 0;
}
