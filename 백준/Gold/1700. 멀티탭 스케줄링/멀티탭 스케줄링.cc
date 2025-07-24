#include <iostream>
#include <vector>
#include <map>

using namespace std;

#define MAX_USES 102

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int number_of_holes, number_of_total_uses;
	cin >> number_of_holes >> number_of_total_uses;

	vector<int> order_of_uses;
	for(int i = 0; i < number_of_total_uses; i++) {
		int device_id;
		cin >> device_id;
		order_of_uses.push_back(device_id);
	}

	bool pluged[MAX_USES] = { false };
	map<int, int> current_pluged_devices;
	int number_of_current_pluged = 0;
	int min_plug = 0;
	for(int i = 0; i < number_of_total_uses; i++) {
		int current_device = order_of_uses[i];

		if(pluged[current_device]) {
			continue;
		}

		if(number_of_current_pluged == number_of_holes){
			int latest_use_device = -1;
			int latest_use_device_time = -1;

			for(auto device : current_pluged_devices) {
				int pluged_device_id = device.first;

				int j;
				for(j = i + 1; j < number_of_total_uses; j++) {
					if(order_of_uses[j] == pluged_device_id) {
						break;
					}
				}
				if(latest_use_device_time < j) {
					latest_use_device = pluged_device_id;
					latest_use_device_time = j;
				}
			}

			pluged[latest_use_device] = false;
			current_pluged_devices.erase(latest_use_device);
			min_plug++;
			number_of_current_pluged--;
		}
		pluged[current_device] = true;
		current_pluged_devices[current_device] = 0;
		number_of_current_pluged++;
	}

	cout << min_plug << "\n";

	return 0;
}
