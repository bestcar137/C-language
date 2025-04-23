#include <stdio.h>
#include <string.h>

char str[100];

void reverse(int c, int i, char newstr[100]) {
    if (c < 0) {
        newstr[i] = '\0';
        printf("%s\n", newstr);
        return;
    }
    newstr[i] = str[c];
    reverse(c - 1, i + 1, newstr);
}

int main() {
    char new_str[100];
    scanf("%s", str);
    reverse(strlen(str) - 1, 0, new_str);

    return 0;
}

#include <stdio.h>
#include <string.h>

char str[100];

void reverse(int c, int i, char newstr[100]) {
    if (c < 0) {
        newstr[i] = '\0';
        return;
    }
    newstr[i] = str[c];
    reverse(c - 1, i + 1, newstr);
}

int main() {
    char new_str[100];
    scanf("%s", str);
    reverse(strlen(str) - 1, 0, new_str);
    
    printf("%s\n", new_str);

    return 0;
}

