#include "main.h"
#include <string.h>

void distribute()
{
	vaccine v1;
	FILE* file;
	FILE* fp;
	FILE* fp1;
	char to_find[3];
	int flag = 0;
	int amount, temp;

	file = fopen("vaccine.txt", "r");
	fp = fopen("temp.txt", "w");
	fp1 = fopen("dist.txt", "a");

	printf("\nEnter vaccine code to subtract: ");
	scanf("%s", to_find);

	if (file == NULL || fp == NULL || fp1 == NULL)
		printf("\nCannot open the file\n");
	else
	{
		while (fread(&v1, sizeof(vaccine), 1, file))
		{
			if (strstr(v1.code, to_find))
			{
				flag = 1;
				printf("\nVaccine's Code: %s\n", v1.code);

				printf("Vaccine's Name: %s\n", v1.name);

				printf("Enter how many vaccine has just distributed: ");
				scanf("%d", &amount);
				temp = v1.currentValue;
				v1.currentValue = amount;

				fwrite(&v1, sizeof(vaccine), 1, fp1);

				v1.currentValue = temp - amount;

				printf("\nThank you for updating %s quantity!\n", v1.name);
			}
			fwrite(&v1, sizeof(vaccine), 1, fp);
		}
		fclose(file);
		fclose(fp);
		fclose(fp1);

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