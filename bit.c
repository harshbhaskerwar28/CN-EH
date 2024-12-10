#include <stdio.h>

int main() {
    int a[20], b[30], n, i, j = 0, cnt = 0;

    printf("Enter frame size: ");
    scanf("%d", &n);

    printf("Enter the frame in the form of 0 and 1: ");
    for (i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }

    for (i = 0; i < n; i++) {
        b[j++] = a[i];
        if (a[i] == 1) {
            cnt++;
            if (cnt == 5) {
                b[j++] = 0;
                cnt = 0;
            }
        } else {
            cnt = 0;
        }
    }

    printf("After Bit Stuffing: ");
    for (i = 0; i < j; i++) {
        printf("%d", b[i]);
    }
    printf("\n");
    return 0;
}
