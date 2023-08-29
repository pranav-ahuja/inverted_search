#include "inverted.h"

void save_database(Wlist *head[])
{    
    char save_db_file[FNAME_SIZE];
    int data_present = 0;

    //Ask the file name form the user
    printf("Enter the file to save database in: ");
    scanf("%s", save_db_file);

    //Open the file in write mode
    FILE *sfptr = fopen(save_db_file, "w");

    // Run the loop through the indexes and call write database for indexes that are not NULL
    for(int i = 0; i < 27; i++)
    {
        if(head[i] != NULL)
        {
            //if data is present update the value of variable data present
            data_present = 1;
            write_databasefile(head[i], sfptr);
        }
    }

    if(data_present)
    {
        printf("INFO: The data is saved in file %s\n", save_db_file);
        fclose(sfptr);
    }
    else{
        printf("ERROR: No database created. Create the database first.\n");
        fclose(sfptr);
        remove(save_db_file);
    }   
    
}

void write_databasefile(Wlist *head, FILE* databasefile)
{
    //loop through the word list
    while(head)
    {
        // Enter the data to the file
        fprintf(databasefile, "The word [%s] is present in %d file/s: ",head->word, head->file_count);

        L_Table *tHead = head->link_table;

        while(tHead)
        {
            fprintf(databasefile, "In the file %s %d times. ", tHead->file_name, tHead->word_count);
            tHead = tHead->l_table_link;
        }
        fprintf(databasefile, "\n");
        head = head->w_link;
    }
}
