#include "inverted.h"

void file_validation_n_file_list(Flist **f_head, char *argv[])
{
    int i = 1;

    while(argv[i] != NULL)
    {
        //3.a) Checkif the file is empty
        output = isFileEmpty(argv[i]);
        
        //3.b) Check for the output value
        if(output == FILE_NOTAVAILABLE)
        {
            printf("ERROR: The file %s is wrong.\n", argv[i]);
                                
        }
        else if(output == FILE_EMPTY)
        {
            printf("ERROR: The file %s is empty.\n", argv[i]);
        }
        else{
            //3.c) if file is not empty, create file linked list
            output = to_create_list_of_files(f_head, argv[i]);

            //3.d) Validate the output of creating file linked list
            if(output == SUCCESS)
            {
                printf("INFO: File %s is successfully uploaded in the data base.\n", argv[i]);
            }
            else if(output == REPEATATION)
            {
                printf("ERROR: The file %s is already there in the data base.\n", argv[i]);
            }
            else if(output == FAILURE)
            {
                printf("ERROR: Unable to create the file list.\n");
            }
        }
        i++;
    }
}

//Function to check if the file is empty
int isFileEmpty(char *filename)
{
    // printf("Inside isFileEmpty\n");

    //3.a.a) Open the file in read mode
    FILE *fptr = fopen(filename, "r");

    //3.a.b) Check if file is present or not
    if(errno == ENOENT)
    {
        return FILE_NOTAVAILABLE;
    }
    else
    {
        //3.a.c) Chcek if the file is empty
        fseek(fptr, 0, SEEK_END);
        if(ftell(fptr) == 0)
        {
            return FILE_EMPTY;
        }
    }
}

//Function definition to create the file linked list
int to_create_list_of_files(Flist **f_head, char *name)
{
    // printf("Inside to_create_list_of_files\n");

    // 3.c.a) Declare a new node and check if it is allocated. 
    //If not then print error message. 
    //Else, populate the data field and link field in new node
    Flist *new = malloc(sizeof(Flist));
    if(new == NULL)
    {
        printf("ERROR: Node was not/could not allocated/allocate.\n");
        return FAILURE;
    }

    strcpy(new->file_name, name);
    new->f_link = NULL;

    //3.c.b) Check if head is NULL, if so then assign the new to first element of the list. 
    //Else, insert file to the last of the list.
    if(*f_head == NULL)
    {
        (*f_head) = new;
    }
    else{
        Flist *temp = *f_head;
        while(temp->f_link != NULL)
        {
            //3.c.c) Check if the file already exist in the list, if so then return repetition
            if(!strcmp(temp->file_name, name))
            {
                return REPEATATION;
            }
            temp = temp->f_link;
        }
        temp->f_link = new;
    }
    return SUCCESS;    
}