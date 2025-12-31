#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

int main() {

    int a;
    int n, m;
    long long int n1 = 1;
    long long int m1 = 1;
   // unsigned long long int result;
    scanf("%d", &a);

    for (int i = 0; i < a; i++) {

        scanf("%d %d", &n, &m);


        for (int j = 0; j < n; j++) {
            m1 *= (m - j);
           // n1 *= ;
            m1 /= (1 + j);

        }

        //result = m1 / n1;
        printf("%lld\n", m1);
        m1=1;
    }
    return 0;
}