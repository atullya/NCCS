#include<iostream>
using namespace std;
int count = 0;

void SelectionSort(int A[],int n)
{
    for(int i=0;i<n;i++)
    {
        int least =A[i];
        int loc =i;
        
        for(int j=i+1;j<n;j++)
        {
            if(A[j]<least)
            {
                least = A[j];
                loc =j;                
            }
            
            count =count+6;
        }
        A[loc] = A[i];
        A[i] =least;
        count = count+8;
    }   
		for(int i=0;i<n;i++)
	{
			cout<<A[i]<<"\t";
	}
	cout<<"\nThe total number of steps for selection sort is:"<<count<<endl; 
}
int main()
{
    
	int n;
	cout<<"Enter the size of data:";
	cin>>n;
	int a[n];
	cout<<"Enter the Elements:"<<endl;
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
	}
	cout<<"Elements before sorting:"<<endl;
		for(int i=0;i<n;i++)
	{
		cout<<a[i]<<"\t";
	}
	cout<<"\nElements after sorting:"<<endl;
	SelectionSort(a,n);

}
