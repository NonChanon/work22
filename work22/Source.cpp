#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<time.h>
#include<windows.h>
struct Card
{
	int PLAYER[2][3];
    int PLAYERDOK[2][3];
}chanonVsBot;


void printNumber(int number) {
	switch (number)
	{
		case 1: printf("A ");  break;
		case 11: printf("J ");  break;
		case 12: printf("Q ");  break;
		case 13: printf("K ");  break;
		default: printf("%d ", number);  break;
	}
}

void printDok(int dok) {
	switch (dok)
	{
		case 0: printf("Heart"); break;
		case 1: printf("Club"); break;
		case 2: printf("Diamond"); break;
		case 3: printf("Spade"); break;
	}
}

int main() {
	srand(time(NULL));
	int sum[2] = {};
	for (int _player = 0; _player < 2; _player++) {
		for (int _noCard = 0; _noCard < 2; _noCard++) {

			chanonVsBot.PLAYER[_player][_noCard] = rand() % 13 + 1;
			chanonVsBot.PLAYERDOK[_player][_noCard] = rand() % 4;

			if (_player == 0) {
				printNumber(chanonVsBot.PLAYER[_player][_noCard]);
				printDok(chanonVsBot.PLAYERDOK[_player][_noCard]);
				printf(" ");
			}

			if (chanonVsBot.PLAYER[_player][_noCard] >= 10)	 sum[_player] += 10;
			else                                 sum[_player] += chanonVsBot.PLAYER[_player][_noCard];

		}
		printf("\n");
		sum[_player] %= 10;
	}

	///////////////////////////////////////////////////////
	for (int _player = 0; _player < 2; _player++) {
		if (_player == 0) { //chanonVsBot.PLAYER
			int wantToDraw = 0;
			printf("If you want to DRAW input 1 else 0 : ");
			scanf("%d", &wantToDraw);
			if (wantToDraw == 1) {
				chanonVsBot.PLAYER[_player][2] = rand() % 13 + 1;
				chanonVsBot.PLAYERDOK[_player][2] = rand() % 4;
				if (chanonVsBot.PLAYER[_player][2] >= 10)	 sum[_player] += 10;
				else                             sum[_player] += chanonVsBot.PLAYER[_player][2];

			}
		}
		else if (_player == 1) { //BOT
			if (sum[_player] >= 5 && rand() % 2 == 1 || sum[_player] < 5) {
				chanonVsBot.PLAYER[_player][2] = rand() % 13 + 1;
				chanonVsBot.PLAYERDOK[_player][2] = rand() % 4;
				if (chanonVsBot.PLAYER[_player][2] >= 10)	 sum[_player] += 10;
				else                             sum[_player] += chanonVsBot.PLAYER[_player][2];
			}
		}

		sum[_player] %= 10;
	}

	for (int _player = 0; _player < 2; _player++) {
		for (int _noCard = 0; _noCard < 3; _noCard++) {

			if(chanonVsBot.PLAYER[_player][_noCard] != 0){
				printNumber(chanonVsBot.PLAYER[_player][_noCard]);
				printDok(chanonVsBot.PLAYERDOK[_player][_noCard]);
				printf(" ");
			}
			
		}
		printf("\n");
	}
	///////////////////////////////////////////////////////
	if (sum[0] > sum[1]) {
		printf("\nPlayer 1 WIN");
	}
	else if (sum[0] < sum[1]) {
		printf("\nPlayer 2 WIN");
	}
	else if (sum[0] == sum[1]) {
		printf("\nDRAW");
	}
}