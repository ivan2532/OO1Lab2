#include <iostream>

#include "PrintingOffice.h"
#include "Deck.h"

int main()
{
	std::string testNames[] = { "Pic1", "Pic2", "Pic3" };
	PrintingOffice po1(testNames, sizeof(testNames) / sizeof(std::string));
	PrintingOffice po2(testNames, sizeof(testNames) / sizeof(std::string));

	PrintingOffice po_move(std::move(po1));
	po_move = std::move(po2);
	std::cout << po_move.GetPictureNamesSize() << std::endl;
	auto p1 = po_move.PrintPicture(1);
	auto p2 = po_move.PrintPicture(2);
	std::cout << (*p1) << std::endl << (*p2) << std::endl;

	Deck d1;
	std::cout << std::endl << "(d1) Cursor at end? " << d1.IsCursorAtEnd() << std::endl;

	d1.AdvanceCursor();
	std::cout << "(d1) Advance cursor" << std::endl;

	std::cout << "(d1) Cursor at end? " << d1.IsCursorAtEnd() << std::endl;

	d1 += p1;
	(d1 += p2) += p2;

	std::cout << std::endl << "(d1) Printing..." << std::endl;
	std::cout << d1 << std::endl << std::endl;

	Deck d2;
	std::cout << std::endl << "(d2) Printing..." << std::endl;
	std::cout << d2 << std::endl << std::endl;

	std::cout << "Moving d1 into d2" << std::endl;
	d2 = std::move(d1);
	std::cout << std::endl << "(d2) Printing..." << std::endl;
	std::cout << d2 << std::endl << std::endl;
	std::cout << std::endl << "(d1) Printing..." << std::endl;
	std::cout << d1 << std::endl << std::endl;

	d2.TakePicture(2);
	std::cout << std::endl << "(d2) Printing..." << std::endl;
	std::cout << d2 << std::endl << std::endl;

	std::cout << *(d2.GetCursorValue()) << std::endl;
	d2.ResetCursor();
	std::cout << *(d2.GetCursorValue()) << std::endl;
	for (int i = 0; i < 3; i++)
	{
		d2.AdvanceCursor();

		if (!d2.IsCursorAtEnd())
			std::cout << *(d2.GetCursorValue()) << std::endl;
		else
			std::cout << "nullptr" << std::endl;
	}

	Deck d3(std::move(d2));
	std::cout << std::endl << "(d3) Printing..." << std::endl;
	std::cout << d3 << std::endl << std::endl;

	std::cout << d3 % 1 << std::endl;
	std::cout << d3 % 2 << std::endl;
	std::cout << d3 % 3 << std::endl;

	delete p1;
	delete p2;

	return 0;
}