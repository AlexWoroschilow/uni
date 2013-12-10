

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdbool.h>


typedef struct Point {
    
    double x;
    double y;    
    
} Point;


typedef struct Poly {
    
    Point *points;
    int numofpoi;
    
} Poly;


double distance(Point a, Point b) {
    
    double x;
    
    x = sqrt(pow((a.x - b.x), 2) + pow((a.y - b.y), 2));
    
    return(x);
    
}


double getmin(const Poly *shape, bool *donot, int y) {

    int i, j;
    double min = 0;
    bool first = 1;
    bool full = 1;
    
    for(i = 0; i < shape->numofpoi; i++) {
        
        if(donot[i] == 0) {
            full = 0;      
            break;
        }
                
    }
   
       
    for(i = 0; i < shape->numofpoi; i++)
        
        if(donot[i] && full) {
            
            continue;
            
        }
        
        if(first) {
            
            min = distance(shape->points[i], shape->points[y]);
            j = i;            
            first = 0;
           
        } else if(distance(shape->points[i], shape->points[y]) < min) {
            
            min = distance(shape->points[i], shape->points[y]);
            j = i;
            
        }
        
        donot[j] = 1;
        
        return(min);
        
}
            

double perimeter(const Poly *shape) {
   
    int i;
    
    bool *donot = malloc(shape->numofpoi * sizeof(*donot));
    for(i = 0; i < shape->numofpoi; i++) {
        
        donot[i] = 0;
        
    }
    
    double per = 0;    
    
    for(i = 0; i < shape->numofpoi; i++) {
        
        per += getmin(shape, donot, i);        
    }
    
    return(per);
    
}


int main(int argc, char *argv[]) {
    
    int l, i;
    double per;
    Poly polygon;
    
    if(argc != 2) {
        
        printf("\n\tERROR1\n\n");
        exit(EXIT_FAILURE);
        
    }
        
    if(!(sscanf(argv[1], "%d", &l))) {
        
        printf("\n\tERROR2\n\n");
        exit(EXIT_FAILURE);
        
    }
    
    polygon.points = malloc(l * sizeof(polygon.points));
    polygon.numofpoi = l;
    
    for(i = 0; i < l; i++) {
        
        polygon.points[i].x = ((i % 2) + i) + ((3 * l) % 7);        /* variable Koordinaten */
        polygon.points[i].y = (i - (i % 2)) + ((2 * l) % 5);
        
    }
    
    per = perimeter(&polygon);
    
    printf("\n\tDer Umfang betraegt %lf.\n\n", per);
    
    
    return(EXIT_SUCCESS);
    
}