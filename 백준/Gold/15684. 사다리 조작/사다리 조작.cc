#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

#define MAX_N 12
#define MAX_H 32

int N, M, H;
bool map[MAX_H][MAX_N] = { false };

vector<pair<int, int>> cad_p;
vector<vector<pair<int, int>>> comb;

int dest_of_N(int s, bool temp[][MAX_N]) {
    int n = s;
    for (int h = 1; h <= H; h++) {
		if (n < N && temp[h][n]) {
			n++;
		}
		else if (n > 1 && temp[h][n - 1]) {
			n--;
		}
	}
    return n;
}

bool is_valid_conf(bool temp[][MAX_N]) {
    for (int i = 1; i <= N; i++) {
        if (dest_of_N(i, temp) != i) {
            return false;
        }
    }
    return true;
}

void gen_comb(int s, int d, int max_d, vector<pair<int, int>> &curr_comb) {
    if (d == max_d) {
        comb.push_back(curr_comb);
        return;
    }

    for (size_t i = s; i < cad_p.size(); i++) {
        int x = cad_p[i].first;
        int y = cad_p[i].second;

        if (map[x][y] || map[x][y - 1] || map[x][y + 1])
            continue;

		if (!curr_comb.empty()) {
			pair<int, int> last = curr_comb.back();
			if (last.first == x && abs(last.second - y) == 1)
				continue;
		}

        curr_comb.push_back({x, y});
        gen_comb(i + 1, d + 1, max_d, curr_comb);
        curr_comb.pop_back();
    }
}

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> M >> H;

    for (int i = 0; i < M; i++) {
        int a, b;
        cin >> a >> b;
        map[a][b] = true;
    }

    for (int i = 1; i <= H; i++) {
        for (int j = 1; j < N; j++) {
			if (!map[i][j] && !map[i][j - 1] && !map[i][j + 1]) {
				cad_p.push_back({i, j});
			}           
		}
    }

    for (int k = 0; k <= 3; k++) {
        comb.clear();
        vector<pair<int, int>> temp;
        gen_comb(0, 0, k, temp);

		/*
		for (auto c : comb) {
			for (auto p : c) {
				cout << "(" << p.first << ", " << p.second << ") ";
			}
			cout << "\n";
		}
		*/

        for (auto c : comb) {
            bool temp[MAX_H][MAX_N] = { false };
		
            for (int i = 1; i <= H; i++) {
                for (int j = 1; j <= N; j++) {
                    temp[i][j] = map[i][j];
				}
			}	

            for (auto p : c) {
                int x = p.first;
                int y = p.second;
                if (temp[x][y] || temp[x][y - 1] || temp[x][y + 1]) goto skip;
                temp[x][y] = true;
            }

            if (is_valid_conf(temp)) {
                cout << k << "\n";
                return 0;
            }

			skip:;
        }
    }

    cout << -1 << "\n";
    return 0;
}
