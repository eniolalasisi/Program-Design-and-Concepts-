#include "mount.h" //include header file with fucntion declration


int colorPath(const vector< vector <int> >& heightMap, vector<vector<int> >& r, vector<vector<int> >& g, vector<vector<int> >& b, int color_r, int color_g, 
int color_b, int start_row)
{
  // variable declrations for function 
int totalpathdistance = 0; 
int columnCount = heightMap[0].size();
int pathdistance2;
int pathdistance3;
int pathdistance;
int minpath; 
int currentRow;


currentRow = start_row;
    int currentColumn = 0;

r [currentRow][currentColumn] = color_r;
g [currentRow][currentColumn] = color_g;
b [currentRow][currentColumn] = color_b;


    for (int i = 0; i < columnCount-1; i++) // checks if the columns are less than 1 
    {
        if (currentRow-1 < 0)
        {
           pathdistance = heightMap[currentRow][i] - heightMap[currentRow][i + 1]; // indexes of the pathdistance at each starting point 
           pathdistance = abs (pathdistance); // absolute vale 
           pathdistance2 = heightMap[currentRow][i] - heightMap[currentRow + 1][i + 1]; // indexes of the pathdistance at each starting point 
           pathdistance2 = abs (pathdistance2); //absolute value calculation 
           pathdistance3 = heightMap[currentRow][i] - heightMap[currentRow][i+1]; // indexes of the pathdistance at each starting point 
           pathdistance3 = abs (pathdistance3); //absolute value calcuation 

        }

        else if (currentRow == heightMap.size()-1) 
        {
           pathdistance = heightMap[currentRow][i] - heightMap[currentRow][i + 1]; // indexes of the pathdistance at each starting point 
           pathdistance = abs (pathdistance); //absolute value calculation 
           pathdistance2 = heightMap[currentRow][i] - heightMap[currentRow][i + 1]; // indexes of the pathdistance at each starting point 
           pathdistance2 = abs (pathdistance2);  // absolute value calcuation 
           pathdistance3 = heightMap[currentRow][i] - heightMap[currentRow-1][i+1]; // indexes of the pathdistance at each starting point 
           pathdistance3 = abs (pathdistance3); // absolute value calculation 
        }

        else
        {    
           pathdistance = heightMap[currentRow][i] - heightMap[currentRow][i + 1]; // // indexes of the pathdistance at each starting point 
           pathdistance = abs (pathdistance); // ansolute value calcuation 
           pathdistance2 = heightMap[currentRow][i] - heightMap[currentRow + 1][i + 1]; // indexes of the pathdistance at each starting point 
           pathdistance2 = abs (pathdistance2); // absolute value calcualtion 
           pathdistance3 = heightMap[currentRow][i] - heightMap[currentRow-1][i+1]; // indexes of the pathdistance at each starting point 
           pathdistance3 = abs (pathdistance3); // absolute value calculation 
        }   
            
            minpath = min(pathdistance2,pathdistance3); // calculate minium pathdistance 
            minpath = min(minpath,pathdistance); //calculates minium pathdistance 

            if (pathdistance == minpath) // if it is minium path 
            {
                totalpathdistance += pathdistance; // running total of totalpathdistance 
                currentColumn++; // move forward 
            }
            else if (pathdistance2 == minpath) // if it is minium path 
            {
                totalpathdistance += pathdistance2; // add to running totalpathdistance 
                currentColumn++; //move foward 
                currentRow++;   // and down 
            }

            else if (pathdistance3 == minpath) // if its is mini path 
            {
                totalpathdistance += pathdistance3; // add to running totalpathdistance 
                currentColumn++; //move forward
                currentRow--; // move up 
            }

            // color minium path distance 
            r [currentRow][currentColumn] = color_r; 
            g [currentRow][currentColumn] = color_g;
            b [currentRow][currentColumn] = color_b;


            

}






//return running tootal of totalpathdistance 
return totalpathdistance; 

}




























