#include <stdio.h>
#include <stdlib.h>


int main()
{
    char c, *string, string2[3] = {0}, **strings;
    int num, *nump, a, *b;
    
    string = "Hallo Welt";
    c = string[6];
    string2[0] = 'A';
    string2[1] = 'B';
    strings = malloc(sizeof (*strings) * 3);
    strings[0] = &c;
    strings[1] = string2;
    strings[2] = "third string";
    
    printf("\n");
        
    printf("\tstring: \"%s\" = %p;\n\tc: \"%c\" = %d;\n\tstring2: \"%s\" = %p;\n", 
           string, &(string), c, c, string2, &(string2));
    printf("\tstrings[0]: \"%s\" = %p;\n\tstrings[1]: \"%s\" = %p;\n\tstrings[2]: \"%s\" = %p;\n", 
            strings[0], &(strings[0]), strings[1], &(strings[1]), strings[2], &(strings[2]));
    printf("\tstring2[0] = %d; *strings = %p; strings[2][2] = %d\n", 
           string2[0], &(strings), strings[2][2]);
    
    
    printf("\n");
    
    a = 7;
        
    printf("\ta = %d", a);
    
    nump = &a;
    
    printf("\t*nump = %d", *nump);
    
    *nump = 5;
    
    printf("\t*nump = %d", *nump);
    
    b = &a;
    
    printf("\t*b = %d\n", *b);    
    
    num = (int) (strings + 1)[1];
    
    printf("\tnum = %d\n", num);
        
    printf("\n");
    
//     if(*strings[0] == *(strings + 6))
//     {
//         printf("\t*strings[0] == *(strings + 6) = 1\n");
//     } else {
//         printf("\t*strings[0] == *(strings + 6) = 0\n");
//     }
    
    printf("\t*strings[0] == *(strings + 6) = 0\n");
    printf("\tcomparison between pointer and integer ('int' and 'char *')\n");

    printf("\n");
    
    if(b == nump)
    {
        printf("\tb == nump = 1\n");
    } else {
        printf("\tb == nump = 0\n");
    }
    
    printf("\n");
        
    if(*b == *nump)
    {
        printf("\t*b == *nump = 1\n");
    } else {
        printf("\t*b == *nump = 0\n");
    }
    
//     if(string == string[1])
//     {
//         printf("\tstring == string[1] = 1\n");
//     } else {
//         printf("\tstring == string[1] = 0\n");
//     }
    
    printf("\n");

    printf("\tstring == string[1] = 0\n");
    printf("\tcomparison between pointer and integer ('char *' and 'int')\n");
    
    printf("\n");
    
    return 0;
}