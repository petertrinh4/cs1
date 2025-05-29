#include <stdio.h>
#include <stdlib.h>

int searchID(int ID[], int targetID, int arrayLength);

int main() {
    char fileName[30];
    FILE *input;
    int targetID;

    int ID[100];
    char **fNarr = (char **)malloc(100 * sizeof(char *));
    char **lNarr = (char **)malloc(100 * sizeof(char *));
    float GPA[100];

    input = fopen("students.txt", "r");

    printf("Enter the file name to process: "); //Asks user for file name to process
    scanf("%s", fileName); //Scans file name from user

    while (fscanf(input, "%d %s %s %.1lf", &ID, fNarr, lNarr, &GPA) != EOF) { //Reads file then assigns the values to respective variables
        for (int index = 0; index < ID; index++) {
            if (ID[index] > ID[index + 1]) {
                printf("Invalid File, ID's aren't sorted in increasing order.");
                break;
            }
            else {
                printf("Enter a student ID to search or -1 to quit: ");
                scanf("%d", targetID);

                if (targetID != -1) {
                int searchResult = searchID(ID, targetID, 100); //FIXME: WRONG LENGTH?
                    if (searchResult == 1) { 
                        printf("[%d, %s, %s, %.1lf]", ID, fNarr, lNarr, GPA); //FIXME: WRONG VARIABLES
                    }
                    else {
                        printf("This ID is not in the records.");
                    }
                }
                else break;
            }
        }
    }
    return 0;
}

int searchID(int ID[], int targetID, int arrayLength) {
    int lowIndex = 0, highIndex = arrayLength - 1;

    while(lowIndex <= highIndex) {
        int middleIndex = lowIndex + (highIndex - lowIndex) / 2;
        
        if(targetID == ID[middleIndex]) {return targetID;} //FIXME: RETURN WHAT?

        else if(targetID > ID[middleIndex]) {lowIndex = middleIndex + 1;}
        
        else {highIndex = middleIndex - 1;}
    }

    return -1;
}