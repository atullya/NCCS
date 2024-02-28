#include<stdio.h>

// Function to allocate memory to blocks as per worst fit algorithm 
void worstFit(int blockSize[], int m, int processSize[], int n) 
{ 
    // Stores block id of the block allocated to a process 
    int allocation[n]; 

    // Initially no block is assigned to any process 
    for (int i = 0; i < n; i++) 
        allocation[i] = -1; 

    // pick each process and find suitable blocks 
    // according to its size and assign to it 
    for (int i = 0; i < n; i++) 
    { 
        // Find the worst fit block for the current process 
        int wstIdx = -1; 
        for (int j = 0; j < m; j++) 
        { 
            if (blockSize[j] >= processSize[i]) 
            { 
                if (wstIdx == -1) 
                    wstIdx = j; 
                else if (blockSize[wstIdx] < blockSize[j]) 
                    wstIdx = j; 
            } 
        } 

        // If we could find a block for the current process 
        if (wstIdx != -1) 
        { 
            // allocate block j to p[i] process 
            allocation[i] = wstIdx; 

            // Reduce available memory in this block. 
            blockSize[wstIdx] -= processSize[i]; 
        } 
    } 

    printf("\nProcess No.\tProcess Size\tBlock no.\n"); 
    for (int i = 0; i < n; i++) 
    { 
        printf(" %d\t\t%d\t\t", i + 1, processSize[i]); 
        if (allocation[i] != -1) 
            printf("%d", allocation[i] + 1); 
        else
            printf("Not Allocated"); 
        printf("\n"); 
    } 
} 

// Driver code 
int main() 
{ 
   int blockSize[] = {200,400,600,500,300,250}; 
	int processSize[] = {357,210,468,419};
    int m = sizeof(blockSize) / sizeof(blockSize[0]); 
    int n = sizeof(processSize) / sizeof(processSize[0]); 

    worstFit(blockSize, m, processSize, n); 

    return 0 ; 
}
