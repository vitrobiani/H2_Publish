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
	initAirline(&company);

	for (int i = 0; i < 4; i++)
	{
		if (!addPlane(&company))
		{
			printf("Error\n");
			freeManager(&manager);
			freeCompany(&company);
			return 0;
		}
	}
	
	addFlight(&company, &manager);
	addAirport(&manager);
	addFlight(&company, &manager);

	for (int i = 0; i < 3; i++)
	{
		if (!addAirport(&manager))
		{
			printf("Error\n");
			freeManager(&manager);
			freeCompany(&company);
			return 0;
		}
	}

	for (int i = 0; i < 3; i++)
	{
		if (!addFlight(&company, &manager))
		{

			printf("Error\n");
			freeManager(&manager);
			freeCompany(&company);
			return 0;
		}
	}

	printCompany(&company);
	
	for (int i = 0; i < 3; i++)
		doPrintFlightsWithPlaneType(&company);

	freeCompany(&company);
	freeManager(&manager);
}
