#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>

typedef int8_t i8;
typedef int16_t i16;
typedef int32_t i32;
typedef int64_t i64;
typedef uint8_t ui8;
typedef uint16_t ui16;
typedef uint32_t u32;

/**
 * pass the array, the start and end? that makes sense to me oh and also the target integer in whcih we want to find 
 * return value as an int though, not sure about that. maybe a struct 
 */
int recurs(int arr[], int start, int end, int target);

res* createResultSet(i32 data, bool isFound);


typedef struct{
    i32 data;
    bool found;
}res;

int main (){
    
    
    //sample sorted array
    i16 sortedArray[] = {1, 3, 4, 5 ,7, 13, 22, 31, 48, 56};

    printf("\nPre sorted array is : ");
    for(int i = 0; i < (sizeof(sortedArray) / sizeof(sortedArray[0])); i++){
        printf("%d", sortedArray[i]);
    }



    return 0;
}


int recurs(int inarr[], int start, int end, int target){

    int i = (start + end) / 2;
    while(inarr[i] != target){

    }
    return 0;
}

res* createResultSet(i32 data, bool isFound){


}