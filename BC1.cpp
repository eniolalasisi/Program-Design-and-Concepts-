#include <iostream> 
#include <cmath>
#include <vector>
#include <random>
#include <string>
#include <cstdlib>
using namespace std;


vector <int> split_num( int y, int v) //create function that can be called later

{

  int a,b,c,d,e,f;

  vector <int> nu;

if (y<=9) {

for (int i =0; i<v -1; i++) { //allows for leading zeros if user doesn't put all digits they hav declared 
nu.push_back(0);
}
nu.push_back(y);

}

else if (y<=99) {
for (int i =0; i< v -2; i++) { //allows for leading zeros if user doesn't put all digits they have declared 
nu.push_back(0);
}

f = y;

a=y/10;
y=y%10;
nu.push_back(a);

b = y;

nu.push_back(b);

}



else if (y<= 999) {
for (int i =0; i<v -3; i++) { //allows for leading zeros if user doesn't put all digits they have declared 
nu.push_back(0);
}

f=y;
a =y/100; // allowing for seperation of digits in order to enter vector 
y = y % 100; // allowing for seperation of digits to enter vector 
nu.push_back(a); //put the digit into the vector 


b = y/10;
y= y % 10;

nu.push_back(b); //put the digit into the vector 

c=y; 
nu.push_back(c); //put the digit into the vector 
}

 else if ( y<= 9999) {
for (int i =0; i<v -4; i++) {  //allows for leading zeros if user doesn't put all digits they have declared 
nu.push_back(0);
}

f=y;

a =y/1000; // allowing for seperation of digits in order to enter vector 
y = y % 1000;
nu.push_back(a); //put the digit into the vector 


b = y/100;
y= y % 100;  // allowing for seperation of digits to enter vector 
nu.push_back(b);


c=y/10;
y=y%10; // allowing for seperation of digits to enter vector 
nu.push_back(c); //put the digit into the vector 

d=y;
nu.push_back(d); //put the digit into the vector 
}


else if ( y<= 99999) {


f=y;

a =y/10000;
y = y % 10000;  // allowing for seperation of digits in order to enter vector 
nu.push_back(a); //put the digit into the vector 


b = y/1000;
y= y % 1000;  // allowing for seperation of digits in order to enter vector 
nu.push_back(b); //put the digit into the vector 


c=y/100;
y=y%100;  // allowing for seperation of digits in order to enter vector 
nu.push_back(c); //put the digit into the vector 


d=y/10;
y=y%10;  // allowing for seperation of digits in order to enter vector 
nu.push_back(d); //put the digit into the vector 

e=y;
nu.push_back(e); //put the digit into the vector 

}

return nu;
}


int main () {
	bool stu = true; //variable declaration 
	int x=0; //variable declaration 
	int y; //variable declaration 
	int a; //variable declaration 
	int b; //variable declaration 
	int c; //variable declaration 
	int m; //variable declaration 
	int d; //variable declaration 
	int e; //variable declaration 
	int f; //variable declaration 
	vector <int> nu; //vector declaration 
	int ran; // //variable declaration 
	int check; //variable declaration 
	int v=0; //variable declaration 
	int guess=0; //variable declaration 
	int bull = 0; //variable declaration 
	int cow=0; //variable declaration 
bool cond1 = true; // defines a bool variableas true to satisfy an initial condition
  bool cond2 = false;// defines a bool variableas false to satisfy an initial condition
  bool cond3 = true;
  vector<int> guessvec;  //vector declaration 

while (stu) { // while statement repeats if user does not enter 0, 3, 4, 5

cout << "Enter number of digits in code (3, 4 or 5): " ; //prompts users to enter difits in code 
cin >> x;
cout << endl;
if (x != 0 &&  x != 3 && x != 4 && x != 5) {
	stu = true; 
}

else {
stu = false;
}
}

if ( x == 0) { //test code; if user enters 0
cout << "Enter code: ";
cin >> y;
cout << endl;

cout<<"Number of digits in code: ";
cin >> v;
cout << endl;


nu = split_num(y,v);

cout << "Number to guess: ";
for (int i =0; i<nu.size(); i++) { // for statement allows the vector to be printed 
cout << nu[i];
}
cout<<endl;
 

}

else { //if not zero; if 3, 4, 5
check = 0; // allows to check for duplicate
for (int i=0;i<x; i++) { // for statment generates a random number between 0 and 9
 ran = (rand () % 9);

                       
 for (int j=0; j < nu.size(); j++)  

	 if (ran == nu[j]) { // for statement checks for duplicate
 	check = check +1; 
  }

if (check < 1 ) { //if there is no duplicate
nu.push_back(ran); //push the randomly generated number into the vector 
}

else
{
check = 0;
i = i-1;
}

}

cout << "Number to guess: ";
for (int i =0; i<nu.size(); i++) { // for statement allows the vector to be printed 
cout << nu[i];
}
cout<<endl;


}


while (cond1 == true) // while loop that doesnt break till the user wins
  {
   
    
      
check = 1; // allows to check for duplicate

while (check > 0){
//check = 1;

v = max(x,v);
 while(guessvec.size() != v)
 {
      cout << "Enter guess: ";// more instructions to the user
      cin >> guess;
      cout << endl;
      guessvec = split_num(guess,v);
      if(guessvec.size() != v)
      {
        cout<<"You can only enter "<< v <<" digits "<<endl;
      }
 }// guess while loop 

 
for (int i=0;i<v; i++)  
 {
 for (int j=0; j < v; j++)  
{
   if (guessvec[i] == guessvec[j] && i != j)  // for statement checks for duplicate
  check = check +1; 
  
}

}

if (check > 1) // if there are duplicates
{
  cout << "Each number must be different."<<endl;
  guessvec.erase(guessvec.begin() + 0, guessvec.begin() + v);// erases the guess vector
  check =1;
}

else {
check = 0;

}
// check while loop


}
    for(int j =0 ; j < guessvec.size(); j++)// for loop to count the bulls
    {
      if (guessvec[j] == nu[j])
      bull =bull+1;
    }
    for(int j =0 ; j < guessvec.size(); j++) // for loop to count the cows
    {
      for(int k =0 ; k < guessvec.size(); k++) // nested for loop that checks for equality in the 'nuvec' and 'guessvec'
      {
        if (guessvec[j] == nu[k] && j != k)
        {
          cow = cow+1;
        }
      }
    }
    if (bull == v)// condition to win the game
    {
      
cout << v <<" bulls - "; 

      for (int i =0; i < guessvec.size(); i++) {

        cout << guessvec[i];
      
      }

cout << " is Correct!" <<endl;
      cond1 = false;
    }
    else
    {
      cout << bull << " bulls"<< endl;//score output
      cout << cow<<" cows"<<endl;// score output
      cow = 0; //reset cow
      bull = 0;// rest bull
      guessvec.clear();// erases the guess vector
      cond3 = true; // sets the guess vector counter condition back to true
    
  }





}// cond while loop
     

  return 0;
}










              









 
