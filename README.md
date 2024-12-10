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
