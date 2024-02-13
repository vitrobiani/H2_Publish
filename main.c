#include <stdio.h>
#include <stdlib.h>
#include "Airport.h"
#include "Plane.h"
#include "Date.h"
#include "AirportManager.h"

int main()
{
    
	Plane p;
    initPlane(&p, NULL , 0);
    printPlane(&p);

//    int opt;
//	printf("Please choose one of the following options\n");
//	printf("1 - Date\n");
//	printf("2 - Plane\n");
//	printf("3 - Airport Code\n");
//	printf("4 - Airport Name\n");
//	printf("5 - Airport\n");
//	scanf("%d", &opt);
//	getchar();
//	
//	Date d;
//	Plane p;
//	Airport port1;
//	switch (opt)
//	{
//	case 1:
//		getCorrectDate(&d);
//		printDate(&d);
//		printf("\n");
//		break;
//
//	case 2:
//		initPlane(&p, NULL, 0);
//		printPlane(&p);
//		printf("\n");
//		break;
//
//	case 3:
//		getAirportCode(port1.code);
//		printf("%s\n", port1.code);
//		break;
//
//	case 4:
//		getAirportName(&port1);
//		printf("%s\n", port1.name);
//		free(port1.name);
//		break;
//
//	case 5:
//		getAirportCode(port1.code);
//		initAirportNoCode(&port1);
//		printAirport(&port1);
//		freeAirport(&port1);
//		break;

//}

}
