#include <iostream>
#include <algorithm>

using namespace std;

int findGate(int* gate, int maxGate);

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int num_of_gate, num_of_plane, maxGate_of_ithPlan, dock = 0;
	int gate[100001];

	cin >> num_of_gate >> num_of_plane;
	for (int i = 1; i <= num_of_gate; ++i) {
		gate[i] = i;
	}

	for(int i = 1; i <= num_of_plane; i++) {
		cin >> maxGate_of_ithPlan;

		int gate_index = findGate(gate, maxGate_of_ithPlan);
		if(gate_index == 0) { break; }
		
		else { 
			gate[maxGate_of_ithPlan] = gate_index;
			gate[gate_index]--;
			dock++;
		}
	}

	cout << dock << "\n";

	return 0;
}

int findGate(int* gate, int maxGate) {
	if(gate[maxGate] == maxGate) { return maxGate; }
	else { return findGate(gate, gate[maxGate]); }
}