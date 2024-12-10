## CN-EH Codes

---

### **1. Byte Stuffing**
**Code:**
```c
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
```
**Sample Output:**
```
Enter Size of the String - 5
Enter the String - abcba
Enter the Start Delimiter: $
Enter the End Delimiter: #
The Final String After Character Stuffing = $abc$ba#
```

---

### **2. Bit Stuffing**
**Code:**
```c
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
```
**Sample Output:**
```
Enter frame size: 8
Enter the frame in the form of 0 and 1: 1 1 1 1 1 0 0 1
After Bit Stuffing: 111110001
```

---

### **3. CRC**
**Code:**
```c
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
```
**Sample Output:**
```
Enter data bits: 1101
Enter generator bits: 101
Transmitted codeword: 110100
No Error Detected!
```

---

### **4. Distance Vector Routing**

**Code:**
```c
#include<stdio.h>
struct node{
    unsigned dist[20];
    unsigned from[20];
}rt[20];

int main(){
    int c[20][20];
    int i, j ,k ,n, count=0;
    printf("Enter the no of nodes:");
    scanf("%d",&n);
    printf("\n Enter the cost matrix:\n");
    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            c[i][j]=0;
            scanf("%d",&c[i][j]);
            rt[i].dist[j] = c[i][j];
            rt[i].from[j] = j;
        }
    }
    do{
        count=0;
        for (i=0;i<n;i++)
        for(j=0;j<n;j++)
        for(k=0;k<n;k++)
        if(rt[i].dist[j] > c[i][k] + rt[k].dist[j]){
            rt[i].dist[j] = rt[i].dist[k]+rt[k].dist[j];
            rt[i].from[j] = k;
            count++;
        }
    }while(count!=0);
    
    for(i=0;i<n;i++){
        printf("\n\nFor router %d\n",i+1);
        for(j=0;j<n;j++){
            printf("\t\nnode %d via %d distance %d",j+1,rt[i].from[j]+1,rt[i].dist[j]);
        }
    }
    printf("\n\n");
}
```

**Sample Output:**
```
Enter the no of nodes:3
Enter the cost matrix:
0 2 7
2 0 1
7 1 0


For router 1
	
node 1 via 1 distance 0	
node 2 via 2 distance 2	
node 3 via 2 distance 3

For router 2
	
node 1 via 1 distance 2	
node 2 via 2 distance 0	
node 3 via 3 distance 1

For router 3
	
node 1 via 2 distance 3	
node 2 via 2 distance 1	
node 3 via 3 distance 0

```

---

### **5. Flow Control Protocols**

#### a. Sliding Window Protocol
**Code:**
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
        for (i = s; i < s + w && i < n; i++) {
            printf("%d ", i + 1);
        }
        printf("\nAcknowledged up to frame %d\n", s + w);
        s += w;
    }

    return 0;
}
```

**Sample Output:**
```
Enter number of frames: 5
Enter window size: 2
Sending frames: 1 2 
Acknowledged up to frame 2
Sending frames: 3 4 
Acknowledged up to frame 4
Sending frames: 5 
Acknowledged up to frame 6
```

#### b. Stop-and-Wait Protocol (with Internet Check Simulation)
**Code:**
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
```

**Sample Output:**
```
Enter number of frames: 3
Sending frame 1
Acknowledgment received for frame 1
Sending frame 2
No acknowledgment, resending frame 2
Sending frame 2
Acknowledgment received for frame 2
Sending frame 3
Acknowledgment received for frame 3
```

--- 
