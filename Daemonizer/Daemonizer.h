//
// Created by rayer on 2015/9/14.
//

#ifndef SCG_CLUSTER_NATIVE_AGENT_DAEMONLIZER_H
#define SCG_CLUSTER_NATIVE_AGENT_DAEMONLIZER_H

#include <vector>
#include <string>
#include "Daemonizer.h"
#include <unistd.h>
#include <sys/stat.h>
#include <stdlib.h>

// Globals and settings
#define PID_DIR "/tmp/"
#define APP_NAME "dropbot"


class Daemonizer {
private:
    int _daemon_flow(int argc, char *argv[]);
    void handle_signal(int signal);
    bool is_daemon = true;


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

    int get_daemon_count();

    void set_daemon(bool isDaemon);

    int run(int argc, char *argv[]);

    virtual ~Daemonizer();

};



#endif //SCG_CLUSTER_NATIVE_AGENT_DAEMONLIZER_H
