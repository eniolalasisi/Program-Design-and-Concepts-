#include "Customer.h"

using namespace std;

//helper function that overloads operator << to help print information 
std::ostream& operator<<(std::ostream &os, const Customer& rhs)
{

	string cree = "false";

	if (rhs.getCredit() == 1){
		cree = "true";
	}

	os << "Customer Name: " << rhs.getName() << '\n'
	   << "Customer ID: " << rhs.getID() << '\n'
	   << "Has Credit: " << cree << '\n'
	   << "Balance: " << rhs.getBalance() << '\n'
	   << "Products purchased -- " << '\n'  
	   << '\n'
	   << rhs.getProductsPurchased() << '\n';
	return os;
}

//default consturctor
Customer::Customer(){};
//constructor
Customer::Customer(int id, std::string name, bool credit):
	name(name), id(id), credit(credit), balance (0) {
	if (name.length()==0) 
			throw runtime_error("Customer name cannot be empty."); //runtime error for empty strings
	}

int Customer::getID() const //function that gets Customer ID and returns it 
{ 
	return id; 
}

string Customer::getName() const //function that gets Customer name and returns it 
{ 
	return name; 
}

void Customer::setName(string name) //function sets the Customer name
{
	if (name.length()==0) 
		throw runtime_error("Customer name cannot be empty."); //runtime error for empty strings
    Customer::name = name;
}

bool Customer::getCredit() const // function that gets Customer credit and returns it 
{
	return credit; 
}

void Customer::setCredit(bool hascredit) //function sets the customer credit
{ 
	credit = hascredit; 
}

double Customer::getBalance() const //function gets the Customer baalance and returns it 
{ 
	return balance;
}

void Customer::processPayment (double amount) //function processes payment using ammount and adds to balance 
{ 
	if (amount < 0)
	{
		throw runtime_error("Amount must be positive."); //Throws runtime error for negative amount
	}
		balance += amount;
}

void Customer::processPurchase(double amount, Product product) //processing the payment using vector of products 
{

	bool num = true;
	int num2 = product.getID();

	for (int i=0; i < productsPurchased.size(); i++) //loops through products 
	{
		if (num2 == productsPurchased[i].getID()) 
		{
			num = false;
		} 
	}

	if (amount < 0) 
	{
		throw runtime_error("Not enough amount."); //throws runtime error for negative amount 
	}

	else if (credit == true){ //allows customer purchase given that they hae credit but not balance to purchase 
		balance -= amount;
		if (num)
		productsPurchased.push_back(product);
	}
	 else {
		if (balance >= amount) { // if customer has no credit 
			balance -= amount;
			if (num)
			productsPurchased.push_back(product);
		}
		else {
			throw runtime_error("Not enough credit."); //throw runtime error when cutomer doesn't have enough balance and credit
		}
	}
	
}

string Customer::getProductsPurchased() //gets the products that haven been purchased using previous vector 
const{
	string pur;
	stringstream pout;
	for (int i=0; i < productsPurchased.size(); i++) 
	{
		pout << productsPurchased.at(i) << endl; 
	} 
	pur = pout.str();
	return pur;
}



