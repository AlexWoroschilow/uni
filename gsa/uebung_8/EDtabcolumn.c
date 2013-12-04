/* header fuer Aufgabe 8.3 by Felix Braun */


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "EDtabcolumn.h"
// #include "alignments.h"


int getmin(int a, int b, int c) {

    if(a <= b && a <= c) {

        return(a);                      /* Replacement */

    } else if(b <= a && b <= c) {

        return(b);                      /* Insertion */

    } else {

        return(c);                      /* Deletion */
    }
}


void firstEDtabcolumn(int *col, int length) {

    int i;

    col[0] = 0;

    printf("\t%d", col[0]);

    for(i = 1; i < length; i++) {

        col[i] = col[i-1] + 1;

        printf("\t%d", col[i]);
    }
}


int* nextEDtabcolumn(int *col, int length, char b, char *u) {

    int i;

    int *ncol = malloc(length * sizeof(ncol));

    ncol[0] = 0;

    printf("\t%d", ncol[0]);

    for(i = 1; i < length; i++) {

        ncol[i] = getmin(col [i-1] + (b == u[i-1] ? 0 : 1),
            col[i] + 1, ncol[i-1] + 1);

        printf("\t%d", ncol[i]);
    }

    free(col);

    return(ncol);
}


// void firstEDtabRcolumn {


// }


// void nextEDtabRcolumn {


// }


// void evaluateallcolumns {


// }
