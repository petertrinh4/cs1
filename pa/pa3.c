#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME_LEN 100

typedef struct hub {
    char name[MAX_NAME_LEN]; // city or location name
    int distance; // Distance from previous hub
    int hour; // simplified timestamp (0-23)
    struct hub* next;
}Hub;

void insert_at_tail(Hub** head, const char* name, int distance, int hour);
void print_chain(Hub* head);
int is_empty(struct hub* head);
Hub search_hub(Hub* head, const char* keyword);
void insert_at_head(Hub** head, const char* name, int distance, int hour);
void remove_first_match(Hub** head, const char* keyword);
void print_chain_reverse(Hub* head);
int total_distance(Hub* head);
void deleteList(Hub *head);

int main() {
    printf("=== ParcelTrack Delivery Chain Test ===\n\n");
    Hub* chain = NULL;
    // Test insert_at_head and insert_at_tail
    insert_at_head(&chain, "Orlando", 0, 9);
    insert_at_tail(&chain, "Atlanta", 400, 14);
    insert_at_tail(&chain, "Charlotte", 350, 17);
    printf("Delivery chain:\n");
    print_chain(chain);
    printf("\n");
    // Test total_distance
    int total = total_distance(chain);
    printf("Total distance: %d km\n\n", total);
    // Test display_bottleneck
    // Uncomment the line below if bonus attempted
    // display_bottleneck(chain);
    // Test search_hub
    Hub found = search_hub(chain, "lanta");
    if (strcmp(found.name,"None")) {
    printf("Search result: Found ");
    printf("\"{%s, %d, %d}\"\n\n", found.name, found.distance,
    found.hour);
    } else
    printf("Search result: No match found\n\n");
    // Test print_chain_reverse
    printf("Reverse delivery chain:\n");
    print_chain_reverse(chain);
    printf("\n");
    // Test remove_first_match
    remove_first_match(&chain, "lanta");
    printf("After removing first match for \"lanta\":\n");
    print_chain(chain);
    printf("\n");
    deleteList(chain);
    chain = NULL;
    return 0;
}

int is_empty(struct hub* head) {
    if(head == NULL) { //Checks for an empty linked list
        return 1;
    }
    else {
        return 0;
    }
}

void insert_at_head(Hub** head, const char* name, int distance, int hour) {
    Hub* newNode = (Hub*)malloc(sizeof(Hub));
    strcpy(newNode->name, name); // Assigning values to data members
    newNode->distance = distance;
    newNode->hour = hour;
    newNode->next= *head; // Updating pointers
    *head = newNode;
}

void insert_at_tail(Hub** head, const char* name, int distance, int hour) {
    Hub* currPtr = *head;

    if(*head == NULL) { //If no linkedlist, then we insert at the head
        insert_at_head(head, name, distance, hour);
        return;
    }

    if(currPtr->next == NULL) { //Inserts at tail
        Hub* newNode = (Hub*)malloc(sizeof(Hub));
        strcpy(newNode->name, name);
        newNode->distance = distance;
        newNode->hour = hour;
        newNode->next = NULL;
        currPtr->next = newNode;
        return;
    }
        insert_at_tail(&currPtr->next, name, distance, hour);
}

void print_chain(Hub* head) {
    Hub* curr = head;
    while(curr->next != NULL) { //Prints each node every iteration
        printf("[%s] - [%d]km, [%d]hours\n", curr->name, curr->distance, curr->hour);
        curr = curr->next;
    }
        printf("[%s] - [%d]km, [%d]hours\n", curr->name, curr->distance, curr->hour);
}

Hub search_hub(Hub* head, const char* keyword) {
    Hub *curr = head;

    while(curr != NULL) { //Checks if each node contains the keyword
        if(strstr(curr->name, keyword)) {
            return *curr;
        }
        curr = curr->next;
    }
        Hub dummyNode;
        strcpy(dummyNode.name, "None");
        dummyNode.distance = -1;
        dummyNode.hour = -1;
        dummyNode.next = NULL;
        return dummyNode; //Returning a dummy hub since no hub was found
}

void remove_first_match(Hub** head, const char* keyword) {
    if(!head || !(*head)) return; //Returns if the linked list doesn't exist

    Hub* curr = *head; //Sets current pointer pointing to the head node
    Hub* prev = NULL;

    while(curr != NULL) {
        if(strstr(curr->name, keyword)) { //Searches for keyword in curr->name
            if(prev == NULL) {
                *head = curr->next;
            }
            else {
                prev->next = curr->next;
            }
            free(curr);
            return;
        }
        prev = curr;
        curr = curr->next;
    }
}

//LOGISTICS-ORIENTED FUNCTIONS BELOW

int total_distance(Hub* head) { //Calculates the total distance
    Hub* currPtr = head;
    int total_dist = 0;

    while(currPtr != NULL) {
        total_dist = total_dist + currPtr->distance;
        currPtr = currPtr->next;
    }
    return total_dist;
}

void print_chain_reverse(Hub* head) { //Prints the chain in reverse starting from the tail
    Hub* curr = head;

    if(curr == NULL) return;

    print_chain_reverse(curr->next);
    printf("[%s] - [%d]km, [%d]hours\n", curr->name, curr->distance, curr->hour);
}

/*void display_bottleneck(Hub* head) { //BONUS FUNCTION

}*/

void deleteList(Hub *head) {
    Hub* temp;
    while(head != NULL) {
        temp = head;
        head = head->next;
        free(temp);
    }
}