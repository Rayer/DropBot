/**
 * Project Untitled
 */


#ifndef _PIDINSTANCESTRATEGY_H
#define _PIDINSTANCESTRATEGY_H

#include "InstanceStrategy.h"
#include <string>
#include <cstdio>

using std::string;
using std::FILE;

class PidInstanceStrategy : public InstanceStrategy {
public:
    string pid_filename;

    /**
     * @param string
     */
    PidInstanceStrategy(const string &pid_file);

protected:

    string get_pid_filename();
};

#endif //_PIDINSTANCESTRATEGY_H