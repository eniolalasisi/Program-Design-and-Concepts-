#include "functions.h"

using namespace std;

//functions declarations 


//printUsageInfo that will be called when there are no arguments or only one argument in command line 
void printUsageInfo (string executable) {
	cout << "Usage: " << executable << "[-c] [-s] string ..." << endl;
	cout << "-c: case sensitvity turned on " << endl;
	cout << "-s: ignoring spaces turned off " << endl;

}

// function that allows to check for arguments beginning with quotations so all arguments can be evaluated seperately 
bool isQ (char Q) 
{
	{
		if (Q == '\"' ) 
			return true;
		else
			return false;
		
	}

	return false;
}


// function that allows for checking of all instances of c flags
bool isC (string cmmdline) {
	for (int i =0; i <cmmdline.length(); i++) {
		if (cmmdline.at(i) == 'c' || cmmdline.at(i) == 'C') {
			return true;
		}
	}

	return false;
}

// function that allows for checking of all instances of s flags
bool isS (string cmmdline) {
	for (int i =0; i <cmmdline.length(); i++) {
		if (cmmdline.at(i) == 's' || cmmdline.at(i) == 'S' ) {
			return true;
		}
	}

	return false;
}


// recursive function that evaluates if argument in command line is a Palidrome and allows for checking of flags  
bool isPal(string myString, bool flag_case, bool flag_spaces) {

	if (flag_case == false ) // for case of c flags 
	{
		for (int i = 0; i < myString.length(); i++) { 
			myString.at(i)  = (tolower (myString.at(i))); //lower letters of string 
		}
	}

	string newmyString = "";

	
	if (flag_spaces == false) // for case of f flags 
	{
		for (int i =0; i <myString.length(); i++) 
		{
			if (myString.at(i) != ' ') 
			{
			newmyString = newmyString + myString.at(i); //add string with space
			}
		
   		}

   		myString = newmyString; 
    } 
    
    //block of code evaluates for palidrome
    int pallength = myString.length(); 

		if (pallength <= 1) 
		{
			return 1;
		}

		else if (myString.at(0) == myString.at (pallength -1)) 
		{
			myString = myString.substr(1, (pallength - 2)); //evaluating for palidronme 
			if (isPal(myString, flag_case, flag_spaces))
				return 1;
		}

		else {

			return 0; 
		}

		return 0;
	}





	

