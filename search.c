#include "main.h"
#include <string.h>

void search()
{
	vaccine v1;
	FILE *file;
	char to_find[3];
	int flag = 0;

	file = fopen("vaccine.txt", "r");

	printf("\nEnter vaccine code to search: ");
	scanf("%s", to_find);

	if (file == NULL)
		printf("\nCannot open the file\n");
	else
	{
		while (fread(&v1, sizeof(vaccine), 1, file))
		{
			if (strstr(v1.code, to_find))
			{
				flag = 1;
				printf("\nHERE IS THE RECORD\n");
				printf("Code: %s\n", v1.code);
				printf("Name: %s\n", v1.name);
				printf("Initial quantity: %d\n", v1.initialValue);
				printf("Current quantity: %d\n", v1.currentValue);
				printf("Dossage required: %d\n", v1.dossage);
				printf("Producing country: %s\n", v1.country);
				printf("Target population covered: %.2f\n", v1.percentage);
			}
		}
		if (flag != 1)
			printf("\nThere is no vaccine that has code as %s\n", to_find);
	}
	fclose(file);
}