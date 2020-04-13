#include <math.h> 
#include <stdio.h> 
#include <stdlib.h>
#include <time.h>
#define NUMEL 1000
char* filename = "data1000.txt";
/* Function to sort an array using insertion sort*/
void insertionSort(int arr[], int n) 
{ 
    int i, key, j; 
    for (i = 1; i < n; i++) { 
        key = arr[i]; 
        j = i - 1; 
  
        /* Move elements of arr[0..i-1], that are 
          greater than key, to one position ahead 
          of their current position */
        while (j >= 0 && arr[j] > key) { 
            arr[j + 1] = arr[j]; 
            j = j - 1; 
        } 
        arr[j + 1] = key; 
    } 
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
  
    insertionSort(arr, NUMEL); 
  
    //printf("\nSorted array is \n"); 
    //printArray(arr, arr_size); 
    free(arr);
    end = clock();
    printf("Execution time = %f seconds\n", ((double) (end - start)) / CLOCKS_PER_SEC);
    return 0; 
} 
