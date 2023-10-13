#include <stdio.h>
#include <stdlib.h>

void fillRandom(int *arr, int size, int max);

int main()
{
    int SIZE;
    printf("Enter array size: ");
    scanf("%d", &SIZE);
    int MAX = 1000000;
    int A[SIZE];

    fillRandom(A, SIZE, MAX);
}

void fillRandom(int *arr, int size, int max)
{
    for (int i = 0; i < size; i++)
    {
        arr[i] = rand() % max;
    }
}
