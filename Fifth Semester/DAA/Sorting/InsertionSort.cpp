#include<iostream>
using namespace std;
int count =0;
void InsertionSort(int A[],int n)
{
    int key;
    int j;
    for(int i=1;i<=n-1;i++)
    {
        key =A[i];
    
        for(j=i-1;A[j]>key && j>=0;j--)
        {
            A[j+1] =A[j];
            count += 7;
        }
        A[j+1] = key;
            count += 7;
    }
	for(int i=0;i<n;i++)
	{
			cout<<A[i]<<"\t";
	}
	cout<<"\nThe total number of steps for insertion sort is:"<<count<<endl; 
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
	InsertionSort(a,n);
}
