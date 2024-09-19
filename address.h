#include <iostream>

using namespace std;

class Address
{

public:
    Address();
    Address(float latitude, float longitude, string number,  string name, string key);
    Address(const Address & copy);
    ~Address();

    void setLatitude(float latitude);
    void setLongitude(float latitude);
    void setNumber(int number);
    void setName(string name);
    void setKey(string p1, string p2);

    float getLatitude();
    float getLongitude();
    string getNumber();
    string getName();
    string getKey();
    
    int compareKey(string key1, string key2);

    void print();

private:
    float Latitude;
    float Longitude;
    string Number;
    string Name;
    string Key;

};