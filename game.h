#ifndef game_H
#define game_H

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "listsingle.h"

void timer ( int sec );
/*Untuk Memberikan delay tiap scene*/
	//Fungsi yang digunakan untuk countdown digunakan pada scene
void Help();
/*Menampilkan Cara Bermain Game Brain Challange*/


void Scene(int num, List *L);
/*Berguna Untuk menampilkan scene dan memasukan jawaban ke link list*/

#endif
