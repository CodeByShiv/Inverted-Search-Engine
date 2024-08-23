#include "main.h"

/*
Name : Shivam Kumar O
Date : 05/10/2023
Title : Data Structures Project -> Inverted Search
*/

Status save_database(Mainnode **hashtable, char *new_filename) {
    // Open a new file for writing the database
    FILE *fptr = fopen(new_filename, "w");

    // Check if the filename has the ".txt" extension
    if (strstr(new_filename, "txt") != NULL) {
        // Loop through the array of main nodes (index 0-26)
        for (int index = 0; index < 27; index++) {
            if (hashtable[index] != NULL) {
                Mainnode *mainNode = hashtable[index];

                // Traverse the linked list of main nodes
                while (mainNode != NULL) {
                    // Write the index, word, and file count to the file
                    fprintf(fptr, "#%d;", index);
                    fprintf(fptr, "%s;%d;", mainNode->word, mainNode->filecount);
                    Subnode *subNode = mainNode->subnode_link;

                    // Traverse the linked list of subnodes (file details)
                    while (subNode != NULL) {
                        // Write the file name and word count for each file
                        fprintf(fptr, "%s;%d;", subNode->sfilename, subNode->wordcount);
                        subNode = subNode->sublink;
                    }
                    // End of main node entry
                    fputs("#\n", fptr);
                    mainNode = mainNode->mainlink;
                }
            }
        }
    } else {
        printf("-----------Incompatible Filename-----------\n");
        return FAILURE; // The filename does not have a .txt extension
    }
    fclose(fptr); // Close the file
    return SUCCESS;
}