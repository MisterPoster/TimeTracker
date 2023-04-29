
/* 
 * File:   TimeRecord.h
 * Author: sxmue
 *
 * Created on April 11, 2023, 10:23 AM
 */

#include <ctime>
#include <string>

using namespace std; 

#ifndef TIMERECORD_H
#define TIMERECORD_H

class TimeRecord 
{
    public:
        TimeRecord ();
        TimeRecord (string);
        TimeRecord(const TimeRecord& orig);
        virtual ~TimeRecord();
        void endTime ();
        time_t getStartTime ();
        time_t getEndTime ();
        string getLabel ();
        pair<time_t, time_t> getTimes ();
    private:
        time_t starting_time;
        time_t ending_time;
        string label;
};

#endif /* TIMERECORD_H */

