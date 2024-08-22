#include <stdio.h>
#include <stdlib.h>

int main(){
	FILE *fP;
	
	fP = fopen("/home/kiit/22053733/lab4/inRand.dat", "w");
	if(fP == NULL){
		printf("File doesn't exist or currupted");
		exit(0);
	}
	
	int ub=1;
    	int lb=100;
    	int n = 500,x;
    for (int i = 0; i < n; i++) 
    {
    	x = rand()%(ub-lb+1);
        fprintf(fP, "%d ", x);
    }
	fclose(fP);
	
	return 0;
}
