//Connect 4 Game made by Saitama Techno

#include <stdio.h>
char map[6][7];

char showmap(void){
	printf("\n\t\t1 2 3 4 5 6 7");
	for (int i=0; i<6; i++){
			printf("\n\t\t");
				for (int a=0; a<7; a++){
					printf("%c ", map[i][a]);
				}
		
		}
	printf("\n\n");
}
int horizontal_check(int a, int start, int end, char signal){
	int s=0;
	for (int f=start; f<end; f++){
		if(map[a][f] == signal){s += 1;}
	}
	if (s==4){return 1;}
	else{return 0;}	
}
int vertical_check(int a, int start, int end, char signal){
	int s=0;
	for (int f=start; f<end; f++){
		if (map[f][a] == signal){s+=1;}
	}
	if (s==4){return 1;}
	else{return 0;}	
}
int right_diagonal_check(int x1, int y1, char signal){
	int s=0; int x2, y2;
	x1-=1; y1-=1;
	for (int i=0; i<4; i++){
		if (map[y1][x1]==signal){
			s+=1;		
		}
		x1+=1;
		y1-=1;
	}
	//printf("diag_s=%d", s);
	if (s==4){return 1;}
	else{return 0;}
}
int left_diagonal_check(int x1, int y1, char signal){
	int s=0; int x2, y2;
	x1-=1; y1-=1;
	for (int i=0; i<4; i++){
		if (map[y1][x1]==signal){
			s+=1;		
		}
		x1+=1;
		y1+=1;
	}
	//printf("diag_s=%d", s);
	if (s==4){return 1;}
	else{return 0;}
}
int draw_check(){
	int number=0;
	for (int i=0; i<6; i++){
				for (int a=0; a<7; a++){
					if(map[i][a]!='O'){
						number+=1;
					}
				}
		
		}
	if (number==42){return 1;}
	else{return 0;}
}
int check_winner(){
//-1:continue, 0: draw, 1: winner player1, 2: winner player2
	int p1 = 0, p2 = 0;
	for (int i=5; i>-1; i--){
		if (horizontal_check(i, 0, 4, '#') || horizontal_check(i, 1, 5, '#') || horizontal_check(i, 2, 6, '#') || horizontal_check(i, 3, 7, '#')){return 1;}
		if (horizontal_check(i, 0, 4, '&') || horizontal_check(i, 1, 5, '&') || horizontal_check(i, 2, 6, '&') || horizontal_check(i, 3, 7, '&')){return 2;}
		}
	for (int i=0; i<7; i++){
		if (vertical_check(i, 0, 4, '#') || vertical_check(i, 1, 5, '#') || vertical_check(i, 2, 6, '#')){return 1;}
		if (vertical_check(i, 0, 4, '&') || vertical_check(i, 1, 5, '&') || vertical_check(i, 2, 6, '&')){return 2;}
	}
	int x=1, y=4;
	while (x<5){
	if (right_diagonal_check(x, y, '#') == 1){return 1;}
	if (right_diagonal_check(x, y, '&') == 1){return 2;}
	y+=1;
	if (y==7){x+=1; y=4;}
	}
	x=1; y=1;
	while (x<5){
	if (left_diagonal_check(x, y, '#') == 1){return 1;}
	if (left_diagonal_check(x, y, '&') == 1){return 2;}
	y+=1;
	if (y==4){x+=1; y=1;}
	}
	if (draw_check()==1){return 0;}
	return -1;
}

int main(void){
	for (int i=0; i<6; i++){
		for (int a=0; a<7; a++){
			map[i][a] = 'O';
		}
	}
	showmap();
	char letter;
	int game=1, x=6, player1=1; int y;
	printf("Connect 4 Game Started!\n");
	while (game == 1){
		if (player1 == 1){
			printf("Player1, enter (number, letter) coordinates to put '#'\n");}
		else{
			printf("Player2, enter (number, letter) coordinates to put '&'\n");}
		scanf("%d", &y);
		while (map[x-1][y-1]!='O'){
			x-=1;
			if (x == 0){
				printf("This column is full, try another location:\n");
				scanf("%d", &y);
				x=6;
			}
		}
		if (player1==1){
			map[x-1][y-1]='#';
			player1=0;
		}
		else{
			map[x-1][y-1]='&';
			player1=1;
		}
		showmap();
		if (check_winner() != -1){
			printf("Game Over!\n");
			game=0;
		}
		x=6;
			
	}
	if (check_winner()!=0){
	printf("Winner is Player%d", check_winner());
	}
	else{printf("Draw!");}
}