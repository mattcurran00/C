#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <stdbool.h>
#include <string.h>

typedef int8_t i8;
typedef int16_t i16;
typedef int32_t i32;
typedef int64_t i64;
typedef uint8_t ui8;
typedef uint16_t ui16;
typedef uint32_t u32;

typedef struct{
    i32 data;
    node* next;

}node;

node* createNode(i32 data);

bool isEmpty(int c, char *string[]);

int main(i16 argc, char *argv[]){

    i32 data = 1; //porting cba
    node* newNode = createNode(data);
    return 0;
}

bool isEmpty( int c, char *argL[]){

   
    if((*argL[0] != NULL)){
        return true;
    }
    return false;    
}