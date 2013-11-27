/* GSA Uebungen 7, Aufgabe 3, Felix Braun */


#include <stdio.h>         /* use standard output routines */
#include <stdlib.h>        /* use standard library functions */
#include <string.h>        /* include string library */


int getmin(int a,int b,int c) {
    
        if(a <= b && a <= c) {
                return a;
        }
        else if(b <= a && b <= c) {
                return b;
        }
        else {
                return c;
        }
}


int fehler(int mode, char *option) {
    
    if(mode == 1){
        
        fprintf(stderr, "\n\tPlease note syntax: %s ", option);
        fprintf(stderr, "<allowed number of errors> <search pattern> <sequence/input file>\n\n");
        return(0);
    }
    
    return(0);
}


int main(int argc, char *argv[]) {
    
    if(argc != 4) {
        
        fehler(1, argv[0]);
        exit(EXIT_FAILURE);
    }
 
    FILE* f;
    int k, i;
    char *p = malloc(strlen(argv[2]) * sizeof(char));
    char *t;
 
    if(!(sscanf(argv[1], "%d", &k))) {

        fehler(1, argv[0]);
        exit(EXIT_FAILURE);
    }
    
    strcpy(p, argv[2]);
    
    
    f = fopen(argv[3], "r");
    
    if(f == NULL) {
        
        t = malloc(strlen(argv[3]) * sizeof(char));
        strcpy(t, argv[3]);
          
    } else {
        
        fseek(f, 0, SEEK_END);
        t = malloc(ftell(f) * sizeof(char));
        fseek(f, 0, SEEK_SET);

        fscanf (f, "%s", t);
        
        fclose(f);
        
    }
      
    
    return(0);
}