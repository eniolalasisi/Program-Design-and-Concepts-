//header guards

#ifndef STORE_H
#define STORE_H

#include "Product.h"
#include "Customer.h"

class Store {

//datatypes

std::string name;
std::vector<Product> products;
std::vector<Customer> customers;
    double cost;
    double amount;

//functions
public:
	Store();
	Store(std::string name);
	std::string getName() const;
	void setName(std::string name);
	void addProduct(int productID, std::string productName); 
	Product& getProduct(int productID); 
	void addCustomer(int customerID, std::string customerName, bool credit); 
	void addCustomer(int customerID, std::string customerName);
	Customer& getCustomer(int customerID); 
	void takeShipment(int productID, int quantity, double cost); 
	void sellProduct(int customerID, int productID, int quantity);
	void takePayment(int customerID, double amount);
	std::string listProducts();
	std::string listCustomers();
	void listProducts() const;
    void listCustomers() const;


};




#endif