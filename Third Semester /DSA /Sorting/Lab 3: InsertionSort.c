// Online C compiler to run C program online
#include <stdio.h>
void display(int a[],int n ){
    for(int i=0; i<n; i++){
        printf("%d \t",a[i]);
    }
}
void insert(int a[],int n){
    int i,j;
    for( i=1; i<n; i++){
        int temp=a[i];
        j=i-1;
        while(temp<a[j]&&j>=0){
            a[j+1]=a[j];
            j--;
        }
        if(j+1!=i){
            a[j+1]=temp;
        }
       
    }
}

int main() {
 int n;
 printf("Enter the no of elements in array:");
 scanf("%d",&n);
 
 int a[n];
 
 for(int i=0; i<n; i++){
     printf("Enter %d element:",i+1);
     scanf("%d",&a[i]);
 }
 printf("The array Before Sorting is:\n");
 display(a,n);
 printf("\n");
 insert(a,n);
 printf("The array After using Insertion sort Sorting is:\n");
 display(a,n);

    return 0;
}
