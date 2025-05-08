#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <iomanip>
#include "menu.h"

// Default constructor
menu::menu() : num_coffees(0), coffees(nullptr) {}

// Destructor
menu::~menu() {
    delete[] coffees;
}

// Copy constructor
menu::menu(const menu& other) : num_coffees(other.num_coffees) {
    if (other.coffees) {
        coffees = new coffee[num_coffees];
        for (int i = 0; i < num_coffees; ++i) {
            coffees[i] = other.coffees[i];
        }
    } else {
        coffees = nullptr;
    }
}

// Assignment operator
menu& menu::operator=(const menu& other) {
    if (this != &other) {
        // Free existing memory
        delete[] coffees;
        // Copy data
        num_coffees = other.num_coffees;
        if (other.coffees) {
            coffees = new coffee[num_coffees];
            for (int i = 0; i < num_coffees; ++i) {
                coffees[i] = other.coffees[i];
            }
        } else {
            coffees = nullptr;
        }
    }
    return *this;
}

void menu::get_order() {
    for (int i = 0; i < num_coffees; i++) {
            std::cout << "\t" << i + 1 << ". " << coffees[i].getName() << std::endl;
    }

    int coffee_choice;

    bool inputInvalid = false;
    do {
        std::cout << "Which of the drinks above from our menu would you "
                  << "like to order? Enter 1 - " << num_coffees << ": ";
        std::cin >> coffee_choice;
        if (coffee_choice < 1 || coffee_choice > num_coffees) {
            inputInvalid = true;
            std::cout << std::endl;
            std::cout << "Invalid input!" << std::endl;
            std::cout << std::endl;
        } else {
            inputInvalid = false;
            do {
                std::cout << "Enter the size: s-small, m-medium, l,large: ";
                std::cin >> coffee_size;
                if (coffee_size != "s" &&
                    coffee_size != "m" && 
                    coffee_size != "l") {

                    inputInvalid = true;
                    std::cout << std::endl;
                    std::cout << "Invalid Input!" << std::endl;
                    std::cout << std::endl;
                } else {
                    inputInvalid = false;
                    do {
                        std::cout << "Enter quantity: ";
                        std::cin >> quantity;
                        if (quantity <= 0) {
                            inputInvalid = true;
                            std::cout << std::endl;
                            std::cout << "Quantity has to be greater than 0!" 
                                      << std::endl;
                            std::cout << std::endl;
                        } else {
                            inputInvalid = false;
                            break;
                        }
                    } while (inputInvalid);
                }
            } while (inputInvalid);
        }
    } while (inputInvalid);

    int index = coffee_choice - 1;

    this->coffee_name = coffees[index].getName();

    if (coffee_size == "s") {
        coffee_size == "S";
        this->total_cost = coffees[index].getSmallCost();
    } else if (coffee_size == "m") {
        coffee_size = "M"; 
        this->total_cost = coffees[index].getMediumCost();
    } else if (coffee_size == "l") {
        coffee_size == "L";
        this->total_cost = coffees[index].getLargeCost();
    }
}

std::string menu::get_coffee_name() const {
    return this->coffee_name;
}

std::string menu::get_size_choice() const {
    return this->coffee_size;
}

int menu::get_quantity() const {
    return this->quantity;
}

double menu::get_total_cost() const {
    return this->total_cost;
}

void menu::populate_menu() {
    std::ifstream inFile("menu.txt");
    if (!inFile.is_open()) {
        std::cerr << "Error: Unable to open menu.txt" << std::endl;
        return;
    }

    // Read the number of coffees from the file
    inFile >> this->num_coffees;

    // Deallocate old coffees array if it exists
    if (coffees != nullptr) {
        delete[] coffees;
    }

    // Allocate memory for the coffees array
    coffees = new coffee[this->num_coffees];

    // Read coffee information from the file and populate the coffees array
    for (int i = 0; i < this->num_coffees; ++i) {
        std::string name;
        double small_cost, medium_cost, large_cost;
        inFile >> name >> small_cost >> medium_cost >> large_cost;

        // Create a new coffee object and set its attributes directly
        coffees[i] = coffee(name, small_cost, medium_cost, large_cost);
    }

    // Close the file
    inFile.close();
}


void menu::get_menu() {
    for (int i = 0; i < num_coffees; i++) {
        std::cout << i + 1 << ". "
                  << coffees[i].getName() << " " << std::endl
                  << "   Small - $" << coffees[i].getSmallCost() << " "
                  << std::endl
                  << "   Medium - $" << coffees[i].getMediumCost() << " "
                  << std::endl
                  << "   Large - $" << coffees[i].getLargeCost()
                  << std::endl;
    }
}

