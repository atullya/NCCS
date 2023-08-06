#include <stdio.h>

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

int partition(int *arr, int low, int high) {
    int pivot = arr[high];
    int i = low - 1, j;

    for (j = low; j <= high - 1; j++) {
        if (arr[j] <= pivot) {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    return i + 1;
}

void quickSort(int *arr, int low, int high) {
    if (low >= high)
        return;

    int p;
    p = partition(arr, low, high);

    quickSort(arr, low, p - 1);
    quickSort(arr, p + 1, high);
}

void display(int *arr, int n) {
    for (int i = 0; i < n; i++) {
        printf("%d\t", arr[i]);
    }
    printf("\n");
}

int main() {
 
    int n;
    printf("Enter the total no. of elements: ");
    scanf("%d", &n);
    int numbers[n];
    printf("Enter %d numbers\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &numbers[i]);
    }
    printf("The numbers before sorting: ");
    display(numbers, n);
    quickSort(numbers, 0, n - 1);
    printf("The numbers after sorting using quick sort: ");
    display(numbers, n);
    return 0;
}
