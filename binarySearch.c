#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>
#include <stdlib.h>

typedef int8_t i8;
typedef int16_t i16;
typedef int32_t i32;
typedef int64_t i64;
typedef uint8_t ui8;
typedef uint16_t ui16;
typedef uint32_t u32;

typedef struct{
    i32 data;
    bool found;
}res;

res* createResultSet(i32 data, bool isFound);
/**
 * pass the array, the start and end? that makes sense to me oh and also the target integer in whcih we want to find 
 * return value as an int though, not sure about that. maybe a struct 
 */
res* recurs(i16 *arr,int size, i16 start, i16 end, i16 target);


int main (){
    
    
    //sample sorted array
    i16 sortedArray[] = {1, 3, 4, 5 ,7, 13, 22, 31, 48, 56};

    //printing the array 
    printf("\nPre sorted array is : ");
    for(int i = 0; i < (sizeof(sortedArray) / sizeof(sortedArray[0])); i++){
        printf("%d, ", sortedArray[i]);
    }
    fflush(stdout);
    printf("\n\nSorting...");
    i16 size = sizeof(sortedArray) / sizeof(sortedArray[0]);
    i16 target = 22;
    res* result = recurs(sortedArray, size, 0, size -1, target );

    if (result->found == true){
        printf("\nFound\n");
    }
    return 0;
}


/**
 * recursively iterate and return the result structure
 */
res* recurs(i16 *inarr,int size, i16 start, i16 end, i16 target){

    i16 mid = (start + end) / 2; //find mid
    while(inarr[mid] != target && start <= end){
        if (target > inarr[mid]){
            start = mid + 1;   
        }
        else{
            end = mid -1;
        }

        mid = (start + end) / 2;
    }

    if(inarr[mid] == target){
        return createResultSet(mid, true);
    }
    return createResultSet(0, false);
}

res* createResultSet(i32 data, bool isFound){
    res *nrs = malloc(sizeof(res));
    nrs->data = data;
    nrs->found = isFound;

    return nrs;
}