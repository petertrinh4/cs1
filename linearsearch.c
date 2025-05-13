#include <stdio.h>

int main() {

    //INITIALIZING USEFUL VARIABLES
    int n;
    int SIZE = (int)malloc(n * sizeof(int));
    int arr[SIZE];
    int key;
    int number;

    //DYNAMIC ARRAY SIZING
    printf("Enter number of elements in array: ");
    scanf("%d", &n);

    //ADDS NUMBERS TO ARRAY
    printf("Enter integer elements in array:" );
    for(int i = 0; i < SIZE; i++) {
        scanf("%d", arr[i]);
    }

    //ASSIGNS THE RETURNED VALUES FROM LINEARSEARCH FUNCTION TO RESULT VARIABLE
    int result[] = linearsearch(arr[SIZE], SIZE, key);

    //PRINT OUT ARRAY
    for(int i = 0; i < SIZE; i++) {
        printf("%d, ", number);
    }

    if(linearsearch == 0) {
        printf("Key value %d found!", key);
    }
    else {
        printf("Key value %d not found", key);
    }

    return 0;
    }

int linearsearch(int arr[], int SIZE, int key) {
int arr[SIZE];
int key;

for(int i = 0; i < SIZE; i++) {
scanf("%d", &key);
if(arr[i] == key) {
    return 0;
}
else {
    return 1;
}
}
}
