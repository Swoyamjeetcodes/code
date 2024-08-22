#include<time.h>
#include<stdio.h>

int main()
{
time_t begin,end;
time(&begin);
int i,n=1000*1000*1000,sum;
for(i=0;i<n;i++)
	{
	   sum=sum+i;
	}
	
time(&end);
time_t elapsed = end - begin;
printf("time taken:%ld seconds\n",elapsed);
return 0;
}


