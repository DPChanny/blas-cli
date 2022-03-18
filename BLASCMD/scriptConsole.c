#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include"line.h"
#include"function.h"
#include"command.h"

extern Line L_scripts[1000];
extern int I_varriable[256];
extern int I_functions[256][2];

int printScriptMenu();
void printScripts();
void resetScripts();
void resetVarriable();
void printVarriable();
void printFunctions();
void saveScripts();
void loadScripts();

void scriptConsole() {
	while (1) {
		system("cls");
		int selection = printScriptMenu();

		if (selection == 1) {
			system("cls");
			printVarriable();
		}
		else if (selection == 2) {
			system("cls");
			printFunctions();
		}
		else if (selection == 3) {
			system("cls");
			printScripts();
		}
		else if (selection == 4) {
			system("cls");
			resetVarriable();
			wait();
		}
		else if (selection == 5) {
			system("cls");
			resetScripts();
			wait();
		}
		else if (selection == 6) {
			system("cls");
			saveScripts();
		}
		else if (selection == 7) {
			system("cls");
			loadScripts();
		}
		else if (selection == 8) {
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
	printf("\t1: print varriable\n");
	printf("\t2: print functions\n");
	printf("\t3: print scripts\n");
	printf("\t4: reset varriable\n");
	printf("\t5: reset scripts\n");
	printf("\t6: save scripts\n");
	printf("\t7: load scripts\n");
	printf("\t8: exit\n\n");
	printf("answer: ");

	scanf("%d", &selection);
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

void printFunctions() {
	int i = 0;
	for (i = 0; i < 256; i++) {
		if (I_functions[i][0] != 0) {
			printf("\t%d is linked to %d, value: %d\n", i, I_functions[i][0], I_functions[i][1]);
		}
	}
	wait();
}

void printVarriable() {
	int i = 0;
	for (i = 0; i < 256; i++) {
		printf("\t%d: %d\n", i, I_varriable[i]);
	}
	wait();
}

void resetScripts() {
	printf("initializing script and functions\n");
	memset(L_scripts, 0, 1000);
	memset(I_functions, 0, 256);
	printf("completed\n\n");
}

void resetVarriable() {
	printf("initializing varriable\n");
	memset(I_varriable, 0, 256);
	printf("completed\n\n");
}

void saveScripts() {
	FILE* p_file = fopen("script.txt", "w");
	printf("saving scripts\n");
	int i = 0;
	for (i = 0; i < 256; i++) {
		if (L_scripts[i].I_lineNumber != 0) {
			fprintf(p_file, "%s %s %s %s %s %s %s %s %s\n",
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
	printf("completed\n\n");
	fclose(p_file);
	wait();
}

void loadScripts() {
	FILE* p_file = fopen("script.txt", "r");
	Line line;
	resetScripts();
	resetVarriable();
	printf("loading scripts\n");
	while (EOF != fscanf(p_file, "%s %s %s %s %s %s %s %s %s", 
		line.C_lineNumber, 
		line.C_functionCode, 
		line.C_I_varriableCode1, 
		line.C_logicFunctionCode, 
		line.C_I_varriableCode2, 
		line.C_O_varriableCode, 
		line.C_IO_functionCode, 
		line.C_IO_varriableCode, 
		line.C_nextFunctionCode)) {
		convert(&line);
		L_scripts[line.I_lineNumber] = line;
		saveFunction(line, I_functions);

	}
	printf("completed\n\n");
	fclose(p_file);
	wait();
}