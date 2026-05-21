#include <string>
#include <vector>

using namespace std;
int cnt = 0;
void func(vector<int> numbers, int target, int idx, int sum){
    if(idx == numbers.size()){
        if(sum == target){
            cnt++;
        }
        return;
    }
    
    func(numbers, target, idx + 1, sum + numbers[idx]);
    func(numbers, target, idx + 1, sum - numbers[idx]);
}

int solution(vector<int> numbers, int target) {
    int answer = 0;
    func(numbers, target, 0,0);
    return answer = cnt;
}