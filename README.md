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
