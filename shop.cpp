#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
#include "shop.h"

// Default constructor (with default values)
shop::shop() : phone(""), address(""), revenue(0.0), num_orders(0), orders(nullptr) {}

// Destructor
shop::~shop() {
    delete[] orders;
}

// Copy constructor
shop::shop(const shop& other) {
    m = other.m;
    phone = other.phone;
    address = other.address;
    revenue = other.revenue;
    num_orders = other.num_orders;
    if (other.orders) {
        orders = new order[num_orders];
        for (int i = 0; i < num_orders; ++i) {
            orders[i] = other.orders[i];
        }
    } else {
        orders = nullptr;
    }
}

shop& shop::operator=(const shop& other) {
    if (this != &other) {
        m = other.m;
        phone = other.phone;
        address = other.address;
        revenue = other.revenue;
        num_orders = other.num_orders;
        // Free existing memory
        delete[] orders;
        // Copy data
        if (other.orders) {
            orders = new order[num_orders];
            for (int i = 0; i < num_orders; ++i) {
                orders[i] = other.orders[i];
            }
        } else {
            orders = nullptr;
        }
    }
    return *this;
}

void shop::get_orders() const {
    std::ifstream inFile("orders.txt");

    if (inFile.good()) {
        
        std::string line;

        // Read the first line
        if (std::getline(inFile, line)) {
            num_orders;
        }

        // Print the first line
        std::cout << std::endl;
        std::cout << "Number of orders: " << num_orders << std::endl;

        // Read and print the remaining lines
        while (std::getline(inFile, line)) {
            std::cout << line << std::endl;
        }
    } else {
        std::cout << "(No orders to display)" << std::endl;
    }


    inFile.close();
}

void shop::add_order() {
    m.get_order();

    int order_number = this->num_orders;

    double total_cost = m.get_total_cost() * m.get_quantity();

    // Set precision to 2 for all floating-point output
    std::cout << std::fixed << std::setprecision(2);
    std::cout << std::endl;
    std::cout << "Your total cost is: $" << total_cost << std::endl;

    bool inputInvalid = true; // Initialize to true to enter the loop
    int confirmed;

    do {
        std::cout << "Confirmed? 1-yes, 0-no: ";
        std::cin >> confirmed;
        if (confirmed == 1) {

            // Create a new coffee object and add it to the menu
            order new_order(order_number, m.get_coffee_name(), m.get_size_choice()[0], m.get_quantity());

            // Allocate memory for the new array of orders
            order* new_orders = new order[this->num_orders + 1];

            // Copy existing orders to the new array
            for (int i = 0; i < this->num_orders; ++i) {
                new_orders[i] = orders[i];
            }

            // Add the new order to the end of the array
            new_orders[this->num_orders] = new_order;

            // Deallocate memory for the old array
            delete[] orders;

            // Update the orders pointer to point to the new array
            orders = new_orders;

            this->num_orders++;
            order_number++;
            this->revenue += total_cost;

            inputInvalid = false;
            std::cout << std::endl;
            std::cout << "Your order has been placed. You are order #" << order_number << "." << std::endl;

            // Open file for appending
            std::ofstream outFile("orders.txt", std::ios_base::trunc);

            if (outFile.is_open()) {
                // Append order information to the file
                outFile << this->num_orders << std::endl;
                for (int i = 0; i < this->num_orders; i++) {
                    outFile << i + 1 << " " 
                            << orders[i].getCoffeeName() << " "
                            << orders[i].getCoffeeSize() << " "
                            << orders[i].getQuantity()
                            << std::endl;
                }
            } else {
                std::cerr << "Failed to open orders.txt for appending" << std::endl;
            }
        } else if (confirmed == 0) {
            inputInvalid = false;
            std::cout << std::endl;
            std::cout << "Your order has been cancelled." << std::endl;
        } else {
            std::cout << "Invalid input!" << std::endl;
        }
    } while (inputInvalid);
}

void shop::add_order(order& o) {
    // Set precision to 2 for all floating-point output
    std::cout << std::fixed << std::setprecision(2);
    std::cout << std::endl;

    // Create a new coffee object and add it to the menu
    order new_order(o.getOrderNumber(), o.getCoffeeName(), o.getCoffeeSize(), o.getQuantity());

    // Allocate memory for the new array of orders
    order* new_orders = new order[this->num_orders + 1];

    // Copy existing orders to the new array
    for (int i = 0; i < this->num_orders; ++i) {
        new_orders[i] = orders[i];
    }

    // Add the new order to the end of the array
    new_orders[this->num_orders] = new_order;

    // Deallocate memory for the old array
    delete[] orders;

    // Update the orders pointer to point to the new array
    orders = new_orders;

    this->num_orders++;
    this->revenue += o.getTotalCost();

    // Open file for appending
    std::ofstream outFile("orders.txt", std::ios_base::trunc);

    if (outFile.is_open()) {
        // Append order information to the file
        outFile << this->num_orders << std::endl;
        for (int i = 0; i < this->num_orders; i++) {
            outFile << i + 1 << " " 
                    << orders[i].getCoffeeName() << " "
                    << orders[i].getCoffeeSize() << " "
                    << orders[i].getQuantity()
                    << std::endl;
        }
    } else {
        std::cerr << "Failed to open orders.txt for appending" << std::endl;
    }
}


void shop::populate_info(std::ifstream& file) {
    // Read data from file and store it in member variables
    if (file.is_open()) {
        getline(file, this->phone);
        getline(file, this->address);
    }
}

void shop::addCoffeeToMenu() {
    m.add_coffee();
    m.populate_menu();
}

void shop::add_coffee_to_menu(coffee& c) {
    m.add_coffee(c);
    m.populate_menu();
}

void shop::removeCoffeeFromMenu() {
    m.remove_coffee();
    m.populate_menu();
}

void shop::search_coffee_menu() {
    m.search_coffee();
}

void shop::search_coffee_price() {
    m.search_price();
}

// Getters and setters
menu shop::getMenu() const {
    return m;
}

std::string shop::get_phone() const {
    return phone;
}

std::string shop::get_address() const {
    return address;
}

double shop::get_revenue() const {
    return revenue;
}

int shop::getNumOrders() const {
    return num_orders;
}

void shop::set_menu(const menu& m) {
    this->m = m;
}