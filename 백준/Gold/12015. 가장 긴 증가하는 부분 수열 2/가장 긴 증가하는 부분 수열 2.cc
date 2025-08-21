#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    cin >> N;

    vector<int> A(N);
    for (int i = 0; i < N; ++i) {
        cin >> A[i];
    }

    vector<int> LIS;
    for (int i = 0; i < N; ++i) {
        int num = A[i];
        auto it = lower_bound(LIS.begin(), LIS.end(), num);
        if (it == LIS.end()) {
            LIS.push_back(num);
        } else {
            *it = num;
        }
    }

    cout << LIS.size() << "\n";
    return 0;
}