#include "inverted.h"

//5..8) Update the link table
int update_link_table(L_Table **head)
{    
    //Declare a new link and check of errors
    L_Table *new_link = malloc(sizeof(L_Table));
    if(new_link == NULL)
    {
        printf("ERROR: The new link table was not allocated");
        return FAILURE;
    }

    //Assign word_count and table link values to new_link    
    new_link->word_count = 1;
    strcpy(new_link->file_name, fname);
    new_link->l_table_link = NULL;
    

    //Check if the link_table link is NULL, if so then assign the new link element
    if((*head) == NULL)
    {                   
        *head = new_link;        
    }
    else{
        //Initialize temp as head
        L_Table *temp = (*head);

        //transverse the loop till the link is NULL
        while(temp->l_table_link != NULL)
        {
            //Traverse through each linked list
            temp = temp->l_table_link;            
        }

        //Attach new_link to the end of the list
        temp->l_table_link = new_link;
    }
    return SUCCESS;
}
