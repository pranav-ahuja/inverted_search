#ifndef INVERTED_H
#define INVERTED_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <ctype.h>
#include <errno.h>

#define FAILURE -1
#define SUCCESS 0
#define FNAME_SIZE 30
#define FILE_NOTAVAILABLE -3
#define REPEATATION -4
#define WORD_SIZE 20
#define FILE_EMPTY -2
#define INDEX_SIZE 27

//Declare a fname variable
char fname[FNAME_SIZE];
int output;

typedef char data_t;

//1. Create file list structure to store files
typedef struct File_List
{
    data_t file_name[FNAME_SIZE];
    struct File_List *f_link;
}Flist;

//2. Create Link table to find the file in which the word is occuring
typedef struct Link_Table
{
    int word_count;
    data_t file_name[FNAME_SIZE];
    struct Link_Table *l_table_link;
}L_Table;

//3. Create Word List structure to store different words
typedef struct Word_List
{
    int file_count;
    data_t word[WORD_SIZE];
    struct Link_Table* link_table;
    struct Word_List *w_link;
}Wlist;

//4. Function prototypes

//Create the linked list of files
int to_create_list_of_files(Flist **f_head, char *name);
//to create the database
void create_database(Flist *f_head, Wlist *head[]);
// read contents of a file
Wlist * read_datafile(Flist *file, Wlist *head[], char *filename);
// create word_list
int insert_at_last(Wlist **head, data_t *data);
// update linktable
int update_link_table(L_Table **head);
// update
int update_word_count(Wlist ** head, char * file_name);
// print_word_count
int print_word_count(Wlist *head);
//searching a word
void search(Wlist *head, char *word);
//display 
void display_database( Wlist *head[] );
//save_databse
void save_database( Wlist *head[]);
//write data to the file
void write_databasefile(Wlist *head, FILE* databasefile);
//update database
void update_database( Wlist *head[], Flist **f_head);
//check if the file is empty
int isFileEmpty(char *filename);
// check the files
void file_validation_n_file_list(Flist **f_head, char *argv[]);
// selection screen
int selection_screen(int *);

#endif