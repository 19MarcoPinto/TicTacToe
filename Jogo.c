#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<locale.h>
#include <windows.h>
#include<time.h>
#include <conio.h>

char t[3][3];

void setFullScreen() {
	keybd_event(VK_MENU, 0x36, 0, 0); // Pressiona a tecla Alt
	keybd_event(VK_RETURN, 0x1C, 0, 0); // Pressiona a tecla Enter
	keybd_event(VK_RETURN, 0x1C, KEYEVENTF_KEYUP, 0); // Solta a tecla Enter
	keybd_event(VK_MENU, 0x38, KEYEVENTF_KEYUP, 0); // Solta a tecla Alt
}
void maiszoom()
{
		keybd_event(VK_CONTROL, 0, 0, 0);
		keybd_event(VK_ADD, 0, 0, 0);
		keybd_event(VK_ADD, 0, KEYEVENTF_KEYUP, 0);
		keybd_event(VK_CONTROL, 0, KEYEVENTF_KEYUP, 0);
}
void menoszoom()
{
		keybd_event(VK_CONTROL, 0, 0, 0);
		keybd_event(VK_SUBTRACT, 0, 0, 0);
		keybd_event(VK_SUBTRACT, 0, KEYEVENTF_KEYUP, 0);
		keybd_event(VK_CONTROL, 0, KEYEVENTF_KEYUP, 0);
}

void inicializart()
{
	int i, j;
	for (i = 0; i < 3; i++)
		for (j = 0; j < 3; j++)
			t[i][j] = ' ';
}

void startmenu()
{
	int a,c=0;
	do {maiszoom(); c++;} while (c <= 42);c = 0;
	while (!_kbhit()) {
		printf("\n\n");
		system("color a");
		printf(" *****************************************\n");
		Sleep(250);
		system("color b");
		printf(" *                                       *\n");
		Sleep(250);
		system("color c");
		printf(" *             JOGO DO GALO              *\n");
		Sleep(250);
		system("color d");
		printf(" *                                       *\n");
		Sleep(250);
		system("color e");
		printf(" *****************************************\n");
		Sleep(250);
		system("color a");
		printf("\n\n\n");
		printf("Precione qualquer tecla!");
		Sleep(750);
		system("cls");
	}
	system("color a");
	do { menoszoom(); c++; } while (c <= 42);c = 0;
}
int menu(int *returnarinicio, int *returnartuturial, int *repetirjogo)
{
	int select, invalidoption;
	
	setlocale(LC_ALL, "Portuguese");

	do {
		invalidoption = 0;
		system("cls");
		printf("\n________MENU________\n\n\n");
		printf("0- Sair\n");
		printf("1- Returnar inicio \n");
		printf("2- Ver tuturial \n");
		printf("3- Novo jogo 1 Vs 1\n");

		printf("Escolha uma opção : ");
		scanf("%d", &select);

		switch (select)
		{
		case 0:
			exit(1);
		case 1:
			*returnarinicio = 1;
			*returnartuturial = 0;
			*repetirjogo = 0;
			system("cls");
			break;
		case 2:
			*returnarinicio = 0;
			*returnartuturial = 1;
			*repetirjogo = 0;
			system("cls");
			break;
		case 3:
			*returnarinicio = 0;
			*returnartuturial = 0;
			*repetirjogo = 1;
			system("cls");
			break;
		default: invalidoption = 1;
			break;
		}
	} while (invalidoption == 1);
}

void exemplojogo()
{
	setlocale(LC_ALL, "Portuguese");
	printf("  1 | 2  | 3 \n");
	printf(" ---|--- |---\n");
	printf("  4 | 5  | 6      <--- tabuleiro \n");
	printf(" ---|--- |---\n");
	printf("  7 | 8  | 9 \n");
	printf("Vez do X \n Digite a posição:  \n Você deve digitar a posição entre (1 e 9) onde pretende efetura a jogada! \n");
}

