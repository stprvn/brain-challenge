#include "game.h"
#include<string.h>

void timer ( int sec ) {
	clock_t wait_till_end;
	wait_till_end = clock () + sec * CLOCKS_PER_SEC ;
	while (clock() < wait_till_end) {}
}

void Help(){
  printf("\t\t\tPetunjuk Permainan\n");
  printf("1. Pemain diminta untuk mengingat jumlah simbol '*' yang muncul \n");
	printf("   pada suatu scene\n");
  printf("2. Pada awal permainan akan diberikan 3 scene yang \n");
	printf("   masing masing memuat 15 simbol\n");
  printf("3. Setiap Scene akan diberikan waktu 5 detik untuk menghitung \n" );
	printf("   jumlah '*' yang muncul\n");
  printf("4. Setelah diawali dengan menampilkan 3 scene, pemain selanjutnya \n" );
	printf("   diberikan pertanyaan jumlah '*' yang muncul pada scene pertama\n");
	printf("5. Jika jawaban benar, maka akan dimunculukan scene berikutnya , \n");
  printf("   dan diberikan pertanyaan jumlah '*' pada scene kedua dan selanjutnya\n");
	printf("   jika salah maka permainan berakhir\n");
	printf("\n");
}

void Scene(int num, List *L){
  int i,sum=0;
  /*Berguna Untuk menampilkan scene dan memasukan jawaban ke link list*/
	/*Num berfungsi untuk menampilkan scene ke-num*/
	/*Sum berfungsi untuk menghitung banyaknya bintang dan memasukkan sum dengan
	InsertLast*/
	/*timer() memanggil fungsi timer yang digunakan untuk countdown per-scene*/
	if (num==15){
		//Ketika masuk ke scene ke-15 maka permaian akan masuk ke Stage 2
		//Stage 2 menampilkan 15 simbol dengan waktu countdown 3 detik
		printf("\n\n\n\t\t\t\t    Stage 2\n");
		printf("\t\t\t         Level Medium\n");
		timer(3);
		system("cls");
	}else if(num==30){
		//Ketika masuk ke scene ke-30 maka permaian akan masuk ke Stage 3
		//Stage 3 menampilkan 20 simbol dengan waktu countdown 3 detik
		printf("\n\n\n\t\t\t\t    Stage 3\n");
		printf("\t\t\t           Level Hard\n");
		timer(3);
		system("cls");
	}
  	printf("\t\t\t\tScene %d\n\n",num);

	if (num>=30){//Level diatas 30
		for (i=0;i<20;i++){
	    char simbol = "*$+/-%"[rand () % 6];//rand() Berguna untuk merandom char
	    printf("%c ",simbol);
	    if(simbol=='*'){
	      sum++;
	    }
	  }
	}else {//Level dibawah 30
		for (i=0;i<15;i++){
	    char simbol = "*$+/-%"[rand () % 6];//rand() Berguna untuk merandom char
	    printf("%c ",simbol);
	    if(simbol=='*'){
	      sum++;
	    }
	  }
	}
	printf("\n" );
	printf("\n\nNote : Ingatlah Jumlah '*' Pada Scene Ini\n" );
  InsertLast(L,Alokasi(sum)); //Sum di alokasi dan dimasukkan di Last
	if (num<15){//level dibawah 15
		timer(5);
	}else{//Level diatas 15
		timer(3);
	}
	system("cls");
}
