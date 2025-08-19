#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int M, N;
    cin >> M >> N;

    vector<vector<int>> a(N, vector<int>(M));
    vector<vector<int>> dist(N, vector<int>(M, -1));
    queue<pair<int,int>> q;

    for (int r = 0; r < N; ++r) {
        for (int c = 0; c < M; ++c) {
            cin >> a[r][c];
            if (a[r][c] == 1) {
                q.push({r, c});
                dist[r][c] = 0;
            }
        }
    }

    int dr[4] = {-1, 1, 0, 0};
    int dc[4] = {0, 0, -1, 1};

    while (!q.empty()) {
        auto [r, c] = q.front(); q.pop();
        for (int k = 0; k < 4; ++k) {
            int nr = r + dr[k];
            int nc = c + dc[k];
            if (nr < 0 || nr >= N || nc < 0 || nc >= M) continue;
            if (a[nr][nc] != 0) continue;
            if (dist[nr][nc] != -1) continue;
            a[nr][nc] = 1;
            dist[nr][nc] = dist[r][c] + 1;
            q.push({nr, nc});
        }
    }

    int ans = 0;
    for (int r = 0; r < N; ++r) {
        for (int c = 0; c < M; ++c) {
            if (a[r][c] == 0) {
                cout << -1 << '\n';
                return 0;
            }
            if (dist[r][c] != -1)
                ans = max(ans, dist[r][c]);
        }
    }
    cout << ans << '\n';
    return 0;
}