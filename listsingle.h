#ifndef listsingle_H
#define listsingle_H

#include "boolean.h"
#include <stdio.h>
#include <stdlib.h>

#define Nil NULL

typedef int infotype;
typedef struct tElmtlist *address;
typedef struct tElmtlist {
	infotype info;
	address next;
} ElmtList;
typedef struct {
	address First;
} List;

/* Definisi list : */
/* List kosong : First(L) = Nil */
/* Setiap elemen dengan address P dapat diacu Info(P), Next(P) */
/* Elemen terakhir list : jika addressnya Last, maka Next(Last)=Nil */

#define Info(P) (P)->info
#define Next(P) (P)->next
#define First(L) (L).First

/****************** TEST LIST KOSONG ******************/
boolean IsListEmpty(List L);
/* Mengirim true jika list kosong */
/****************** PEMBUATAN LIST KOSONG ******************/
void CreateList (List *L);
/* I.S. sembarang             */
/* F.S. Terbentuk list kosong */
/****************** Manajemen Memori ******************/
address Alokasi (infotype X);
/* Mengirimkan address hasil alokasi sebuah elemen */
/* Jika alokasi berhasil, maka address tidak nil, dan misalnya */
/* menghasilkan P, maka Info(P)=X, Next(P)=Nil */
/* Jika alokasi gagal, mengirimkan Nil */

void Dealokasi (address *P);
/* I.S. P terdefinisi */
/* F.S. P dikembalikan ke sistem */
/* Melakukan dealokasi/pengembalian address P */

void InsertFirst (List *L, address P);
/* I.S. Sembarang, P sudah dialokasi  */
/* F.S. Menambahkan elemen ber-address P sebagai elemen pertama */

void InsertAfter (List *L, address P, address Prec);
/* I.S. Sembarang, P sudah dialokasi  */
/* F.S. Menambahkan elemen ber-address P sebagai elemen pertama */

void InsertLast (List *L, address P);
/* I.S. Sembarang, P sudah dialokasi  */
/* F.S. P ditambahkan sebagai elemen terakhir yang baru */

void DelFirst (List *L, address *P);
/* I.S. List tidak kosong */
/* F.S. P adalah alamat elemen pertama list sebelum penghapusan */
/*      Elemen list berkurang satu (mungkin menjadi kosong) */
/* First element yg baru adalah suksesor elemen pertama yang lama */

#endif
