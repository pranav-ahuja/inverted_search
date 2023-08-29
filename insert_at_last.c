#include "inverted.h"

int insert_at_last(Wlist **head, data_t *data)
{
    //printf("Inside insert_at_last\n");
    //5.b.d.1) Create a new node and do error check
    Wlist *new_word = malloc(sizeof(Wlist));
    if(new_word == NULL)
    {
        printf("ERROR: The new word list was not allocated");
        return FAILURE;
    }
    //5.b.d.2) Enter the values of the new node
    new_word->file_count = 1;
    strcpy(new_word->word, data);
    new_word->w_link = NULL;
    new_word->link_table = NULL;

    //declare the table
    Wlist *temp = *head;

    //5.b.d.3) check if the head is null
    if(*head == NULL)
    {        
        *head = new_word; 

        //5.b.d.3) Update the link    
        output = update_link_table(&(*head)->link_table);               
    }
    else{
        //5.b.d.4) If head is not NULL
        while(temp->w_link != NULL)
        {
            //5.b.d.5) If word is repeated, break the loop
            if(!strcmp(temp->word, data))
            {
                break;
            }
            //5.b.d.6) else traverse to the next list
            temp = temp->w_link;
        }
        //5.b.d.7) Add new_word as the next item of the list
        temp->w_link = new_word;
        temp = temp->w_link;

        //5.b.d.8) Update the link    
        output = update_link_table(&temp->link_table);
    }

    if(output == SUCCESS)
    {
        printf("INFO: The link table for word [%s] is updated successfully.\n", data);
        return SUCCESS;
    }
    else{
        printf("ERROR: The link table updation failed.\n");
        return FAILURE;
    }
}