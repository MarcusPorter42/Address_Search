#include <iostream>
#include <fstream>
#include "bst.h"

using namespace std;

int Size = 33129;

int main()
{
  // Get start time
   clock_t time1=clock();

  BST mapData;

  float tempLat;
  float tempLong;
  string tempNumber;
  string tempName;

  ifstream infile;
  infile.open("address.txt");

  if(infile.fail())
  {
    cout << "Error reading the file." << endl;
  }

  for(int i = 0; i < Size; i++)
  {
    infile >> tempLat;
    infile >> tempLong;
    infile >> tempNumber;
    getline(infile, tempName);
    tempName = tempName.substr(1, tempName.length()); //getting rid of white space
    string key = tempNumber + tempName;

    Address temp(tempLat, tempLong, tempNumber, tempName, key);

    //temp.print();

    //insert Address objects into hashtable
    mapData.Insert(temp);

  }

  //mapData.Print();

  infile.close();

  // Get end time
   clock_t time2=clock();
   double run_time = (time2-time1)/(double)CLOCKS_PER_SEC;
   cout << "Run time for inserts: " << run_time << " seconds\n";
   cout << endl;

  bool leave = false;
  cout << "At any point, enter -1 to exit\n" << endl;

  while(leave != true)
  {
    string bldgNum;
    string stName;

    cout << "Please enter a Building Number: ";
    getline(cin, bldgNum);
    cout << endl;
    if(bldgNum == "-1")
    {
        leave = true;
        return 0;
    }
    cout << "Please enter a Street Name: ";
    getline(cin, stName);
    cout << endl;
    if(stName == "-1")
    {
        leave = true;
        return 0;
    }

    string searchKey = bldgNum + stName;
    Address result;

    // Get start time
   clock_t time1=clock();

   mapData.Search(result, searchKey);

    if(mapData.Search(result, searchKey) == false)
    {
        cout << "No results match your search." << endl;
        return 0;
    }

    cout << "Result Found, Printing Address: " << endl;
    result.print();

    // Get end time
    clock_t time2=clock();
    double run_time = (time2-time1)/(double)CLOCKS_PER_SEC;
    cout << "Run time for search: " << run_time << " seconds\n";
    cout << endl;

    //cout << "Latitude: " << result.getLatitude() << endl;
    //cout << "Longitude: " << result.getLongitude() << endl;

  }

}