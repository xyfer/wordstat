#include <stdio.h>
#include <strings.h>
#include <string.h>
#include <stdlib.h>

#include "tree.h"

struct tree * ProcessStr(struct tree * root, char * word){
    struct tree * ptr = root;
    struct tree * leaf;
    struct tree * prev;
    struct tree * permptr;
    int compare = 0;

    leaf = (struct tree *)malloc( sizeof(struct tree) );
    leaf->count = 1;         /* when word is added, intial permutation count and occurance count is 1 */
    leaf->permutations = 1;
    leaf->word = (char *)malloc( sizeof(char)*strlen(word)+1);
    strcpy(leaf->word, word);

    while ( ptr != NULL )
   {
        prev = ptr;
        compare = strcasecmp( word, ptr->word );   /* checks if word is identical case insensitive */
        if (compare == 0)
	 {

            ptr->count++;      /* update occurances */
            permptr = ptr;     
         
         /* moves in a third dimension of permutation leaves, (ie. a permutation LL) checking if word is a new version or an already existing permutation */
         
		for (permptr = ptr; permptr != NULL; permptr = permptr->perm)
        {
                if( (strcmp(word, permptr->word)) == 0 ) /* perm has already been counted */
                {
                    break;
                }
            if( (strcmp(word, permptr->word)) != 0 ) /* a new one! */
            {
                prev = permptr;
            }
        }
        
        ptr->permutations++;   /* add to the permutation field in "root" of permutation list */
        prev->perm = leaf;      /* add new permutation to perm. list */
         
        break;
         
      }
       
       /* compare was not 0, move through list accordinly */
       
        else if (compare < 0) /* move down left */
	    {
            ptr = ptr->left;
        }
        else if (compare > 0) /* move down right */
        {
            ptr = ptr->right;
        }
    }
    
    /* ptr is now Null, we have reached an end of the tree */
    
    
    if (root == NULL) /* first add - leaf becomes root */
    {
        return leaf;
    }
    if ( compare < 0 ) /* new leaf is first alphabetically */
    {
        prev->left = leaf;
        return root;
    }
    else if (compare > 0) /* new leaf is last alphabetically */
    {
        prev->right = leaf;
        return root;
    }
    return root;
}

void printResult(struct tree * ptr){  /* simple recursive function for in-order traversal to print alphabetically */
    if(ptr->left != NULL)
    {
        printResult(ptr->left);
    }
    printf("%s\t\t\t%d\t\t\t%d\n", ptr->word, ptr->count, ptr->permutations);
    if(ptr->right != NULL)
    {
        printResult(ptr->right);
    }
    return;
}
