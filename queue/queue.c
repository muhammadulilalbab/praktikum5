#include "queue.h"
#include <stdio.h>

boolean IsEmpty (Queue Q){
/* Mengirim true jika Q kosong: lihat definisi di atas */
	return (Head(Q)==Nil &&Tail(Q)==Nil);
}
boolean IsFull(Queue Q){
/* Mengirim true jika tabel penampung elemen Q sudah penuh */
/* yaitu mengandung elemen sebanyak MaxEl */
	return (NBElmt(Q)==MaxEl(Q));
}
int NBElmt(Queue Q){
/* Mengirimkan banyaknya elemen queue. Mengirimkan 0 jika Q kosong */
	int jumlah;
	if(IsEmpty(Q))
	{
		jumlah =0;
	}else if(Tail(Q)<Head(Q))
	{
			Head(Q)=MaxEl(Q)-Head(Q);
			jumlah = Tail(Q)+ Head(Q)+1;
	}else
	{
		jumlah = Tail(Q)+1-Head(Q);
	}
	return jumlah;
}
/*** Konstruktor/Kreator ***/
void CreateEmpty(Queue *Q, int Max){
/* I.S. sembarang */
/* F.S. Sebuah Q kosong terbentuk dan salah satu kondisi sbb: */
/* Jika alokasi berhasil, Tabel memori dialokasi berukuran Max */
/* atau : jika alokasi gagal, Q kosong dengan MaxEl = 0 */
/* Proses : Melakukan alokasi, membuat sebuah Q kosong */
	(*Q).T=(float *) malloc (sizeof(float)*Max);
	Head(*Q)=Nil;
	Tail(*Q)=Nil;
	MaxEl(*Q) = Max;
}
/*** Destruktor ***/
void DeAlokasi(Queue *Q){
/* Proses: Mengembalikan memori Q */
/* I.S. Q pernah dialokasi */
/* F.S. Q menjadi tidak terdefinisi lagi, MaxEl(Q) diset 0 */
	free((*Q).T);
	(*Q).T=NULL;
	Head(*Q)=Nil;
	Tail(*Q)=Nil;
	MaxEl(*Q) = 0;
	
}
/*** Primitif Add/Delete ***/
void Add (Queue * Q, float X){
/* Proses: Menambahkan X pada Q dengan aturan FIFO */
/* I.S. Q mungkin kosong, tabel penampung elemen Q TIDAK penuh */
/* F.S. X menjadi TAIL yang baru, TAIL "maju" */
/* Jika Tail(Q)=MaxEl maka Tail(Q) diset ke-0  */
	
	if(IsEmpty(*Q)){
		Head(*Q)=0;
		Tail(*Q)=0;
		InfoHead(*Q)=X;
		InfoTail(*Q)=X;
		
		
	}else if(Tail(*Q)>Head(*Q)){
		Tail(*Q)++;
		
		if(Tail(*Q)==MaxEl(*Q))
		{
			Tail(*Q)=0;
			if(Head(*Q)==0)
			{
				Tail(*Q)=MaxEl(*Q)-1;
			}else
			{
				InfoTail(*Q)=X;
			}
		}else{
			InfoTail(*Q)=X;
		}
		
	}else{
		Tail(*Q)++;
		if(Tail(*Q)==Head(*Q))
		{
			Tail(*Q)--;
		}else
		{
			InfoTail(*Q)=X;
		}
		
	}
}
void Del (Queue * Q, float *X){
/* Proses: Menghapus X pada Q dengan aturan FIFO */
/* I.S. Q tidak mungkin kosong */
/* F.S. X = nilai elemen HEAD pd I.S.,HEAD "maju"; Q mungkin kosong */
	if(Head(*Q)==Tail(*Q))
	{
		
		*X =InfoHead(*Q);
		Head(*Q)=Nil;
		Tail(*Q)=Nil;
	}else{
		*X =InfoHead(*Q);
		Head(*Q)++;
		if(Head(*Q)==MaxEl(*Q))
		{
			Head(*Q)=0;
		}
	}
}
/*** Iterate isi Queue ***/
float peek (Queue Q, int i){ 
/* Prekondisi: Q tidak kosong */
/* Menghasilkan nilai Q pada indeks ke-i tanpa mengubah state dari Queue */

	return Q.T[i];
}
void iterate(Queue Q){
/* menuliskan isi Q dari Head ke Tail menggunakan peek */
/* tidak menuliskan apa pun jika S kosong */
/* I.S.: Q terdefinisi */
/* F.S. Isi Q tertulis ke layar dari Head ke Tail dengan dua digit di belakang koma. 
        Setiap elemen dituliskan sebagai satu baris. */
    float lama;
    while(!IsEmpty(Q))
	{
		Del(&Q,&lama);
		printf("%.2f\n",lama);
	}
}

