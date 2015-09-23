/* File : queue.h */
/* Tgl: 9 Oktober 2014 */

/* Versi I : tabel dinamik, Head dan Tail eksplisit, ukuran disimpan */
/* Queue diimplementasikan dengan buffer sirkular */

#ifndef _QUEUE_H_
#define _QUEUE_H_

#include "boolean.h"
#include <stdlib.h>

/* Konstanta */
#define Nil -1

typedef struct { float *T;   /* tabel penyimpan elemen */
                 int HEAD;   /* alamat penghapusan */
                 int TAIL;   /* alamat penambahan */
                 int MaxEl;  /* Max elemen queue */
               } Queue;
/* Definisi Queue kosong: HEAD=Nil; TAIL=Nil. */ 

/*** AKSES (Selektor) ***/
/* Jika Q adalah Queue, maka akses elemen : */
#define Head(Q) (Q).HEAD
#define Tail(Q) (Q).TAIL
#define InfoHead(Q) (Q).T[(Q).HEAD]
#define InfoTail(Q) (Q).T[(Q).TAIL]
#define MaxEl(Q) (Q).MaxEl 

boolean IsEmpty (Queue Q);
/* Mengirim true jika Q kosong: lihat definisi di atas */
boolean IsFull(Queue Q);
/* Mengirim true jika tabel penampung elemen Q sudah penuh */
/* yaitu mengandung elemen sebanyak MaxEl */
int NBElmt(Queue Q);
/* Mengirimkan banyaknya elemen queue. Mengirimkan 0 jika Q kosong */

/*** Konstruktor/Kreator ***/
void CreateEmpty(Queue *Q, int Max);
/* I.S. sembarang */
/* F.S. Sebuah Q kosong terbentuk dan salah satu kondisi sbb: */
/* Jika alokasi berhasil, Tabel memori dialokasi berukuran Max */
/* atau : jika alokasi gagal, Q kosong dengan MaxEl = 0 */
/* Proses : Melakukan alokasi, membuat sebuah Q kosong */

/*** Destruktor ***/
void DeAlokasi(Queue *Q);
/* Proses: Mengembalikan memori Q */
/* I.S. Q pernah dialokasi */
/* F.S. Q menjadi tidak terdefinisi lagi, MaxEl(Q) diset 0 */

/*** Primitif Add/Delete ***/
void Add (Queue * Q, float X);
/* Proses: Menambahkan X pada Q dengan aturan FIFO */
/* I.S. Q mungkin kosong, tabel penampung elemen Q TIDAK penuh */
/* F.S. X menjadi TAIL yang baru, TAIL "maju" */
/* Jika Tail(Q)=MaxEl maka Tail(Q) diset ke-0  */
void Del (Queue * Q, float *X);
/* Proses: Menghapus X pada Q dengan aturan FIFO */
/* I.S. Q tidak mungkin kosong */
/* F.S. X = nilai elemen HEAD pd I.S.,HEAD "maju"; Q mungkin kosong */

/*** Iterate isi Queue ***/
float peek (Queue Q, int i); 
/* Prekondisi: Q tidak kosong */
/* Menghasilkan nilai Q pada indeks ke-i tanpa mengubah state dari Queue */
void iterate(Queue Q);
/* menuliskan isi Q dari Head ke Tail menggunakan peek */
/* tidak menuliskan apa pun jika S kosong */
/* I.S.: Q terdefinisi */
/* F.S. Isi Q tertulis ke layar dari Head ke Tail dengan dua digit di belakang koma. 
        Setiap elemen dituliskan sebagai satu baris. */

#endif
