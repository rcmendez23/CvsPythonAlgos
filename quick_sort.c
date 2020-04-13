#include <math.h> 
#include <stdio.h> 
#include <stdlib.h>
#include <time.h>
#define NUMEL 100000

// A utility function to swap two elements
void swap(int* a, int* b) 
{ 
    int t = *a; 
    *a = *b; 
    *b = t; 
} 
  
/* This function takes last element as pivot, places 
   the pivot element at its correct position in sorted 
    array, and places all smaller (smaller than pivot) 
   to left of pivot and all greater elements to right 
   of pivot */
int partition (int arr[], int low, int high) 
{ 
    int pivot = arr[high];    // pivot 
    int i = (low - 1);  // Index of smaller element 
  
    for (int j = low; j <= high- 1; j++) 
    { 
        // If current element is smaller than the pivot 
        if (arr[j] < pivot) 
        { 
            i++;    // increment index of smaller element 
            swap(&arr[i], &arr[j]); 
        } 
    } 
    swap(&arr[i + 1], &arr[high]); 
    return (i + 1); 
} 
  
/* The main function that implements QuickSort 
 arr[] --> Array to be sorted, 
  low  --> Starting index, 
  high  --> Ending index */
void quickSort(int arr[], int low, int high) 
{ 
    if (low < high) 
    { 
        /* pi is partitioning index, arr[p] is now 
           at right place */
        int pi = partition(arr, low, high); 
  
        // Separately sort elements before 
        // partition and after partition 
        quickSort(arr, low, pi - 1); 
        quickSort(arr, pi + 1, high); 
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
	FILE *fp = fopen("data.txt","r");
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
 
    quickSort(arr, 0, NUMEL - 1); 
  
    //printf("\nSorted array is \n"); 
    //printArray(arr, arr_size); 
    free(arr);
    end = clock();
    printf("Execution time = %f seconds\n", ((double) (end - start)) / CLOCKS_PER_SEC);
    return 0; 
} 
