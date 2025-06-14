
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

typedef struct { //STUDENT STRUCTURE
    int ID;
    char firstName[20];
    char lastName[20];
    float GPA;
}Student;

int searchStudentID(Student student_Arr[], int lengthArray, int searchValue);

int main() {
    char fileName[30];
    FILE *file; //DECLARING VARIABLES
    Student student_Arr[100];
    int index = 0;
    int searchOrQuit;
    int searchResult;

    printf("Enter the file name to process: "); //ASK USER TO ENTER FILE NAME
    scanf("%s", fileName);
    file = fopen(fileName, "r"); //OPENS FILE

    while(fscanf(file, "%d %s %s %f",
                &student_Arr[index].ID, //SCANS THROUGH FILE & ASSIGNS DATA MEMBERS TO STRUCTURE ARRAY
                 student_Arr[index].firstName,
                 student_Arr[index].lastName,
                &student_Arr[index].GPA) == 4) {
    
        if(index > 0 && student_Arr[index].ID <= student_Arr[index - 1].ID) { //CHECKS FOR INCREASING ID ORDER IN DATA
            printf("Invalid file, student record ID's must be in increasing order.");
            fclose(file);
            return 1;
        }
        index++;
        if(index >= 100) break; //COUNTS NUMBER OF STUDENTS
    }
        while(1) { //SEARCHING STUDENT
            printf("Enter a student ID to search or -1 to quit: ");
            scanf("%d", &searchOrQuit);

            if(searchOrQuit == -1) break;
            searchResult = searchStudentID(student_Arr, index, searchOrQuit);
            if(searchResult != -1) {
                printf("%d, %s %s, GPA: %.1f\n", student_Arr[searchResult].ID, 
                                                   student_Arr[searchResult].firstName, 
                                                   student_Arr[searchResult].lastName, 
                                                   student_Arr[searchResult].GPA);
            }
            else {printf("This ID is not in the records.\n");}
        }
    return 0;
}

int searchStudentID(Student student_Arr[], int lengthArray, int searchValue) {
    int low = 0, high = lengthArray - 1;

    while(low <= high) {
        int middle = low + (high - low) / 2;

        if(searchValue == student_Arr[middle].ID) {return middle;}
        else if(searchValue < student_Arr[middle].ID) {high = middle - 1;}
        else {low = middle + 1;}
    }
    return -1;
}