#include <stdio.h>



int merge();
void mergeSort(int *numbers, int length);

int main(){

    int numbers[] = {45, 78, 34, 6, 94, 59, 69, 16, 49, 11, 71, 38, 81, 80, 47, 74, 25, 91, 9, 85};

    int length = sizeof(numbers) / sizeof(numbers[0]);
    mergeSort(numbers, length);
    return 0;
}

int merge(){
    return 0;

}

void mergeSort(int *numbers, int length){

    if(length <= 1){
        return;
    }
    int mid = length / 2;
    printf("\nMid = %d \n", mid);

    int temp[mid];
    int tlength = sizeof(temp) / sizeof(temp[0]);

    for (int i = 0; i < mid; i++){
        temp[i] = numbers[i];
    }

    for (int i = 0; i < mid; i++){
        fflush(stdout);
        printf("\nLeft half is: %d", temp[i]);
    }

    mergeSort(temp, tlength);
}