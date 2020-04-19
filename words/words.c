//Eyasu Lemma, CS50, Spring 2020
// This program takes input either from a file or from the user
// and displays each word in a separate line. 
// Date 4/16/2020



#include<stdio.h>
#include<ctype.h>
#include <string.h>

FILE *fp_i;   //a file pointer for our files

void file_processor(FILE *fp_i){   // a function that processes the file and prints
    char c;                        // each word in a line
    int space = 0;

    while ( (c = fgetc(fp_i)) != EOF){     //read the file till end of file reached
        if(isalpha(c)){                    // if an alphabet character print out to standard out put
            fputc(c, stdout);
            space = 1;
        }
        else if(space == 1){                // use space counter in order to account for more than one white space
            printf("\n");
            space = 0;
        }
    }
    if(space == 1){   // add a new line character in case print ends in a non new line
        printf("\n");
    }
}

int main(int argc, char *argv[]){
    if(argc > 1){                              
        for(int n = 1; n < argc; n++){          //iterate through each counter
            if(strcmp(argv[n], "-") == 0){      // if counter equals the character "-", then take input from user
                file_processor(stdin);
            }   
            else {
                fp_i = fopen(argv[n], "r");      //else open the file
                if(fp_i == NULL){
                    fprintf(stderr, "Error: file doesn't exist or can't be read\n");
                    return 1;
                }
                else{
                    file_processor(fp_i);   // call the file processor
                } 
            }    
        }
    }
    else if (argc == 1){   //if no argument, also accept from user 
        file_processor(stdin);
    }    
    
    return 0;
}     