void telatuturial()
{
	int c=0;
	setlocale(LC_ALL, "Portuguese");
	int a;
	printf("Deseja ver o tuturial ? \n Digite 1 (sim) ou 0 (não): ");
	scanf("%d", &a);
	system("cls");
	switch (a)
	{
	case 1:
		printf("\n");
		printf(" *****************************************\n");
		printf(" *                                       *\n");
		printf(" *             JOGO DO GALO              *\n");
		printf(" *                                       *\n");
		printf(" *****************************************\n");
		printf("\n Tabuleiro: O jogo é jogado em um tabuleiro de 3x3. \n \n Jogadores: Existem dois jogadores.\n Um representa o símbolo x e o outro representa o símbolo O. \n \n Objetivo: O objetivo é ser o primeiro a formar uma linha de três símbolos iguais,\n seja na horizontal, vertical ou diagonal. \n \n Turnos: Os jogadores se revezam para colocar seus símbolos em uma das nove células vazias do tabuleiro. \n \n Vencedor: O primeiro jogador a alinhar três símbolos iguais ganha o jogo. \n \n Empate: Se todas as nove células forem preenchidas e nenhum jogador tiver alinhado três símbolos iguais\n o jogo termina em empate. \n \n É um jogo rápido e divertido que testa a capacidade de antecipar os movimentos do oponente. \n \n Boa sorte e divirta-se jogando! \n \n \n");
		system("pause");
		system("cls");
		exemplojogo();
		system("pause");
		system("cls");
		break;
	case 0:system("cls"); break;
	}
}

void tabuleiro()
{
	printf(" %c | %c | %c\n", t[0][0], t[0][1], t[0][2]);
	printf("---|---|---\n");
	printf(" %c | %c | %c\n", t[1][0], t[1][1], t[1][2]);
	printf("---|---|---\n");
	printf(" %c | %c | %c\n", t[2][0], t[2][1], t[2][2]);
}

void marcaX()
{
	int invalid = 0,place,i, j;
	setlocale(LC_ALL, "Portuguese");
	do
	{
		printf("Vez do X \n");
		
		invalid = 0;

		printf("Digite a posição: ");
		scanf("%d", &place);
		
		switch (place)
		{
		case 1:
			i = 0;
			j = 0;
			break;
		case 2:
			i = 0;
			j = 1;
			break;
		case 3:
			i = 0;
			j = 2;
			break;
		case 4:
			i = 1;
			j = 0;
			break;
		case 5:
			i = 1;
			j = 1;
			break;
		case 6:
			i = 1;
			j = 2;
			break;
		case 7:
			i = 2;
			j = 0;
			break;
		case 8:
			i = 2;
			j = 1;
			break;
		case 9:
			i = 2;
			j = 2;
			break;
		default :
			invalid = 1;
			break;
		}
		
		if (t[i][j] != ' ' || invalid == 1)
		{
			system("cls");
			tabuleiro();
		}
	} while (t[i][j] != ' ' || invalid == 1 );
	
	t[i][j] = 'X';
}
void marcaO()
{
	int invalid = 0, place, i, j;
	setlocale(LC_ALL, "Portuguese");
	do
	{
		printf("Vez do O \n");

		invalid = 0;

		printf("Digite a posição: ");
		scanf("%d", &place);

		switch (place)
		{
		case 1:
			i = 0;
			j = 0;
			break;
		case 2:
			i = 0;
			j = 1;
			break;
		case 3:
			i = 0;
			j = 2;
			break;
		case 4:
			i = 1;
			j = 0;
			break;
		case 5:
			i = 1;
			j = 1;
			break;
		case 6:
			i = 1;
			j = 2;
			break;
		case 7:
			i = 2;
			j = 0;
			break;
		case 8:
			i = 2;
			j = 1;
			break;
		case 9:
			i = 2;
			j = 2;
			break;
		default:
			invalid = 1;
			break;
		}

		if (t[i][j] != ' ' || invalid == 1)
		{
			system("cls");
			tabuleiro();
		}
	} while (t[i][j] != ' ' || invalid == 1);

	t[i][j] = 'O';
}

