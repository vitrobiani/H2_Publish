#include <stdio.h>
#include <stdlib.h>
#include "Plane.h"
#include "Airline.h"
#include "AirportManager.h"

int main()
{
	AirportManager manager;
	Airline company;

	if (!initManager(&manager))
	{
		printf("Error\n");
		return 0;
	}

	for (int i = 0; i < 2; i++)
	{
		if (!addAirport(&manager))
		{
			printf("Error\n");
			freeManager(&manager);
			return 0;
		}
	}


	initAirline(&company);

	for (int i = 0; i < 2; i++)
	{
		if (!addPlane(&company))
		{
			printf("Error\n");
			freeManager(&manager);
			freeCompany(&company);
			return 0;
		}
	}
	

	Flight f;
	//This function get an address of the struct Flight,
	//A plane that the flight used (I choose the plane in index 0)
	//and the address of the manager
	//The function ask the user for code of the origin airport,
	//code of the destination airport
	//do checking (there is an airport with that code, not the same airport...)
	//set the plane of the flight and the date
    initFlight(&f, &company.planeArr[0], &manager);
	printFlight(&f);


	freeCompany(&company);
	freeManager(&manager);
}
