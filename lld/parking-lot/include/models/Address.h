#pragma once

#include <iostream>
using namespace std;

class Address {
    string streetName;
    string city;
    string country;
    string pincode;

public:
    Address(string a, string b, string c, string d): streetName(a), city(b), country(c), pincode(d) { }

    string getStreetName() const {
        return streetName;
    }

    void setStreetName(const string& street) {
        streetName = street;
    }

    string getCity() const {
        return city;
    }

    void setCity(const string& cityName) {
        city = cityName;
    }

    string getCountry() const {
        return country;
    }

    void setCountry(const string& countryName) {
        country = countryName;
    }

    string getPincode() const {
        return pincode;
    }

    void setPincode(const string& code) {
        pincode = code;
    }
};;