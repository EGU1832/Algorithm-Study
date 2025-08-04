#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

#define MAX_DEPTH 3

vector<vector<int>> rate;
vector<vector<int>> comb;

void gen_comb(int n, int d, vector<int> curr) {
	if (d == MAX_DEPTH) {
		comb.push_back(curr);
		return;
	}

	int curr_back;
	if (d == 0) curr_back = -1;
	else curr_back = curr.back();

	for (int i = curr_back+1; i < n; i++) {
		curr.push_back(i);
		gen_comb(n, d + 1, curr);
		curr.erase(curr.end() - 1);
	}

	return;
}

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N, M;
	cin >> N >> M;
	
	for (int i = 0; i < N; i++) {
		vector<int> temp;
		for (int j = 0; j < M; j++) {
			int r;
			cin >> r;
			temp.push_back(r);
		}
		rate.push_back(temp);
	}

	vector<int> m;
	gen_comb(M, 0, m);

	int max_rate = 0;
	for (auto C : comb) {
		int temp = 0;
		for (auto ri : rate) {
			vector<int> ri3;
			for (auto c : C) {
				ri3.push_back(*(ri.begin() + c));
			}
			sort(ri3.begin(), ri3.end());
			temp += ri3.back();
		}
		max_rate = max(max_rate, temp);
	}
	cout << max_rate << "\n";

	return 0;
}
