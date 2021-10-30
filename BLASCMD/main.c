/*
This is BLAS, interpreter of RED

About Varriable Name
	I = Input
	O = Output
	IO = Input/Output
	I = Int
	C = Char
	type_i/o_name
	EX): C_I_VarriableCode1 = Char Input Varriable Code 1

BLAS: function code
	BLAS: /.////./ bin: 01000010 dec: 66 logic: not
	BLAS: ..////.. bin: 11000011 dec: 195 logic: and
	BLAS: .//////. bin: 10000001 dec: 129 logic: or
	BLAS: ././/./. bin: 10100101 dec: 165 logic: xor
	BLAS: ././././ bin: 10101010 dec: 170 logic: flip-flop
	BLAS: ......./ bin: 11111110 dec: 254 logic: out
	BLAS: /....... bin: 01111111 dec: 127 logic: in
	BLAS: //////// bin: 00000000 dec: 0   logic: null
	BLAS: ...//... bin: 11100111 dec: 231 logic: set function varriable

BLAS: command style
(line number)(function code) (input varriable 1 code) (logic function) (input varriable 2 code) (output varrialbe code) (i/o function code) (i/o varriable code) (next function code)

Programmed By DPC0516
*/

#include<stdio.h>
#include<stdlib.h>
#include"line.h"

//varriable declare
int I_varriable[256] = { 0, }; //saved varriables
int I_functions[256][2] = { {0, 1}, }; //saved functions
Line L_scripts[1000];

//function declare
int printMainMenu();

extern void mainConsole();
extern void scriptConsole();
extern void functionConsole();

int main() {
	while (1) {
		system("cls");
		int selection = printMainMenu();

		if (selection == 1) {
			system("cls");
			mainConsole();
		}
		else if (selection == 2) {
			system("cls");
			functionConsole();
		}
		else if (selection == 3) {
			system("cls");
			scriptConsole();
		}
		else if (selection == 4) {
			break;
		}
		else {
			continue;
		}
	}
}

int printMainMenu() {
	int selection = 0;

	printf("Main Menu (BLAS v.1.1)\n\n");
	printf("select console\n");
	printf("\t1: main console\n");
	printf("\t2: function console\n");
	printf("\t3: script console\n");
	printf("\t4: exit\n\n");
	printf("answer: ");

	scanf_s("%d", &selection);
	rewind(stdin);

	return selection;
}