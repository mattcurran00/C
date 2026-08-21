#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct{
    int number;
    bool isFound;
}result;

void merge(int *left, int *right, int leftlength, int rightlength, int *result);
void mergeSort(int *numbers, int length);
void recursiveBinary();
result* createResultSet(int data, bool isFound);


result* binarySearch(int *arr, int length, int target);

int main(){

    int numbers[] = { 73, 12, 89, 4, 56, 31, 97, 25, 68, 10, 42, 85, 19, 63, 7, 54, 38, 91, 16, 47};
    int numbersLength = sizeof(numbers) / sizeof(numbers[0]);
    int target;
    printf("Search for a number in an unsorted array\n");
    printf("Target Number: ");
    fflush(stdin);
    scanf("%d", &target);

    mergeSort(numbers, numbersLength);

    fflush(stdout);
    printf("\nSORTED TEST: ");
    for(int i = 0; i < numbersLength; i++){
        printf("%d, ", numbers[i]);
    }

    binarySearch(numbers, numbersLength, target); //using typedef means i dont actually assign the value

    return 0;
}

void mergeSort(int *inarr, int length){

    if(length <= 1){
        return;
    }
    int mid = length / 2;
    int left[mid];
    int right[length - mid];
    int leftlength = sizeof(left) / sizeof(left[0]);
    int rightlength = sizeof(right) / sizeof(right[0]);

    for(int i = 0; i < mid; i++){
        left[i] = inarr[i];
    }
    for(int i = mid; i < length; i++){
        right[i - mid] = inarr[i];
    }

    mergeSort(left, leftlength);
    mergeSort(right, rightlength);

    merge(left, right, leftlength, rightlength, inarr);
}

void merge(int *left, int *right, int leftlength, int rightlenght, int *inarr){

    int leftindex = 0;
    int rightindex = 0;
    int resultindex = 0;

    while(leftindex < leftlength && rightindex < rightlenght){
        if(left[leftindex] >= right[rightindex]){
            inarr[resultindex] = right[rightindex];
            rightindex++;
        }
        else{
            inarr[resultindex] = left[leftindex];
            leftindex++; 
        }
        resultindex++;
    }
    while(leftindex < leftlength){
        inarr[resultindex] = left[leftindex];
        resultindex++;
        leftindex++;
    }
    while(rightindex < rightlenght){
        inarr[resultindex] = right[rightindex];
        resultindex++;
        rightindex++;
    }
}

/**
 * so we've gotten a decent bit here, just eed to take another look at the splitting 
 * logic in order to split the arrays right, and also test the merge sort
 * although i do think its fine. What I noticed is that it will probably be more common to be 
 * asked to maintain/return the ORIGINAL index of the number being searched, pre-sort
 * use the other file in here to use an array of structs instead and easily do it that way
 */
result* createResultSet(int data, bool isFound){

    result *newResultSet = malloc(sizeof(result));
    newResultSet->number = data;
    newResultSet->isFound = isFound;

    return newResultSet;
}

result* binarySearch(int *arr, int length, int target){
    int mid = length / 2;
    
    if(arr[mid] == target){
        return createResultSet(arr[mid], true); //create result set for being found
    }

    if(target < arr[mid]){

    }
}