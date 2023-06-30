
#include <stdio.h>
int i=1;
int TOH(int n, char A, char B, char C){
    if(n>0){
        TOH(n-1,A,C,B);
        printf("%d Move %d disk from %c to %c \n ",i++,n, A,C);
        TOH(n-1,B,A,C);
    }
}

int main() {
    system ("clear");
   int n;
   printf("Enter the number of disk:");
   scanf("%d",&n);
   TOH(n,'a','b','c');
   
    return 0;
}
