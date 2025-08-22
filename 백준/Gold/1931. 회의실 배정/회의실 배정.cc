#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool is_not_intersecting(pair<int, int>, pair<int, int>);

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int number_of_meetings;
	cin >> number_of_meetings;

	vector<pair<int, int>> information_of_meetings;
	for(int i = 0; i < number_of_meetings; i++) {
		int meeting_start, meeting_end;
		cin >> meeting_start >> meeting_end;
		information_of_meetings.push_back(make_pair(meeting_end, meeting_start));
	}
	sort(information_of_meetings.begin(), information_of_meetings.end());

	int max_meetings = 1;
	int iter = 0;
	for(int i = 1; i < number_of_meetings; i++) {
		if(is_not_intersecting(information_of_meetings[iter], information_of_meetings[i])) {
			max_meetings++;
			iter = i;
		}
	}

	cout << max_meetings;

	return 0;
}

bool is_not_intersecting(pair<int, int> a, pair<int, int> b) {
	return a.first <= b.second;
}