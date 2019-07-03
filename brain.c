#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>
#include "boolean.h"  //header for boolean (true false) statement
#include "header.h"   //header for opening program
#include "listsingle.c"	// linked list data structure header,i used listsingle as the variant of linked list structure that contain 1 head(entry point) 
#include "game.c" //contain functions and procedure to support this main program
int main (){
  
	opening();	//display opening screen brain challenge 

  	List L; 	//define List
  	CreateList(&L);
	int i,jawaban,benar=0,pilih;	/*i 	, variable to count the number of scene
									  benar , variable that contains number of scene that player can solve(true)
                          			  pilih , variable of option that contains if 1 is chosen means game is going to play
									             	2 is chosen means open help() function or how to play 
													3 to exit the game
									*/		
	char name[10];						
	address P;						// P , linked list variable that contains jawaban variables that has been allocated 
	
  	
a: // goto statement
	srand(time(NULL)); //makes use of the computer's internal clock to control the choice of the seed. 
	printf("\t\t\t-----Brain Challange------\n");
	printf("\t\t\t[1]Main\n" );
	printf("\t\t\t[2]Help\n" );
	printf("\t\t\t[0]Keluar\n\n" );
	printf("\t\t\tPilihan : ");
	scanf("  %d",&pilih );
  	fflush(stdin);
	system("cls");

/*Option 1 to play*/
	if (pilih==2){
		Help(); // Calling the games procedure 
		system("pause"); // give a delay to continue
		system("cls"); 
		goto a; // back to start
	}else if(pilih==0){
		exit;
	}else if (pilih==1){
    	/*--------------------------Game start--------------------------*/

    	//display 3 first scene to remember with delay
		for (i=1;i<=3;i++){
			Scene(i,&L);	//procedure to generate the symbols
		}
	
		while (true){
			printf("Berapa Jumlah '*' yang muncul pada scene ke-%d ?\n",i);
			printf("Jawaban : " );
			scanf("%d",&jawaban);
			system("cls");
			/*if answer is True,counting the number of true answer by player and save as entry point from the linked list
			  if False , stop the game*/
			if (jawaban==Info(First(L))){
				benar++;
				Scene(i,&L); //display next scene
				i++;	
				P=First(L);
				DelFirst(&L,&P);
			}else{
				break;
			}
		}
		/*the game is over,then print the last score of player .The last score is the number of scenes that player can solve*/
		printf("Score yang anda dapatkan adalah %d\n",benar);
		system("pause"); 
/*~~~~~~~~~~~~~~~~~~~~~Game ended~~~~~~~~~~~~~~~~~~~~*/

  	}else{
    	goto a; 
  	}
  	ending();
}
