#include"inverted.h"

void display_database( Wlist *head[])
{   
    //5.1) Give the heading
    printf("[index]   [word]   file_count file/s    File: File_name     word_count\n"); 

    //5.12) Run the loop till 27 to include all the indexes
    for(int i = 0; i<27; i++)
    {
        // 5.3) if the head[i] is not NULL, call the function to print the data
        if(head[i] != NULL)
        {    
            print_word_count(head[i]);
        }
    }
}

int print_word_count(Wlist *head)
{   
    //calculate the index
    int ind;
    if(isalpha(head->word[0]))
    {
        ind = tolower(head->word[0]) % 97;
    }
    else{
        ind = 26;
    }

    //Run the loop
    while(head)
    {
        //Print the data
        printf("%d    %s    %d file/s    ", ind, head->word, head->file_count);

        //declare the tHead
        L_Table *tHead = head->link_table;

        //Transverse through tHead
        while(tHead)
        {
            //print the data
            printf("%s    %d", tHead->file_name, tHead->word_count);
            tHead = tHead->l_table_link;
        }

        printf("\n");
        //move to next head
        head = head->w_link;
    }
}