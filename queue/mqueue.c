#include <stdio.h>
#include "queue.h"
float AvgElmt (Queue Q);
int main()
{
	Queue Q;
	
	int pilihan,N;
	float lama;
	scanf("%d",&N);
	CreateEmpty(&Q, N);
	do{
		scanf("%d",&pilihan);
		if(pilihan==1)
		{
			scanf("%f",&lama);
			if(!IsFull(Q)){
				Add(&Q,lama);
			}
		}else if(pilihan==2)
		{
			if(!IsEmpty(Q))
			{
				Del(&Q,&lama);
			}
		
		}
	}while(pilihan!=0);
	printf("%d\n",NBElmt(Q));
	if(!IsEmpty(Q))
	{
		printf("%.2f\n",AvgElmt(Q));
	}else{
		printf("Tidak bisa dihitung\n");
	}
	return 0;
}
float AvgElmt (Queue Q){
	float total=0,avg=0,lama;
	int sum = NBElmt(Q);
	while(!IsEmpty(Q))
	{
		Del(&Q,&lama);
		total=total+lama;
	}
	avg = (float) total/sum;
	return avg;
}
