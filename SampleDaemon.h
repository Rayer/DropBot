//
// Created by Rayer on 2/2/16.
//

#include "Daemonlizer.h"

#ifndef DROPBOT_SAMPLEDAEMON_H
#define DROPBOT_SAMPLEDAEMON_H


class SampleDaemon : public Daemonlizer {

public:
    virtual int application_main(int argc, char **argv);

    virtual int daemon_main();
};


#endif //DROPBOT_SAMPLEDAEMON_H
