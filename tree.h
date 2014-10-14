#ifndef TREE_H
#define TREE_H

struct tree
{
    struct tree * left;
    struct tree * right;
    struct tree * perm;
    char * word;
    int count;
    int permutations;
};

void printResult(struct tree *); 
struct tree * ProcessStr(struct tree *, char *);


#endif
