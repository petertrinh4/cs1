#include <stdio.h>

int linearsearch(int arr[], int SIZE, int key);

int main() {
    int sizeArr = 6, arr[] = {2, 4, 6, 7, 9, 3}, key = 2, result = linearsearch(arr, sizeArr, key);

    for(int i = 0; i < sizeArr; i++) {
        printf("%d ", arr[i]);
    }

    if(result >= 0 && result <= sizeArr - 1) {
        printf("\nKey value %d found at index %d!", key, result);
    }
    else {
        printf("\nKey value %d not found", key);
    }
    
    return 0;
    }

int linearsearch(int arr[], int sizeArr, int key) {
    for(int i = 0; i < sizeArr; i++) {
        if(arr[i] == key) {
            return i;
        }
        else {
            continue;
        }   
    }
    return -1;
}
