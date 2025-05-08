#include "coffee.h"

// Default constructor
coffee::coffee() : name(""), small_cost(0.0), medium_cost(0.0), large_cost(0.0) {}

// Parameterized constructor
coffee::coffee(const std::string& name, double small_cost, double medium_cost, double large_cost)
    : name(name), small_cost(small_cost), medium_cost(medium_cost), large_cost(large_cost) {}

// Getter functions
std::string coffee::getName() const {
    return this->name;
}

double coffee::getSmallCost() const {
    return this->small_cost;
}

double coffee::getMediumCost() const {
    return this->medium_cost;
}

double coffee::getLargeCost() const {
    return this->large_cost;
}

/*
// Setter functions (if necessary)
void coffee::setName(const std::string& name) {
    this->name = name;
}

void coffee::setSmallCost(double cost) {
    small_cost = cost;
}

void coffee::setMediumCost(double cost) {
    medium_cost = cost;
}

void coffee::setLargeCost(double cost) {
    large_cost = cost;
}
*/