int verificarx()
{
	int i, j,c=0;
	for (i = 0; i < 3; i++) {
		if (c != 3) {
			c = 0;
			for (j = 0; j < 3; j++)
				if (t[i][j] == 'X')
					c++;
		}
	}
	if (c < 3)
	{
		for (j = 0; j < 3; j++)
		{
			if (c != 3) {
				c = 0;
				for (i = 0; i < 3; i++) {
					if (t[i][j] == 'X')
						c++;
				}
			}
		
		}
		if (c<3)
		{
			c = 0;
			if (t[0][0] == t[1][1] && t[2][2] == t[1][1] && t[1][1] == 'X')
				c = 3;
			if (t[0][2] == t[1][1] && t[2][0] == t[1][1] && t[1][1] == 'X')
				c = 3;
		}

	}
	if (c == 3)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}
int verificaro()
{
	int i, j, c = 0;
	for (i = 0; i < 3; i++) {
		if (c != 3) {
			c = 0;
			for (j = 0; j < 3; j++)
				if (t[i][j] == 'O')
					c++;
		}
	}
	if (c < 3)
	{
		for (j = 0; j < 3; j++)
		{
			if (c != 3) {
				c = 0;
				for (i = 0; i < 3; i++)
					if (t[i][j] == 'O')
						c++;
			}
		}
		if (c < 3)
		{
			c = 0;
			if (t[0][0] == t[1][1] && t[2][2] == t[1][1] && t[1][1] == 'O')
				c = 3;
			if (t[0][2] == t[1][1] && t[2][0] == t[1][1] && t[1][1] == 'O')
				c = 3;
		}

	}
	if (c == 3)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}

void main()
{
	setFullScreen();

	int returnarinicio = 1, returnartuturial = 1, repetirjogo = 1, X , O ,contadorjogadas, c=0, scoreboard_X = 0, scoreboard_O = 0, KeepCurrentGame;
	
	do {
		switch (returnarinicio) 
		{
		case 1: startmenu(); menu(&returnarinicio, &returnartuturial, &repetirjogo); break; 
		}
		
		switch (returnartuturial) 
		{
			case 1:
				telatuturial(); 
				exemplojogo();
				menu(&returnarinicio, &returnartuturial, &repetirjogo);
				break;
		}
		
		switch (repetirjogo) 
		{
			case 1: 
				inicializart();
				contadorjogadas = 0;
				X = 0;
				O = 0;
				do {
					system("cls");
					printf("Pontuação:\t X = %d\t O = %d\n\n",scoreboard_X,scoreboard_O);
					tabuleiro();
					marcaX();
					X = verificarx();
					contadorjogadas++;
					
					if (X != 1 && contadorjogadas < 9)
					{
						system("cls");
						printf("Pontuação:\t X = %d\t O = %d\n\n", scoreboard_X, scoreboard_O);
						tabuleiro();
						marcaO();
						O = verificaro();
						contadorjogadas++;
					}
					
				} while (X != 1 && O != 1 && contadorjogadas < 9);
				
				if (X == 1) { scoreboard_X++; }
				if (O == 1) { scoreboard_O++; }
				
				system("cls");
				printf("Deseja continuar com o jogo atual (1(sim) ou 0(não)): ");
				scanf("%d", &KeepCurrentGame);
				system("cls");
				
				if (KeepCurrentGame == 1)
				{
					returnarinicio = 0;
					returnartuturial = 0;
					repetirjogo = 1;
				}
				else
				{
					scoreboard_O = 0;
					scoreboard_X = 0;
					menu(&returnarinicio, &returnartuturial, &repetirjogo);
				}
				break;
				
		}
		
	} while (returnarinicio != 0 || returnartuturial != 0 || repetirjogo != 0);
}