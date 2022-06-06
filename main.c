//Name: LAURENTIUS MICHAEL
//TP Number: TP061310

#include "main.h"
#include "create.h"
#include "update.h"
#include "search.h"
#include "produce.h"

int main()
{
	int opt;

	do
	{
		printf("\n\n\t\t*****WELCOME TO VACCINE INVENTORY MANAGEMENT SYSTEM*****\n\n");
		printf("Select one of these functionalities:\n");
		printf("1. Inventory Creation\n");
		printf("2. Update Vaccine Quantity\n");
		printf("3. Search Vaccine and its Available Quantity\n");
		printf("4. Produce a list of All Vaccines and their Distributed Quantity\n");
		printf("0. Exit\n");
		printf("Enter your choice: ");
		scanf("%d", &opt);

		switch (opt)
		{
		case 1:
			create();
			break;
		case 2:
			update();
			break;
		case 3:
			search();
			break;
		case 4:
			produce();
			break;
		default:
			if (opt != 0)
			{
				printf("\nWrong choice! Pleasee choose again!\n");
			}
		}
	} while (opt != 0);

	printf("\nGOOD BYE!\n");

	return 0;
}