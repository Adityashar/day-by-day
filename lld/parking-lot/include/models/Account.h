#pragma once

#include <iostream>
using namespace std;


class Account {
    string username, password;
public:
    Account(string _user, string _pass): username(_user), password(_pass) { }
    void resetPassword(string _pass) { password = _pass; }
};

class Attendant: public Account {
    PaymentService pay;
public:
    Attendant(string user, string pass, PaymentService *_pay): pay(_pay), Account(user, pass) { }

    bool processPayment(ParkingTicket *ticket) {
        //
    } 
};