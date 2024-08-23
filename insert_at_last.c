#include "main.h"

/*
Name: Shivam Kumar O
Date: 05/10/2023
Title: Data Structures Project -> Inverted Search
*/

// Function to insert a new node at the end of a linked list
Status insert_at_last(Slist **head, char *data)
{
    Slist *new = malloc(sizeof(Slist)); // Allocate memory for a new linked list node.

    if (new == NULL)
        return FAILURE; // Return FAILURE if memory allocation for the new node fails.

    new->file_name = strdup(data); // Duplicate and store the data (file name) in the new node.

    if (new->file_name == NULL)
    {
        free(new); // Free the allocated node if strdup fails 
        return FAILURE; 
    }

    new->link = NULL; 

    if (*head == NULL) // Check if the linked list is empty.
    {
        *head = new; // Set the new node as the head if the list is empty.
        return SUCCESS; 
    }

    Slist *temp = *head; 

    while (temp->link != NULL) // Traverse the linked list until the last node is reached.
    {
        if (strcmp(temp->file_name, data) == 0)
        {
            free(new->file_name); // Free the allocated file name.
            free(new); // Free the allocated node.
            return DUPLICATE; // Return DUPLICATE if the file name already exists in the list.
        }

        temp = temp->link; // Move to the next node.
    }

    if (strcmp(temp->file_name, data) == 0)
    {
        free(new->file_name); // Free the allocated file name.
        free(new); // Free the allocated node.
        return DUPLICATE; // Return DUPLICATE if the file name already exists in the list.
    }

    temp->link = new; // Insert the new node at the end of the linked list.
    return SUCCESS; 
}
