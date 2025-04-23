#include <stdio.h>

unsigned long long factorial(int n) {
    if (n <= 1 || n>=100000) return 1;
    else return (n * factorial(n - 1));
}


int main(void) {
    int n;
    scanf("%d", &n);
    if (n > 5) {
        int sol;
        sol=factorial(n)%(1000000000+7);
        printf("%d\n", sol);
    }else
    printf("%llu\n", factorial(n));
return 0;
}

