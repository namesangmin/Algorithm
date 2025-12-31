#include <stdio.h>

int main(void){
    int ch;
    long long sum = 0;

    while ((ch = getchar()) != '\n' && ch != EOF) {
        if (ch >= '0' && ch <= '9') {
            int d = ch - '0';
            sum += d * d;
        }
    }

    printf("%lld\n", sum % 10);
    return 0;
}
