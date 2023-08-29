#include "inverted.h"

void create_database(Flist *f_head, Wlist *head[])
{   
    // 5.a) Run the loop till the file is empty
    while(f_head)
    {
        // 5.b) Read each file and iterate through each file
        read_datafile(f_head, head, f_head->file_name);
        f_head = f_head->f_link;
    }
    printf("The darabase is created successfully.\n");
}

Wlist * read_datafile(Flist *file, Wlist *head[], char *filename)
{
    int index, flag = 0;
    //5.b.a) Open the file and check if file is opened
    FILE *fptr = fopen(filename, "r");
    if(fptr == NULL)
    {
        printf("ERROR: The file was unable to open.\n");
    }

    //5.b.b) Check each word and character in the file
    strcpy(fname, filename);    
    char word[WORD_SIZE];    
    while(fscanf(fptr, "%s", word) != EOF)
    {        
        flag = 0;

        //5.b.c) Find index            
        if(isalpha(word[0]))
        {
            index = tolower(word[0]) % 97;
        }
        else{
            index = 26;
        }

        // 5.b.d) Start the loop to check if the word already exist
        Wlist *temp = head[index];
        while(temp)
        {            
            //if the word is there in the list
            if(!strcmp(temp->word, word))
            {
                //Update the word count
                output = update_word_count(&temp, filename);      
                flag = 1;
                break;          
            }   
            temp = temp->w_link;         
        }
        //5.b.d) If word doesnt exist then Insert at last
        if(flag == 0)
        {
            output = insert_at_last(&head[index], word);            
        }            
    }

    printf("INFO: The data from [%s] inserted successfully.\n", fname);
}

int update_word_count(Wlist ** head, char * file_name)
{
    //Declare the temp
    L_Table *temp = (*head)->link_table;

    //transverse through link table
    while(temp)
    {
        //if filename is same then increase the word count only
        if(!strcmp(temp->file_name, file_name))
        {
            temp->word_count++;
            return SUCCESS;
        }
        temp = temp->l_table_link;        
    }                   
    //else, create a new link and increase the file count
    update_link_table(&(*head)->link_table);
    (*head)->file_count++;

    return SUCCESS;
}
