#include <stdio.h>

int main() {
    int A, B;

    // EOF(End of File)가 입력될 때까지 반복
    while (scanf("%d %d", &A, &B) == 2) {
        // A와 B를 더한 값을 출력
        printf("%d\n", A + B);
    }

    return 0;
}
