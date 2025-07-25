#include <iostream>
#include <queue>
#include <string>

using namespace std;

#define MAX 105

int N, M;
int map[MAX][MAX];
bool visited[MAX][MAX];
int dist[MAX][MAX];

int dx[] = { -1, 1, 0, 0 };
int dy[] = { 0, 0, -1, 1 };

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N >> M;

    for (int i = 0; i < N; i++) {
        string S;
        cin >> S;
        for (int j = 0; j < M; j++) {
            map[i][j] = S[j] - '0';
        }
    }

    queue<pair<int, int>> q;
    visited[0][0] = true;
    dist[0][0] = 1;
    q.push({0, 0});

    while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
        q.pop();

        for (int dir = 0; dir < 4; dir++) {
            int nx = x + dx[dir];
            int ny = y + dy[dir];

            if (nx < 0 || ny < 0 || nx >= N || ny >= M) continue;
            if (visited[nx][ny]) continue;
            if (map[nx][ny] == 0) continue;

            visited[nx][ny] = true;
            dist[nx][ny] = dist[x][y] + 1;
            q.push({nx, ny});
        }
    }

    cout << dist[N - 1][M - 1] << "\n";
    return 0;
}

