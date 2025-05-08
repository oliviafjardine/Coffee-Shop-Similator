#include <iostream>
#include <iomanip>
#include "display.h"

void print_options() {
	std::cout << "What would you like to do?" << std::endl;
	std::cout << "	1. View shop info" << std::endl;
	std::cout << "	2. Add an item to menu" << std::endl;
	std::cout << "	3. Remove an item from menu" << std::endl;
	std::cout << "	4. Search by coffee name" << std::endl;
	std::cout << "	5. Search by price" << std::endl;
	std::cout << "	6. Place an order" << std::endl;
	std::cout << "	7. Log out" << std::endl;
}

void print_selection_error() {
	std::cout << std::endl;
	std::cout << "Error: You must choose one of the 7 options provided."
			  << std::endl;
	std::cout << std::endl;
}

int get_option() {
	int option;
	bool first = true;
	do {
		if (!first) {
			print_selection_error();
		}
		first = false;
		print_options();
		std::cout << "Selection: ";
		std::cin >> option;
	} while (option < 1 || option > 7);

	return option;
}

void execute_option(shop& s, menu& m, int option) {
	if (option == 1) {
		// TODO Display shop info
		std::cout << std::endl;
		std::cout << "Address: " << s.get_address() << std::endl;
		std::cout << "Phone: " << s.get_phone() << std::endl;
		std::cout << "Revenue: $" << std::fixed << std::setprecision(2)
				  << s.get_revenue() << std::endl;
		std::cout << std::endl;
		std::cout << "Here is our menu:" << std::endl;
		std::cout << "-----------------" << std::endl;
		m.populate_menu();
		m.get_menu();
		std::cout << "-----------------" << std::endl;
		std::cout << std::endl;
		std::cout << "Order info:" << std::endl;
		s.get_orders();
		std::cout << std::endl;
	} else if (option == 2) {
		// TODO Guide user through adding a coffee to the menu
		std::cout << std::endl;
		s.addCoffeeToMenu();
		std::cout << std::endl;
	}
	else if (option == 3)
	{
		// TODO Guide user through removing a coffee from the menu
		std::cout << std::endl;
		s.removeCoffeeFromMenu();
		std::cout << std::endl;
	}
	else if (option == 4)
	{
		// TODO Guide user through searching the menu by coffee name
		std::cout << std::endl;
		s.search_coffee_menu();
		std::cout << std::endl;
	}
	else if (option == 5)
	{
		// TODO Guide user through searching the menu by coffee price
		std::cout << std::endl;
		s.search_coffee_price();
		std::cout << std::endl;
	}
	else if (option == 6)
	{
		// TODO Guide user through placing an order
		std::cout << std::endl;
		s.add_order();
		std::cout << std::endl;
	}
}