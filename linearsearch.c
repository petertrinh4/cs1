#include <stdio.h>

int linearsearch(int arr[], int SIZE, int key);

int main() {

    //INITIALIZING USEFUL VARIABLES
    const int SIZE = 6;
    int arr[] = {2, 4, 6, 7, 9, 3};
    int key;

    //ASSIGNS THE RETURNED VALUES FROM LINEARSEARCH FUNCTION TO RESULT VARIABLE
    int result = linearsearch(arr, SIZE, key);

    //PRINT OUT ARRAY
    for(int i = 0; i < SIZE; i++) {
        printf("%d, ", arr[i]);
    }

    if(result == 0) {
        printf("Key value %d found!", key);
    }
    else {
        printf("Key value %d not found", key);
    }

    return 0;
    }

int linearsearch(int arr[], int SIZE, int key) {

    for(int i = 0; i < SIZE; i++) {
        scanf("%d", &key);
        if(arr[i] == key) {
            return 0;
        }
        else {
            return 1;
        }   
    }
    return -1;
}
