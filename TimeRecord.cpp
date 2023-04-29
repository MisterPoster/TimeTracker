
/* 
 * File:   TimeRecord.cpp
 * Author: sxmue
 * 
 * Created on April 11, 2023, 10:23 AM
 */

#include <ctime>
#include <utility>

#include "TimeRecord.h"
#include "Admin.h"

using namespace std;

TimeRecord::TimeRecord () {}

TimeRecord::TimeRecord (string label) 
{
    this->label = label;
    time (&starting_time);
    cout << "|----> Starting time is " << starting_time << endl;
    cout << "|----> Starting time is " << ctime (&starting_time) << endl;
}

void TimeRecord::endTime () 
{ 
    time (&ending_time);
    cout << "|----> Ending time is " << ending_time << endl;
    cout << "|----> Ending time is " << ctime (&ending_time) << endl;
}

pair<time_t, time_t> TimeRecord::getTimes ()
{
    pair <time_t, time_t> s;
    
    s = make_pair (ending_time, starting_time);
    
    return s;
}

time_t TimeRecord::getStartTime () { return (starting_time); }

time_t TimeRecord::getEndTime () { return (ending_time); }

string TimeRecord::getLabel () { return (label); }

TimeRecord::TimeRecord (const TimeRecord& orig) { }

TimeRecord::~TimeRecord () { }

