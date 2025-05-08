#ifndef MENU_H
#define MENU_H

#include "coffee.h"

class menu
{
private:
	coffee c;

	// Order info for a coffee
	std::string coffee_name; // coffee name order
	std::string coffee_size; // coffee order size
	int quantity; // Number of coffees in order
	double total_cost; // Total cost of order

	int num_coffees; // Number of coffees in menu
	coffee *coffees; // Dynamic array of coffees

public:
	// Default constructor
	/**
	 * Name: menu
	 * Description: Default construction for menu class
	 * Parameters: None
	 * Returns: None
	 * Post conditions: Initializes num_coffees to 0 and coffees pointer to nullptr.
	*/
	menu();


	// Destructor
	/**
	 * Name: ~menu
	 * Description: Destructor for the menu class.
	 * Parameters: None
	 * Returns: None
	 * Post conditions: Deallocates memory for the coffees array.
	*/
	~menu();

	// Copy constructor
	/**
	 * Name: menu
	 * Description: Copy constructor for the menu class.
	 * Parameters: const menu& other - reference to another menu object to copy from
	 * Returns: None
	 * Post conditions: Creates a new menu object with the same content as 'other'.
	*/
	menu(const menu &other);

	// Assignment operator
	/**
	 * Name: operator=
	 * Description: Assignment operator for the menu class.
	 * Parameters: const menu& other - reference to another menu object to copy from
	 * Returns: menu& - reference to the assigned menu object
	 * Post conditions: Assigns the content of 'other' to the current menu object.
	*/
	menu &operator=(const menu &other);

	/**
	 * Name: get_order
	 * Description: Allows the user to select a coffee drink from the menu, specify size and quantity.
	 * Parameters: None
	 * Returns: None
	 * Post conditions: Updates the coffee_name, coffee_size, quantity, and total_cost members.
	*/
	void get_order();

	/**
	 * Name: get_coffee_name
	 * Description: Returns the name of the selected coffee drink.
	 * Parameters: None
	 * Returns: std::string - name of the selected coffee drink
	 * Post conditions: None
	*/
	std::string get_coffee_name() const;

	/**
	 * Name: get_size_choice
	 * Description: Returns the size choice (small, medium, large) of the selected coffee.
	 * Parameters: None
	 * Returns: std::string - size choice of the selected coffee
	 * Post conditions: None
	*/
	std::string get_size_choice() const;

	/**
	 * Name: get_quantity
	 * Description: Returns the quantity of the selected coffee.
	 * Parameters: None
	 * Returns: int - quantity of the selected coffee
	 * Post conditions: None
	*/
	int get_quantity() const;

	/**
	 * Name: get_total_cost
	 * Description: Returns the total cost of the selected coffee order.
	 * Parameters: None
	 * Returns: double - total cost of the selected coffee order
	 * Post conditions: None
	*/
	double get_total_cost() const;

	/**
	 * Name: populate_menu
	 * Description: Reads coffee information from a file and populates the menu with coffee items.
	 * Parameters: None
	 * Returns: None
	 * Post conditions: Updates the coffees array with coffee items from the file
	*/
	void populate_menu();

	/**
	 * Name: coffeeExists
	 * Description: Checks if a coffee with the given name exists in the menu.
	 * Parameters: const std::string& name - name of the coffee to search for
	 * Returns: bool - true if the coffee exists, false otherwise
	 * Post conditions: None
	*/
	bool coffeeExists(const std::string& name) const;

	/**
	 * Name: get_menu
	 * Description: Displays the entire coffee menu with prices.
	 * Parameters: None
	 * Returns: None
	 * Post conditions: None
	*/
	void get_menu();

	/**
	 * Name: add_coffee
	 * Description: Adds a new coffee drink to the menu.
	 * Parameters: None
	 * Returns: None
	 * Post conditions: Adds the new coffee item to the menu and updates the menu file
	*/
	void add_coffee();

	/**
	 * Name: add_coffee
	 * Description: Adds a new coffee drink to the menu.
	 * Parameters: coffee& c - Reference to coffee class instance
	 * Returns: None
	 * Post conditions: Adds the new coffee item to the menu and updates the menu file
	*/
	void add_coffee(coffee& c);

	/**
	 * Name: remove_coffee
	 * Description: Removes a coffee drink from the menu.
	 * Parameters: None
	 * Returns: None
	 * Post conditions: Removes the selected coffee item from the menu and updates the menu file.
	 */
	void remove_coffee();

	/**
	 * Name: search_coffee
	 * Description: Searches for a coffee drink in the menu by name.
	 * Parameters: None
	 * Returns: None
	 * Post conditions: Displays the details of the found coffee or a message if not found.
	 */
	void search_coffee();

	/**
	 * Name: search_price
	 * Description: Searches for coffee drinks within a specified budget.
	 * Parameters: None
	 * Returns: None
	 * Post conditions: Displays the list of coffee drinks within the specified budget.
	*/
	void search_price();

	/**
	 * Name: getNumCoffees
	 * Description: Returns the number of coffee drinks in the menu.
	 * Parameters: None
	 * Returns: int - number of coffee drinks in the menu
	 * Post conditions: None
	 */
	int getNumCoffees() const;

	/**
	 * Name: getCoffeeAt
	 * Description: Returns a pointer to the coffee at the specified index in the menu.
	 * Parameters: int index - index of the coffee in the menu
	 * Returns: coffee* - pointer to the coffee object at the specified index
	 * Post conditions: None
	 */
	coffee *getCoffeeAt(int index) const;

	/**
	 * Name: set_coffee
	 * Description: Sets the coffee attribute of the menu object.
	 * Parameters: const coffee& c - reference to the coffee object to set
	 * Returns: None
	 * Post conditions: Sets the coffee attribute of the menu object to 'c'.
	 */
	void set_coffee(const coffee &c);
};

#endif