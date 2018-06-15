
#include "Product.h"

using namespace std;

//helper function that overloads operator << to help print information 
std::ostream& operator<<(std::ostream &os, const Product& hs)
{
	os << "Product Name: " << hs.getName() << '\n'
	   << "Product ID: " << hs.getID() << '\n'
	   << "Description: " << hs.getDescription() << '\n'
	   << "Inventory: " << hs.getInventoryCount() << '\n'
	   << "Total Paid: " << hs.getTotalPaid()<< '\n';
	return os;
}

//default constructor 
Product::Product(){};
//constructor
Product::Product(int id, string name) : id(id), name(name),
	inventory(0), numSold(0), totalPaid(0.0), description("")
	{
		if (name.length()==0) 
			throw runtime_error("Product name cannot be empty."); //runtime error for empty strings
	}
	
int Product::getID() const //function that gets Product ID and returns it 
{ 
	return id; 
}

string Product::getName() const //function that gets Product name and returns it 
{ 
	return name; 
}

void Product::setName(string productName) 
{
	if (productName.length()==0) 
		throw runtime_error("Product name cannot be empty."); //runtime error for empty strings

	Product::name = productName;
	//return an empty string 
}

string Product::getDescription() const { //function that gets Product ddescription and returns it
 
	return description;  
}

void Product::setDescription(string description) //function that sets Product description
{
	this->description = description; 
}

int Product::getNumberSold() const //function gets the numher of products sold and returns it 
{ 
	return numSold; 
}

double Product::getTotalPaid() const //function gets the number total paid and returns it 
{ 
	return totalPaid; 
}

int Product::getInventoryCount() const //function gets the inventory count and returns it 
{ 
	return inventory;  
}

double Product::getPrice()const //function calculates the price using a given formula and returns the price
{

 	double price = (totalPaid / (inventory + numSold)) * 1.25;
	return price;
 }

void Product::addShipment(int quantity, double shipmentCost) //function calculates shipment cost 
{
	if (quantity < 0 || (shipmentCost < 0) ) 
		throw runtime_error("Shipment quantity and cost must be positive."); //throw runtime error for negative cost or quantity 
	inventory += quantity;
	totalPaid += shipmentCost;
}

void Product::reduceInventory(int quantity)  // fucntion reduces inventory when purchased is made 
{
	if (inventory < quantity) 
	{
		throw runtime_error("Not enough inventory."); //throw runtime error if inventory is less than quantity 
	}

	else if  (quantity < 0)
	{
		throw runtime_error("Not enough quantity."); //throw runtime error if quantity is equal to zero
	}

	else
	{
		inventory -= quantity;
		numSold += quantity;
	}
}



