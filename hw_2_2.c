#include <stdio.h>

int power(int base, int exponent) {
    if (exponent == 0) return 1;
    else if ((exponent % 2) == 0)
        return power(base * base, exponent / 2);
    else return base * power(base * base, (exponent - 1) / 2);
}

int main(void) {
    int base, exponent;
    scanf ("%d %d", &base, &exponent);
    printf("%d\n",power(base,exponent));
    return 0;
}
