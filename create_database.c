#include"main.h"

/*
Name : Shivam Kumar O
Date : 05/10/2023
Title : Data Structures Project -> Inverted Search
*/

Status create_database(Slist **head, Mainnode **hashtable)
{
    Slist *temp = *head;

    while (temp)
    {
        FILE *fptr = fopen(temp->file_name, "r");
        if (fptr == NULL)
        {
            printf("ERROR while opening file %s\n", temp->file_name);
            return FAILURE;
        }

        char word[50];
        while (fscanf(fptr, "%s", word) == 1)
        {
            int index;
            if (islower(word[0]) || isupper(word[0]))
                index = tolower(word[0]) % 97;
            else
                index = 26;
            
            Mainnode *mainNode = hashtable[index];

            // Search for the word in the hashtable
            while (mainNode != NULL)
            {
                if (strcmp(mainNode->word, word) == 0)
                {
                    // Word found in the hashtable

                    // Check if the file is already associated with the word
                    Subnode *subNode = mainNode->subnode_link;
                    while (subNode != NULL)
                    {
                        if (strcmp(subNode->sfilename, temp->file_name) == 0)
                        {
                            // File already associated with the word; increment word count
                            subNode->wordcount++;
                            break;
                        }
                        subNode = subNode->sublink;
                    }

                    if (subNode == NULL)
                    {
                        // File not associated with the word; create a new Subnode
                        Subnode *newSubNode = malloc(sizeof(Subnode));
                        if (newSubNode == NULL)
                        {
                            printf("Subnode creation failed\n");
                            return FAILURE;
                        }
                        strcpy(newSubNode->sfilename, temp->file_name);
                        newSubNode->wordcount = 1;
                        newSubNode->sublink = mainNode->subnode_link;
                        mainNode->subnode_link = newSubNode;
                        mainNode->filecount++;
                    }
                    break;
                }
                mainNode = mainNode->mainlink;
            }

            if (mainNode == NULL)
            {
                // Word not found in the hashtable; create a new Mainnode and Subnode
                Mainnode *newMainNode = malloc(sizeof(Mainnode));
                if (newMainNode == NULL)
                {
                    printf("Mainnode creation failed\n");
                    return FAILURE;
                }
                strcpy(newMainNode->word, word);
                newMainNode->filecount = 1;

                Subnode *newSubNode = malloc(sizeof(Subnode));
                if (newSubNode == NULL)
                {
                    printf("Subnode creation failed\n");
                    return FAILURE;
                }
                strcpy(newSubNode->sfilename, temp->file_name);
                newSubNode->wordcount = 1;

                newMainNode->subnode_link = newSubNode;
                newMainNode->mainlink = hashtable[index];
                hashtable[index] = newMainNode;
            }
        }

        fclose(fptr);
        temp = temp->link;
    }

    return SUCCESS;
}
