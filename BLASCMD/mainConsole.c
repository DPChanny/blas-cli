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
			printVarriable(line, I_varriable);

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
	gets_s(line->C_lineNumber, 4);
	printf("FunctionCode: ");
	gets_s(line->C_functionCode, 9);
	printf("I_VarriableCode1: ");
	gets_s(line->C_I_varriableCode1, 9);
	printf("logicFunctionCode: ");
	gets_s(line->C_logicFunctionCode, 9);
	printf("I_VarriableCode2: ");
	gets_s(line->C_I_varriableCode2, 9);
	printf("O_VarriableCode: ");
	gets_s(line->C_O_varriableCode, 9);
	printf("IO_FunctionCode: ");
	gets_s(line->C_IO_functionCode, 9);
	printf("IO_VarriableCode: ");
	gets_s(line->C_IO_varriableCode, 9);
	printf("nextFunctionCode: ");
	gets_s(line->C_nextFunctionCode, 9);
	printf("\n");
}
