#ifndef COFFEE_H
#define COFFEE_H

#include <string>

class coffee {
private:
    std::string name;
    double small_cost;
    double medium_cost;
    double large_cost;

public:
    // Default constructor
    /**
     * Name: coffee
     * Description: Initializes a coffee object with empty name and zero costs for all sizes
     * Parameters: None
     * Returns: None
     * Post conditions: A coffee object is created with empty name and costs set to 0.0 for small, medium, and large sizes
    */
    coffee();

    // Parameterized constructor
    /**
    * Name: coffee
    * Description: Initializes a coffee object with specified name and costs for small, medium, and large sizes
    * Parameters: 
    *       name - name of coffee drink
    *       small_cost - cost of a small coffee
    *       medium_cost - cost of a medium coffee
    *       large_cost - cost of a large coffee
    * Returns: None
    * Post conditions:  A coffee object is created with the specified name and costs for small, medium, and large sizes
   */
    coffee(const std::string& name, double small_cost, double medium_cost, double large_cost);

    // Getters

    /**
     * Name: getName
     * Description: Retrieves the name of the coffee
     * Parameters: None
     * Returns: A string representing the name of the coffee
     * Post-conditions: None
    */
    std::string getName() const;

    /**
     * Name: getSmallCost
     * Description: Retrieves the cost of the small size of the coffee
     * Parameters: None
     * Returns: The cost of the small size of the coffee
     * Post-conditions: None
    */
    double getSmallCost() const;

    /**
     * Name: getMediumCost
     * Description: Retrieves the cost of the medium size of the coffee
     * Parameters: None
     * Returns: The cost of the medium size of the coffee
     * Post-conditions: None
    */
    double getMediumCost() const;

    /**
     * Name: getLargeCost
     * Description: Retrieves the cost of the large size of the coffee
     * Parameters: None
     * Returns: The cost of the large size of the coffee
     * Post-conditions: None
    */
    double getLargeCost() const;

    /*
    
    // Setters

    /**
     * Name: setName
     * 
    
    void setName(const std::string& name);
    void setSmallCost(double cost);
    void setMediumCost(double cost);
    void setLargeCost(double cost);
    */
};

#endif



/*
#ifndef COFFEE_H
#define COFFEE_H

#include <string>

class coffee {
private:
	std::string name;
	double small_cost = 0.0;
	double medium_cost = 0.0;
	double large_cost = 0.0;

public:
	/*
	 * NOTE: THIS IS A REQUIRED FUNCTION. DO NOT ALTER ITS PROTOTYPE.
	 *		YOU MUST IMPLEMENT IT IN `coffee.cpp` OR SET IT TO `default`.
	 *		THIS FUNCTION IS USED BY THE BIG 3 TESTING SCRIPT.
	 * Name: coffee (default constructor)
	 * Description: Constructs a coffee object with an empty name
	 *		and all costs of 0
	 
	coffee();

	coffee(const std::string &name, double small_cost, double medium_cost, double large_cost);
	
	void populate_coffee(coffee &c, std::ifstream &file);

	std::string get_name();
	double get_small_cost();
	double get_medium_cost();
	double get_large_cost();
	
};

#endif
*/