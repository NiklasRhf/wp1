// aufgabe1.cpp

#include <iostream>
#include "triangle.h"

int main()
{
	coords   *pCoords   = new coords();
	triangle *pTriangle = new triangle();
	
	try {
		if (pTriangle->setCoords(-1, *pCoords))
			std::cout << "ERROR: Negative Index-Werte nicht korrekt behandelt";

		if (pTriangle->setCoords(10, *pCoords))
			std::cout << "ERROR: Zu grosse Index-Werte nicht korrekt behandelt";
	}
	catch (std::exception e) {
		std::cout << "ERROR: Exception!";
		return -1;
	}

	triangle *pT1 = new triangle(coords(0, 0), coords(1, 1), coords(1, 2));
	triangle *pT2 = new triangle(*pT1);
	triangle *pT3 = new triangle(*pT1);

	*pT3 = *pT1;

	// Test: triangle
	pT1->setCoords(0, coords(4, 4));
	pT2->setCoords(1, coords(4, 4));
	pT3->setCoords(2, coords(4, 4));

	std::cout << "Test: Klasse triangle auf Unabgaengigkeit" << std::endl;
	std::cout << "Erwartet:" << std::endl;
	std::cout << "[(4|4) (1|1) (1|2)]" << std::endl;
	std::cout << "[(0|0) (4|4) (1|2)]" << std::endl;
	std::cout << "[(0|0) (1|1) (4|4)]" << std::endl;
	std::cout << "-------------------" << std::endl;
	std::cout << "Ergebnis:" << std::endl;
	std::cout << *pT1 << std::endl;
	std::cout << *pT2 << std::endl;
	std::cout << *pT3 << std::endl;

	std::system("pause");
	std::system("cls");

	// Test: triangleContainer
	triangleContainer *pTC1 = new triangleContainer(3);
	pTC1->addTriangle(*pT1);
	pTC1->addTriangle(*pT2);
	pTC1->addTriangle(*pT3);

	triangleContainer *pTC2 = new triangleContainer(*pTC1);
	triangleContainer *pTC3 = new triangleContainer(6); // sic!
	*pTC3 = *pTC1;

	//// Wir loeschen unsere Dreiecke, um zu testen,
	//// ob der Container wirklich unabhängig ist
	delete pT1;
	delete pT2;
	delete pT3;

	pTC2->changeTriangle(0, triangle(coords(7, 7), coords(7, 7), coords(7, 7)));
	pTC3->changeTriangle(2, triangle(coords(8, 8), coords(8, 8), coords(8, 8)));

	std::cout << "Test: Klasse triangleContainer auf Unabgaengigkeit" << std::endl;
	std::cout << "Erwartet:" << std::endl;
	std::cout << "[(4|4) (1|1) (1|2)]" << std::endl;
	std::cout << "[(0|0) (4|4) (1|2)]" << std::endl;
	std::cout << "[(0|0) (1|1) (4|4)]" << std::endl << std::endl;
	std::cout << "[(7|7) (7|7) (7|7)]" << std::endl;
	std::cout << "[(0|0) (4|4) (1|2)]" << std::endl;
	std::cout << "[(0|0) (1|1) (4|4)]" << std::endl << std::endl;
	std::cout << "[(4|4) (1|1) (1|2)]" << std::endl;
	std::cout << "[(0|0) (4|4) (1|2)]" << std::endl;
	std::cout << "[(8|8) (8|8) (8|8)]" << std::endl;
	std::cout << "-------------------" << std::endl;
	std::cout << "Ergebnis:" << std::endl;
	std::cout << *pTC1 << std::endl;
	std::cout << *pTC2 << std::endl;
	std::cout << *pTC3 << std::endl;

	std::system("pause");


}