#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define MAXLEN 100

struct student {
    char name[MAXLEN];
    int age;
    double GPA;
    char gradelevel[MAXLEN];
} student, student2, students[MAXLEN];

void opg1firsthalf(void);
void opg1secondhalf(void);
void opg2(void);
void opg3(void);
void quickSort (int arr[], int low, int high);
void quickSortIterative(int arr[], int low, int high);
int partition(int arr[], int low, int high);
void printSortedArr(int arr[], int size);


int main(void){
    //opg1firsthalf();
    opg1secondhalf();
    opg2();
    opg3();
}

/*1. To understand the value of records in a programming language, write a
small program in a C-based language that uses an array of structs that
store student information, including name, age, GPA as a float, and grade
level as a string (e.g., “freshmen,” etc.). Also, write the same program in
the same language without using structs.*/
void opg1firsthalf(void){
    strcpy(student.name, "peter");
    strcpy(student.gradelevel, "firstyear");
    student.age=2;
    student.GPA=3.2;

    strcpy(student2.name, "ali");
    strcpy(student2.gradelevel, "second year");
    student2.age=4;
    student2.GPA=5;

    students[0] = student;
    students[1] = student2;
    printf("\n %s \n %d \n %f \n %s \n\n", student.name, student.age, student.GPA, student.gradelevel);
    printf("\n %s \n %d \n %f \n %s \n\n", student2.name, student2.age, student2.GPA, student2.gradelevel);
}

void opg1secondhalf(void){
  //2 dimensionelt array ville kunne gøre arbejdet.
}
/*2. To understand the value of recursion in a programming language, write a
program that implements quicksort, first using recursion and then without
recursion.*/
void opg2(void){
    int arr[] = {1, 3, 2, 6, 2, 5};
    int size;
    size = sizeof(arr)/sizeof(arr[0]);
    //quickSort(arr, 0,size-1);
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
