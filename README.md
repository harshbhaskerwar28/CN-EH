## CN&EH Codes

---

### **1. Byte Stuffing**
```c
#include <stdio.h>
#include <string.h>

int main() {
    int n, j = 0;
    printf("Enter size: ");
    scanf("%d", &n);

    char a[n + 1], b, c, d[2 * n + 1];
    printf("Enter string: ");
    scanf("%s", a);

    printf("Enter start delimiter: ");
    scanf(" %c", &b);

    printf("Enter end delimiter: ");
    scanf(" %c", &c);

    d[j++] = b;

    for (int i = 0; i < n; i++) {
        if (a[i] == b || a[i] == c) d[j++] = b;
        d[j++] = a[i];
    }

    d[j++] = c;
    d[j] = '\0';

    printf("Final string: %s\n", d);
    return 0;
}
```

---

### **2. Bit Stuffing**
```c
#include <stdio.h>

int main() {
    int a[20], b[30], n, i, j = 0, k = 0;
    printf("Enter frame size: ");
    scanf("%d", &n);

    printf("Enter frame: ");
    for (i = 0; i < n; i++) scanf("%d", &a[i]);

    for (i = 0; i < n; i++) {
        b[j++] = a[i];
        if (a[i] == 1) {
            k++;
            if (k == 5) {
                b[j++] = 0;
                k = 0;
            }
        } else k = 0;
    }

    printf("After stuffing: ");
    for (i = 0; i < j; i++) printf("%d", b[i]);
    printf("\n");
    return 0;
}
```

---

### **3. CRC**
```c
#include <stdio.h>
#include <string.h>

void f(char a[], char b[], char c[]) {
    int i, j, m = strlen(a), n = strlen(b);
    strcpy(c, a);

    for (i = 0; i <= m - n; i++) {
        if (c[i] == '1') {
            for (j = 0; j < n; j++) c[i + j] = (c[i + j] == b[j]) ? '0' : '1';
        }
    }
}

int main() {
    char a[100], b[20], c[120], d[120];
    int i, x;

    printf("Enter data: ");
    scanf("%s", a);

    printf("Enter generator: ");
    scanf("%s", b);

    x = strlen(b) - 1;
    strcpy(d, a);

    for (i = 0; i < x; i++) strcat(d, "0");

    f(d, b, c);

    for (i = strlen(a); i < strlen(d); i++) d[i] = c[i];
    printf("Codeword: %s\n", d);

    f(d, b, c);

    int valid = 1;
    for (i = strlen(a); i < strlen(d); i++) {
        if (c[i] != '0') {
            valid = 0;
            break;
        }
    }
    printf(valid ? "No Error\n" : "Error\n");
    return 0;
}
```

---

### **4. Distance Vector Routing**
```c
#include <stdio.h>
#include <limits.h>

#define N 10

int main() {
    int n, a[N][N], b[N][N], c[N][N];

    printf("Enter nodes: ");
    scanf("%d", &n);

    printf("Enter costs (-1 for no connection):\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &a[i][j]);
            if (a[i][j] == -1 && i != j) {
                b[i][j] = INT_MAX;
                c[i][j] = -1;
            } else {
                b[i][j] = a[i][j];
                c[i][j] = i;
            }
        }
    }

    for (int k = 0; k < n; k++) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (b[i][j] > b[i][k] + b[k][j] && b[i][k] != INT_MAX && b[k][j] != INT_MAX) {
                    b[i][j] = b[i][k] + b[k][j];
                    c[i][j] = c[k][j];
                }
            }
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) printf("%d ", b[i][j]);
        printf("\n");
    }

    return 0;
}
```

---

### **5. Sliding Window Protocol**
```c
#include <stdio.h>

int main() {
    int n, w, s = 0, i;

    printf("Enter frames: ");
    scanf("%d", &n);

    printf("Enter window: ");
    scanf("%d", &w);

    while (s < n) {
        for (i = s; i < s + w && i < n; i++) printf("%d ", i + 1);
        printf("\n");
        s += w;
    }

    return 0;
}
```

---

### **6. Stop-and-Wait Protocol**
```c
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int n, i, x;

    printf("Enter frames: ");
    scanf("%d", &n);

    srand(time(0));

    for (i = 1; i <= n; i++) {
        x = rand() % 2;
        if (x) printf("Ack for %d\n", i);
        else {
            printf("No ack, resend %d\n", i);
            i--;
        }
    }

    return 0;
}
```

--- 
