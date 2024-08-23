#include "main.h"
#include <stdio.h>

/*
Name : Shivam Kumar O
Date : 05/10/2023
Title : Data Structures Project -> Inverted Search
*/

Status display_database(Mainnode **hashtable)
{
    printf("Displaying Database : \n");
    printf("[index]\t\t[Word]\t\t\tFile_count\tFiles\n");

    for (int i = 0; i < 27; i++)
    {
        if (hashtable[i])
        {
            Mainnode *temp = hashtable[i];
            while (temp)
            {
                printf("[%d]\t\t%-28s%-8d\t", i, temp->word, temp->filecount);

                Subnode *temp1 = temp->subnode_link;
                if (temp1)
                {
                    printf("Files: ");
                    while (temp1)
                    {
                        printf("%s(%d time/s) ", temp1->sfilename, temp1->wordcount);
                        temp1 = temp1->sublink;
                    }
                }

                printf("\n");
                temp = temp->mainlink;
            }
        }
    }

    return SUCCESS;
}
