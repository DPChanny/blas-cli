#include<stdio.h>
#include"line.h"
#include"command.h"
#include"function.h"

//varriable declare
Line line;

extern Line L_scripts[1000];
extern int I_functions[256][2];
extern int I_varriable[256];

void functionConsole() {
	//varriable declare
	char C_functionCode[9] = {"0",};
	int I_functionCode = 0;
	printf("Function Code:");
	scanf("%s", &C_functionCode);
	rewind(stdin);

	I_functionCode = binaryToDec(C_functionCode);

	if (I_functions[I_functionCode][0] != 0) {
		if (I_functions[I_functionCode][1] == 1) {
			printf("processing function: %s(%d)\n\n", C_functionCode, I_functionCode);
			line = L_scripts[I_functions[I_functionCode][0]];

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
		}
		else {
			I_functions[I_functionCode][1] = 1;
			printf("function: %s(%d)'s varriable is not 1\n\n", C_functionCode, I_functionCode);
		}
	}
	wait();
}