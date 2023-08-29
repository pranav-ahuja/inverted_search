#include "inverted.h"

int main(int argc, char * argv[])
{
    system("clear");
    
    //1. Check CLA, if not present print error and stop execution
    if(argc <= 1)
    {
        printf("ERROR: Enter the file name. Enter file name\n");
        printf("Example: ./a.out file.txt\n");
        return 0;
    }
    
    //2) Declare the struct variable
    Flist *f_head = NULL;

    //3) Validate the file_list
    file_validation_n_file_list(&f_head, argv);
    if(f_head == NULL)
    {
        printf("ERROR: File Validation failed.\n");
        printf("--------------Project Terminated--------------\n");
    }
    

    //4) Select from the TODO list and start the operation according to the choice
    int choice;
    Wlist *w_head[INDEX_SIZE] = {NULL};
    char word[30];
    int continue_loop = 1;
    char yes_or_no;

    while(continue_loop == 1)
    {
        selection_screen(&choice);
        switch(choice)
        {
            case 1: //5) Create DATABASE
                create_database(f_head, w_head);                
                break;

            case 2: //6) Display Database
                display_database(w_head);
                break;

            case 3: //7) Update database
                update_database(w_head, &f_head);
                break;

            case 4: //8) Search
                printf("Enter the word to search: ");
                scanf(" %s", word);
                
                search(w_head[tolower(word[0]) % 97], word);
                break;

            case 5: //9) Save database
                save_database(w_head);
                break;

			case 6://Exit the program
				exit(0);
				break;

			default: //Error message fore default choice input
				printf("Enter the correct choice.\n");
        }

        printf("Do you want to continue (y/n)?");
        scanf(" %c", &yes_or_no);

        if(tolower(yes_or_no) == 'y')
            continue_loop = 1;
        else
            continue_loop = 0;
    }
    
}

int selection_screen(int *choice)
{
    printf("Select your choice among following options:\n");
    printf("1. Create DATABASE.\n2. Display Database.\n3. Update DATABASE.\n4. Search.\n5. Save Database\n6. Exit\n");
    printf("Enter your choice: ");
    scanf("%d", choice);
}
