#include <stdio.h>
#include <string.h>

int main() {
    int n, j = 0;
    printf("Enter Size of the String - ");
    scanf("%d", &n);

    char a[n + 1], b, c, d[2 * n + 1];
    printf("Enter the String - ");
    scanf("%s", a);

    printf("Enter the Start Delimiter: ");
    scanf(" %c", &b);

    printf("Enter the End Delimiter: ");
    scanf(" %c", &c);

    d[j++] = b;

    for (int i = 0; i < n; i++) {
        if (a[i] == b || a[i] == c) {
            d[j++] = b;
        }
        d[j++] = a[i];
    }

    d[j++] = c;
    d[j] = '\0';

    printf("The Final String After Character Stuffing = %s\n", d);
    return 0;
}
