
#include "mount.h" //include header file with function declaration

//variable declaration 
int main()
{
   double max;
   double min;
   int rows;
   int columns;
   int shadeofgray;
   string fname;
   int data;
   string str;
   vector<int>temp; //temporary vector to store values 
   vector<long long int> tempi;
   vector<vector<double> >  temp2; // temporary vector that stores vector values 
   string ofname;
   int i;
   int j;
   int a;
   int b;
   int c;
   int d;
   int e;
   int f;
   int g;
   int maxi; // stores max value
   int mini; // stores min value
   vector <long long int> paths;
   
   
   cout << "How many rows?" << endl; //ask user number of rows in file 
   cin >> rows; // user enters number of rows 
   cout << endl;
   
   cout << "How many columns?" << endl; // ask user number of columns in file   
   cin >> columns; //user enters columns
   cout <<endl;
   
   cout << "What is the name of the file?" << endl; //ask user name of file 
   cin >> fname; // user enters name 
   cout <<endl;
   
   vector<vector<int> > vec2; // 2D vector that stores elvation data 
   vector<vector<vector<double> > > vec3; //3D vector that stores RGB values
   vector<vector<int> > red;
   vector<vector<int> > green;
   vector<vector<int> > blue;

    
    
    ifstream ifs; //binds file to ifstream object 
    ifs.open(fname); //opens user file input 
    

    
    for ( i =0;  i < rows;  i++ ) { //for loop that reads from file 
        for ( j=0;  j < columns;  j++) {
            if (!ifs.eof()) // if stream is not at end 
            ifs >> data; 
            if (ifs.bad()) { // if unrecoverable error end program 
                return 1;
            }
            if (ifs.fail()) { // if recoverable error, clear and ignore 
                ifs.clear();
                ifs.ignore();
            }
            temp.push_back(data); //push data into temporary vector 
        }
            vec2.push_back(temp); //push temporary vector into 2D vector 
            temp.clear(); //clear temporary vector 
    }

    
    if (vec2.size() != rows || vec2[vec2.size()-1].size() != columns ) { //if user input does not match row and columns give an error and end program 
        cout << "Error: Incorrect number of rows or columns";
        return 1;
    }

    
    
    
    max = vec2[0][0];
    min = vec2[0][0];
    
    for (int a =0; a < rows; a++ ) {	// for loop that Calculates max and min values 
        
		maxi  = *max_element(vec2[a].begin(), vec2[a].end()); //Calculates max value 
		
		if (max <= maxi)
            max = *max_element (vec2[a].begin(), vec2[a].end()); //updates max value 
        
        mini = *min_element (vec2[a].begin(), vec2[a].end()); //Calculates min value 
        
        if  (min >= mini)
            min = *min_element (vec2[a].begin(), vec2[a].end()); //updates min value 
        
    }

    
    
    for (b =0; b<rows; b++) { // for loop for calcuating shadeofgray value 
        for (c =0; c <columns;c++ ) {
         
             shadeofgray = ((vec2[b][c]-min)/(max-min)) * 255; //shadeofgray calcuation 
             temp.push_back(shadeofgray); //push shadeofgray value into temporary vector 
         }
         
            red.push_back(temp); // push temporary vector into 2D temporary vector 
            green.push_back(temp);
            blue.push_back(temp);
            temp.clear(); // clear temporary vector 
        
             
    }



    long long int num;
// calling the function 
    for (int i =0; i < rows; i++) 
    {
      num = colorPath(vec2, red, green, blue, 252,25,63, i);
      paths.push_back( num  ); 


    }
    

    tempi = paths;
//allows to osort running total in order to get shortest path 
    sort(tempi.begin(), tempi.end());

    for(int i =0; i< paths.size(); i++)
    {
      if(tempi[0] == paths[i])
      {
        num = i;
        break;
      }
    }

//color shortest path green 
    colorPath(vec2, red, green, blue, 31,253,13, num);


   for (int i =0; i < tempi.size(); i++)
    cout << tempi [i] << endl;

    tempi.clear();







    
    ofname = fname + ".ppm"; //create file with ppm extension 
    
    ofstream outputfile; // bind file to ofstream object 
    outputfile.open (ofname); // open outputfile 
    
    //writing into file 
    outputfile << "P3" << endl; //first line of file 
    outputfile << columns <<" "<<rows << endl; // second line of file (columns and rows)
    outputfile << "255" << endl; // third line of file maxium 
    
    for (e =0; e<rows; e++) {  // for loops that print out 3D vector into created file 
        for (f=0; f<columns;f++ ) {
         //for (g=0; g <3; g++) {

             outputfile << red[e][f] << " "; //printing out 3D vector with spaces
             outputfile << green[e][f] << " "; //printing out 3D vector with spaces
             outputfile << blue[e][f] << " "; //printing out 3D vector with spaces
         //}
        }
            outputfile << endl; // ending line after each row 
        }

    ifs.close(); //close ifstream file
    outputfile.close(); //close ofstream file 

    

    return 0;
}



