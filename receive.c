#include "main.h"
#include <string.h> /* The string.h header defines one variable type, one macro, and various functions for manipulating arrays of characters. */

void receive()
{
	vaccine v1;
	FILE* file;
	FILE* fp;
	char to_find[3];
	int flag = 0;
	int amount;

	file = fopen("vaccine.txt", "r");
	fp = fopen("temp.txt", "w");

	printf("\nEnter vaccine code to add: ");
	scanf("%s", to_find);

	if (file == NULL || fp == NULL)
		printf("\nCannot open the file\n");
	else
	{
		while (fread(&v1, sizeof(vaccine), 1, file)) /* fread means read file into v1 with size of vaccine */
		{
			if (strstr(v1.code, to_find)) /* if variable to_find found in v1.code */
			{
				flag = 1;
				printf("\nVaccine's Code: %s\n", v1.code);
				printf("Vaccine's Name: %s\n", v1.name);
				printf("Enter how many vaccine has just received: ");
				scanf("%d", &amount);
				v1.currentValue = v1.currentValue + amount;
				printf("\nThank you for updating %s quantity!\n", v1.name);
			}
			fwrite(&v1, sizeof(vaccine), 1, fp);
		}
		fclose(file);
		fclose(fp);

		if (flag == 1)
		{
			file = fopen("vaccine.txt", "w");
			fp = fopen("temp.txt", "r");

			while (fread(&v1, sizeof(vaccine), 1, fp))
			{
				fwrite(&v1, sizeof(vaccine), 1, file);
			}

			fclose(file);
			fclose(fp);
		}
		else
			printf("\nThere is no vaccine that has code as %s\n", to_find);
	}
}