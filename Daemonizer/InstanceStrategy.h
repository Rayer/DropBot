/**
 * Project Untitled
 */


#ifndef _INSTANCESTRATEGY_H
#define _INSTANCESTRATEGY_H

class InstanceStrategy {
public:

    virtual bool allow_next_instance() = 0;

    virtual int get_current_instance_count() = 0;

    virtual int add_instance() = 0;

    virtual int remove_instance() = 0;
};

#endif //_INSTANCESTRATEGY_H