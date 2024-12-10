#include <stdio.h>
//Sliding window
int main() {
    int n, w, s = 0, i;

    printf("Enter number of frames: ");
    scanf("%d", &n);

    printf("Enter window size: ");
    scanf("%d", &w);

    while (s < n) {
        printf("Sending frames: ");
        for (i = s; i < s + w && i < n; i++) {
            printf("%d ", i + 1);
        }
        printf("\nAcknowledged up to frame %d\n", s + w);
        s += w;
    }

    return 0;
}
