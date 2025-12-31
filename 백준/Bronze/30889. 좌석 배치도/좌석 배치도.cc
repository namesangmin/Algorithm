#include <iostream>
#include <vector>
#include <string>

using namespace std;
int main() {
    // 좌석 배열 초기화
    const int ROWS = 10;
    const int COLS = 20;
    vector<std::vector<char>> seatingPlan(ROWS, vector<char>(COLS, '.'));

    // 예매 정보 입력
    int numCustomers;
    cin >> numCustomers;

    for (int i = 0; i < numCustomers; ++i) {
        string seat;
        cin >> seat;

        // 예매된 좌석 정보 반영
        char row = seat[0] - 'A'; // A를 0으로 매핑
        int col = stoi(seat.substr(1)) - 1; // 좌석 번호를 0으로 매핑
        seatingPlan[row][col] = 'o';
    }
    /*
    // 좌석 배치도 출력
    cout << "  ";
    for (int j = 1; j <= COLS; ++j) {
        cout << j << ' ';
    }
    cout << "\n";*/

    for (int i = 0; i < ROWS; ++i) {
        char rowLabel = 'A' + i;
        //cout << rowLabel << ' ';
        for (int j = 0; j < COLS; ++j) {
            cout << seatingPlan[i][j] ;
        }
        cout << "\n";
    }

    return 0;
}
