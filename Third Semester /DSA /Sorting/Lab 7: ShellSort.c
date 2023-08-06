#include <stdio.h>

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void shellSort(int *arr, int n) {
    int gap, i, j, temp;
    for (gap = n / 2; gap > 0; gap /= 2) {
        for (i = gap; i < n; i++) {
            temp = arr[i];
            for (j = i; j >= gap; j -= gap) {
                if (temp < arr[j - gap]) {
                    arr[j] = arr[j - gap];
                } else {
                    break;
                }
            }
            arr[j] = temp;
        }
    }
}

void display(int *arr, int n) {
    for (int i = 0; i < n; i++) {
        printf("%d\t", arr[i]);
    }
    printf("\n");
}

int main() {
    system("clear");
    int n;
    printf("Enter the total no. of elements: ");
    scanf("%d", &n);
    int numbers[n], i;
    printf("Enter %d numbers\n", n);
    for (i = 0; i < n; i++) {
        scanf("%d", &numbers[i]);
    }
    printf("The numbers before sorting: ");
    display(numbers, n);
    shellSort(numbers, n);
    printf("The numbers after sorting using shell sort: ");
    display(numbers, n);
    return 0;
}
