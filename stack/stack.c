#include <stdio.h>
#include "stack.h"
void CreateEmpty (Stack *S, int size){
/* I.S. S sembarang, size terdefinisi */
/* F.S. Membuat sebuah stack S yang kosong berkapasitas size */ 
/* Ciri stack kosong : Top bernilai Nil */ 
	(*S).Data=(long *)malloc(sizeof(long)*size);
	Top(*S)=Nil;
	MaxEl(*S)= size;
	
}

/*** Desktruktor ***/ 
void Dealokasi (Stack *S){
/* Proses: Mengembalikan memori S */ 
/* I.S. S pernah dialokasi */ 
/* F.S. S menjadi tidak terdefinisi lagi, MaxEl(S) diset 0 */
	free((*S).Data);
	(*S).Data=NULL;
	MaxEl(*S)=0;
	Top(*S)=Nil;
}
/*** Predikat Untuk Test Keadaan Koleksi ***/
boolean IsEmpty (Stack S){
/* Mengirim true jika Stack kosong: lihat definisi di atas */
	return (Top(S) == Nil);
}
boolean IsFull (Stack S){
/* Mengirim true jika tabel penampung nilai elemen stack penuh */
	return (Top(S) == S.MaxEl-1);
}

/*** Menambahkan sebuah elemen ke Stack ***/
void Push (Stack *S, long X){
/* Menambahkan X sebagai elemen Stack S. */
/* I.S. S mungkin kosong, tabel penampung elemen stack TIDAK penuh */
/* F.S. X menjadi TOP yang baru, Top bertambah 1 */
	(*S).Top++;
	InfoTop(*S)=X;
		
}

/*** Menghapus sebuah elemen Stack ***/
void Pop (Stack *S, long *X){
/* Menghapus X dari Stack S */
/* I.S. S tidak mungkin kosong */
/* F.S. X adalah nilai elemen Top yang lama, Top berkurang 1. 
        S mungkin menjadi kosong. */
	(*X)=InfoTop(*S);
	Top(*S)--;
		       
}
/*** Operasi Tambahan ***/
long peek (Stack S, int i){
/* Prekondisi: S tidak kosong */
/* Menghasilkan nilai S pada indeks ke-i tanpa mengubah state dari Stack */
	return S.Data[i];
}
void iterate (Stack S){
/* menuliskan isi S dari Top ke 0 dengan menggunakan peek */
/* tidak menuliskan apa pun jika S kosong */
/* I.S.: S terdefinisi */
/* F.S. Isi S tertulis ke layar dari Top ke 0. Setiap elemen dituliskan sebagai satu baris. */
	
	long isi;
    while(!IsEmpty(S))
	{
		Pop(&S,&isi);
		printf("%ld\n",isi);
	}
}
