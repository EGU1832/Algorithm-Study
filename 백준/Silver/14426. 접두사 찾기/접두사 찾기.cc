#include <iostream>
#include <cstring>

using namespace std;

struct Trie {
	bool fin;
	Trie* next[26];

	Trie() : fin(false) {
		memset(next, 0, sizeof(next));
	}

	~Trie() {
		for (int i = 0; i < 26; i++) {
			if (next[i])
				delete next[i];
		}
	}

	void insert(const char* key) {
        if (*key == '\0')
            fin = true;
        else {
            int curr = *key - 'a';
            if (next[curr] == NULL)
                next[curr] = new Trie();
            next[curr]->insert(key + 1);
		}
    }
    
	Trie* find(const char* key) {
        if (*key == '\0') return this;
        int curr = *key - 'a';
        if (next[curr] == NULL) return NULL;
        return next[curr]->find(key + 1);
    }
};

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N, M;
	cin >> N >> M;

	Trie trie;
	for (int i = 0; i < N; i++) {
		string s;
		cin >> s;
		trie.insert(s.c_str());
	}
	
	int num_substr = 0;
	for (int i = 0; i < M; i++) {
		string s;
		cin >> s;
		if (trie.find(s.c_str())) { num_substr++; }
	}
	cout << num_substr << "\n";

	return 0;
}
