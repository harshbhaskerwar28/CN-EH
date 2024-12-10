## CN-EH CODES

---

### **1. Byte Stuffing**  
```c
#include <stdio.h>
#include <string.h>

int main() {
    char in[100], out[200];
    int i, j = 0;

    printf("Enter the input string: ");
    scanf("%s", in);

    out[j++] = 'F';  // Starting Flag
    for (i = 0; in[i] != '\0'; i++) {
        if (in[i] == 'F' || in[i] == 'E') {
            out[j++] = 'E';  // Escape character
        }
        out[j++] = in[i];
    }
    out[j++] = 'F';  // Ending Flag
    out[j] = '\0';

    printf("Byte Stuffed Output: %s\n", out);
    return 0;
}
```

---

### **2. Bit Stuffing**  
```c
#include <stdio.h>
#include <string.h>

int main() {
    char in[100], out[200];
    int i, j = 0, cnt = 0;

    printf("Enter the input bit stream: ");
    scanf("%s", in);

    for (i = 0; in[i] != '\0'; i++) {
        out[j++] = in[i];
        if (in[i] == '1') {
            cnt++;
            if (cnt == 5) {
                out[j++] = '0';  // Stuffing a '0' after five '1's
                cnt = 0;
            }
        } else {
            cnt = 0;
        }
    }
    out[j] = '\0';

    printf("Bit Stuffed Output: %s\n", out);
    return 0;
}
```

---

### **CRC**  
```c
#include <stdio.h>
#include <string.h>

void crc(char d[], char g[], char res[]) {
    int i, j, dl = strlen(d), gl = strlen(g);

    strcpy(res, d);
    for (i = 0; i <= dl - gl; i++) {
        if (res[i] == '1') {
            for (j = 0; j < gl; j++) {
                res[i + j] = res[i + j] == g[j] ? '0' : '1';  // XOR operation
            }
        }
    }
}

int main() {
    char d[100], g[20], res[120], code[120];
    int i;

    printf("Enter data bits: ");
    scanf("%s", d);

    printf("Enter generator bits: ");
    scanf("%s", g);

    int dl = strlen(d), gl = strlen(g);
    strcpy(code, d);

    // Append zero bits
    for (i = 0; i < gl - 1; i++) {
        strcat(code, "0");
    }

    crc(code, g, res);

    // Extract remainder
    for (i = dl; i < dl + gl - 1; i++) {
        code[i] = res[i];
    }

    printf("Transmitted codeword: %s\n", code);

    // Simulate receiver side
    crc(code, g, res);

    // Check if remainder is zero
    int valid = 1;
    for (i = dl; i < dl + gl - 1; i++) {
        if (res[i] != '0') {
            valid = 0;
            break;
        }
    }

    if (valid)
        printf("No Error Detected!\n");
    else
        printf("Error Detected!\n");

    return 0;
}
```

---

### **Distance Vector Routing**  
```c
#include <stdio.h>

int main() {
    int c[10][10], d[10], n, i, j, k, v[10], src;

    printf("Enter the number of nodes: ");
    scanf("%d", &n);

    printf("Enter the cost matrix:\n");
    for (i = 0; i < n; i++)
        for (j = 0; j < n; j++)
            scanf("%d", &c[i][j]);

    printf("Enter the source node: ");
    scanf("%d", &src);

    for (i = 0; i < n; i++) {
        d[i] = c[src][i];
        v[i] = 0;
    }

    v[src] = 1;

    for (i = 1; i < n; i++) {
        int min = 999, u;

        for (j = 0; j < n; j++)
            if (!v[j] && d[j] < min) {
                min = d[j];
                u = j;
            }

        v[u] = 1;

        for (k = 0; k < n; k++)
            if (!v[k] && d[u] + c[u][k] < d[k])
                d[k] = d[u] + c[u][k];
    }

    printf("Shortest distances from node %d:\n", src);
    for (i = 0; i < n; i++)
        printf("To node %d: %d\n", i, d[i]);

    return 0;
}
```

---

### **File Control Protocol**
### **a. Sliding Window Protocol**  
```c
#include <stdio.h>

int main() {
    int n, w, s = 0, i;

    printf("Enter number of frames: ");
    scanf("%d", &n);

    printf("Enter window size: ");
    scanf("%d", &w);

    while (s < n) {
        printf("Sending frames: ");
        for (i = s; i < s + w && i < n; i++)
            printf("%d ", i + 1);

        printf("\nAcknowledged up to frame %d\n", s + w);
        s += w;
    }

    return 0;
}
```

---

### **b. Stop-and-Wait Protocol (with Internet Check Simulation)**  
```c
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int n, i, ack;

    printf("Enter number of frames: ");
    scanf("%d", &n);

    srand(time(0));

    for (i = 1; i <= n; i++) {
        printf("Sending frame %d\n", i);

        ack = rand() % 2;  // Random success or failure

        if (ack) {
            printf("Acknowledgment received for frame %d\n", i);
        } else {
            printf("No acknowledgment, resending frame %d\n", i);
            i--;  // Resend the same frame
        }
    }

    return 0;
}
```

---
