#include <stdio.h>
#include <stdlib.h>

    char* str_copy(const char* src);
    char* str_concat(const char* s1, const char* s2);
    int str_length(const char* s);
    int str_compare(const char* s1, const char* s2);
    void str_free(char* s);

int main() {
    printf("=== Custom String Library Test ===\n\n");
    // Test str_copy
    const char* original = "Hello, world!";
    char* copy = str_copy(original);
    printf("Original: %s\nCopy: %s\n\n", original, copy);
    // Test str_concat
    const char* part1 = "Dynamic ";
    const char* part2 = "Memory!";
    char* combined = str_concat(part1, part2);
    printf("Concatenation:\n\"%s\" + \"%s\" = \"%s\"\n\n", part1, part2,
    combined);
    // Test str_length
    int len = str_length(original);
    printf("Length of \"%s\" = %d\n\n", original, len);
    // Test str_compare
    const char* cmp1 = "apple";
    const char* cmp2 = "banana";
    int cmp_result = str_compare(cmp1, cmp2);
    printf("Compare \"%s\" vs \"%s\" = %d\n\n", cmp1, cmp2, cmp_result);
    // Free allocated memory
    str_free(copy);
    str_free(combined);
    printf("All tests completed. If no memory leaks occurred, you're good!\n");
    return 0;
}

char* str_copy(const char* src) {
    if(src == NULL) {
        printf("Error: src is NULL\n");
        return NULL;
    }
    int n = 0; //Initializing n to 0

    while(src[n] != '\0') { //Counting number of chars in src string
        n++;
    }

    char* dest_str = (char*)malloc(n + 1); //Allocating memory for number of chars in string + 1 for null terminator
    if(dest_str == NULL) {
        printf("Error: Memory Allocation Failed\n");
        return NULL;
    }

    for(int i = 0; i < n; i++) { //Assigning the chars from src to the destination string
        dest_str[i] = src[i];
    }

    dest_str[n] = '\0'; //Appending null terminator to end the string
    return dest_str; //Returns string back to main function
}

char* str_concat(const char* s1, const char* s2) {
    if(s1 == NULL || s2 == NULL) {
        printf("Error: s1 or s2 is NULL\n");
        return NULL;
    }

    int n = 0, q = 0; //Setting n and q to zero for readability

    while(s1[n] != '\0') n++; //Counting number of characters in s1 and s2
    while(s2[q] != '\0') q++;

    char* final_str = (char*)malloc(n + q + 1); //Allocates memory enough for both n and q combined plus 1 for the null terminator
    if(final_str == NULL) {
        printf("Error: Memory Allocation Failed\n");
        return NULL;
    }

    for(int i = 0; i < n; i++) { //Assigning the characters from s1 to the final string
        final_str[i] = s1[i];
    }
    for (int j = 0; j < q; j++) { //Assigning the characters from s2 to the final string
        final_str[n + j] = s2[j];
    }

    final_str[n + q] = '\0'; //Assigning the null terminator at the end of the string
    return final_str;
}

int str_length(const char* s) {
    if(s == NULL) {
        printf("Error: NULL pointer\n");
        return -1;
    }

    int length = 0; //Setting length to zero

    while(s[length] != '\0') { //Counts the length by incrementing the length count by one every character read
        length++;
    }

    return length;
}

int str_compare(const char* s1, const char* s2) {
    if(s1 == NULL || s2 == NULL) {
        printf("Error: s1 or s2 is NULL\n");
        return -1;
    }
    int i = 0;

    while(s1[i] != '\0' && s2[i] != '\0') { //Iterating through both strings to compare each letter until we hit the null terminator
        if(s1[i] > s2[i]) return 1; //If the letter at s1 is greater than the letter at s2, we return 1
        else if(s1[i] < s2[i]) return -1; //Unless the letter of s1 at index i is less than s2, return -1
        i++; //Increment i to iterate through the char array
    }

    if(s1[i] == '\0' && s2[i] == '\0') return 0; //If we successfully read through both s1 and s2 and the letters are all the same, return 0
    else if(s1[i] == '\0') return -1; //If we read that s1 reaches the null terminator before s2, we return -1 because s1 is shorter than s2

    return 1; //Otherwise, s1 is longer than s2, therefore return 1
}

void str_free(char* s) {
    free(s); //Frees the memory of the character array s
}
