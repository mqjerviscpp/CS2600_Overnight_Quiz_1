#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <time.h>

//Declaring functions
bool isMagicSquare(int arr[3][3]);
void generateMagicSquare(int arr[3][3]);
void printArrayFormat(int arr[], int length);

int main(){
    srand(time(NULL));
    int magicSquare[3][3]= {
        {0,0,0},
        {0,0,0},
        {0,0,0}
    };

    int count = 0;
    do{
        generateMagicSquare(magicSquare);
        count++;
    }
    while(!isMagicSquare(magicSquare));

    //Print out magic square attempts
    printf("Count of Squares Generated and Tested: %d\n", count);
    for(int i = 0; i<3; i++){
        printArrayFormat(magicSquare[i],3);
    }
}

//print out the array format
void printArrayFormat(int array[], int arrayLength){
    printf("[");

    for(int i = 0; i<arrayLength; i++){
        if(i!=(arrayLength-1)){
            printf("%d ", array[i]);
        }
        else{
            printf("%d]\n", array[i]);
        }
    }
}

//generates a magic square, passes through array by refrence
void generateMagicSquare(int array[3][3]){
    int numbers[9];

    for(int i=0; i<9; i++){
        numbers[i] = (i+1);
    }

    int j;
    int temp;
    for(int i=8; i>1; i--){
        //cond: 0<=j<=i
        j= (rand())%(i+1);
        temp = numbers[i];
        numbers[i] = numbers[j];
        numbers[j] = temp;
    }

    //fill up array with shuffled numbers
    int count = 0;
    for(int i=0; i<3; i++){
        for(int j=0; j<3; j++){
            array[i][j] = numbers[count++];
        }
    }
}

//checks to see if magic square is valid
bool isMagicSquare(int array[3][3]){
    int sumSquare;
    int magicNumber=0;

    //locate first row sum, store sum to magic number
    for(int i=0; i<3; i++){
        magicNumber+=array[0][i];
    }

    //check remainder of rows
    for(int i=0; i<3; i++){
        sumSquare=0;
        
        for(int j=0; j<3; j++){
            sumSquare+=array[i][j];
        }

        if(sumSquare!=magicNumber){
            return false;
        }
    }

    //check columns
    for(int i=0; i<3; i++){
        sumSquare=0;
        for(int j=0; j<3; j++){
            sumSquare+=array[j][i];
        }

        if(sumSquare!=magicNumber){
            return false;
        }
    }

    //check \ diagnoses
    sumSquare=0;

    for(int i=0; i<3; i++){
        sumSquare+=array[i][i];
    }

    if(sumSquare!=magicNumber){
        return false;
    }

    //check / diagnoses
    sumSquare=0;
    for(int i=0; i<3; i++){
        sumSquare+=array[i][2-i];
    }
    
    if(sumSquare!=magicNumber){
        return false;
    }

    //iff all checks pass
    return true;
}