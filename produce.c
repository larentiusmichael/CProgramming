#include "main.h"
#include <string.h>
#include <stdlib.h>

void produce()
{
	vaccine* v, v1;
	vaccine* s;
	vaccine* t, t1;
	FILE* file;
	FILE* fp;
	FILE* fp2;
	int i, j, m, n, o;
	int total, temp;

	file = fopen("dist.txt", "r");

	fseek(file, 0, SEEK_END); /* Seek file to move file pointer to the end */
	n = ftell(file) / sizeof(vaccine); /* ftell means tell the position of file pointer with respect to starting of the file*/
	v = (vaccine*)calloc(n, sizeof(vaccine));
	rewind(file); /* Rewind the file pointer position to the beginning of the file */

	for (i = 0; i < n; i++)
	{
		fread(&v[i], sizeof(vaccine), 1, file);
	}

	for (i = 0; i < n; i++)
	{
		for (j = i + 1; j < n; j++)
		{
			if (v[i].currentValue < v[j].currentValue)
			{
				v1 = v[i];
				v[i] = v[j];
				v[j] = v1;
			}
		}
	}

	fp = fopen("vaccine.txt", "r");
	fp2 = fopen("temp2.txt", "w");

	fseek(fp, 0, SEEK_END);
	m = ftell(fp) / sizeof(vaccine); 
	s = (vaccine*)calloc(m, sizeof(vaccine));
	rewind(fp); 

	for (i = 0; i < m; i++)
	{
		fread(&s[i], sizeof(vaccine), 1, fp);
	}

	for (i = 0; i < m; i++)
	{
		total = 0;
		for (j = 0; j < n; j++)
		{
			if (strstr(s[i].code, v[j].code))
			{
				total = v[j].currentValue + total;
			}
		}
		temp = s[i].currentValue;
		s[i].currentValue = total;
		fwrite(&s[i], sizeof(vaccine), 1, fp2);
		s[i].currentValue = temp;
	}
	fclose(fp);
	fclose(fp2);

	fp2 = fopen("temp2.txt", "r");

	fseek(fp2, 0, SEEK_END);
	o = ftell(fp2) / sizeof(vaccine);
	t = (vaccine*)calloc(o, sizeof(vaccine));
	rewind(fp2);

	for (i = 0; i < o; i++)
	{
		fread(&t[i], sizeof(vaccine), 1, fp2);
	}

	for (i = 0; i < o; i++)
	{
		for (j = i + 1; j < o; j++)
		{
			if (t[i].currentValue < t[j].currentValue)
			{
				t1 = t[i];
				t[i] = t[j];
				t[j] = t1;
			}
		}
	}

	printf("\nLIST OF TOTAL DISTRIBUTION IN DESCENDING ORDER\n");

	for (i = 0; i < o; i++)
	{
		printf("%s\t", t[i].code);
		printf("%s\t", t[i].name);
		printf("%d\n", t[i].currentValue);
	}
	fclose(fp2);

	printf("\nDETAIL OF DISTRIBUTION RECORD IN DESCENDING ORDER\n");

	for (i = 0; i < n; i++)
	{
		printf("%s\t", v[i].code);
		printf("%s\t", v[i].name);
		printf("%d\n", v[i].currentValue);
	}

	fclose(file);
}