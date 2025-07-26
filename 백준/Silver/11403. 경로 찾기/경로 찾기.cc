#include <iostream>
#include <vector>

using namespace std;

#define MAX 101

vector<vector<int>> Adj(MAX);
bool visited[MAX];
bool have_path;
int s, f, dist;

void dfs(int c) {
	if (c == f && dist != 0) { have_path = true; return; }
	if (visited[c]) { return; }
	visited[c] = true;

	for (auto n : Adj[c]) {
		if (n == f) { have_path = true; }
		if (visited[n]) { continue; }
		dist++;
		dfs(n);
	}

	return;
}

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N;
	cin >> N;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			int path;
			cin >> path;
			if (path) { Adj[i].push_back(j); }
		}
	}

	for (s = 0; s < N; s++) {
		for (f = 0; f < N; f++) {
			dist = 0;
			have_path = false;
			dfs(s);
			cout << have_path << " ";

			for (int i = 0; i < N; i++) {
				visited[i] = false;
			}
		}
		cout << "\n";
	}

	return 0;
}
