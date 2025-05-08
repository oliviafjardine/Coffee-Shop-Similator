#ifndef ORDER_H
#define ORDER_H

#include <string>

class order {
private:
    int order_number;
    std::string coffee_name;
    char coffee_size;
    int quantity;
	double total_cost;

public:
    /**
	 * Name: order
	 * Description: Default constructor for the order class.
	 * Parameters: None
	 * Returns: None
	 * Post conditions: Initializes order_number to 0, coffee_name to an empty string, coffee_size to '\0', and quantity to 0.
	 */
    order();

	/**
	 * Name: order
	 * Description: Parameterized constructor for the order class.
	 * Parameters: 
	 *  - int order_number: the order number
	 *  - const std::string& coffee_name: the name of the coffee
	 *  - char coffee_size: the size of the coffee
	 *  - int quantity: the quantity of coffee ordered
	 * Returns: None
	 * Post conditions: Initializes order_number, coffee_name, coffee_size, and quantity with the provided values.
	 */
    order(int order_number, const std::string& coffee_name, char coffee_size, int quantity);

    /**
	 * Name: getOrderNumber
	 * Description: Getter function to retrieve the order number.
	 * Parameters: None
	 * Returns: int - the order number
	 * Post conditions: None
	 */
    int getOrderNumber() const;

	/**
	 * Name: getCoffeeName
	 * Description: Getter function to retrieve the coffee name.
	 * Parameters: None
	 * Returns: std::string - the name of the coffee
	 * Post conditions: None
	 */
    std::string getCoffeeName() const;

	/**
	 * Name: getCoffeeSize
	 * Description: Getter function to retrieve the coffee size in uppercase.
	 * Parameters: None
	 * Returns: char - the size of the coffee (uppercase)
	 * Post conditions: None
	 */
    char getCoffeeSize() const;

	/**
	 * Name: getQuantity
	 * Description: Getter function to retrieve the quantity of coffee ordered.
	 * Parameters: None
	 * Returns: int - the quantity of coffee ordered
	 * Post conditions: None
	 */
	int getQuantity() const;

	double getTotalCost();

	/*
	/**
	 * Name: setOrderNumber
	 * Description: Setter function to set the order number.
	 * Parameters: int order_number - the order number to set
	 * Returns: None
	 * Post conditions: Updates the order number with the provided value.
	 
	void setOrderNumber(int order_number);

	/**
	 * Name: setCoffeeName
	 * Description: Setter function to set the coffee name.
	 * Parameters: const std::string& coffee_name - the name of the coffee to set
	 * Returns: None
	 * Post conditions: Updates the coffee name with the provided value.
	 
    void setCoffeeName(const std::string& coffee_name);

	/**
	 * Name: setCoffeeSize
	 * Description: Setter function to set the coffee size.
	 * Parameters: char coffee_size - the size of the coffee to set
	 * Returns: None
	 * Post conditions: Updates the coffee size with the provided value.
	 
    void setCoffeeSize(char coffee_size);

	/**
	 * Name: setQuantity
	 * Description: Setter function to set the quantity of coffee ordered.
	 * Parameters: int quantity - the quantity of coffee to set
	 * Returns: None
	 * Post conditions: Updates the quantity of coffee with the provided value.
	 
    void setQuantity(int quantity);
	*/
};

#endif