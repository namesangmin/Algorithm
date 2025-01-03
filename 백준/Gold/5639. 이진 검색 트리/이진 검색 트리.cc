#include <iostream>
#include <vector>
using namespace std;
vector<int> preorder, postorder;
// BST : 기준 노드 < N 노드
// 언제 오른쪽보다 큰가? 를 찾아야 함.
// 큰 값이 나오면 무조건 부모 노드보다 더 큰 값임
// 그 다음 노드를 검색함. 
// 처음 기준 노드가 끝나면 루트 노드보다 큰 오른쪽을 검사
// 위랑 똑같이 함.
void findPostOrder(vector<int>& preorder, int begin, int end, vector<int>& postorder) {
    if (begin > end) return;
    int root = preorder[begin];
    int find_bigger_index= begin + 1;
    // cout << root << " " << splitIndex << "\n";
    while (find_bigger_index <= end && preorder[find_bigger_index] < root) {
        find_bigger_index++;
    }

    findPostOrder(preorder, begin + 1, find_bigger_index - 1, postorder);
    findPostOrder(preorder, find_bigger_index, end, postorder);
    postorder.push_back(root);
}

int main() {
    int input;
    while (cin >> input) {
        preorder.push_back(input);
    }
    findPostOrder(preorder, 0, preorder.size() - 1, postorder);

    for (int a : postorder) {
        cout << a << "\n";
    }
    return 0;
}
