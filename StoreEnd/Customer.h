#ifndef CUSTOMER_H
#define CUSTOMER_H


#include "Product.h"



//datatypes
class Customer {
	int id;
	std::string name;
	double balance;
	std::vector<Product> productsPurchased;
	bool credit;

//accessors
public:
	Customer();
	Customer(int customerID, std::string name, bool credit);
	int getID() const;
	std::string getName() const;
	void setName(std::string name);
	bool getCredit() const;
	void setCredit(bool hasCredit);
	double getBalance()  const;
	void processPayment(double amount );
	void processPurchase (double amount, Product product);
	std::string getProductsPurchased () const;
};


//helper function
std::ostream& operator <<(std::ostream &os, const Customer& rhs);


#endif