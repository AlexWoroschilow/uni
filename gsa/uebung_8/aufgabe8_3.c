/* main fuer Aufgabe 8.3 by Felix Braun */


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "EDtabcolumn.h"
// #include "alignments.h"


void error(int mode, char *option) {
    
    if(mode == 1) {
        
        fprintf(stderr, "\n\tPlease note syntax: %s ", option);
        fprintf(stderr, "<sequence u> <sequence v>\n\n");        
    }
}


int main(int argc, char *argv[]) {
 
    if(argc != 3) {
        
        error(1, argv[0]);
        exit(EXIT_FAILURE);
    }
 
    FILE* f;
    char *u, *v;
    int *col;
    int length;
    int i;

    f = fopen(argv[1], "r");
    
    if(f == NULL) {
        
        u = malloc(strlen(argv[1]) * sizeof(u));
        strcpy(u, argv[1]);
          
    } else {
        
        fseek(f, 0, SEEK_END);
        u = malloc(ftell(f) * sizeof(u) + 1);
        fseek(f, 0, SEEK_SET);

        fscanf (f, "%s", u);
        
        fclose(f);        
    }

    f = fopen(argv[2], "r");

    if(f == NULL) {
        
        v = malloc(strlen(argv[2]) * sizeof(v));
        strcpy(v, argv[2]);
          
    } else {
        
        fseek(f, 0, SEEK_END);
        v = malloc(ftell(f) * sizeof(v) + 1);
        fseek(f, 0, SEEK_SET);

        fscanf (f, "%s", v);
        
        fclose(f);        
    }

    col = malloc((strlen(u) + 1) * sizeof(col));

    length = sizeof(col);

 
    printf("\n\t");

    firstEDtabcolumn(col, length);

    printf("\n\t");

    for(i = 0; i < strlen(v); i++) {

        col = nextEDtabcolumn(col, length, v[i], u);

        printf("\n\t");
    }

    printf("\n");

    return(EXIT_SUCCESS);
}