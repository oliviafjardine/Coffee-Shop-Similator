#include <cctype>
#include "order.h"

// Default constructor
order::order() : order_number(0), coffee_name(""), coffee_size('\0'), quantity(0) {}

// Parameterized constructor
order::order(int order_number, const std::string& coffee_name, char coffee_size, int quantity)
    : order_number(order_number), coffee_name(coffee_name), coffee_size(coffee_size), quantity(quantity) {}

// Getter functions
int order::getOrderNumber() const {
    return order_number;
}

std::string order::getCoffeeName() const {
    return coffee_name;
}

char order::getCoffeeSize() const {
    return std::toupper(coffee_size);
}

int order::getQuantity() const {
    return quantity;
}

double order::getTotalCost() {
    return total_cost;
}

/*
// Setter functions (if necessary)
void order::setOrderNumber(int order_number) {
    this->order_number = order_number;
}

void order::setCoffeeName(const std::string& coffee_name) {
    this->coffee_name = coffee_name;
}

void order::setCoffeeSize(char coffee_size) {
    this->coffee_size = coffee_size;
}

void order::setQuantity(int quantity) {
    this->quantity = quantity;
*/