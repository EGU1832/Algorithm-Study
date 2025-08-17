#include <iostream>
#include <stack>
#include <string>

using namespace std;

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int digit_of_number, num_to_delete, num_of_delete = 0; 
	string input_number;
	stack<int> number_stack;
	stack<int> final_number;
	
	cin >> digit_of_number >> num_to_delete >> input_number;
	for(char inputChar : input_number) {
        int num = inputChar - '0';
		
		while(!number_stack.empty() && num_of_delete < num_to_delete && number_stack.top() < num) {
			number_stack.pop();
			num_of_delete++;
		}
			number_stack.push(num);
	}
	while(num_of_delete < num_to_delete) {
		number_stack.pop();
		num_of_delete++;
	}

	while(!number_stack.empty()) {
		final_number.push(number_stack.top());
        number_stack.pop();
	}
	while(!final_number.empty()) {
		cout << final_number.top();
		final_number.pop();
	}
	
	return 0;
}