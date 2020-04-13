#include <math.h> 
#include <stdio.h> 
#include <stdlib.h>
#include <time.h>
#define NUMEL 1000
char* filename = "data1000.txt";

void swap(int *xp, int *yp) 
{ 
    int temp = *xp; 
    *xp = *yp; 
    *yp = temp; 
} 
  
// A function to implement bubble sort 
void bubbleSort(int arr[], int n) 
{ 
   int i, j; 
   for (i = 0; i < n-1; i++)       
  
       // Last i elements are already in place    
       for (j = 0; j < n-i-1; j++)  
           if (arr[j] > arr[j+1]) 
              swap(&arr[j], &arr[j+1]); 
}  
// A utility function to print an array of size n 
void printArray(int arr[], int n) 
{ 
    int i; 
    for (i = 0; i < n; i++) 
        printf("%d ", arr[i]); 
    printf("\n"); 
} 

void readfile(int A[], int size)
{
	FILE *fp = fopen(filename,"r");
	if (fp == NULL)
		return;
	for (int i = 0; i < size; i++)
	{
		fscanf(fp, "%d", &A[i]);
	}
	fclose(fp);
}
 
/* Driver program to test above functions */
int main() 
{ 
    clock_t start, end;
    start = clock();
    int *arr = malloc(sizeof(int)*NUMEL);  
    int arr_size = NUMEL; 
    readfile(arr, NUMEL);
  
    //printf("Given array is \n"); 
    //printArray(arr, arr_size); 
  
    bubbleSort(arr, NUMEL); 
  
    //printf("\nSorted array is \n"); 
    //printArray(arr, arr_size); 
    free(arr);
    end = clock();
    printf("Execution time = %f seconds\n", ((double) (end - start)) / CLOCKS_PER_SEC);
    return 0; 
} 
