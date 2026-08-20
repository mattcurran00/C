#include <stdio.h>
/**
 * so we need an algorithm that will find the two numbers in the array so that they add to the target
 * we cant use the same number twice
 * we can only have one solution
 * 
 * if there is only one solution, then we can first rule out every number thats larger i guess?
 * oh actually maybe we can do something with it being based on whether its even or odd
 * if the target is an odd number, we know that one must be of each
 * maybe in this example we could divide the
 * 
 * what we could do to start is start from each end, and work our way in, after we've sorted. that
 *  could be huge 
 */

typedef struct{

    int value;
    int originalIndex;
}arrayTracking;

//void findIndices(int *nums, int size, int target);

arrayTracking* createNode(int value, int originalIndex, int size);

int main(){

    int nums[20] = {45, 78, 34, 6, 94, 59, 69, 16, 49, 11, 71, 38, 81, 80, 47, 74, 25, 91, 9, 85};
    int target = 78;

    arrayTracking arr[20]; //create array of structs

    for(int i = 0; i < sizeof(nums) / sizeof(nums[0]); i++){
        arr[i].value = nums[i];
        arr[i].originalIndex = i;
    }

    return 0;
}


// arrayTracking* createNode(int value, int originalIndex, int size){

//     arrayTracking *aT = malloc(sizeof(aT));
//     aT->value = value;
//     aT->originalIndex = originalIndex;

//     return aT;
// }


