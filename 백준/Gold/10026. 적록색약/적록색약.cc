#include <iostream>
#include <cstring>

using namespace std;

#define MAX 102

bool visited[MAX][MAX] = { false };
int map[MAX][MAX];
int N;

int dirX[] = { 0, 0, -1, 1 };
int dirY[] = { -1, 1, 0, 0 };


void dfs(int i, int j) {
	if (visited[i][j]) {
		return;
	}
	visited[i][j] = true;

	for (int d = 0; d < 4; d++) {
		int ni = i + dirY[d];
		int nj = j + dirX[d];

		if (ni < 0 || nj < 0 || ni >= N || nj >= N) continue;
		if (visited[ni][nj]) continue;
		if (map[ni][nj] != map[i][j]) continue;
		dfs(ni, nj);
	}

	return;
}

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;
	for (int i = 0; i < N; i++) {
		string s;
		cin >> s;

		for (int j = 0; j < N; j++) {
			map[i][j] = s[j] - 'A';
		}
	}

	int r1 = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (!visited[i][j]) {
				dfs(i, j);
				r1++;
			}
		}
	}
	
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (map[i][j] == 'G' - 'A') map[i][j] = 'R' - 'A';
			visited[i][j] = false;
		}
	}
	
	int r2 = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (!visited[i][j]) {
				dfs(i, j);
				r2++;
			}
		}
	}
	cout << r1 << " " << r2 << "\n";

	return 0;
}
