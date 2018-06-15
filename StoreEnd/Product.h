//header guards
#ifndef PRODUCT_H
#define PRODUCT_H

#include <iostream>
#include <string>
#include <stdexcept>
#include <sstream>
#include <vector>

//datatypes
class Product {
	int id;
	std::string name;
	std::string description;
	int inventory;
	int numSold;
	double totalPaid;
	

//	accessors
public:
	Product();
	Product(int id, std::string);
	int getID() const;
	std::string getName() const;
	void setName(std::string);
	std::string getDescription() const;
	void setDescription(std::string);
	int getNumberSold() const;
	double getTotalPaid() const;
	int getInventoryCount() const;
	double getPrice() const;
	void addShipment(int, double);
	void reduceInventory(int);
};

//helper function
std::ostream& operator <<(std::ostream &os, const Product& hs);

#endif