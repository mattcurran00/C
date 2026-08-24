#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct{
    int number;
    bool isFound;
}result;

/**
 * struct needed in order to maintain the appropriate index of the array
 */
typedef struct{
    int value;
    int originalIndex;
    int postIndex;
}element;

result resultSet; //just declare the result set globally to avoid all the weird shit with having binary return something. 

void merge(element *left, element *right, int leftlength, int rightlength, element *result);
void mergeSort(element *numbers, int length);
void binarySearch(element *arr, int length, int target);

int main(){
    
    int numbers[] = { 73, 12, 89, 4, 56, 31, 97, 25, 68, 10, 42, 85, 19, 63, 7, 54, 38, 91, 16, 47};
    int numbersLength = sizeof(numbers) / sizeof(numbers[0]);
    element newNumbers[numbersLength];

    //copy original array values and indexes into the structure array fields
    for(int i = 0; i < numbersLength; i++){
        newNumbers[i].value = numbers[i];
        newNumbers[i].originalIndex = i;
    }
    int target;
    printf("Search for a number in an unsorted array\n");
    printf("Target Number: ");
    fflush(stdin);
    scanf("%d", &target);

    mergeSort(newNumbers, numbersLength);

    fflush(stdout);
    printf("\nSORTED TEST: ");
    for(int i = 0; i < numbersLength; i++){
        printf("%d, ", newNumbers[i].value);
    }

    fflush(stdout);
    printf("\nBEGIN BINARY SEARCH...\n");
    binarySearch(newNumbers, numbersLength, target); //using typedef means i dont actually assign the value

    if(resultSet.isFound == true){
        printf("\nBinary Search complete.\nNumber found: TRUE\nIndex: %d", resultSet.number);
    }
    else{
        printf("\nBinary Search complete.\nNumber found: FALSE");
    }

    return 0;
}

void mergeSort(element *inarr, int length){

    if(length <= 1){
        return;
    }

    int mid = length / 2;

    element left[mid];
    element right[length - mid];

    int leftlength = mid;
    int rightlength = length - mid;

    for(int i = 0; i < leftlength; i++){
        left[i] = inarr[i];
    }

    for(int i = 0; i < rightlength; i++){
        right[i] = inarr[mid + i];
    }

    mergeSort(left, leftlength);
    mergeSort(right, rightlength);

    merge(left, right, leftlength, rightlength, inarr);
}

void merge(element *left, element *right, int leftlength,
           int rightlength, element *inarr){

    int leftindex = 0;
    int rightindex = 0;
    int resultindex = 0;

    while(leftindex < leftlength && rightindex < rightlength){

        if(left[leftindex].value >= right[rightindex].value){
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

    while(rightindex < rightlength){
        inarr[resultindex] = right[rightindex];
        resultindex++;
        rightindex++;
    }
}

void binarySearch(element *arr, int length, int target){

    int low = 0;
    int high = length - 1;

    while(low <= high){

        int mid = (low + high) / 2;

        if(arr[mid].value == target){
            resultSet.isFound = true;
            resultSet.number = arr[mid].originalIndex;
            return;
        }

        if(arr[mid].value < target){
            low = mid + 1;
        }
        else{
            high = mid - 1;
        }
    }

    resultSet.isFound = false;
}