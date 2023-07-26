// Heap Sort
#include <stdio.h>
void swap(int *a, int *b){
    int temp=*a;
    *a=*b;
    *b=temp;
    
}
void heapify(int a[], int n, int i){
    int largest, lc, rc;
    largest =i;
    lc=2*i+1;
    rc=lc+1;
    if(lc<n && a[lc]>a[largest])
    largest=lc;
    if(rc<n && a[rc]>a[largest])
    largest=rc;
    if(largest!=i){
        swap(&a[i], &a[largest]);
        heapify(a,n,largest);
    }
}
void heap_sort(int *a, int n){
    int i;
    for(i=n/2-1; i>=0; i--){
        heapify(a,n,i);
    }
    for(i=n-1; i>0; i--){
        swap(&a[0], &a[i]);
        heapify(a,i,0);
    }
}
void printArray(int arr[], int n) {
	int i;
    for (i = 0; i < n; ++i)
      printf("%d ", arr[i]);
    printf("\n");
  }
int main() {
    int arr[10]={11,12,13,14,55,66,7,8,9,91};
    int size=sizeof(arr)/sizeof(arr[0]);
    

    heap_sort(arr,size);
    printArray(arr,size);



    return 0;
}
