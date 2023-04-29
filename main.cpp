
/* 
 * File:   main.cpp
 * Author: sxmue
 *
 * Created on April 11, 2023, 10:21 AM
 */

#include <cstdlib>
#include <iostream>
#include <iomanip>
#include <iterator>
#include <ctime>
#include <list>
#include <string>
#include <vector>
#include <fstream>

#include "Admin.h"
#include "TimeRecord.h"
#include "User.h"

using namespace std;

User printable [5];

int main(int argc, char** argv) 
{
    fstream users;
    
    User a ("Stan",    "marsh@gmail.com", "stan_2001", 5); 
    printable [0] = a;
    User b ("Kyle",    "broflovski@gmail.com", "ike_fan", 2); 
    printable [1] = b;
    User c ("Eric",    "cartman@gmail.com", "my_authorith", 9); 
    printable [2] = c;
    User d ("Kenny",   "mccormick@gmail.com", "i_like_mmph", 1); 
    printable [3] = d;
    User e ("Butters", "scotch@gmail.com", "my_very_own_pwd", 4); 
    printable [4] = e;
    
    users.open ("Users.dat", ios::out | ios::binary);
    for (int i = 0; i < 5; i++)
    {
        printable[i].to_str ();
        users.write ( reinterpret_cast<char *> (&printable[i]), sizeof (User) );
    }
    users.close ();
    
    
    string n;
    
    cout << "Enter a name for the user of this time tracker" << endl;
    cout << "______________________________________________" << endl; 
    cin >> n;
    
    Admin* named = new Admin (n);
    
    return 0;
}

