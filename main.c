#include "main.h"
#include <ctype.h>

/*
Name: Shivam Kumar O
Date: 05/10/2023
Title: Data Structures Project -> Inverted Search
*/

Mainnode *hashtable[27] = {NULL}; // Initialize an array of pointers for the database.

int main(int argc, char *argv[])
{
    // Check if command line arguments are provided
    if (argc > 1)
    {
        Slist *head = NULL; // Initialize a linked list to store file names.
        char new_filename[50]; 
        char backup_filename[50]; 
        int flag = 0; 

        // Read and validate Command Line Arguments (CLA)
        if ((read_and_validate_cla(&head, argc, argv)) == SUCCESS)
        {
            printf("Reading and validation of Command Line Arguments -----------> Successful\n");
            char ch;
            do
            {
                int choice;
                printf("Select your choice among following options: \n1. Create DATABASE\n2. Display DATABASE\n3. Search DATABASE\n4. Save DATABASE\n5. Update DATABASE\nEnter your choice: ");
                scanf("%d", &choice);

                switch (choice)
                {
                    case 1:
                        // Create a new database
                        if (create_database(&head, hashtable) == SUCCESS)
                        {
                            printf("SUCCESSFUL: Database creation is successful.\n");
                            flag = 1;
                        }
                        else
                            printf("ERROR: There is an issue with database creation.\n");
                        break;

                    case 2:
                        // Display the database
                        if (display_database(hashtable) == SUCCESS)
                            printf("SUCCESSFUL: Database display.\n");
                        else
                            printf("ERROR: There is an issue with the database display.\n");
                        break;

                    case 3:
                        char word[30];
                        printf("Enter the word you want to search: ");
                        scanf(" %[^\n]", word);

                        // Search for a word in the database
                        if (search_database(hashtable, word) == SUCCESS)
                            printf("SUCCESSFUL: Search Database\n");
                        else
                            printf("ERROR: Word isn't present in the database\n");
                        break;

                    case 4:
                        printf("Enter the new file name to save the database: ");
                        scanf("%s", new_filename);

                        // Save the database to a new file
                        if (save_database(hashtable, new_filename) == SUCCESS)
                        {
                            printf("Database saved SUCCESSFULLY\n");
                        }
                        else
                        {
                            printf("Save database ----------> Unsuccessful\n");
                        }
                        break;

                    case 5:
                    {
                        // Check if the database has already been created
                        if (flag == 1)
                        {
                            printf("-----------------------ERROR-----------------------\nCannot update database since the database has already been created\n");
                            return FAILURE;
                        }
                        printf("Enter the backup filename: ");
                        scanf("%s", backup_filename);

                        // Update the database using a backup file
                        if (update_database(hashtable, backup_filename) == SUCCESS)
                        {
                            printf("Updating database -----------------> successful\n");
                        }
                        else
                        {
                            printf("Updating database -----------------> Unsuccessful\n");
                        }
                        break;
                    }
                    default:
                        printf("Enter the Correct choice!!!\n");
                }

                getchar();
                printf("Do you want to Continue (y/Y)?: ");
                ch = getchar();

            } while (ch == 'y' || ch == 'Y');
        }
        else
        {
            printf("Reading and validation of Command Line Arguments -----------> Unsuccessful\n");
        }
    }
    else
    {
        printf("------------------------ERROR------------------------\n     Usage: %s <file1> <file2> ... <fileN>\n", argv[0]);
        printf("Do you want to update the database? (y/Y)");
        char ch = getchar();
        
        if (ch == 'y' || ch == 'Y')
        {
            Slist *head = NULL; // Initialize a linked list to store file names.
            char new_filename[50]; 
            char backup_filename[50]; 
            int flag = 0; 

            do
            {
                int choice;
                printf("Select your choice among the following options: \n1. Display DATABASE\n2. Search DATABASE\n3. Save DATABASE\n4. Update DATABASE\nEnter your choice: ");
                scanf("%d", &choice);

                switch (choice)
                {
                    case 1:
                        // Display the database
                        if (display_database(hashtable) == SUCCESS)
                            printf("SUCCESSFUL: Database display.\n");
                        else
                            printf("ERROR: There is an issue with the database display.\n");
                        break;

                    case 2:
                        char word[30];
                        printf("Enter the word you want to search: ");
                        scanf(" %[^\n]", word);

                        // Search for a word in the database
                        if (search_database(hashtable, word) == SUCCESS)
                            printf("SUCCESSFUL: Search Database\n");
                        else
                            printf("ERROR: Word isn't present in the database\n");
                        break;

                    case 3:
                        printf("Enter the new file name to save the database: ");
                        scanf("%s", new_filename);

                        // Save the database to a new file
                        if (save_database(hashtable, new_filename) == SUCCESS)
                        {
                            printf("Database saved SUCCESSFULLY\n");
                        }
                        else
                        {
                            printf("Save database ----------> Unsuccessful\n");
                        }
                        break;

                    case 4:
                    {
                        printf("Enter the backup filename: ");
                        scanf("%s", backup_filename);

                        // Update the database using a backup file
                        if (update_database(hashtable, backup_filename) == SUCCESS)
                        {
                            printf("Updating database -----------------> successful\n");
                        }
                        else
                        {
                            printf("Updating database -----------------> Unsuccessful\n");
                        }
                        break;
                    }
                    default:
                        printf("Enter the Correct choice!!!\n");
                }

                getchar();
                printf("Do you want to Continue (y/Y)?: ");
                ch = getchar();

            } while (ch == 'y' || ch == 'Y');
        }
        else
        {
            printf("Try again\n");
            return FAILURE;
        }
        
        return 0;
    }
    return 1; // Indicates successful program execution
}
