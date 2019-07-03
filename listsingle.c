#include "listsingle.h"
/****************** TEST LIST KOSONG ******************/
boolean IsListEmpty(List L){
  /* Mengirim true jika list kosong */
	return (First(L) == Nil);
}
/****************** PEMBUATAN LIST KOSONG ******************/
void CreateList (List *L){
  /* I.S. sembarang             */
  /* F.S. Terbentuk list kosong */
	First(*L) = Nil;
}

/****************** Manajemen Memori ******************/
address Alokasi (infotype X){
  /* Mengirimkan address hasil alokasi sebuah elemen */
  /* Jika alokasi berhasil, maka address tidak nil, dan misalnya */
  /* menghasilkan P, maka Info(P)=X, Next(P)=Nil */
  /* Jika alokasi gagal, mengirimkan Nil */
	address P;
	P = (address) malloc (sizeof(ElmtList));
	if(P != Nil)
	{
		Info(P) = X;
		Next(P) = Nil;
		return P;
	}
	else
	{
		return Nil;
	}
}

void Dealokasi (address *P){
  /* I.S. P terdefinisi */
  /* F.S. P dikembalikan ke sistem */
  /* Melakukan dealokasi/pengembalian address P */
	free(*P);
}

void InsertFirst (List *L, address P){
  /* I.S. Sembarang, P sudah dialokasi  */
  /* F.S. Menambahkan elemen ber-address P sebagai elemen pertama */
	Next(P) = First(*L);
	First(*L) = P;
}
void InsertAfter (List *L, address P, address Prec){
  /* I.S. Prec pastilah elemen list dan bukan elemen terakhir, */
  /*      P sudah dialokasi  */
  /* F.S. Insert P sebagai elemen sesudah elemen beralamat Prec */
	Next(P) = Next(Prec);
	Next(Prec) = P;
}

void InsertLast (List *L, address P){
  /* I.S. Sembarang, P sudah dialokasi  */
  /* F.S. P ditambahkan sebagai elemen terakhir yang baru */
	address Last;
	if(IsListEmpty(*L))
	{
		InsertFirst(&(*L),P);
	}
	else
	{
		Last  = First(*L);
		while(Next(Last) != Nil)
		{
			Last = Next(Last);
		}
		InsertAfter(&(*L),P,Last);

	}
}

void DelFirst (List *L, address *P){
  /* I.S. List tidak kosong */
  /* F.S. P adalah alamat elemen pertama list sebelum penghapusan */
  /*      Elemen list berkurang satu (mungkin menjadi kosong) */
  /* First element yg baru adalah suksesor elemen pertama yang lama */
	*P = First(*L);
	First(*L) = Next(First(*L));
	Dealokasi(P);
}
