#include <stdio.h>

int linearSearch(int arr[], int SIZE, int key);

int main() {
    int sizeArr = 6, arr[] = {2, 4, 6, 7, 9, 3}, key = 2, result = linearSearch(arr, sizeArr, key); //Declaring variables

    for(int i = 0; i < sizeArr; i++) { //Printing out array
        printf("%d ", arr[i]);
    }
    if(result >= 0 && result <= sizeArr - 1) { //Comparing returned values from linearSearch function
        printf("\nKey value %d found at index %d!", key, result);
    }
    else {
        printf("\nKey value %d not found", key);
    }
    return 0;
    }

int linearSearch(int arr[], int sizeArr, int key) {
    for(int i = 0; i < sizeArr; i++) { //Compares each element in the array to the key value inputted from main function
        if(arr[i] == key) {
            return i; //Returns the index of the key value
        }
        else { //If key value != to the element at index i, continue iterating through the array
            continue;
        }   
    }
    return -1;
}
