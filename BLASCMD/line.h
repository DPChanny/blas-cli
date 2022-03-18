#ifndef __LINE_H__
#define __LINE_H__

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

int binaryToDec(char binary[8]);
void initLine(Line* line);
void convert(Line* line);
void printDebug(Line line, int I_varriable[256]);
void saveLine(Line line, Line L_Scripts[1000]);

#endif 