bool menu::coffeeExists(const std::string& name) const {
    for (int i = 0; i < num_coffees; ++i) {
        if (coffees[i].getName() == name) {
            return true; // Coffee with the same name already exists
        }
    }
    return false; // No coffee with the same name found
}


// Add a coffee to the menu
void menu::add_coffee() {
    std::ifstream inFile("menu.txt");
    // Read the current number of coffees
    int numCoffees;
    inFile >> numCoffees;
    inFile.close(); // Close the file
    
    std::string name;
    double small_price, medium_price, large_price;

    std::cout << "Enter the name of the new coffee drink (in 1 word): ";
    std::cin >> name;

    // Check if the coffee already exists in the menu
    if (coffeeExists(name)) {
        std::cout << std::endl;
        std::cout << "This coffee already exists in the menu!" << std::endl;
        return; // Exit the function if the coffee already exists
    }

    // Prompt for prices of different sizes
    std::cout << "Enter price of small size (8oz): ";
    std::cin >> small_price;
    std::cout << "Enter price of medium size (12oz): ";
    std::cin >> medium_price;
    std::cout << "Enter price of large size (16oz): ";
    std::cin >> large_price;

    // Create a new coffee object and add it to the menu
    coffee new_coffee(name, small_price, medium_price, large_price);
    
    // Allocate memory for the new array of coffees
    coffee* new_coffees = new coffee[num_coffees + 1];
    
    // Copy existing coffees to the new array
    for (int i = 0; i < num_coffees; ++i) {
        new_coffees[i] = coffees[i];
    }
    
    // Add the new coffee to the end of the array
    new_coffees[num_coffees] = new_coffee;
    
    // Delete the old array of coffees
    delete[] coffees;
    
    // Update the coffees pointer to point to the new array
    coffees = new_coffees;
    
    // Increment the number of coffees
    this->num_coffees++;

    std::ofstream outFile("menu.txt", std::ios_base::trunc);
    // Write the updated number of coffees to the file
    outFile << this->num_coffees << std::endl;

    // Write all coffee items to the file
    for (int i = 0; i < this->num_coffees; ++i) {
        outFile << coffees[i].getName() << " " << coffees[i].getSmallCost() << " "
                << coffees[i].getMediumCost() << " " << coffees[i].getLargeCost() << std::endl;
    }

    std::cout << std::endl;
    std::cout << "This new drink has been successfully added to the coffee menu!" << std::endl;
}

void menu::add_coffee(coffee& c) {
    std::ifstream inFile("menu.txt");
    // Read the current number of coffees
    int numCoffees;
    inFile >> numCoffees;
    inFile.close(); // Close the file

    // Create a new coffee object and add it to the menu
    coffee new_coffee(c.getName(), c.getSmallCost(), c.getMediumCost(), c.getLargeCost());
    
    // Allocate memory for the new array of coffees
    coffee* new_coffees = new coffee[num_coffees + 1];
    
    // Copy existing coffees to the new array
    for (int i = 0; i < num_coffees; ++i) {
        new_coffees[i] = coffees[i];
    }
    
    // Add the new coffee to the end of the array
    new_coffees[num_coffees] = new_coffee;
    
    // Delete the old array of coffees
    delete[] coffees;
    
    // Update the coffees pointer to point to the new array
    coffees = new_coffees;
    
    // Increment the number of coffees
    this->num_coffees++;

    std::ofstream outFile("menu.txt", std::ios_base::trunc);
    // Write the updated number of coffees to the file
    outFile << this->num_coffees << std::endl;

    // Write all coffee items to the file
    for (int i = 0; i < this->num_coffees; ++i) {
        outFile << coffees[i].getName() << " " << coffees[i].getSmallCost() << " "
                << coffees[i].getMediumCost() << " " << coffees[i].getLargeCost() << std::endl;
    }

    std::cout << std::endl;
    std::cout << "This new drink has been successfully added to the coffee menu!" << std::endl;
}

