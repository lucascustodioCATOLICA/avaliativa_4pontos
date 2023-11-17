#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <time.h>
#include <stdlib.h>

#define LIST_LIMIT 999

typedef struct Car {
	char owner[64];	
	char gasType[12]; // alcool, diesel ou gasolina
	char model[64];	
	char color[64];	
	int numChassi;
	int year;
	char placa[8];	
} Car;

typedef struct Node {
	Car data;
    struct Node *next;
} Node;

int userListIndex = 0;

void clearScreen()
{
  const char *CLEAR_SCREEN_ANSI = "\e[1;1H\e[2J";
  write(STDOUT_FILENO, CLEAR_SCREEN_ANSI, 12);
}

Node* initiateList () {
    srand(time(NULL));

	Node *one = malloc(sizeof(Node));
    strcpy(one->data.owner, "Jureba Souza");
    strcpy(one->data.gasType, "alcool");
    strcpy(one->data.model, "Ford K");
    strcpy(one->data.color, "Branco");
    strcpy(one->data.placa, "ASD1324");
    one->data.year = 2000;
    one->data.numChassi = rand();
	Node *sec = malloc(sizeof(Node));
    strcpy(sec->data.owner, "Jorge Caramelo");
    strcpy(sec->data.gasType, "diesel");
    strcpy(sec->data.model, "Chevrolet Camaro");
    strcpy(sec->data.color, "Amarelo");
    strcpy(sec->data.placa, "KRD5947");
    sec->data.year = 2010;
    sec->data.numChassi = rand();
	Node *third = malloc(sizeof(Node));
    strcpy(third->data.owner, "Xandao Jeremias");
    strcpy(third->data.gasType, "gasolina");
    strcpy(third->data.model, "Fiat Toro");
    strcpy(third->data.color, "Vermelho");
    strcpy(third->data.placa, "GFF4535");
    third->data.year = 2020;
    third->data.numChassi = rand();
	Node *four = malloc(sizeof(Node));
    strcpy(four->data.owner, "Ana Marvada");
    strcpy(four->data.gasType, "alcool");
    strcpy(four->data.model, "Fiat Punto");
    strcpy(four->data.color, "Preto");
    strcpy(four->data.placa, "FFS1423");
    four->data.year = 2016;
    four->data.numChassi = rand();
	Node *five = malloc(sizeof(Node));
    strcpy(five->data.owner, "Matheus Luis");
    strcpy(five->data.gasType, "gasolina");
    strcpy(five->data.model, "Ford Focus");
    strcpy(five->data.color, "Branco");
    strcpy(five->data.placa, "GSL1423");
    five->data.year = 2016;
    five->data.numChassi = rand();

    one->next = sec;
    sec->next = third;
    third->next = four;
    four->next = five;
    five->next = NULL;

    return one;
}


void handleReadAll (Node *liskedListHead) {
	printf("--- DEBUG --- \n\n");

    Node *index = liskedListHead;
	while(index != NULL) {
        printf("%s \n", index->data.owner);
        index = index->next;
    }
}

void handleA (Node *liskedListHead) {}
void handleB (Node *liskedListHead) {}
void handleC (Node *liskedListHead) {}
void handleD (Node *liskedListHead) {}

void handleInput (Node *liskedListHead) {
	char input;
	scanf("%s", &input);
	getchar();

	switch (input)
	{
	case 'A':
	case 'a':
		handleA(liskedListHead);
		break;
	case 'B':
	case 'b':
		handleB(liskedListHead);
		break;
	case 'C':
	case 'c':
		handleC(liskedListHead);
		break;
	case 'D':
	case 'd':
		handleD(liskedListHead);
		break;
	default:
		break;
	}
}

int main () {
	Node* liskedListHead = initiateList();
    handleReadAll(liskedListHead);

	while (1) {
		printf("--- \n");
		printf("A - lista todos os proprietários cujos carros são do ano de 2010 ou posterior e que sejam movidos a diesel \n");
		printf("B - lista todas as placas que comecem com a letra J e terminem com 0, 2, 4 ou 7 e seus respectivos proprietários \n");
		printf("C - lista o modelo e a cor dos veículos cujas placas possuem como segunda letra uma vogal e cuja soma dos valores numéricos fornece um número par \n");
		printf("D - troca de proprietário com o fornecimento do número do chassi apenas para carros com placas que não possuam nenhum dígito igual a zero \n");
		printf("Ctrl/C - SAIR \n");

		handleInput(liskedListHead);
	}


	return 0;
}
