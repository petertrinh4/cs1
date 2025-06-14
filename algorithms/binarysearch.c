#include <stdio.h>

int binarySearch(int arr[], int sizeArr, int key);

int main() {
    int arr[] = {1, 2, 3, 4, 5}, sizeArr = 5, key = 5, result = binarySearch(arr, sizeArr, key); //Declaring variables

    for(int i = 0; i < sizeArr; i++) { //Prints out array
        printf("%d ", arr[i]);
    }
    if(result && result >= 0 && result <= 4) { //Compares the returned value from binarySearch
        printf("\nFound key value %d at index %d!", key, result);
    }
    else {
        printf("\nKey not found");
    }
    return 0;
}

int binarySearch(int arr[], int sizeArr, int key) {
    int leftIndex = 0, rightIndex = sizeArr - 1, middleIndex = (leftIndex + rightIndex) / 2; //Setting up the left/right/middle index on the array

    while(leftIndex <= rightIndex) { //When leftIndex is = rightIndex, the middleIndex is also = so we either find/not find the keyvalue
        if(key == arr[middleIndex]) {
            return middleIndex;
        }
        else if(key < arr[middleIndex]) { //Shifting the rightIndex to where middleIndex was - 1, this narrows the search space in half
            rightIndex = middleIndex - 1;
        }
        else if(key > arr[middleIndex]) {
            leftIndex = middleIndex + 1;
        }
        middleIndex = (leftIndex + rightIndex) / 2; //After the comparisions, we have to account for the new search space, so we find the new middleIndex
    }
    return -1;
}