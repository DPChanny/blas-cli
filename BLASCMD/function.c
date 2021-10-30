#include<stdio.h>
#include<stdlib.h>

int agreement() {
	system("cls");

	int I_agreement = 0;

	printf("1: proceed 2: exit\n");
	printf("answer: ");

	scanf_s("%d", &I_agreement);
	rewind(stdin);

	if (I_agreement == 1) {
		return 1;
	}
	else if (I_agreement == 2) {
		return 0;
	}
	else {
		agreement();
	}
	return 0;
}

void wait() {
	char dump[2] = { "", };
	printf("press enter to continue...");
	gets_s(dump, 2);
}