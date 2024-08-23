#ifndef MAIN_H_INCLUDED
#define MAIN_H_INCLUDED

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

#define DUPLICATE -1
typedef char* data_t; // char* for generic data type

typedef enum
{
    FAILURE,
    SUCCESS
} Status;

typedef struct node
{
    data_t file_name;
    struct node *link;
} Slist;

typedef struct snode
{
    int wordcount;
    char sfilename[50];
    struct snode *sublink;
} Subnode;

typedef struct mnode
{
    int filecount;
    char word[50];
    Subnode *subnode_link;
    struct mnode *mainlink;
} Mainnode;

Status read_and_validate_cla(Slist **head, int argc, char *argv[]);
Status insert_at_last(Slist **head, data_t data);
Status create_database(Slist **head, Mainnode **hashtable);
Status display_database(Mainnode **hashtable);
Status search_database(Mainnode **hashtable, char *word);
Status save_database(Mainnode **hashtable, char *new_filename);
Status update_database(Mainnode **hashtable, char *filename);

#endif // MAIN_H_INCLUDED
