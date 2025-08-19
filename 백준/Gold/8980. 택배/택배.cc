#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef struct Delivery {
	int start;
	int end;
	int distance;
	int quantity;
} Delivery;

bool order_in_define (Delivery& a, Delivery& b);

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int number_of_villages, capacity_of_truck, number_of_box_information;
	int villages[2001];
	int possible_max_deliver = 0;
	vector<Delivery> delivery_information;
	
	cin >> number_of_villages >> capacity_of_truck >> number_of_box_information;
	for (int i = 1; i <= number_of_villages; ++i) {
		villages[i] = capacity_of_truck;
	}

	for (int i = 1; i <= number_of_box_information; ++i) {
		Delivery information;

		cin >> information.start >> information.end >> information.quantity;	
		information.distance = information.end - information.start;

		delivery_information.push_back(information);
	}

	sort(delivery_information.begin(), delivery_information.end(), order_in_define);

	
	for(Delivery deliver : delivery_information) {
		int possible_max_quantity = villages[deliver.start];
		for(int i = deliver.start; i < deliver.end; ++i) {
			possible_max_quantity = min(possible_max_quantity, villages[i]);
        }
		possible_max_quantity = min(possible_max_quantity, deliver.quantity);

		for (int i = deliver.start; i < deliver.end; ++i) {
			villages[i] -= possible_max_quantity;
		}
		possible_max_deliver += possible_max_quantity;
	}

	cout << possible_max_deliver << "\n";	

	return 0;
}

bool order_in_define (Delivery& a, Delivery& b) {
	if(a.end < b.end) {
		return true;
	}
	else if(a.end == b.end) {
		if(a.start < b.start) {
			return true;
		}
		else {
			return false;
		}
	}
	else {
		return false;
	}
}