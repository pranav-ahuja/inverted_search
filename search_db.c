#include "inverted.h"

void search(Wlist *head, char *word)
{
    int data_found = 0;

    //check if the head is empty. If so then print error
    if(head == NULL)
    {
        printf("ERROR: Search ended because no elements are in the index.\n");
    }
    else{        
        //Run the loop through head
        while(head)
        {
            // if the word matched with the input
            if(!strcmp(head->word, word))
            {
                data_found = 1;
                //if so the nprint the data
                printf("The word [%s] is present in %d file/s: ", head->word, head->file_count);

                L_Table *tHead = head->link_table;

                while(tHead)
                {
                    printf("In File %s %d time/s ", tHead->file_name, tHead->word_count);
                    tHead = tHead->l_table_link;                    
                }                                                
                break;
            }            
            head = head->w_link;            
        }
        if(data_found)
        {
            printf("\n");
        }
        else{
            printf("ERROR: Word [%s] is not present in the database.\n", word);
        }
		
    }
}
