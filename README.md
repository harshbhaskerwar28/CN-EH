## CN-EH CODES

---

### **1. Byte Stuffing**  
```c
#include <stdio.h>
#include <string.h>

int main() {
    int n, j = 0;
    printf("Enter Size of the String - ");
    scanf("%d", &n);

    char input[n + 1], start_delimiter, end_delimiter, output[2 * n + 1];
    printf("Enter the String - ");
    scanf("%s", input);

    printf("Enter the Start Delimiter: ");
    scanf(" %c", &start_delimiter);

    printf("Enter the End Delimiter: ");
    scanf(" %c", &end_delimiter);

    output[j++] = start_delimiter; // Add start delimiter

    for (int i = 0; i < n; i++) {
        if (input[i] == start_delimiter || input[i] == end_delimiter) {
            output[j++] = start_delimiter; // Add extra start delimiter for escape
        }
        output[j++] = input[i]; // Add the current character
    }

    output[j++] = end_delimiter; // Add end delimiter
    output[j] = '\0';            // Null-terminate the output string

    printf("The Final String After Character Stuffing = %s\n", output);

    return 0;
}
```

---

### **2. Bit Stuffing**  
```c
#include <stdio.h>

int main() {
    int a[20], b[30], n, i, j = 0, count = 0;

    printf("Enter frame size (Example: 8): ");
    scanf("%d", &n);

    printf("Enter the frame in the form of 0 and 1: ");
    for (i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }

    for (i = 0; i < n; i++) {
        b[j++] = a[i];
        if (a[i] == 1) {
            count++;
            if (count == 5) {
                b[j++] = 0; // Add a 0 after five consecutive 1s
                count = 0;
            }
        } else {
            count = 0;
        }
    }

    printf("After Bit Stuffing: ");
    for (i = 0; i < j; i++) {
        printf("%d", b[i]);
    }
    printf("\n");

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
                res[i + j] = (res[i + j] == g[j]) ? '0' : '1'; 
            }
        }
    }
}

int main() {
    char d[100], g[20], res[120], code[120];
    int i;

    printf("Enter data bits: ");
    scanf("%s", d);  // Read data bits

    printf("Enter generator bits: ");
    scanf("%s", g);  // Read generator bits

    int dl = strlen(d), gl = strlen(g);
    strcpy(code, d);

    for (i = 0; i < gl - 1; i++) strcat(code, "0");  // Append zeros to the data

    crc(code, g, res);  // Perform CRC division

    for (i = dl; i < dl + gl - 1; i++) code[i] = res[i];  // Get the remainder

    printf("Transmitted codeword: %s\n", code);

    crc(code, g, res);  // Check for errors

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
#include <limits.h>

#define MAX_NODES 10

void print_table(int n, int dist[n][n], int via[n][n]) {
    printf("Node Distance Via\n");
    for (int i = 0; i < n; i++) {
        printf("%d ", i);
        for (int j = 0; j < n; j++) {
            if (dist[i][j] == INT_MAX)
                printf("-1 ");  // Representing no path as -1
            else
                printf("%d ", dist[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int n;
    printf("Enter the number of nodes: ");
    scanf("%d", &n);

    int cost[n][n], dist[n][n], via[n][n];

    printf("Enter the cost matrix (-1 for infinity):\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &cost[i][j]);
            if (cost[i][j] == -1 && i != j) {
                dist[i][j] = INT_MAX;  // Representing no connection with INT_MAX
                via[i][j] = -1;        // No intermediate node
            } else {
                dist[i][j] = cost[i][j];
                via[i][j] = i;         // Direct connection uses the node itself
            }
        }
    }

    // Distance vector algorithm (Bellman-Ford style)
    for (int k = 0; k < n; k++) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (dist[i][j] > dist[i][k] + dist[k][j] && dist[i][k] != INT_MAX && dist[k][j] != INT_MAX) {
                    dist[i][j] = dist[i][k] + dist[k][j];
                    via[i][j] = via[k][j];  // Update via with intermediate node
                }
            }
        }
    }

    printf("Node Distance Via\n");
    for (int i = 0; i < n; i++) {
        printf("%d ", i);
        if (dist[0][i] == INT_MAX) {
            printf("-1 ");  // No path, so print -1
        } else {
            printf("%d ", dist[0][i]);
        }
        printf("%d\n", via[0][i]);
    }

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
