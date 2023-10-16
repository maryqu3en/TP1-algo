#include <stdio.h>
#include <stdlib.h>

void fillRandom(int *arr, int size, int max);
void swap(int *x, int *y);
void selectionSort(int *arr, int size);
void printOriginalArray(int *arr, int size);
void printSortedArray(int *arr, int size);

int main()
{
    int SIZE;
    printf("Enter array size: ");
    scanf("%d", &SIZE);
    int MAX = 1000000;
    int A[SIZE];

    fillRandom(A, SIZE, MAX);

    printOriginalArray(A, SIZE);
    selectionSort(A, SIZE);
    printSortedArray(A, SIZE);
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