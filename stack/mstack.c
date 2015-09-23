#include <stdio.h>
#include "stack.h"
#include <string.h>

#define Max 20
boolean operator(char c);
int main()
{
	char * ekspresi;
	int jum, lengthEkspresi,i,j;
	long op1,op2,temphasil;
	Stack S;
	ekspresi = (char *) malloc(sizeof(char)*Max);
	scanf("%d",&jum);
	for(i=0;i<jum;i++)
	{
		scanf("%s",ekspresi);
		lengthEkspresi=strlen(ekspresi);
		CreateEmpty(&S,lengthEkspresi);
		for(j=0;j<lengthEkspresi;j++)
		{
			if(!operator(ekspresi[j]))
			{
				Push(&S,(long)ekspresi[j]-48);
			}else{
				Pop(&S,&op1);
				Pop(&S,&op2);
				switch (ekspresi[j])
				{
					case 37 :
						temphasil = op2%op1;
						break;
					case 42 :
						temphasil = op2*op1;
						break;
					case 43 :
						temphasil = op2+op1;
						break;
					case 45 :
						temphasil = op2-op1;
						break;
					case 47 :
						temphasil = op2/op1;
						break;
				}
				Push(&S,temphasil);
			}
			
		}
		iterate (S);
		Dealokasi(&S);
		
	}
	iterate(S);
	free(ekspresi);
	
	return 0; 
}
boolean operator(char c)
{
	boolean check = false;
	if(c==37 || c== 42 || c==43 || c==45 || c==47)
	{
		check = true;
	}
	return check;
}

