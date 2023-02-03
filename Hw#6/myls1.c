//Vincenzo D'Aria
//CS 355 - ls cmd

//Necessary header file declarations
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <stdio.h>
#include <dirent.h>
#include <stdbool.h>


//Function prototype for do_ls when it's needed in main()
void do_ls(char [], bool, bool);

//String comparison method that's necessary for qSort();
//uses strcmp to compare two strings passed as parameters
int compareChars(const void *a, const void *b) { 
    const char *string1 = *(const char **)a;
    const char *string2 = *(const char **)b;
    return strcmp(string1, string2);
}
//Main Method
int main(int argc, char *argv[]){

    //boolean comparison variables for -s and -r cases 
    bool r = false;   
    bool s = false;
    //if only the program name is passed, do ls for current directory
    if(argc==1){
        do_ls(".",s,r);
    }
    //if the program name and an argument is passed (like -s, -r, 'directory name')    
    else if(argc==2){
        int len = strlen(argv[1]);
        char argument_1[len];
        strcpy(argument_1,argv[1]);
        //if the first character in argv[1] isnt a sort case, pass control to do_ls for the selected directory
        if(argument_1[0] != '-'){
            printf("%s:\n\n", argument_1);
            do_ls(argument_1,s,r);
        // Else, indicate that a sort case is true, and pass control to do_ls
        }else{
            if(argv[1][1] == 's'){
                s = true;
            }if(argv[1][1] == 'r'){
                r = true;
            }
            printf("%s:\n\n", argument_1);
            do_ls(".", s, r);
        }
    //If three (or more) arguments are passed (i.e. myls1 -s dirA)    
    }else{
        //puts argv[1] into array of characters       
        int len = strlen(argv[1]);
        char argument_1[len];
        strcpy(argument_1,argv[1]);
        //puts argv[2] into array of characters    
        len = strlen(argv[2]);
        char argument_2[len];
        strcpy(argument_2,argv[2]);
        //if the second character of argv[1] is s or r, indicate a sort case
        if(argv[1][1] == 's'){
            s = true;
        }
        if(argv[1][1] == 'r'){
            r = true;
        }
        printf("%s ", argument_1);
        printf("%s :\n\n",argument_2);
        //Then, pass control to do_ls for the directory defined in argv[2]
        do_ls(argument_2, s,r);
    }
}

//ls method
//*** Unlike my first version of myls1, I used qSort instead of strcpy to sort, as I ran into less problems *** 

void do_ls(char dirname[], bool s, bool r){
    //Directory pointer and structure declarations
    DIR                 *dir_ptr;
    struct dirent       *direntp;

    //Array and size variable declarations
    char* dir_array[200];
    int size = 0;

    //If directory doesn't exist, print error message
    if((dir_ptr = opendir(dirname)) == NULL)
        fprintf(stderr,"myls1: cannot open %s\n", dirname);

    //Else, open directory, read files, put into 2D array, increment array size
    else{
        while((direntp=readdir(dir_ptr)) != NULL){
            dir_array[size] = direntp->d_name;
            size++;
        }
        //Close the directory after array has been populated
        closedir(dir_ptr);

        //if boolean check values are true, either sort lexicographically based on comparator method
        if(s == 1){
            printf("%s\n","Files displayed in order");
            printf("%s\n\n","......................... ");
            qsort (dir_array, size, sizeof(char*), compareChars);

        }
        // or sort in reverse
        if(r == 1){
            printf("%s\n","Files displayed in reverse order ");
            printf("%s\n\n","................................. ");
            qsort (dir_array, size, sizeof(char*), compareChars);
            for(int i = size-1; i >= 0; i--){
                    printf("%s\n",dir_array[i]);
            }
        //else, just print the directories as-is
        }else{
            for(int i = 0; i < size; i++){
                    printf("%s\n",dir_array[i]);
            }
        }
    }
}