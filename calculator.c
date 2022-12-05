#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
typedef struct tree {
    float value;
    char operateur;
    struct tree *left;
    struct tree *right; 
} node_t;
node_t *build_tree(char *argv[],int *position){
    node_t *arbre =malloc(sizeof(node_t));
    if ((argv[*position][0] != '+') && (argv[*position][0] != '*') && (argv[*position][0] != '/') && (argv[*position][0] != '-')){
        (*arbre).value = atof(argv[*position]);
        (*arbre).left  = NULL;
        (*arbre).right = NULL;
        (*position)++;
    }
    else{
        if( argv[*position][0] == '*'){
            (*arbre).operateur = '*';

        } 
        else if( argv[*position][0] == '+'){
            (*arbre).operateur = '+';
        }
        else if( argv[*position][0] == '/'){
            (*arbre).operateur = '/';

        }  
        else if( argv[*position][0] == '-'){
            (*arbre).operateur = '-';
        }   
    (*position)++;
    (*arbre).left  = build_tree(argv,position);
    (*arbre).right = build_tree(argv,position);
    }
    return arbre;
}

void display_tree(node_t *root){
    if((*root).left == NULL && (*root).right == NULL){
        printf(" %.2f ",(*root).value);
    }
    else{
        printf("(");
        display_tree((*root).left);
        printf(" %c ",(*root).operateur);
        display_tree((*root).right);
        printf(") ");
    }
}

float compute_tree(node_t *root){
    if(((*root).left == NULL) && ((*root).right == NULL)){
        return (*root).value;
    }
    else{
        if((*root).operateur == '+')
            return compute_tree((*root).left) + compute_tree((*root).right);
        if((*root).operateur == '*')
            return compute_tree((*root).left) * compute_tree((*root).right);
        if((*root).operateur == '/')
            return compute_tree((*root).left) / compute_tree((*root).right);
        if((*root).operateur == '-')
            return compute_tree((*root).left) - compute_tree((*root).right);


    }
    return 0;
}
int main(int argc,char * argv[]){
    node_t *arbre = NULL;
    int position = 1;
    arbre = build_tree(argv , &position);
    display_tree(arbre);
    printf(" = %.2f\n",compute_tree(arbre));
    return 0;
}
