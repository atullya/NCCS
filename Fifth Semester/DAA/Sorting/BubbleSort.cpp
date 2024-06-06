#include<iostream>
using namespace std;
int count = 0;

void BubbleSort(int A[],int n)
{
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n-1;j++)
        {
            if(A[j]>A[j+1])
            {
                int t= A[j];
                A[j]=A[j+1];
                A[j+1]=t;
                
            }
            
            count =count+8;
            
        }
        count = count+4;
    }    
}

int main()
{
    
int a[9] = {110,2,22,44,819,30,10,1,210};



cout<<"Before sorting: \n";
   for(int i=0 ;i<9 ;i++)
        {
    cout<<a[i]<<"\t" ;
    
    
        }
        
    cout<<endl;
    
BubbleSort(a,9);

cout<<"After Bubble sorting: \n";
 for(int i=0 ;i<9 ;i++)
        {
    cout<<a[i]<<"\t" ;
        }
cout<<endl;        
cout<<"No. of Steps required : "<<count;        
        
return 0;

}
