//
// Created by rayer on 2015/9/14.
//

#ifndef SCG_CLUSTER_NATIVE_AGENT_DAEMONLIZER_H
#define SCG_CLUSTER_NATIVE_AGENT_DAEMONLIZER_H

#include <vector>
#include <string>
#include "Daemonlizer.h"
#include <unistd.h>
#include <sys/stat.h>
#include <stdlib.h>

#define PID_DIR "/tmp/"
#define APP_NAME "dropbot"

class Daemonlizer {
private:
    int _daemon_flow(int argc, char *argv[]);


protected:
    bool pid_file_exists();

    std::string pid_file_name();

    void create_pid_file(pid_t pid);

    void pid_file_delete();

public:

    /**
     * It's main application.
     * TBD: Search for paired daemon PID
     */
    virtual int application_main(int argc, char* argv[]) = 0;
    /**
     * It's daemon logic
     */
    virtual int daemon_main() = 0;

    int run(int argc, char *argv[]);

    virtual ~Daemonlizer();

};



#endif //SCG_CLUSTER_NATIVE_AGENT_DAEMONLIZER_H
