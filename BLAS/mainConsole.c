#include<stdio.h>
#include<stdlib.h>
#include"line.h"
#include"function.h"
#include"command.h"

//varriable declare
Line line;

extern int I_varriable[256];
extern int I_functions[256][2];
extern Line L_scripts[1000];

//function declare
void getCommand(Line* line);

void mainConsole() {
	while (1) {
		//init 
		initLine(&line);

		//command
		getCommand(&line);

		//char type binary -> int type decimal
		convert(&line);

		//save line to scripts
		saveLine(line, L_scripts);

		//function
		saveFunction(line, I_functions);

		while (1) {
			//print bebug
			printDebug(line, I_varriable);

			//logic function
			logicFunction(line, I_varriable);

			//IO function
			IOFunction(line, I_varriable, I_functions);

			if (!nextFunction(&line, L_scripts, I_functions)) {
				break;
			}
		}

		wait();

		if (agreement() == 1) {
			system("cls");
			continue;
		}
		else break;
	}

}

void getCommand(Line* line) {
	//(line number) (function code) (input varriable 1 code) (logic function) (input varriable 2 code) (output varrialbe code) (i/o function code) (i/o varriable code) (next function code)
	printf("LineNumber: ");
	gets(line->C_lineNumber);
	printf("FunctionCode: ");
	gets(line->C_functionCode);
	printf("I_VarriableCode1: ");
	gets(line->C_I_varriableCode1);
	printf("logicFunctionCode: ");
	gets(line->C_logicFunctionCode);
	printf("I_VarriableCode2: ");
	gets(line->C_I_varriableCode2);
	printf("O_VarriableCode: ");
	gets(line->C_O_varriableCode);
	printf("IO_FunctionCode: ");
	gets(line->C_IO_functionCode);
	printf("IO_VarriableCode: ");
	gets(line->C_IO_varriableCode);
	printf("nextFunctionCode: ");
	gets(line->C_nextFunctionCode);
	printf("\n");
}
