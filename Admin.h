
/* 
 * File:   Admin.h
 * Author: sxmue
 *
 * Created on April 11, 2023, 11:16 AM
 */

#include <vector>
#include <ctime>
#include <string>
#include <iostream>

#include "TimeRecord.h"

using namespace std;

#ifndef ADMIN_H
#define ADMIN_H

class Admin 
{
    public:
        Admin ();
        Admin (string name);
        Admin (const Admin& orig);
        virtual ~Admin ();
        double getAverageTime ();
        void createNewRecord ();
        void exportTimes ();
        time_t subtractTime (time_t, time_t);
    private:
        string name;
        vector <TimeRecord> itinerary;
};

#endif /* ADMIN_H */

