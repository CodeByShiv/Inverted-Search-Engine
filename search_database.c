#include "main.h"

/*
Name : Shivam Kumar O
Date : 05/10/2023
Title : Data Structures Project -> Inverted Search
*/

Status search_database(Mainnode **hashtable, char *word)
{

    int index = tolower(word[0]) - 'a';  // Calculate the index based on the first character

    Mainnode *mainNode = hashtable[index];

    // Search for the word in the hashtable
    while (mainNode != NULL)
    {
        if (strcmp(mainNode->word, word) == 0)
        {
            // Word found in the hashtable
            printf("Word: %s\n", mainNode->word);
            printf("File Count: %d\n", mainNode->filecount);

            // Display file names and word counts for each file
            Subnode *subNode = mainNode->subnode_link;
            while (subNode != NULL)
            {
                printf("File: %s, Word Count: %d\n", subNode->sfilename, subNode->wordcount);
                subNode = subNode->sublink;
            }

            return SUCCESS;  // Word found, return success
        }
        mainNode = mainNode->mainlink;
    }

    printf("Word not found in the database.\n");
    return FAILURE;  // Word not found, return failure
}
