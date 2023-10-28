#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void fillRandom(int *arr, int size, int max);
void swap(int *x, int *y);
void selectionSort(int *arr, int size);
void insertionSort(int *arr, int size);
void printOriginalArray(int *arr, int size);
void printSortedArray(int *arr, int size);

void fill2Random(int *arr1, int *arr2, int size, int max);

int main()
{
    int SIZE;
    printf("Enter array size: ");
    scanf("%d", &SIZE);
    int MAX = 1000000;
    int A[SIZE], B[SIZE];
    fill2Random(A, B, SIZE, MAX);
    printf("Your array has been filled successfully with random integer values.\n");
    printOriginalArray(A, SIZE);
    printf("\nThe array has been sorted using two different methods: insertion sort and selection sort.\nWe will compare the execution time of each of the methods to see which is more convinient.\n");
    double executionTime[2];

    clock_t startClock1 = clock();
    selectionSort(A, SIZE);
    clock_t endSelectionClock = clock();
    executionTime[0] = (double)(endSelectionClock - startClock1) / CLOCKS_PER_SEC;

    clock_t startClock2 = clock();
    insertionSort(B, SIZE);
    clock_t endInsertionClock = clock();
    executionTime[1] = (double)(endInsertionClock - startClock1) / CLOCKS_PER_SEC;

    printSortedArray(A, SIZE);

    printf("\nThe execution time of selection sort is: %lf s.\nThe execution time of insertion sort is: %lf s.", executionTime[0], executionTime[1]);
    if (executionTime[0] < executionTime[1])
    {
        printf("\nThe selection sort took less time to execute than insertion sort");
    }
    else
    {
        printf("\nThe insertion sort took less time to execute than selection sort");

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
    printf("Your array: \n");
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

void fill2Random(int *arr1, int *arr2, int size, int max)
{
    for (int i = 0; i < size; i++)
    {
        arr1[i] = rand() % max;
        arr2[i] = arr1[i];
    }
}