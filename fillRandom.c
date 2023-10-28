#include <stdio.h>
#include <stdlib.h>

void fillRandom(int *arr, int size, int max);
void swap(int *x, int *y);
void selectionSort(int *arr, int size);
void insertionSort(int *arr, int size);
void printOriginalArray(int *arr, int size);
void printSortedArray(int *arr, int size);

int main()
{
    int SIZE;
    printf("Enter array size: ");
    scanf("%d", &SIZE);
    int MAX = 1000000;
    // int MAX;
    // printf("Enter maximum value of array: ");
    // scanf("%d", &MAX);
    int A[SIZE];
    fillRandom(A, SIZE, MAX);
    printf("\nYour array has been filled successfully with random integer values. \nChoose which method to use for sorting your array: \n \tChoose \"1\" for selection sort\n \tChoose \"2\" for insertion sort\n");
    int choice;
    scanf("%d", &choice);
    
    if (choice == 1)
    {
        printOriginalArray(A, SIZE);
        selectionSort(A, SIZE);
        printSortedArray(A, SIZE);
    }
    else if (choice == 2)
    {
        printOriginalArray(A, SIZE);
        insertionSort(A, SIZE);
        printSortedArray(A, SIZE);
    }
    else
    {
        printf("The choice you entered is not available.");
    }
    printf("\n\n\n");
    return 0;
}

void fillRandom(int *arr, int size, int max)
{
    for (int i = 0; i < size; i++)
    {
        arr[i] = rand() % max;
    }
}

void swap(int *x, int *y)
{
    int temp = *x;
    *x = *y;
    *y = temp;
}

void selectionSort(int *arr, int size)
{
    for (int i = 0; i < size - 1; i++)
    {
        int minIndex = i;
        for (int j = i + 1; j < size; j++)
        {
            if (arr[j] < arr[minIndex])
            {
                minIndex = j;
            }
        }
        swap(&arr[i], &arr[minIndex]);
    }
}

void insertionSort(int *arr, int size)
{
    int pos, temp;
    for (int i = 1; i < size; i++)
    {
        temp = arr[i];
        pos = i;
        while ((pos > 0) && (arr[pos - 1] > temp))
        {
            arr[pos] = arr[pos - 1];
            pos = pos - 1;
        }
        arr[pos] = temp;
    }
}

void printOriginalArray(int *arr, int size)
{
    printf("The original array: \n");
    for (int i = 0; i < size; i++)
    {
        printf("%d \t", arr[i]);
    }
}

void printSortedArray(int *arr, int size)
{
    printf("\nThe sorted array: \n");
    for (int i = 0; i < size; i++)
    {
        printf("%d \t", arr[i]);
    }
}