#include<time.h>
#include<stdio.h>
#include <math.h>

int main()
{
clock_t end;
clock_t start = clock(); 

int i,n=1000*1000*1000,sum;
for(i=0;i<n;i++)
	{
	   sum=sum+i;
	}
	
//clock_t end = clock();
end = clock() - start;
double time_taken = ((double) end) /CLOCKS_PER_SEC;
printf("time taken:%f\n",time_taken);
return 0 ;
}
