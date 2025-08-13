#include <iostream>
#include <string>
#include <map>

using namespace std;

int find_parent(int* friend_set, int element);
void union_set(int* friend_set, int* number_set, int element1, int element2);

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int test_case;

	cin >> test_case;
	for(int i = 0; i < test_case; i++) {
		int friend_set[200001];
		int number_of_friends_of[200001];
		map<string, int> friends_id;
		int number_of_relationships, id = 0;

		for(int j = 0; j < 200001; j++) {
			friend_set[j] = j;
			number_of_friends_of[j] = 1;
		}

		cin >> number_of_relationships;
		for(int k = 0; k < number_of_relationships; k++) {
			string friend1, friend2;
			cin >> friend1 >> friend2;
			
			auto it1 = friends_id.find(friend1);
			auto it2 = friends_id.find(friend2);
			if (it1 == friends_id.end()) {
				friends_id[friend1] = ++id;
			}
			if (it2 == friends_id.end()) {
				friends_id[friend2] = ++id;
			}
			union_set(friend_set, number_of_friends_of, friends_id[friend1], friends_id[friend2]);
			cout << number_of_friends_of[find_parent(friend_set, friends_id[friend1])] << "\n";
		}
	}

	return 0;
}

int find_parent(int* friend_set, int element) {
	if(friend_set[element] == element) {
		return element;
	}
	return find_parent(friend_set, friend_set[element]);
}

void union_set(int* friend_set, int* number_set, int element1, int element2) {
	int element1_parent = find_parent(friend_set, element1);
	int element2_parent = find_parent(friend_set, element2);

	if(element1_parent < element2_parent) {
		friend_set[element2_parent] = element1_parent;
		number_set[element1_parent] += number_set[element2_parent];
	}
	else if(element1_parent > element2_parent) {
		friend_set[element1_parent] = element2_parent;
		number_set[element2_parent] += number_set[element1_parent];
	}

	return;
}