#include "Store.h"

using namespace std;
#include <sstream>

//default consturctor
Store::Store(){};

//consturctor
Store::Store(string name): name (name){};

string Store::getName() const //function that gets Store name and returns it
{
	return name;
}

void Store::setName(string newName) //function sets the Store name
{
	this->name = newName;
}

 //function adds a product, check if it already exists and if it doesn't pushses it into the product vector 
void Store::addProduct(int productID, string productName)
{
	for (int i = 0; i < products.size(); i++) 
		{
			if (products.at(i).getID() == productID) 
			{
				throw runtime_error("Product exists");
			}
		}

	products.push_back(Product(productID, productName));
}


//function gets a product given its ID  and checks if that ID exists by looping through product vector 
Product& Store::getProduct(int productID)
{
	bool find = false;

	for (int i = 0; i < products.size(); i++) 
		{
			if (products.at(i).getID()==productID) 
			{
				find = true;
				return products.at(i);
			}
		}

		if (!find)
			throw runtime_error("Product Not Found");
}


 //function adds a customer, check if the customer already exists and if they doesn't pushses them into the customer vector
void Store::addCustomer(int customerID, string customerName, bool credit)
{
	for (int i = 0; i < customers.size(); i++) 
		{
			if (customers.at(i).getID() == customerID) 
			{
				throw runtime_error("Customer exists");
			}
		}
	customers.push_back(Customer(customerID, customerName, credit));
}


//function gets a customer given their ID  and checks if that ID exists by looping through customer vector; overloaded function that sets customer credit to false by default 
void Store::addCustomer(int customerID, string customerName)
{
	for (int i = 0; i < customers.size(); i++) 
		{
			if (customers.at(i).getID() == customerID) 
			{
				throw runtime_error("Customer exists");
			}
		}

	bool credit = false;
	customers.push_back(Customer(customerID, customerName, credit));
}

//function gets a customer given their ID  and checks if that ID exists by looping through customer vector
Customer& Store::getCustomer(int customerID)
{

	bool find = false;
	for (int i = 0; i < customers.size(); i++) 
		{
			if (customers.at(i).getID()==customerID) 
			{
				find = true;
				return customers.at(i);
				
			}
		}

		if (!find)
			throw runtime_error ("Customer not found");
}


//fucntion allows a sale by using processPurchase from customer class and reduce inventory from product class; changes quanitity into amount so function parameters are valid 
void Store::sellProduct(int customerID, int productID, int quantity)
{
	getProduct(productID).reduceInventory(quantity);
    amount = getProduct(productID).getPrice() * quantity;
    getCustomer(customerID).processPurchase(amount, getProduct(productID));    
}

//function take product ID and finds it quantity and shipment cost; uses getProduct to catch its error 
void Store::takeShipment(int productID, int quantity, double cost)
{

	getProduct(productID).addShipment(quantity, cost);
	
}


//finds the matching customer and processes their payment 
void Store::takePayment(int customerID, double amount)
{
	    getCustomer(customerID).processPayment(amount);

}

//outputs information about products; uses the overloaded opertaor 
 void Store::listProducts() const
{
	for (int i = 0; i < products.size(); i++) 
		{
			cout << products.at(i)<< endl;
		}
}


//outputs information about customers; uses overloaded opertaor 
 void Store::listCustomers() const
{
	 for (int i = 0; i < customers.size(); i++) 
		{
			cout << customers.at(i)<< endl;
		}
}

//allows the listProducts to be returned as string 
string Store::listProducts() 
{
    ostringstream os;
    if(products.size() == 0)
    {
        os << "No Products" << endl;
    }
    else
    {
        for(int i = 0; i < products.size(); i++)
        {
            Product product = products.at(i);
            os << products.at(i) << endl;
            cout << products.at(i) << endl;
        }
    }
    return os.str();
}

//allows the listCustomer to be returned as string 
string Store::listCustomers()
{
    ostringstream os;
    if(customers.size() == 0)
    {
        os << "No Customer" << endl;
    }
    else
    {
        for(int i = 0; i < customers.size(); i++)
        {
            Customer customer = customers.at(i);
            os << customers.at(i) << endl;
            cout << customers.at(i) << endl;
        }
    }
    return os.str();
}









