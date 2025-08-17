#include <iostream>
#include <stack>
#include <string>

using namespace std;

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N, K, res = 0; 
	string num;
	stack<int> s;
	stack<int> fnum;
	
	cin >> N >> K >> num;
	for(char d : num) {
        int num = d - '0';
		
		while(!s.empty() && res < K && s.top() < num) {
			s.pop();
			res++;
		}
			s.push(num);
	}
	while(res < K) {
		s.pop();
		res++;
	}

	while(!s.empty()) {
		fnum.push(s.top());
        s.pop();
	}
	while(!fnum.empty()) {
		cout << fnum.top();
		fnum.pop();
	}
	
	return 0;
}
