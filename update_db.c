#include "inverted.h"

void update_database( Wlist *head[], Flist **f_head)
{
    //Enter the file name
    printf("Enter the new file name: ");
    scanf("%s", fname);

    output = isFileEmpty(fname);
        
    //Check for the output value
    if(output == FILE_NOTAVAILABLE)
    {
        printf("ERROR: The file %s is wrong.\n", fname);
                            
    }
    else if(output == FILE_EMPTY)
    {
        printf("ERROR: The file %s is empty.\n", fname);
    }
    else{
        output = to_create_list_of_files(f_head, fname);

        if(output == SUCCESS)
        {
            printf("The file [%s] gets updated in the file list.\n", fname);
        }
        else if(output == REPEATATION)
        {
            printf("ERROR: The file [%s] is already there in the file list.\n", fname);
        }
        else if(output == FAILURE)
        {
            printf("ERROR: Unable to update the file list.\n");
        }
    }

    if(output == SUCCESS)
    {
        read_datafile(*f_head, head, fname);
    }
}


