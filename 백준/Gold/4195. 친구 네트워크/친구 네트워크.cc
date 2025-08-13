#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

int parent(int* fset, int e) {
	if (fset[e] != e) {
		fset[e] = parent(fset, fset[e]);
	}
	return fset[e];
}

void union_set(int* fset, int* nset, int a, int b) {
	int a_parent = parent(fset, a);
	int b_parent = parent(fset, b);

	if (a_parent == b_parent) return;

	if (a_parent < b_parent) {
		fset[b_parent] = a_parent;
		nset[a_parent] += nset[b_parent];
	} else {
		fset[a_parent] = b_parent;
		nset[b_parent] += nset[a_parent];
	}
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int T;
	cin >> T;

	while (T--) {
		int fset[200001];
		int fnum[200001];
		unordered_map<string, int> fid;
		int rnum, id = 0;

		for (int j = 0; j < 200001; j++) {
			fset[j] = j;
			fnum[j] = 1;
		}

		cin >> rnum;
		for (int k = 0; k < rnum; k++) {
			string a, b;
			cin >> a >> b;

			if (fid.find(a) == fid.end()) fid[a] = ++id;
			if (fid.find(b) == fid.end()) fid[b] = ++id;

			int rootA = parent(fset, fid[a]);
			int rootB = parent(fset, fid[b]);

			union_set(fset, fnum, rootA, rootB);
			cout << fnum[parent(fset, rootA)] << "\n";
		}
	}

	return 0;
}