#include<stdio.h>
#include"line.h"
#include"logic.h"

void saveFunction(Line line, int I_functions[256][2]) {
	if (line.I_functionCode != 0) {
		I_functions[line.I_functionCode][0] = line.I_lineNumber;
		I_functions[line.I_functionCode][1] = 1;
		printf("saving function: %s(%d)\n\n", line.C_functionCode, line.I_functionCode);
	}
}

void logicFunction(Line line, int I_varriable[256]) {
	int result = 0;
	if (line.I_logicFunctionCode != 0) {
		if (line.I_I_varriableCode1 != 0) {
			if (line.I_I_varriableCode2 != 0) {
				//not logic
				if (line.I_logicFunctionCode == 66) {
					printf("processing not logic\n\n");
					result = l_not(I_varriable[line.I_I_varriableCode1]);
					if (line.I_O_varriableCode != 0) {
						I_varriable[line.I_O_varriableCode] = result;
					}
				}
				//and logic 
				if (line.I_logicFunctionCode == 195) {
					printf("processing and logic\n\n");
					result = l_and(I_varriable[line.I_I_varriableCode1], I_varriable[line.I_I_varriableCode2]);
					if (line.I_O_varriableCode != 0) {
						I_varriable[line.I_O_varriableCode] = result;
					}
				}
				//or logic
				if (line.I_logicFunctionCode == 129) {
					printf("processing or logic\n\n");
					result = l_or(I_varriable[line.I_I_varriableCode1], I_varriable[line.I_I_varriableCode2]);
					if (line.I_O_varriableCode != 0) {
						I_varriable[line.I_O_varriableCode] = result;
					}
				}
				//xor logic 
				if (line.I_logicFunctionCode == 165) {
					printf("processing xor logic\n\n");
					result = l_xor(I_varriable[line.I_I_varriableCode1], I_varriable[line.I_I_varriableCode2]);
					if (line.I_O_varriableCode != 0) {
						I_varriable[line.I_O_varriableCode] = result;
					}
				}
				//flip-flop logic
				if (line.I_logicFunctionCode == 170) {
					printf("processing flip-flop logic\n\n");
					//¹¹ÇÏ´Â ¾ÖÁö?
				}
				printf("logic function result: %d\n", result);
			}
			else printf("no logic processed\n");
		}
		else printf("no logic processed\n");
	}
	else printf("no logic processed\n");
}

void IOFunction(Line line, int I_varriable[256], int I_functions[256][2]) {
	if (line.I_IO_functionCode != 0) {
		if (line.I_IO_functionCode == 254) {
			if (line.I_IO_varriableCode != 0) {
				printf("I/O function result: %d\n\n", I_varriable[line.I_IO_varriableCode]);
			}
		}
		else if (line.I_IO_functionCode == 127) {
			if (line.I_IO_varriableCode != 0) {
				printf("I/O function result: I_IO_varriableCode(%d) to I_O_varriableCode\n\n", line.I_IO_varriableCode);
				I_varriable[line.I_O_varriableCode] = line.I_IO_varriableCode;
			}
		}
		else if (line.I_IO_functionCode == 231) {
			if (line.I_O_varriableCode != 0) {
				printf("I/O function result: I_IO_varriableCode(%d) to function I_O_varriableCode(%s)\n\n", line.I_IO_varriableCode, line.C_O_varriableCode);
				I_functions[line.I_O_varriableCode][1] = I_varriable[line.I_IO_varriableCode];
			}
		}
		else printf("no I/O function processed\n\n");
	}
	else printf("no I/O function processed\n\n");
}

int nextFunction(Line* line, Line L_scripts[1000], int I_functions[256][2]) {
	if (line->I_nextFunctionCode != 0) {
		if (I_functions[line->I_nextFunctionCode][1] == 1) {
			printf("processing next function: %s(%d)\n\n", line->C_nextFunctionCode, line->I_nextFunctionCode);
			*line = L_scripts[I_functions[line->I_nextFunctionCode][0]];

			return 1;
		}
		else {
			printf("function: %s(%d)'s varriable is not 1\n\n", line->C_nextFunctionCode, line->I_nextFunctionCode);
			I_functions[line->I_nextFunctionCode][1] = 1;
			
			return 0;
		}
	}
	else {
		printf("no more function\n\n");
		return 0;
	}
}