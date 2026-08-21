#include <stdio.h>



void merge(int *left, int leftsize, int *right, int rightsize, int *result, int length);
void mergeSort(int *numbers, int length);

int main(){

    int numbers[] = {45, 78, 34, 6, 94, 59, 69, 16, 49, 11, 71, 38, 81, 80, 47, 74, 25, 91, 9, 85};

    int length = sizeof(numbers) / sizeof(numbers[0]);
    mergeSort(numbers, length);

     fflush(stdout);
    printf("\nSorting Finished. Sorted array is: ");
    for(int i = 0; i < length; i++){
        printf("%d, ", numbers[i]);
    }
    return 0;
}

void merge(int *left,int leftsize, int *right, int rightsize, int *result, int length){
    
    int leftIndex = 0;
    int rightIndex = 0;
    int resultIndex = 0; 

    while(leftIndex < leftsize && rightIndex < rightsize){
        if(left[leftIndex] <= right[rightIndex]){
            result[resultIndex] = left[leftIndex];
            leftIndex++;
        }
        else{
            if(left[leftIndex] >= right[rightIndex]){
                result[resultIndex] = right[rightIndex];
                rightIndex++;
            }
        }
        resultIndex++;
    }

    while(leftIndex < leftsize){
        result[resultIndex] = left[leftIndex];
        resultIndex++;
        leftIndex++;
    }
    while(rightIndex < rightsize){
        result[resultIndex] = right[rightIndex];
        resultIndex++;
        rightIndex++;
    }
}

void mergeSort(int *numbers, int length){

    if(length <= 1){ //base case to stop the infinite loop 
        return;
    }
    int mid = length / 2;

    int leftlength = mid;
    int rightlength = length - mid;
    printf("\nMid = %d \n", mid);

   //temparrays 
   int left[leftlength];
   int right[rightlength];

    for (int i = 0; i < mid; i++){
        left[i] = numbers[i];
    }

    for(int i = 0; i < rightlength; i++){
        right[i] = numbers[mid + i];
    }

    for (int i = 0; i < mid; i++){
        fflush(stdout);
        printf("\nLeft half is: %d", left[i]);
    }
    for (int i = 0; i < rightlength; i++){
        fflush(stdout);
        printf("\nRight half is: %d", right[i]);
    }

    mergeSort(left, leftlength);
    mergeSort(right, rightlength);

    merge(left, leftlength, right, rightlength, numbers, length);
}