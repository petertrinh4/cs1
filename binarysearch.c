#include <stdio.h>

int binarySearch(int arr[], int sizeArr, int key);

int main() {
    int arr[] = {1, 2, 3, 4, 5}, sizeArr = 5, key = 5, result = binarySearch(arr, sizeArr, key);

    for(int i = 0; i < sizeArr; i++) {
        printf("%d ", arr[i]);
    }

    if(result && result >= 0 && result <= 4) {
        printf("\nFound key value %d at index %d!", key, result);
    }
    else {
        printf("\nKey not found");
    }

    return 0;
}

int binarySearch(int arr[], int sizeArr, int key) {
    int leftIndex = 0, rightIndex = sizeArr - 1, middleIndex = (leftIndex + rightIndex) / 2;

    while(leftIndex <= rightIndex) {
        if(key == arr[middleIndex]) {
            return middleIndex;
        }
        else if(key < arr[middleIndex]) {
            rightIndex = middleIndex - 1;
        }
        else if(key > arr[middleIndex]) {
            leftIndex = middleIndex + 1;
        }
        middleIndex = (leftIndex + rightIndex) / 2;
    }

    return -1;
}