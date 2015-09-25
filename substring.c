/*Program untuk menghitung kemunculan substring
 * 
 * */
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int main()
{
	/* kamus */
	char * S1;
	char * S2;
	int i, s1Length,s2Length,count=0;
	
	/*Algoritma */
	/* alokasi memori string */
	S1 = (char *) malloc (sizeof(char)*100);
	S2 = (char *) malloc (sizeof(char)*100);
	
	/* baca string dan substringnya*/
	scanf("%s",S1);
	scanf("%s",S2);
	
	/*menghilangkan karakter terakhir string dan substring jika karakter terakhir adalah . */
	if(S1 && *S1 && S1[strlen(S1) - 1] == '.')
	{
		S1[strlen(S1)-1]=0;
	}
	if(S2 && *S2 && S2[strlen(S2) - 1] == '.')
	{
		S2[strlen(S2)-1]=0;
	}
	s1Length = strlen(S1);
	s2Length = strlen(S2);
	
	/*tampilkan string dan substring yang dibaca */
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
	
	/* hitung jumlah kemunculan substring */
	while(S1 = strstr(S1, S2))
	{
		count++;
		S1++;
	}
	
	printf("munculnya sebanyak %d\n",count);
	return 0;
}

