/**
 * Author: Olivia Jardine
 * Program Description: Stimulates a coffee cafe the the user is the
 * 		shop manager and interacts with the shop. There are 7
 * 		functionalities: view shop, add coffee item to menu,
 * 		remove coffee item from menu, search by coffee name, search
 * 		by price, place an order, log out.
*/

#include <iostream>
#include <fstream>
#include "display.h"
#include "shop.h"

int main() {
    std::cout << "Welcome to the Coffee++ Cafe!" << std::endl;

    // Construct and initialize a shop object `s`, along with everything inside it,
    // using data from the text files.

    // Here, you would typically read the shop information and menu items from files
    // and initialize the shop object accordingly.

	// Read shop from file and populate shop object
    shop s;
	std::ifstream shop;
	shop.open("shop_info.txt");
	s.populate_info(shop);
	shop.close();

	// Initialize menu and coffee objects
	menu m;
	coffee c;

	// Read and populate menu object
	std::ifstream menu;
	menu.open("menu.txt");
	m.populate_menu();
	menu.close();

	// Set menu and coffee objects in the shops
	s.set_menu(m);
	m.set_coffee(c);

	// Loop display options until logout
	int option;
	do {
        option = get_option();
        if (option >= 1 && option <= 6) {
            execute_option(s, m, option);
        }
    } while (option != 7);

    return 0;
}