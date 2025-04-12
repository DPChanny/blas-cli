#ifndef __COMMAND_H__
#define __COMMAND_H__

#include"line.h"

void saveFunction(Line line, int I_functions[256][2]);
void logicFunction(Line line, int I_varriable[256]);
void IOFunction(Line line, int I_varriable[256], int I_functions[256][2]);
int nextFunction(Line* line, Line L_scripts[1000], int I_functions[256][2]);

#endif	