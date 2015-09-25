#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int main()
{
	char * S1;
	char * S2;
	
	S1 = (char *) malloc (sizeof(char)*2);
	S2 = (char *) malloc (sizeof(char)*2);
	int i, s1Length,s2Length,count=0;
	scanf("%s",S1);
	scanf("%s",S2);
	S1[strlen(S1)-1]=0;
	S2[strlen(S2)-1]=0;
	s1Length = strlen(S1);
	s2Length = strlen(S2);
	for(i=0;i<s1Length;i++)
	{
		
		printf("%c",(char)S1[i]);
	}
	printf("\n");
	for(i=0;i<s2Length;i++)
	{
		printf("%c",(char)S2[i]);
	}
	printf("\n");
	
	while(S1 = strstr(S1, S2))
	{
		count++;
		S1++;
	}
	
	printf("munculnya sebanyak %d\n",count);
	return 0;
}
