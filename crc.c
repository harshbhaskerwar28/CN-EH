#include <stdio.h>
#include <string.h>

void crc(char d[], char g[], char r[]) {
    int i, j, dl = strlen(d), gl = strlen(g);
    strcpy(r, d);

    for (i = 0; i <= dl - gl; i++) {
        if (r[i] == '1') {
            for (j = 0; j < gl; j++) {
                r[i + j] = (r[i + j] == g[j]) ? '0' : '1';
            }
        }
    }
}

int main() {
    char a[100], b[20], c[120], d[120];
    int i;

    printf("Enter data bits: ");
    scanf("%s", a);

    printf("Enter generator bits: ");
    scanf("%s", b);

    int al = strlen(a), bl = strlen(b);
    strcpy(c, a);

    for (i = 0; i < bl - 1; i++) strcat(c, "0");

    crc(c, b, d);

    for (i = al; i < al + bl - 1; i++) c[i] = d[i];

    printf("Transmitted codeword: %s\n", c);

    crc(c, b, d);

    int v = 1;
    for (i = al; i < al + bl - 1; i++) {
        if (d[i] != '0') {
            v = 0;
            break;
        }
    }

    if (v)
        printf("No Error Detected!\n");
    else
        printf("Error Detected!\n");

    return 0;
}
