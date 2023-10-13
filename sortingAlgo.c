#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

void fillRandom(int *arr, int size, int max);
void printOriginalArray(int arr, int size);
void printSortedArray(int arr, int size);
bool isSorted();
void swap();
void selectionSort();
void insertionSort();
void bubbleSort();

int main()
{
    int SIZE;

    printf("Enter array size: ");
    scanf("%d", &SIZE);

    int MAX = 1000000;
    int A[SIZE];

    fillRandom(A, SIZE, MAX);

    printf("\nThe array has been randomly filled with integer numbers between 0 and 1 000 000.\nChoose which sort algorithm to apply to the array: \n-Press 0 for Selection Sort\n-Press 1 for Insertion Sort\n-Press 2 for Bubble Sort\n");
    int choice;
    scanf("%d", &choice);

    switch (choice)
    {
    case 0:
        selectionSort();
        break;
    case 1:
        insertionSort();
        break;
    case 2:
        bubbleSort();
    default:
        printf("The option you chose is not available.");
        
    }


}

void fillRandom(int *arr, int size, int max)
{
    for (int i = 0; i < size; i++)
    {
        arr[i] = rand() % max;
    }
}

void printOriginalArray(int arr, int size) {
    printf("The original array: \n");
    for (int i = 0; i < size; i++)
    {
        printf("%d \t", arr[i]);
    }
    
}

void printSortedArray(int arr, int size) {
    printf("\nThe sorted array: \n");
    for (int i = 0; i < size; i++)
    {
        printf("%d \t", arr[i]);
    }
    
}

