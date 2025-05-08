#ifndef SHOP_H
#define SHOP_H

#include <string>
#include "menu.h"
#include "order.h"

class shop {
private:
    menu m;
	order o;
    std::string phone;
    std::string address;
    double revenue;
    int num_orders;
    order* orders;

public:
    /**
     * Name: shop
     * Description: Default constructor for the shop class.
     * Parameters: None
     * Returns: None
     * Post conditions: Initializes phone, address, revenue to 0.0, num_orders to 0, and orders to nullptr.
     */
    shop();

    /**
     * Name: ~shop
    * Description: Destructor for the shop class.
    * Parameters: None
    * Returns: None
    * Post conditions: Deallocates memory for the orders array.
    */
    ~shop();

    /**
     * Name: shop
     * Description: Copy constructor for the shop class.
     * Parameters: const shop& other - reference to another shop object to be copied from
     * Returns: None
     * Post conditions: Creates a copy of the shop object.
     */
    shop(const shop& other);

    /**
     * Name: operator=
     * Description: Assignment operator for the shop class.
     * Parameters: const shop& other - reference to another shop object to be assigned from
     * Returns: shop& - reference to the modified shop object
     * Post conditions: Copies the data from another shop object and returns a reference to this modified object.
     */
    shop& operator=(const shop& other);

    /**
     * Name: get_orders
     * Description: Reads and prints the orders from a file.
     * Parameters: None
     * Returns: None
     * Post conditions: None
     */
	void get_orders() const;

    /**
     * Name: add_order
     * Description: Adds a new order to the shop.
     * Parameters: None
     * Returns: None
     * Post conditions: Adds a new order to the shop's order list and updates the orders.txt file.
     */
	void add_order();

    /**
     * 
    */
    void add_order(order& o);

    /**
     * Name: populate_info
     * Description: Reads shop information from a file and populates member variables.
     * Parameters: std::ifstream& file - reference to the input file stream
     * Returns: None
     * Post conditions: Populates phone and address member variables with data from the file.
     */
	void populate_info(std::ifstream &file);

	/**
     * Name: addCoffeeToMenu
     * Description: Adds a new coffee drink to the shop's menu.
     * Parameters: None
     * Returns: None
     * Post conditions: Adds a new coffee item to the menu and updates the menu file.
     */
    void addCoffeeToMenu();

    /**
     * Name: addCoffeeToMenu
     * Description: Adds a new coffee drink to the shop's menu.
     * Parameters: coffee& c - coffee class
     * Returns: None
     * Post conditions: Adds a new coffee item to the menu and updates the menu file.
     */
	void add_coffee_to_menu(coffee& c);

    /**
     * Name: removeCoffeeFromMenu
     * Description: Removes a coffee drink from the shop's menu.
     * Parameters: None
     * Returns: None
     * Post conditions: Removes a coffee item from the menu and updates the menu file.
     */
	void removeCoffeeFromMenu();

    /**
     * Name: search_coffee_menu
     * Description: Searches for a coffee item in the shop's menu by name.
     * Parameters: None
     * Returns: None
     * Post conditions: None
     */
	void search_coffee_menu();

    /**
     * Name: search_coffee_price
     * Description: Searches for coffee items in the shop's menu within a given price range.
     * Parameters: None
     * Returns: None
     * Post conditions: None
     */
	void search_coffee_price();

	/**
     * Name: getMenu
     * Description: Getter function to retrieve the menu.
     * Parameters: None
     * Returns: menu - the shop's menu
     * Post conditions: None
     */
    menu getMenu() const;

    /**
     * Name: get_phone
     * Description: Getter function to retrieve the shop's phone number.
     * Parameters: None
     * Returns: std::string - the phone number
     * Post conditions: None
     */
    std::string get_phone() const;

    /**
     * Name: get_address
     * Description: Getter function to retrieve the shop's address.
     * Parameters: None
     * Returns: std::string - the address
     * Post conditions: None
     */
    std::string get_address() const;

    /**
     * Name: get_revenue
     * Description: Getter function to retrieve the shop's revenue.
     * Parameters: None
     * Returns: double - the revenue
     * Post conditions: None
     */
    double get_revenue() const;

    /**
     * Name: getNumOrders
     * Description: Getter function to retrieve the number of orders.
     * Parameters: None
     * Returns: int - the number of orders
     * Post conditions: None
     */
    int getNumOrders() const;

    /**
     * Name: set_menu
     * Description: Setter function to set the shop's menu.
     * Parameters: const menu& m - reference to the menu to set
     * Returns: None
     * Post conditions: Updates the shop's menu with the provided menu.
     */
    void set_menu(const menu& m);
};

#endif