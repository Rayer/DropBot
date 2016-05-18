/**
 * Project Untitled
 */


#ifndef _SINGLEINSTANCEPIDSTRATEGY_H
#define _SINGLEINSTANCEPIDSTRATEGY_H

#include "PidInstanceStrategy.h"


class SingleInstancePidStrategy : public PidInstanceStrategy {
public:
    SingleInstancePidStrategy(const string &pid_file) : PidInstanceStrategy(pid_file) { }
};

#endif //_SINGLEINSTANCEPIDSTRATEGY_H