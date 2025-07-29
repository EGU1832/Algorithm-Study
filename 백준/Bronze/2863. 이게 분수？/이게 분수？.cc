#include <iostream>

using namespace std;

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	float map[4] = { 0 };
	for (int i = 0; i < 4; i++) {
		cin >> map[i];
	}

	int R = 0;
	float max_E = map[0]/map[2] + map[1]/map[3];
	for(int r = 1; r < 4; r++) {
		float temp[4] = { 0 };
		temp[0] = map[2];
		temp[1] = map[0];
		temp[2] = map[3];
		temp[3] = map[1];

		float E = temp[0]/temp[2] + temp[1]/temp[3];
		if (E > max_E) {
			max_E = E;
			R = r;
		}

		map[0] = temp[0];
		map[1] = temp[1];
		map[2] = temp[2];
		map[3] = temp[3];
	}
	cout << R << "\n";

	return 0;
}
