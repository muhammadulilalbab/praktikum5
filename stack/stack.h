
/* File: stack.h */
/* IF5021 sem. 1 2014/2015 - Praktikum 06 */
/* Tgl: 9 Oktober 2014 */

/* Implementasi Stack dalam bahasa C dengan alokasi dinamik */ 

#ifndef __STACK_H_
#define __STACK_H_

#include "boolean.h"
#include <stdlib.h>

/* Konstanta */
#define Nil -1     /* Nil adalah stack dengan elemen kosong */

typedef struct {
	long * Data;
	int Top; 
	int MaxEl; 
} Stack;
/* Definisi : Stack kosong adalah Top(S) = Nil */

/* Definisi akses dengan selektor: */
#define Top(S) (S).Top
#define InfoTop(S) (S).Data[(S).Top] 
#define MaxEl(S) (S).MaxEl 

/*** Konstruktor/Kreator ***/
void CreateEmpty (Stack *S, int size); 
/* I.S. S sembarang, size terdefinisi */
/* F.S. Membuat sebuah stack S yang kosong berkapasitas size */ 
/* Ciri stack kosong : Top bernilai Nil */ 

/*** Desktruktor ***/ 
void Dealokasi (Stack *S); 
/* Proses: Mengembalikan memori S */ 
/* I.S. S pernah dialokasi */ 
/* F.S. S menjadi tidak terdefinisi lagi, MaxEl(S) diset 0 */

/*** Predikat Untuk Test Keadaan Koleksi ***/
boolean IsEmpty (Stack S);
/* Mengirim true jika Stack kosong: lihat definisi di atas */
boolean IsFull (Stack S);
/* Mengirim true jika tabel penampung nilai elemen stack penuh */
 
/*** Menambahkan sebuah elemen ke Stack ***/
void Push (Stack *S, long X);
/* Menambahkan X sebagai elemen Stack S. */
/* I.S. S mungkin kosong, tabel penampung elemen stack TIDAK penuh */
/* F.S. X menjadi TOP yang baru, Top bertambah 1 */

/*** Menghapus sebuah elemen Stack ***/
void Pop (Stack *S, long *X);
/* Menghapus X dari Stack S */
/* I.S. S tidak mungkin kosong */
/* F.S. X adalah nilai elemen Top yang lama, Top berkurang 1. 
        S mungkin menjadi kosong. */

/*** Operasi Tambahan ***/
long peek (Stack S, int i); 
/* Prekondisi: S tidak kosong */
/* Menghasilkan nilai S pada indeks ke-i tanpa mengubah state dari Stack */

void iterate (Stack S);
/* menuliskan isi S dari Top ke 0 dengan menggunakan peek */
/* tidak menuliskan apa pun jika S kosong */
/* I.S.: S terdefinisi */
/* F.S. Isi S tertulis ke layar dari Top ke 0. Setiap elemen dituliskan sebagai satu baris. */

#endif
