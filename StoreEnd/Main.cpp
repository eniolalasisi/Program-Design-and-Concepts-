#include "Product.h"
#include "Customer.h"
#include "Store.h"

using namespace std;

 int main () 
 {
 	Product p (11, "Alex");
 	Product q;
 	
 	p.setName("me");
 	p.setDescription("Good eggs");
 	p.addShipment(20000, 300);
 	//p.reduceInventory(200);

 	Customer d (15, "Sam", true);
 	d.setName("Sam");
 	d.setCredit(true);
 	d.processPayment(500);
 	d.processPurchase(600, p);
 	



 	Store h ("Daniel");
 	h.addProduct(200,"Man");
    h.addProduct(122,"food");
 	h.addCustomer(300,"Me", true);
 	

  h.getProduct(200).addShipment(20000,300);
  cout<< "got the first"<<endl;
  h.getProduct(122).addShipment(200,3);
cout<< "got the second"<<endl;
  h.sellProduct(300,200,5);
    h.sellProduct(300,122,15);

 	h.listProducts();
 	h.listCustomers();
 	//cout << h << endl;

	




	

 	//p.set()
 }
