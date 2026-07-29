#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int solution(vector<int> A, vector<int> B) {
    sort(A.begin(), A.end());
    sort(B.begin(), B.end());

    int i = 0, j = 0;
    int answer = 0;

    while (i < A.size() && j < B.size()) {
        if (B[j] > A[i]) {
            answer++;
            i++;
            j++;
        } 
        else {
            j++;
        }
    }
    return answer;
}