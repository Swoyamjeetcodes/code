#include <stdio.h>
#include <stdlib.h>

int main() {

    //rand
    int x;
    int n;

    printf("how many number you want? = ");
    scanf("%d",&n);
        
    printf("rand are = ");
    for (int i = 0; i < n; i++) {
    	x = rand();
        printf("%d ", x);
    }
    
    //rand within range
    int ub=1;
    int lb=100;
    
    printf("rand within rannge are = ");
    for (int i = 0; i < n; i++) {
    	x = rand()%(ub-lb+1);
        printf("%d ", x);
    }
    
        return 0;}
