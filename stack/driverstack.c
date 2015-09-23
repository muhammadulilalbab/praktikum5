#include "stack.h"
#include <stdio.h>
int main()
{
	Stack S;
	int i,ukuran = 4;
	long data;
	CreateEmpty(&S,ukuran);
	for(i=0;i<ukuran;i++){
		scanf("%ld",&data);
		Push(&S,data);
	}
	iterate(S);
	printf("top stack %d\n",Top(S));
	printf("max element %d\n",MaxEl(S));
	for(i=0;i<ukuran;i++){
		
		Pop(&S,&data);
		printf("%ld\n",data);
	}
	data = peek(S, 3);
	printf("peek %ld\n",data);
	return 0;
}