void menu::remove_coffee() {
    int choice;
    bool validChoice;
    do {
        validChoice = true;

        for (int i = 0; i < num_coffees; i++) {
            std::cout << "\t" << i + 1 << ". " << coffees[i].getName() << std::endl;
        }
        std::cout << std::endl;
        std::cout << "Which of the drinks above from our menu would you "
                  << "like to remove? Enter 1 - " << num_coffees << ": ";
        std::string input;
        std::cin >> input;

        // Validate input to ensure it's a valid integer
        bool validInput = true;
        for (char c : input) {
            if (!std::isdigit(c)) {
                validInput = false;
                break;
            }
        }

        if (!validInput) {
            std::cout << std::endl;
            std::cout << "Invalid input. Please enter a valid number." << std::endl;
            validChoice = false;
            continue;
        }

        choice = std::stoi(input);
        if (choice < 1 || choice > num_coffees) {
            std::cout << std::endl;
            std::cout << "Invalid choice. Please enter a number between 1 and " << num_coffees << std::endl;
            validChoice = false;
        }
    } while (!validChoice);

    int index = choice - 1;

    // Shift elements after the removed coffee one position to the left
    for (int i = index; i < num_coffees - 1; ++i) {
        coffees[i] = coffees[i + 1];
    }

    // Update the number of coffees
    --num_coffees;

    // Allocate memory for the new array of coffees
    coffee* new_coffees = new coffee[num_coffees];

    // Copy existing coffees to the new array
    for (int i = 0; i < num_coffees; ++i) {
        new_coffees[i] = coffees[i];
    }

    // Delete the old array of coffees
    delete[] coffees;

    // Update the coffees pointer to point to the new array
    coffees = new_coffees;

    std::cout << std::endl;
    std::cout << "This drink has been successfully removed from the menu!"
              << std::endl;

    // Update menu.txt file
    std::ofstream outFile("menu.txt", std::ios::trunc); // Open file in trunc mode to clear existing content
    if (outFile.is_open()) {
        // Write the updated number of coffees to the file
        outFile << num_coffees << std::endl;

        // Write all coffee items to the file
        for (int i = 0; i < num_coffees; ++i) {
            outFile << coffees[i].getName() << " " << coffees[i].getSmallCost() << " "
                    << coffees[i].getMediumCost() << " " << coffees[i].getLargeCost() << std::endl;
        }
        outFile.close();
    }
}

void menu::search_coffee() {
    bool found = false;

    std::cout << std::endl;
    std::cout << "Enter the coffee name: ";
    std::string name;
    std::cin >> name;

    for (int i = 0; i < num_coffees; ++i) {
        if (coffees[i].getName() == name) {
            found = true;
            std::cout << std::endl;
            std::cout << "Results:" << std::endl;
            std::cout << "1. " << coffees[i].getName() << std::endl;
            std::cout << "   Small: $" << coffees[i].getSmallCost() << std::endl;
            std::cout << "   Medium: $" << coffees[i].getMediumCost() << std::endl;
            std::cout << "   Large: $" << coffees[i].getLargeCost() << std::endl;
            break;
        }
    }
    if (!found) {
        std::cout << std::endl;
        std::cout << "Coffee not found in the menu." << std::endl;
    }
}

void menu::search_price() {
    std::cout << "Enter your budget for one drink, and I will list out "
              << "our cheaper or equal to your budget: ";
    double budget;
    std::cin >> budget;
    std::cout << std::endl;

    // Set precision to 2 decimals
    std::cout << std::fixed << std::setprecision(2);

    for (int i = 0; i < num_coffees; i++) {
        if (coffees[i].getSmallCost() <= budget ||
            coffees[i].getMediumCost() <= budget ||
            coffees[i].getLargeCost() <= budget) {
            std::cout << i + 1 << ". " << coffees[i].getName() << std::endl;
            if (coffees[i].getSmallCost() <= budget) {
                std::cout << "   Small - $" << coffees[i].getSmallCost()
                          << std::endl;
                if (coffees[i].getMediumCost() <= budget)
                    std::cout << "   Medium - $" << coffees[i].getMediumCost()
                               << std::endl;
                    if (coffees[i].getLargeCost() <= budget) {
                        std::cout << "   Large - $"
                                  << coffees[i].getLargeCost()
                                  << std::endl;
                    }
            } else if (coffees[i].getMediumCost() <= budget) {
                std::cout << "   Medium - $" << coffees[i].getMediumCost()
                         << std::endl;
                if (coffees[i].getLargeCost() <= budget) {
                    std::cout << "   Large - $" << coffees[i].getLargeCost()
                              << std::endl;
                }
            } else if (coffees[i].getMediumCost() <= budget) {
                std::cout << "   Large - $" << coffees[i].getLargeCost()
                          << std::endl;
            }
        } else {
            // No drinks within budget
            i = num_coffees;
            std::cout << "There are no drinks within your budget." << std::endl;
        }
    }
}


// Get the number of coffees in the menu
int menu::getNumCoffees() const {
    return this->num_coffees;
}

// Get a pointer to the coffee at a specific index in the menu
coffee* menu::getCoffeeAt(int index) const {
    if (index >= 0 && index < num_coffees) {
        return &coffees[index];
    } else {
        return nullptr;
    }
}

void menu::set_coffee(const coffee& c) {
    this->c = c;
}