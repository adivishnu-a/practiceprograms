#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <windows.h>

FILE* fp;      // Global file pointer
char* buffer;  // Global buffer pointer

// Function to handle the keyboard interrupt
void keyboardInterruptHandler(int signal) {
    printf("Keyboard interrupt received. Exiting...\n");
    // Perform any necessary cleanup or actions before exiting
    // For example, you can close open files, release resources, etc.
    // ...
    // Close any open files
    fclose(fp);
    // Release any allocated resources
    free(buffer);
    // Exit the program
    exit(0);
}

// File pointer and buffer for example purposes
FILE* fp;
char* buffer;

int main() {
    // Register the keyboard interrupt handler
    signal(SIGINT, keyboardInterruptHandler);

    // Open a file for example purposes
    fp = fopen("example.txt", "r");
    if (fp == NULL) {
        printf("Failed to open the file.\n");
        return 1;
    }

    // Allocate a buffer for example purposes
    buffer = (char*)malloc(1024);
    if (buffer == NULL) {
        printf("Failed to allocate memory.\n");
        fclose(fp);
        return 1;
    }

    printf("Press Ctrl+C to trigger the keyboard interrupt.\n");

    // Keep the program running until the interrupt is received
    while (1) {
        // Perform your main program logic here
        // For example, read lines from a file
        if (fgets(buffer, 1024, fp) != NULL) {
            printf("Read line: %s", buffer);
            Sleep(2000);  // Sleep for 2000 milliseconds (2 seconds)
        } else {
            printf("End of file reached.\n");
            break;
        }
    }

    // Close the file
    fclose(fp);
    // Free the allocated buffer
    free(buffer);

    return 0;
}
