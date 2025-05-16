/*Write a program that accepts an array of integers. Then,
reverses the array in place using two pointers (one pointing
to the start and the other to the end). Prints the reversed array.*/

#include <stdio.h>

void reverse_array(int arr[], int size)
{

    int *left = arr, *right = arr + size - 1;
    while (left < right)
    {
        int temp = *left;
        *left = *right;
        *right = temp;
        left++;
        right--;
    }
}

void print_array(int arr[], int size)
{
    for (int i = 0; i < size; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}
int main()
{
    int size;
    scanf("%d", &size);
    int arr[size];
    for (int i = 0; i < size; i++)
    {
        scanf("%d", &arr[i]);
    }
    reverse_array(arr, size);
    print_array(arr, size);
    return 0;
}