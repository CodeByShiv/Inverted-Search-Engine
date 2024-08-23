#include "main.h"

/*
Name: Shivam Kumar O
Date: 05/10/2023
Title: Data Structures Project -> Inverted Search
*/

// Function to read and validate Command Line Arguments (CLA)
Status read_and_validate_cla(Slist **head, int argc, char *argv[])
{
    FILE *file = NULL; // Initialize a file pointer.
    
    // Loop through command line arguments starting from the second argument (argv[1])
    for (int i = 1; i < argc; i++)
    {
        file = fopen(argv[i], "r"); //open the file in read mode.
        
        if (file == NULL)
        {
            printf("Error opening file\n"); // Display an error message if the file cannot be opened.
            return FAILURE;
        }

        // Check if the file has a "txt" extension
        if (strstr(argv[i], "txt") != NULL)
        {
            fseek(file, 0, SEEK_END); // Move the file pointer to the end of the file.
            int size = ftell(file); // Get the size of the file.
            rewind(file); // Rewind the file pointer to the beginning.

            // Check if the file is not empty
            if (size > 0)
            {
                // Insert the filename into a linked list
                if (insert_at_last(head, argv[i]) == SUCCESS)
                {
                    printf("Successful: Inserting filename: %s into the file Linked List\n", argv[i]);
                }
                else if (insert_at_last(head, argv[i]) == DUPLICATE)
                    printf("INFO: %s file is a Duplicate\n", argv[i]);
                else
                    printf("ERROR: Insertion unsuccessful\n");
            }
            else
                printf("INFO: File %s is empty\n", argv[i]);
        }
        else
            printf("Invalid file format\n"); // Display a message for files with an invalid format.
    }
    return SUCCESS; 
}
