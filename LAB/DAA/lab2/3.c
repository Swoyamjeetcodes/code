#include <stdio.h>
#include <stdlib.h>

int main(){
	FILE *fP;
	
	fP = fopen("/home/kiit/22053733/lab2/writefor3.txt", "w");
	if(fP == NULL){
		printf("File doesn't exist or currupted");
		exit(0);
	}
	
	int arr[5] = {1, 3, 5, 7, 9};
	for(int i=0;i<5;i++){
		fprintf(fP, "%d ", arr[i]);
	}
	fclose(fP);
	
	return 0;
}
