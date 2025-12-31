#include <iostream>
#include <list>
using namespace std;

int main() {
    int N;
    int arr[100001] = {};
    list<int> stack_list;
    list<char> result_list;
    int j = 0;
    cin >> N;

    for (int i = 0; i < N; i++) {
        cin >> arr[i];
    }

    for (int i = 1; i <= N; i++) {
        stack_list.push_back(i);
        result_list.push_back('+');

        while (!stack_list.empty() && stack_list.back() == arr[j]) {
            stack_list.pop_back();
            result_list.push_back('-');
            j++;
        }
    }

    if (!stack_list.empty()) {
        cout << "NO";
    } else {
        for (auto it = result_list.begin(); it != result_list.end(); ++it) {
            cout << *it << "\n";
        }
    }

    return 0;
}
