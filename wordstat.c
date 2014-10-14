#include <stdlib.h>
#include <stdio.h>

#include <strings.h>
#include <string.h>

#include <ctype.h>
#include "tree.h"

int main(int argc, char ** argv){
    struct tree * list; 
    char * temp ;
    FILE * thefile;
    int i = 0;             /* current position in array temp, iterator */
    char curr;

    if(argc != 2)
    {
        fprintf(stderr, "wrong number of arguments!\n");
        return 1;
    }

    if(strcmp(argv[1],"-h") == 0)
    {
        printf("Usage: Argument is name of file to be examined including file extension, without quotes!\n");
        return 2;
    }

    thefile = fopen(argv[1], "r");
    
    if(thefile == NULL)
    {
        fprintf(stderr, "File error %s!\n", argv[1]);
        return 3;
    }

    temp = (char * )malloc(2048);

    while( (curr = fgetc(thefile)) != EOF)
    {
        if(isalpha(curr) && i == 0 ) /* first char in word must be a letter, iterates forward */
        { 
            temp[i] = curr;
            i++;
        }
        else if( i > 0 && isalnum(curr)  )  /* a number or letter char inside a word, continue iteration */
        {
            temp[i] = curr;
            i++;
        }
        else
        {
            if(temp[0] != '\0')
	    {
                list = ProcessStr(list, temp);  /* process current array as finished word and adds to tree */
            }
        bzero(temp, i+1 );  /*resets array to store subsequent string in thefile */
        i = 0;    /* resets iteration counter */
        }
    }
    printf("Word \t Total No. Occurances \t No. Case-Sensitive Versions  \n");
    printResult(list);
    free(temp);

return 0;
}

