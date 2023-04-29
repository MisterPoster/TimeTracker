
/* 
 * File:   Admin.cpp
 * Author: sxmue
 * 
 * Created on April 11, 2023, 11:16 AM
 */

#include <cctype>
#include <ctime>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <string>
#include <utility>

#include "Admin.h"
#include "TimeRecord.h"
#include "User.h"

Admin::Admin () {}

Admin::Admin (string name) 
{   
    this->name = name;
    char choice;
    
    
    if  (name == "Stan")
        cout << "Logging as marsh@gmail.com" << endl;
    else if  (name == "Kyle")
        cout << "Logging as broflovski@gmail.com" << endl;
    else if  (name == "Eric")
        cout << "Logging as cartman@gmail.com" << endl;
    else if  (name == "Kenny")
        cout << "Logging as mccormick@gmail.com" << endl;
    else if  (name == "Butters")
        cout << "Logging as scotch@gmail.com" << endl;
    
    cout << "Hello, " << name << endl;
    
    do
    {
        cout << "__________________________________"   << endl;
        cout << "|   What would you like to do?   |"   << endl;
        cout << "|     Create New Record - C      |"   << endl;
        cout << "| Get Average Time in Record - A |"   << endl;
        cout << "|     Export Times & Quit - E    |"   << endl;
        cout << "‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾"   << endl;
        
        cin >> choice;
        choice = toupper (choice);
        
        switch (choice)
        {
            case 'C':
                createNewRecord ();
                break;
            case 'A':
                cout << "You have an average of " << fixed << setprecision (2) << getAverageTime () << " seconds." << endl;
                break;
        }
    } while (choice != 'E');
    
    exportTimes ();
}

double Admin::getAverageTime ()
{
    if (itinerary.empty ())
    {
        cout << "No times available in itinerary" << endl << endl;
        return 0.0;    
    }
    
    int i;
    double total_sec,
           curr_sec;
    TimeRecord curr;
    pair <time_t, time_t> time_pair;
    
    struct tm * earlier, later;
    
    for (i = 0; i < itinerary.size (); i++)
    {
        curr = itinerary[i];
        
        time_pair = curr.getTimes();
        
        curr_sec = difftime (time_pair.second, time_pair.first);

        total_sec += curr_sec;
    }
    
    return (total_sec / itinerary.size ());
}

void Admin::createNewRecord () 
{ 
    itinerary.clear ();
    
    char   time_choice;
    string reason = "";
    
    do
    {
        cout << "\tPlease check in & out as much as you need!" << endl;
        cout << "\tClock In - I" << endl;
        cout << "\tQuit - Q" << endl;
        
        cin >> time_choice;
        time_choice = toupper (time_choice);
        
        if (time_choice == 'I')
        {
            cout << "What will be this time be labeled under? Limit one word." << endl;
            cin >> reason;
            
            TimeRecord labeled_time (reason);
            
            cout << "Use \'O\' to clock out.";
            cin >> time_choice;
            
            time_choice = toupper (time_choice);
            
            if (time_choice == 'O')
            {
                labeled_time.endTime ();
                itinerary.push_back (labeled_time);
            }
        }
    } while (time_choice != 'Q');
}

void Admin::exportTimes ()
{
    fstream admin_file;
    TimeRecord record;
    
    admin_file.open ("TimeRecords.dat", ios::out | ios::binary);
    
    for (int i = 0; i < itinerary.size (); i++)
    {
        record = itinerary[i];
        cout << "ADDING: " << itinerary[i].getLabel () << " TO FILE" << endl;
        
        admin_file.write (reinterpret_cast<char *> (&record), sizeof (record));
    }
    
    cout << "Time records have been exported to TimeRecords.dat" << endl;
    
    itinerary.clear ();
}

Admin::Admin (const Admin& orig) { }

Admin::~Admin () { }

