#include <stdio.h>

int binarySearch(int arr[], int sizeArr, int key);

int main() {
    int arr[] = {1, 2, 3, 4, 5};
    const int sizeArr = 5;
    int key = 7;

    int result = binarySearch(arr, sizeArr, key);

    if(result == 1) {
        printf("We found the key!");
    }
    else {
        printf("Key not found");
    }

    return 0;
}

int binarySearch(int arr[], int sizeArr, int key) {
    int leftIndex = 0;
    int rightIndex = sizeArr - 1;
    int middleIndex = (leftIndex + rightIndex) / 2;

    while(leftIndex <= rightIndex) {

        if(key == arr[middleIndex]) {
            return 1;
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