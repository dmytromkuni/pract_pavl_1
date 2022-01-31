#include "BusControlSystem.h"
#include <iostream>


int main()
{
	control::BusList list;

	std::cout << "Print 1 to see the current bus list.\n";
	std::cout << "Print 2 to depart the bus.\n";
	std::cout << "Print 3 to return the bus.\n";
	std::cout << "Print 4 to add the bus.\n";
	std::cout << "Print 5 to see the current list of departed buses.\n";
	std::cout << "Print 6 to see the current list of returned buses.\n";
	std::cout << "Print any other symbol to exit the system.\n\n";

	while (true)
	{
		int x;
		std::cin >> x;

		if (x == 1)
		{
			list.PrintAll();
		}

		else if (x == 2)
		{
			std::cout << "Enter the ID of the bus, which you want to be departed: \n";
			int ID;
			std::cin >> ID;
			list.BusDeparture(ID);
		}

		else if (x == 3)
		{
			std::cout << "Enter the ID of the bus, which you want to be returned: \n";
			int ID;
			std::cin >> ID;
			list.BusReturn(ID);
		}

		else if (x == 4)
		{
			int ID, route;
			char driver_name[20];
			bool status;
			std::cout << "Enter the ID of the bus, its ROUTE, NAME of the driver (no more than 20 letters) " <<
				"and STATUS (on the way or not, where 0 is not and 1 is on)\n";
			std::cin >> ID >> route >> driver_name >> status;
			control::Bus bus(ID, route, driver_name, status);
			list.Add(&bus);
		}

		else if (x == 5)
		{
			list.PrintEn_Route();
		}

		else if (x == 6)
		{
			list.PrintAtHome();
		}

		else break;

	}
	return 0;
}