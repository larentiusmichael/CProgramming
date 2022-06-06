#include "main.h"
#include <stdlib.h> /* stdlib.h is the header for the General Purpose Standard Library of C programming language which declares a variety of utility functions for type conversions, memory allocation, process control and other similar tasks */
#define SIZE 5

void create()
{
	vaccine* v;
	FILE *file;
	int i;

	v = (vaccine*)calloc(SIZE, sizeof(vaccine)); /* Allocate bytes as big as vaccine and blocks as big as SIZE to v */

	file = fopen("vaccine.txt", "w");

	if (file == NULL)
		printf("\nCannot open the file\n");
	else
	{
		for (i = 0; i < SIZE; i++)
		{
			printf("\nEnter vaccine %d code: ", i + 1);
			scanf("%s", v[i].code);
			getchar(); /* This will capture the <enter> char */

			fflush(stdin); /* fflush(stdin) is used to flush the output buffer of the stream */
			printf("Enter vaccine %d name: ", i + 1);
			scanf("%[^\n]s", v[i].name); /* ^\n means to scan all characters except \n */
			getchar();

			printf("Enter vaccine %d initial value: ", i + 1);
			scanf("%d", &v[i].initialValue);
			getchar();

			v[i].currentValue = v[i].initialValue;
			
			printf("Enter vaccine %d dossage required: ", i + 1);
			scanf("%d", &v[i].dossage);
			getchar();

			printf("Enter vaccine %d producing country: ", i + 1);
			scanf("%[^\n]s", v[i].country);
			getchar();

			printf("Enter vaccine %d target of population covered: ", i + 1);
			scanf("%f", &v[i].percentage);
			getchar();

			fwrite(&v[i], sizeof(vaccine), 1, file); /* fwrite means add v[i].code, v[i].name, v[i].initialValue, v[i].currentValue, v[i].dossage, v[i].country, v[i].percentage in file with size of vaccine */
		}
		printf("\nThank you for creating an inventory!\n");
	}
	fclose(file);
}