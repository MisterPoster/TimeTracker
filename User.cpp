
/* 
 * File:   User.cpp
 * Author: sxmue
 * 
 * Created on April 28, 2023, 11:25 AM
 */

#include <iostream>
#include <string>
#include <vector>

#include "User.h"

using namespace std;

User::User () {}

User::User (string name, string email, string password, int records)
{
    this->name     = name;
    this->email    = email;
    this->password = password;
    this->records  = records;
}

void User::to_str ()
{
    cout << "Name: "              << name << endl;
    cout << "Email: "             << email << endl;
    cout << "Password: "          << password << endl;
    cout << "Number of records: " << records << endl << endl;
}

User::User (const User& orig) { }

User::~User () { }
