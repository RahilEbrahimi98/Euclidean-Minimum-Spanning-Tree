/* C program for Merge Sort */
#include <stdio.h> 
#include <stdlib.h> 
  
// Merges two subarrays of arr[]. 
// First subarray is arr[l..m] 
// Second subarray is arr[m+1..r] 
void merge(int arr[][2], int l, int m, int r, int dim) 
{ 
    int i, j, k; 
    int n1 = m - l + 1; 
    int n2 = r - m; 
  
    /* create temp arrays */
    int L[n1][2], R[n2][2]; 
  
    /* Copy data to temp arrays L[] and R[] */
    for (i = 0; i < n1; i++) 
    {
        L[i][0] = arr[l + i][0]; 
        L[i][1] = arr[l + i][1];
    }
    for (j = 0; j < n2; j++) 
    {
        R[j][0] = arr[m + 1 + j][0];
        R[j][1] = arr[m + 1 + j][1]; 
    }
    /* Merge the temp arrays back into arr[l..r]*/
    i = 0; // Initial index of first subarray 
    j = 0; // Initial index of second subarray 
    k = l; // Initial index of merged subarray 
    while (i < n1 && j < n2) { 
        if (L[i][dim] <= R[j][dim]) { 
            arr[k][0] = L[i][0]; 
            arr[k][1] = L[i][1];
            i++; 
        } 
        else { 
            arr[k][0] = R[j][0]; 
            arr[k][1] = R[j][1]; 
            j++; 
        } 
        k++; 
    } 
  
    /* Copy the remaining elements of L[], if there 
       are any */
    while (i < n1) { 
        arr[k][0] = L[i][0]; 
        arr[k][1] = L[i][1]; 
        i++; 
        k++; 
    } 
  
    /* Copy the remaining elements of R[], if there 
       are any */
    while (j < n2) { 
        arr[k][0] = R[j][0]; 
        arr[k][1] = R[j][1]; 
        j++; 
        k++; 
    } 
} 
  
/* l is for left index and r is right index of the 
   sub-array of arr to be sorted */
void mergeSort(int arr[][2], int l, int r, int dim) 
{ 
    if (l < r) { 
        // Same as (l+r)/2, but avoids overflow for 
        // large l and h 
        int m = l + (r - l) / 2; 
  
        // Sort first and second halves 
        mergeSort(arr, l, m, dim); 
        mergeSort(arr, m + 1, r, dim); 
  
        merge(arr, l, m, r, dim); 
    } 
} 
  
/* UTILITY FUNCTIONS */
/* Function to print an array */
void printArray(int A[][2], int size) 
{ 
    int i; 
    for (i = 0; i < size; i++) 
        printf("(%d,%d) ", A[i][0],A[i][1]); 
    printf("\n"); 
} 
  
/* Driver program to test above functions */
int main() 
{ 
    int arr[][2] = {{12,2}, {11,4}, {13,15}, {5,0}, {6,90}, {7,20 }}; 
    int arr_size = sizeof(arr) / sizeof(arr[0]); 
    
    printf("Given array is \n"); 
    printArray(arr, arr_size); 
  
    mergeSort(arr, 0, arr_size - 1,1); 
  
    printf("\nSorted array is \n"); 
    printArray(arr, arr_size); 
    return 0; 
} 
