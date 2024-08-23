#include "main.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

Status update_database(Mainnode **hashtable, char *fileName)
{
    FILE *fptr = fopen(fileName, "r"); // Open the backup file for reading.
    if (fptr == NULL)
    {
        printf("ERROR opening file\n");
        return FAILURE;
    }

    fseek(fptr, 0, SEEK_END); // Move the file pointer to the end to calculate its size.
    int size = ftell(fptr); // Get the file size in bytes.
    rewind(fptr); // Rewind the file pointer to the beginning.
    
    if (size == 0)
    {
        printf("File %s is empty\n", fileName);
        return FAILURE; // Return FAILURE if the file is empty.
    }

    char str[100];
    int index;

    while (fscanf(fptr, "%s", str) > 0) // Read words from the file.
    {
        if (str[0] == '#')
        {
            index = atoi(strtok(&str[1], ";")); // Extract the index 
            
            Mainnode *newMainNode = malloc(sizeof(Mainnode)); // Allocate memory for a new Mainnode.
            if (newMainNode == NULL)
            {
                printf("Mainnode creation failed\n");
                return FAILURE; 
            }
            
            char *word = strtok(NULL, ";"); // Extract the word.
            strcpy(newMainNode->word, word); // Copy the word to the Mainnode.
            int fcount = (atoi(strtok(NULL, ";"))); // Extract the file count.
            newMainNode->filecount = fcount; // Store the file count in the Mainnode.
            newMainNode->subnode_link = NULL; 
            newMainNode->mainlink = NULL; 

            for (int i = 0; i < newMainNode->filecount; i++)
            {
                Subnode *newsubNode = malloc(sizeof(Subnode)); 
                strcpy(newsubNode->sfilename, strtok(NULL, ";")); // Extract and store the filename.
                newsubNode->wordcount = atoi(strtok(NULL, ";")); // Extract and store the word count.
                
                if (newMainNode->subnode_link == NULL)
                {
                    newMainNode->subnode_link = newsubNode; // Set the new Subnode as the first in the list.
                }
                else
                {
                    Subnode *tempsubNode = newMainNode->subnode_link;
                    while (tempsubNode->sublink != NULL)
                    {
                        tempsubNode = tempsubNode->sublink; // Traverse the Subnode list.
                    }
                    tempsubNode->sublink = newsubNode; // Insert the new Subnode at the end.
                }
            }

            if (hashtable[index] == NULL)
            {
                hashtable[index] = newMainNode; // Set the new Mainnode in the hashtable at the specified index.
            }
            else
            {
                Mainnode *nextmainNode = hashtable[index];
                while (nextmainNode->mainlink != NULL)
                {
                    nextmainNode = nextmainNode->mainlink; // Traverse the Mainnode list at the index.
                }
                nextmainNode->mainlink = newMainNode; // Insert the new Mainnode at the end.
            }
        }
    }
    fclose(fptr); // Close the file.
    return SUCCESS;
}
