#include <stdio.h>

#define SIZE 20

int hashTable[SIZE];

void init(int m) {
    for (int i = 0; i < m; i++)
        hashTable[i] = -1;
}

void insert(int key, int m) {
    int index = key % m;
    while (hashTable[index] != -1) {
        index = (index + 1) % m;
    }
    hashTable[index] = key;
}

void display(int m) {
    printf("\nHash Table:\n");
    for (int i = 0; i < m; i++) {
        if (hashTable[i] == -1)
            printf("%d : EMPTY\n", i);
        else
            printf("%d : %d\n", i, hashTable[i]);
    }
}

int main() {
    int n, key, m;

    printf("Enter size of Hash Table (m): ");
    scanf("%d", &m);

    init(m);

    printf("Enter number of employee records (N): ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        printf("Enter 4-digit key: ");
        scanf("%d", &key);
        insert(key, m);
    }

    display(m);
    return 0;
}
