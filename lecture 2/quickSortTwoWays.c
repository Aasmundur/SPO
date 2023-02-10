#include <stdlib.h>
#include <stdio.h>
#include <string.h>


void quickSort2Ways(void);
void quickSort (int arr[], int low, int high);
void quickSortIterative(int arr[], int low, int high);
int partition(int arr[], int low, int high);
void printSortedArr(int arr[], int size);


int main(void){
    quickSort2Ways();
}


void quickSort2Ways(void){
    int arr[] = {1, 3, 2, 6, 2, 5};
    int size;
    size = sizeof(arr)/sizeof(arr[0]);

    /*QUICKSORT IMPLEMENTED RECURSIVELY AND ITERATIVELY*/
    quickSort(arr, 0,size-1);
    printf("\n\nRECURSIVELY\n\n");
    printSortedArr(arr, size);
    printf("\n\nITERATIVELY\n\n");
    quickSortIterative(arr, 0, size-1);
    printSortedArr(arr, size);

}

void quickSort (int arr[], int low, int high){
    if(low<high){
        //partitioning index pi
        int pi;
        pi = partition(arr, low, high);
        quickSort(arr, low, pi-1);
        quickSort(arr, pi+1, high);
    }
}

void quickSortIterative(int arr[], int low, int high){
    int pi, pi2, i, temp;

    
    for(i=0; i<=high; i++){
        pi= partition(arr, low, high);
        partition(arr, low, pi-1);
    }
}

int partition(int arr[], int low, int high){
    //pivot (element to be placed at the right position)
    int pivot, i, j, temp, tempTwo;
    pivot = arr[high];
    i=(low-1); //Index of smaller element and indicates the right position of pivot so far

    for(j=low; j<=high; j++){
        if(arr[j] < pivot){
            i++;
            temp = arr[j];
            arr[j]=arr[i];
            arr[i]=temp;
        }
    }
    tempTwo = arr[high];
    arr[high] = arr[i+1];
    arr[i+1]=tempTwo;
    return (i+1);
}

void printSortedArr(int arr[], int size){
    int i;
    for(i=0; i<size; i++){
        printf("\n%d\n", arr[i]);
    }
}
