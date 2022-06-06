#define _CRT_SECURE_NO_WARNINGS /* eliminate deprecation warnings for the older, less secure functions. */
#include <stdio.h> /* The header file stdio.h stands for Standard Input Output. It has the information related to input/output functions */

typedef struct vaccine
{
	char code[3];
	char name[20];
	int initialValue;
	int currentValue;
	int dossage;
	char country[20];
	float percentage;
}vaccine;