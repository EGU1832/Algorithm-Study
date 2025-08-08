#include <iostream>
#include <queue>
#include <cstring>

#define MAX 10001

using namespace std;

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	bool P[MAX];
	memset(P, true, sizeof(P));

	int i = 2;
	while(i <= 100) {
		int j = i;
		while (i * j <= MAX) {
			P[i * j] = false;
			j++;
		}
		i++;
	}

	int tc;
	cin >> tc;
	for (int t = 0; t < tc; t++) {
		int n1, n2;
		cin >> n1 >> n2;

		queue<pair<int, int>> q;
		bool visited[MAX];
		memset(visited, false, sizeof(visited));

		q.push({n1, 0});
		visited[n1] = true;

		bool possible;
		while(!q.empty()) {
			int n = q.front().first;
			int d = q.front().second;
			q.pop();
			
			if (n == n2) {
				possible = true;
				cout << d << "\n";
				break;
			}
			
			string n_str = to_string(n);
			for (int i = 0; i < 4; i++) {
				for (char dg = '0'; dg <= '9'; dg++) {
					if (n_str[i] == dg) continue;

					string nn_str = n_str;
					nn_str[i] = dg;
					int nnum = stoi(nn_str);

					if (nnum >= 1000 && P[nnum] && !visited[nnum]) {
						visited[nnum] = true;
						q.push({nnum, d + 1});
					}
				}
			}
		}
		if (!possible) cout << "Impossible\n";
	}

	return 0;
}