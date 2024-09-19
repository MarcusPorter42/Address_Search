#include "address.h"

Address::Address()
{
    Latitude = 0;
    Longitude = 0;
    Number = "";
    Name = "";
    Key = "";
}

Address::Address(float latitude, float longitude, string number,  string name, string key)
{
    Latitude = latitude;
    Longitude = longitude;
    Number = number;
    Name = name;
    Key = key;
}

Address::Address(const Address & copy)
{
    Latitude = copy.Latitude;
    Longitude = copy.Longitude;
    Number = copy.Number;
    Name = copy.Name;
    Key = copy.Key;
}

Address::~Address()
{
    //
}

void Address::setLatitude(float latitude)
{
    Latitude = latitude;
}

void Address::setLongitude(float longitude)
{
    Longitude = longitude;
}

void Address::setNumber(int number)
{
    Number = number;
}

void Address::setName(string name)
{
    Name = name;
}

void Address::setKey(string p1, string p2)
{
    Key = p1 + p2;
}

float Address::getLatitude()
{
    return Latitude;
}

float Address::getLongitude()
{
    return Longitude;
}

string Address::getNumber()
{
    return Number;
}

string Address::getName()
{
    return Name;
}

string Address::getKey()
{
    return Key;
}

int Address::compareKey(string key1, string key2)
{
    if(key1 > key2)
    {
        return 1;
    }

    else if(key1 == key2)
    {
        return 0;
    }

    else if(key1 < key2)
    {
        return -1;
    }
    
    return -2;
}

void Address::print()
{
    cout << "Address:\n" << endl;
    cout << "Latitude: " << Latitude << endl;
    cout << "Longitude: " << Longitude << endl;
    cout << "Number: " << Number << endl;
    cout << "Name: " << Name << endl;
}