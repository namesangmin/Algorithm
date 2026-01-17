#include <stdio.h>
#include <string.h>

int main() {
    char str[1000001];
    int alpha[26] = {0};
    int max = 0;
    char result = '?';

    scanf("%s", str);

    for (int i = 0; str[i] != '\0'; i++) {
        char ch = str[i];
        // 소문자일 경우 대문자로 변환
        if (ch >= 'a' && ch <= 'z') {
            ch = ch - 32;  // 소문자를 대문자로
        }
        alpha[ch - 'A']++;
    }

    for (int i = 0; i < 26; i++) {
        if (alpha[i] > max) {
            max = alpha[i];
            result = 'A' + i;
        } else if (alpha[i] == max) {
            result = '?';
        }
    }

    printf("%c\n", result);
    return 0;
}
