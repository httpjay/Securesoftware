#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LENGTH 100
#define MAX_ENTRIES 1000  // Memory limit

// Structure for linked list node
typedef struct namelist_s {
    char name[MAX_LENGTH];
    struct namelist_s* next;
} *namelist_t;

int main() {
    namelist_t names = NULL, temp;
    char new_name[MAX_LENGTH];
    int count = 0;

    printf("\n=== Enter names (type 'quit' to stop) ===\n");

    // Compliant Code: Restrict memory allocation
    while (count < MAX_ENTRIES) {
        printf("Enter name: ");
        if (!fgets(new_name, MAX_LENGTH, stdin)) break;

        new_name[strcspn(new_name, "\n")] = '\0'; // Remove newline

        if (strcmp(new_name, "quit") == 0) break;

        // Allocate memory for a new name entry
        namelist_t new_entry = (namelist_t)malloc(sizeof(struct namelist_s));
        if (new_entry == NULL) {
            fprintf(stderr, "Memory allocation failed! Exiting safely.\n");
            break;
        }

        strcpy(new_entry->name, new_name);
        new_entry->next = names;
        names = new_entry;
        count++;
    }

    printf("\n=== Stored Names ===\n");
    temp = names;
    while (temp) {
        printf("%s\n", temp->name);
        temp = temp->next;
    }

    // Free allocated memory
    while (names) {
        temp = names;
        names = names->next;
        free(temp);
    }

    printf("\nProgram exited safely.\n");
    return 0;
}
