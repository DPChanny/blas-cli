#include <stdio.h>
#include<math.h>
#include<stdlib.h>
#include<string.h>

typedef struct Line {
	char C_lineNumber[4]; //line number
	char C_functionCode[9]; //function code
	char C_I_varriableCode1[9]; //input varriable 1 code 
	char C_I_varriableCode2[9]; //input varriable 2 code
	char C_logicFunctionCode[9]; //logic function code
	char C_O_varriableCode[9]; //output varriable code
	char C_IO_functionCode[9]; //i/o function code
	char C_IO_varriableCode[9]; //i/o varriable code
	char C_nextFunctionCode[9]; //next function code

	int I_lineNumber;
	int I_functionCode;
	int I_I_varriableCode1;
	int I_I_varriableCode2;
	int I_logicFunctionCode;
	int I_O_varriableCode;
	int I_IO_functionCode;
	int I_IO_varriableCode;
	int I_nextFunctionCode;
} Line;

int binaryToDec(char binary[8]) {
	int decimal = 0;
	int position = 0;
	int i = (int) strlen(binary) - 1;
	for (i; i >= 0; i--) {
		if (binary[i] == '1') {
			decimal += (int) pow(2, position);
		}
		position++;
	}
	return decimal;
}

void initLine(Line* line) {
	memset(line->C_lineNumber, "", 4);
	memset(line->C_functionCode, '0', 8);
	memset(line->C_I_varriableCode1, '0', 8);
	memset(line->C_logicFunctionCode, '0', 8);
	memset(line->C_I_varriableCode2, '0', 8);
	memset(line->C_O_varriableCode, '0', 8);
	memset(line->C_IO_functionCode, '0', 8);
	memset(line->C_IO_varriableCode, '0', 8);
	memset(line->C_nextFunctionCode, '0', 8);
}

void convert(Line* line) {
	printf("converting char type binary to int type decimal\n\n");
	line->I_lineNumber = atoi(line->C_lineNumber);
	line->I_functionCode = binaryToDec(line->C_functionCode);
	line->I_I_varriableCode1 = binaryToDec(line->C_I_varriableCode1);
	line->I_logicFunctionCode = binaryToDec(line->C_logicFunctionCode);
	line->I_I_varriableCode2 = binaryToDec(line->C_I_varriableCode2);
	line->I_O_varriableCode = binaryToDec(line->C_O_varriableCode);
	line->I_IO_functionCode = binaryToDec(line->C_IO_functionCode);
	line->I_IO_varriableCode = binaryToDec(line->C_IO_varriableCode);
	line->I_nextFunctionCode = binaryToDec(line->C_nextFunctionCode);
}

void printDebug(Line line, int I_varriable[256]) {
	//(line number) (function code) (input varriable 1 code) (logic function) (input varriable 2 code) (output varrialbe code) (i/o function code) (i/o varriable code) (next function code)
	printf("Code: %s %s %s %s %s %s %s %s %s\n\n",
		line.C_lineNumber,
		line.C_functionCode,
		line.C_I_varriableCode1,
		line.C_logicFunctionCode,
		line.C_I_varriableCode2,
		line.C_O_varriableCode,
		line.C_IO_functionCode,
		line.C_IO_varriableCode,
		line.C_nextFunctionCode);

	//varriable 
	printf("I_lineNumber: %d\n", line.I_lineNumber);
	printf("I_functionCode: %d\n", line.I_functionCode);
	printf("I_varriableCode1: %d\n", line.I_I_varriableCode1);
	printf("I_logicFunctionCode: %d\n", line.I_logicFunctionCode);
	printf("I_I_varriableCode2: %d\n", line.I_I_varriableCode2);
	printf("I_O_varriableCode: %d\n", line.I_O_varriableCode);
	printf("I_IO_functionCode: %d\n", line.I_IO_functionCode);
	printf("I_IO_varriableCode: %d\n", line.I_IO_varriableCode);
	printf("I_nextFunctionCode: %d\n\n", line.I_nextFunctionCode);

	printf("I_varriable[I_I_varriableCode1]: %d\n", I_varriable[line.I_I_varriableCode1]);
	printf("I_varriable[I_I_varriableCode2]: %d\n\n", I_varriable[line.I_I_varriableCode2]);
}

void saveLine(Line line, Line L_scripts[1000]) {
	if (line.I_lineNumber != 0) {
		printf("saving line\n\n");
		L_scripts[line.I_lineNumber] = line;
	}
}