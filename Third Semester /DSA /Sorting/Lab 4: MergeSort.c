#include <stdio.h>

void display(int *a, int n) {
    for (int i = 0; i < n; i++) {
        printf("%-6d", a[i]);
    }
}

void conquer(int *a, int si, int mid, int ei) {
    int merge[ei - si + 1];
    int idx1 = si;
    int idx2 = mid + 1;
    int x = 0;

    while (idx1 <= mid && idx2 <= ei) {
        if (a[idx1] <= a[idx2]) {
            merge[x] = a[idx1];
            x++;
            idx1++;
        } else {
            merge[x++] = a[idx2++];
        }
    }

    while (idx1 <= mid) {
        merge[x++] = a[idx1++];
    }

    while (idx2 <= ei) {
        merge[x++] = a[idx2++];
    }
    
    for (int i = 0; i < ei - si + 1; i++) {
        a[si + i] = merge[i];
    }
}

void divide(int *a, int si, int ei) {
    if (si >= ei) {
        return;
    }

    int mid = si + (ei - si) / 2;
    divide(a, si, mid);
    divide(a, mid + 1, ei);
    conquer(a, si, mid, ei);
}

int main() {
    int n;
    printf("Enter the size of the array: ");
    scanf("%d", &n);
    int a[n];

    for (int i = 0; i < n; i++) {
        printf("Enter item %d: ", i + 1);
        scanf("%d", &a[i]);
    }

    printf("\nThe array before sorting:\n");
    display(a, n);

    printf("\nThe array after merge sort:\n");
    divide(a, 0, n - 1);
    display(a, n);

    return 0;
}
