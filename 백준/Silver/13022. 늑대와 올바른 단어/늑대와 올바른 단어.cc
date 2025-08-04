#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	string str;
	cin >> str;
	
	if (str[0] != 'w') {
		cout << "0\n";
		return 0;
	}

	int W = 0, O = 0, L = 0, F = 0;
	for (auto c : str) {
		if (c == 'w') W++;
		else if (c == 'o') O++;
		else if (c == 'l') L++;
		else if (c == 'f') F++;
	}
	if (W != O || O != L || L != F || F != W) {
		cout << "0\n";
		return 0;
	}

	for (size_t i = 0; i < str.size() - 1; i++) {
		char c = str[i];
		char nc = str[i + 1];		
		if (c == nc) continue;

		if ((c == 'w' && nc != 'o') || (c == 'o' && nc != 'l') ||
			(c == 'l' && nc != 'f') || (c == 'f' && nc != 'w')) {
			cout << "0\n";
			return 0;
		}
	}

	int prev = 0, curr = 1;
	for (size_t i = 0; i < str.size() - 1; i++) {
		char c = str[i];
		char nc = str[i + 1];		
		if (c == nc) { curr++; continue; }
		
		if (prev != 0 && prev != curr) {
			cout << "0\n";
			return 0;
		}
		prev = curr;
		curr = 1;
		
		if (nc == 'w') { prev = 0; }
	}

	cout << "1\n";
	return 0;
}
