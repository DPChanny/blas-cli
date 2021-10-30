#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include"line.h"
#include"function.h"

extern Line L_scripts[256];
extern int I_varriable[256];

int printScriptMenu();
void printScripts();
void resetScripts();
void resetVarriable();

void scriptConsole() {
	while (1) {
		system("cls");
		int selection = printScriptMenu();

		if (selection == 1) {
			system("cls");
			printScripts();
		}
		else if (selection == 2) {
			system("cls");
			resetScripts();
		}
		else if (selection == 3) {
			system("cls");
			resetVarriable();
		}
		else if (selection == 4) {
			break;
		}
		else {
			continue;
		}
	}
}

int printScriptMenu() {
	int selection = 0;

	printf("Script Menu (BLAS v.1.1)\n\n");
	printf("select to do\n");
	printf("\t1: print scripts\n");
	printf("\t2: reset scripts\n");
	printf("\t3: reset varriable\n");
	printf("\t4: exit\n\n");
	printf("answer: ");

	scanf_s("%d", &selection);
	rewind(stdin);

	return selection;
}

void printScripts() {
	int i = 0;
	for (i = 0; i < 256; i++) {
		if (L_scripts[i].I_lineNumber != 0) {
			printf("\t %s %s %s %s %s %s %s %s %s\n",
				L_scripts[i].C_lineNumber,
				L_scripts[i].C_functionCode,
				L_scripts[i].C_I_varriableCode1,
				L_scripts[i].C_logicFunctionCode,
				L_scripts[i].C_I_varriableCode2,
				L_scripts[i].C_O_varriableCode,
				L_scripts[i].C_IO_functionCode,
				L_scripts[i].C_IO_varriableCode,
				L_scripts[i].C_nextFunctionCode);
		}
		
	}
	wait();
}

void resetScripts() {
	printf("initializing script and functions\n");
	printf("completed\n\n");
	wait();
}

void resetVarriable() {
	printf("initializing varriable\n");
	memset(I_varriable, 0, 256);
	printf("completed\n\n");
	wait();
}