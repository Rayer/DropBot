/**
 * Project Untitled
 */


#ifndef _MULTIPLEINSTANCEPIDSTRATEGY_H
#define _MULTIPLEINSTANCEPIDSTRATEGY_H

#include "PidInstanceStrategy.h"


class MultipleInstancePidStrategy : public PidInstanceStrategy {
public:
    MultipleInstancePidStrategy(const string &pid_file) : PidInstanceStrategy(pid_file) { }
};

#endif //_MULTIPLEINSTANCEPIDSTRATEGY_H