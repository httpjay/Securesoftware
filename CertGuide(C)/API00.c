#include <stdio.h>
#include <errno.h> // For error codes

static FILE *myFile = NULL; // Internal file pointer (initialized to NULL)

/*
======================================================================
🔴 Noncompliant Code (Commented Out) - No Validation, Unsafe Behavior
======================================================================

void setfile(FILE *file) {
    myFile = file; // No validation! Allows invalid file pointers.
}

void usefile(void) {
    if (myFile) {
        fprintf(myFile, "Writing to file...\n"); // Undefined behavior if myFile is invalid
    }
}
*/

// ======================================================================
// 🟢 Compliant Code - Proper Validation and Error Handling
// ======================================================================

// Function to set the file pointer safely
errno_t setfile(FILE *file) {
    if (file == NULL || ferror(file) || feof(file)) {
        return EINVAL; // Return error if the file is invalid
    }

    myFile = file;
    return 0; // Success
}

// Function to use the file safely
errno_t usefile(void) {
    if (!myFile) {
        return EINVAL; // Return error if no valid file is set
    }

    fprintf(myFile, "Writing to file safely...\n");
    return 0;
}

// ======================================================================
// 🏃 Main Function - Demonstrates Both Versions
// ======================================================================
int main() {
    FILE *fp = fopen("output.txt", "w");
    
    if (!fp) {
        printf("Error: Could not open file\n");
        return 1;
    }

    // Using the compliant version
    if (setfile(fp) != 0) {
        printf("Error: Invalid file pointer\n");
        return 1;
    }

    if (usefile() != 0) {
        printf("Error: Could not use file\n");
    } else {
        printf("File written successfully.\n");
    }

    fclose(fp);
    return 0;
}
