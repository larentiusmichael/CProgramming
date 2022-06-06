#include "main.h"
#include "receive.h"
#include "distribute.h"

void update()
{
	int option;

	printf("\nWhat do you want to do?\n");
	printf("1. Add Vaccine Quantity\n");
	printf("2. Subtract Vaccine Quantity\n");
	printf("Enter your choice: ");
	scanf("%d", &option);

	while (option > 2 || option < 1)
	{
		printf("\nWrong choice! Please choose again!\n");
		printf("What do you want to do?\n");
		printf("1. Add Vaccine Quantity\n");
		printf("2. Subtract Vaccine Quantity\n");
		printf("Enter your choice: ");
		scanf("%d", &option);
	}

	if (option == 1)
	{
		receive();
	}
	else
	{
		distribute();
	}
}