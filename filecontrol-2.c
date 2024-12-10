#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//Stop and Wait

int main() {
    int n, i, ack;

    printf("Enter number of frames: ");
    scanf("%d", &n);

    srand(time(0));

    for (i = 1; i <= n; i++) {
        printf("Sending frame %d\n", i);

        ack = rand() % 2;

        if (ack) {
            printf("Acknowledgment received for frame %d\n", i);
        } else {
            printf("No acknowledgment, resending frame %d\n", i);
            i--;
        }
    }

    return 0;
}
