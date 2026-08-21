#include <stdio.h>

void merge(int *left, int *right, int leftlength, int rightlength, int *result);
void mergeSort(int *numbers, int length);
void recursiveBinary();

void binarySearch();

int main(){

    int numbers[] = { 73, 12, 89, 4, 56, 31, 97, 25, 68, 10, 42, 85, 19, 63, 7, 54, 38, 91, 16, 47};
    int numbersLength = sizeof(numbers) / sizeof(numbers[0]);
    int target;
    printf("Search for a number in an unsorted array\n");
    printf("Target Number: ");
    fflush(stdin);
    scanf("%d", &target);

    mergeSort(numbers, numbersLength);


    return 0;
}

void mergeSort(int *inarr, int length){

    if(length <= 1){
        return;
    }
}